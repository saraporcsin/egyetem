#include "std_lib_facilities.h"

struct Date{
	int year;
	int month;
	int day;
	Date(int y, int m, int d);
	void add_day(int n);
};

Date::Date(int y, int m, int d)
{
	if (y>0)
		year= y;
	else
		error("Invalid year");
	if (m<13 && m>0)
		month = m;
	else
		error("Invalid month");
	if (d<32 && d>0)
		day = d;
	else
		error("Invalid day");
}

void Date::add_day(int n)
{
	day += n;
	if (day>31)
	{
		month++;
		day -= 31;
		if (month>12)
		{
			year++;
			month -= 12;
		}
	}
}

int main()
try{
Date today {1978, 6, 25};

cout<< "Today: "<< today.year << ". " << today.month << ". " << today.day << ".\n";

today.add_day(1);

Date tomorrow {today};

cout << "Tomorrow: "<< today.year << ". " << today.month << ". " << today.day << ".\n";

return 0;
}
catch (exception& e){
	cout<< "Error: " << e.what()<<endl;
	return 1;}