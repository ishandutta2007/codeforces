#include <iostream>
using namespace std;
typedef long long LL;



double m[5][2], a[5];

int chk(double x)
{
    for (int i = 1; i <= 4; i ++)
    {
        m[i][0] = a[i] - x;
        m[i][1] = a[i] + x;
    }

    double mn1 = 1e18, mx1 = -1e18, mn2 = 1e18, mx2 = -1e18;
   
    mn1 = min(mn1, m[1][0]*m[4][0]);
    mn1 = min(mn1, m[1][0]*m[4][1]);
    mn1 = min(mn1, m[1][1]*m[4][0]);
    mn1 = min(mn1, m[1][1]*m[4][1]);

    mx1 = max(mx1, m[1][0]*m[4][0]);
    mx1 = max(mx1, m[1][0]*m[4][1]);
    mx1 = max(mx1, m[1][1]*m[4][0]);
    mx1 = max(mx1, m[1][1]*m[4][1]);

    mn2 = min(mn2, m[2][0]*m[3][0]);
    mn2 = min(mn2, m[2][0]*m[3][1]);
    mn2 = min(mn2, m[2][1]*m[3][0]);
    mn2 = min(mn2, m[2][1]*m[3][1]);

    mx2 = max(mx2, m[2][0]*m[3][0]);
    mx2 = max(mx2, m[2][0]*m[3][1]);
    mx2 = max(mx2, m[2][1]*m[3][0]);
    mx2 = max(mx2, m[2][1]*m[3][1]);

    if ( max(mn1, mn2) <= min(mx1, mx2) ) return 1;
    return 0;
}

int main()
{

    for (int i = 1; i <= 4; i ++)
    {
        cin >> a[i];
    }

    double L = 0, R = 1e12;
    for (int i = 1; i <= 100; i ++)
    {
        double mid = (L + R) / 2;
        if (chk(mid)) R = mid;
        else L = mid; 
    }
    printf("%.12f\n", R);

}