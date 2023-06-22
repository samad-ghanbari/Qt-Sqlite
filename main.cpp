#include <QCoreApplication>
#include <QtSql>
#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString dbPath="dbSqlite.db";
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);
    if(!db.open()) qDebug()<<db.lastError().text();

    QSqlQuery query(db);
    query.prepare("create table red_folder (red_id int, abb1 varchar(20), code1 varchar(20));");
    if(!query.exec()) qDebug()<<query.lastError().text();

    query.prepare("insert into red_folder values(1, 'ks', '4400');");
    if(!query.exec()) qDebug()<<query.lastError().text();

    query.prepare("insert into red_folder values(2, 'ba', '2200');");
    if(!query.exec()) qDebug()<<query.lastError().text();

    query.prepare("insert into red_folder values(2, 'امتحان', 'بررسی');");
    if(!query.exec()) qDebug()<<query.lastError().text();

    query.prepare("select * from red_folder");
    if(!query.exec()) qDebug()<<query.lastError().text();
    while(query.next())
    {
        qDebug()<<query.value(0).toInt()<<" "<<query.value(1).toString()<<" "<<query.value(2).toString()<<endl;
    }


    db.close();

    return a.exec();
}

