#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
const int MOD = 1000000000 + 7;
const int NICO = 1000 + 10;
int n, tot, ans;
double a,b,c,d,x,y;
struct Point
{
    double x, y;
} p[NICO];
struct Mid
{
    double x, y, k;
} mid[NICO*NICO];
bool equal(double x, double y)
{
    return abs(x-y) < 1e-9;
}
bool cmp(Mid a, Mid b)
{
    if(equal(a.x, b.x))
    {
        if(equal(a.y,b.y))
        {
            return a.k < b.k;
        } 
        return a.y < b.y;
    }
    return a.x < b.x;
}
void read()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
        x = a/b;
        y = c/d;
        p[i].x = x / (x*x + y*y);
        p[i].y = y / (x*x + y*y);
    }
}
void init()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            mid[++tot].x = p[i].x + p[j].x;
            mid[tot].y = p[i].y + p[j].y;
            if(equal(p[i].x, p[j].x))
            {
                mid[tot].k = 1e9;
            } else {
                mid[tot].k = (p[j].y - p[i].y) / (p[j].x - p[i].x);
            }
        }
    }
}
void solve()
{
    sort(mid+1,mid+1+tot,cmp);
    int i, j;
    for(i=1;i<=tot;i=j)
    {
        int cnt = 1; LL res = 1;
        for(j=i+1;j<=tot && equal(mid[j].x ,mid[i].x) && equal(mid[j].y, mid[i].y);j++)
        {
            if(equal(mid[j].k,mid[j-1].k)) cnt ++;
            else res = res*(cnt+1)%MOD, cnt = 1;
        }
        res = res * (cnt+1) % MOD;
        ans = (ans + res - 1) % MOD;
    }
    printf("%d\n", ans - tot);
}
int main()
{
    read();
    init();
    solve();   
}