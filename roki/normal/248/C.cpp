#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
using namespace std;
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vvint vector<vint>
#define vint vector<int>
#define pdd pair<double,double>
typedef long long LL;
#pragma comment(linker, "/STACK:167177216")
int main()
{
    double y1,y2,yw,xa,ya,r;
    cin >> y1 >> y2 >> yw >> xa >> ya >> r;
    double xl = 0,xr = xa;
    yw -= r;
    double yt = y1 + r + 1e-6;
    for(int i = 0;i < 100;++i)
    {
        double xm = (xl + xr) / 2;
        double dx1 = - xm,dy1 = yt - yw;
        double a1 = acos(-dy1 / sqrt(dx1 * dx1 + dy1 * dy1));
        dx1 = xa - xm,dy1 = ya - yw;
        double a2 = acos(-dy1 / sqrt(dx1 * dx1 + dy1 * dy1));
        if(a1 > a2)
            xr = xm;
        else
            xl = xm;
    }
    double xm = (xl + xr) / 2;
    double a = yw - yt,b = -xm,c = -b * yt;
    double d = fabs(b * y2 + c) / sqrt(a * a + b * b);
    if(d - 1e-6 < r)
    {
        cout << -1 << endl;
        return 0;
    }
    printf("%.10lf\n",xm);
    return 0;
}