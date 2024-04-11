#include <iostream>

using namespace std;

bool ravn (int a1, int a2, int a3, int a4)
{
    if (a1==a2&&a1==a3&&a1==a4)
        return true;
    else return false;
}

bool check (int q1, int q2, int w1, int w2, int e1, int e2, int r1, int r2, int q3, int q4, int w3, int w4, int e3, int e4, int r3, int r4)
{
    if (q1==q2&&w1==w2&&e1==e2&&r1==r2&&q3==q4&&w3==w4&&e3==e4&&r3==r4)
    {
        if ((q1==w3&&w1==e3&&e1==r3&&r1==q3)||(q1==r3&&w1==q3&&e1==w3&&r1==e3))
            return true;
        else return false;
    }
    else return false;
}

int main()
{
    int a[25];
    for (int i=1; i<25; i++)
            cin >> a[i];
    if (ravn(a[1],a[2],a[3],a[4]))
    {
        if (ravn(a[9],a[10],a[11],a[12]))
            {if (check(a[5],a[6],a[17],a[18],a[21],a[22],a[13],a[14],a[7],a[8],a[19],a[20],a[23],a[24],a[15],a[16]))
                cout << "YES";
            else
                cout << "NO";}
        else cout << "NO";
        return 0;
    }
    if (ravn(a[5],a[6],a[7],a[8]))
    {
        if (ravn(a[21],a[22],a[23],a[24]))
            {if (check(a[3],a[4],a[17],a[19],a[10],a[9],a[16],a[14],a[1],a[2],a[18],a[20],a[12],a[11],a[15],a[13]))
                cout << "YES";
            else
                cout << "NO";}
        else cout << "NO";
        return 0;
    }
    if (ravn(a[13],a[14],a[15],a[16]))
    {
        if (ravn(a[17],a[18],a[19],a[20]))
            {if (check(a[2],a[4],a[6],a[8],a[10],a[12],a[21],a[23],a[1],a[3],a[5],a[7],a[9],a[11],a[22],a[24]))
                cout << "YES";
            else
                cout << "NO";}
        else cout << "NO";
        return 0;
    }
    else cout << "NO";
    return 0;
}