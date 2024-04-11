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
int n,x[500000],v[500000];
bool f(double t)
{
    double last = 2 * -1e18;
    for(int i = 0;i < n;++i)
    {
        if(v[i] > 0)
            last = max(last,x[i] + t * v[i]);
        else
            if(last >= x[i] + t * v[i])
                return 1;
    }
    return 0;
}
int main()
{
    int y = 1e9,y1 = -1e9;
    scanf("%d",&n);
    for(int i = 0;i < n;++i)
    {
        scanf("%d%d",&x[i],&v[i]);
        if(v[i] > 0)
            y = min(y,x[i]);
        else
            y1 = max(y1,x[i]);
    }
    if(y > y1)
    {
        printf("-1\n");
        return 0;
    }
    double l = 0,r = 2 * 1e9;
    for(int i = 0;i < 100;++i)
    {
        double m = (r + l) / 2;
        if(f(m))
            r = m;
        else
            l = m;
    }
    printf("%.9lf\n",(r + l) / 2);
    return 0;
}