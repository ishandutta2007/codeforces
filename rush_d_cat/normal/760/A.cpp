#include <iostream>
using namespace std;
int m, d;
int main()
{
    int res = 0;
    cin >> m >> d;
    if(m==2 && d==1)
    {
        res = 4;
    } 
    else if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&(d==6||d==7))
    {
        res = 6;
    } 
    else if((m==4||m==6||m==9||m==11) && (d==7))
    {
        res = 6;
    } else {
        res = 5;
    }
    cout << res << endl;
}