# include <iostream>
# include <algorithm>
# include <stdio.h>
using namespace std;
struct lemm
{
    int m;
    int v;
    int idx;
};
bool comp(lemm a,lemm b)
{
    if (a.m==b.m)
        return a.v<b.v;
    else
        return a.m<b.m;
}
lemm a[1000000];
int n,k,h;
bool check(double mid)
{
    int num=0;
    for (int i=0;i<n;i++)
    {
        if (num>=k)
            return 1;
        if ((double(num+1)*h)/a[i].v<=mid)
            num++;
    }
    if (num>=k)
        return 1;
    return 0;
}
void solve(double mid)
{
    int num=0;
    for (int i=0;i<n;i++)
    {
        if (num>=k)
            break;
        if ((double(num+1)*h)/a[i].v<=mid)
            printf("%d ",a[i].idx),num++;
    }
    printf("\n");
}
int main()
{
    scanf("%d%d%d",&n,&k,&h);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i].m);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i].v);
    for (int i=0;i<n;i++)
        a[i].idx=i+1;
    sort(a,a+n,comp);
    double s=0,e=(double)h*k;
    double best;
    for (int i=0;i<100;i++)
    {
        double mid=(s+e)/2.0;
        if (check(mid))
        {
            best=mid;
            e=mid;
        }
        else
            s=mid;
    }
    solve(best);
}