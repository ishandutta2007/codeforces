#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[10000];
int b[10000];
    int n;
    long double m;
bool check(long double mid)
{
    long double w = m+mid;
    long double f = mid;
    for (int i=0;i<n;i++)
    {
        if (f*a[i]<w)
            return 0;
        f-=w/a[i];
        w=m+f;
        if (f*b[i]<w)
            return 0;
        f-=w/b[i];
        w=m+f;
    }
    return 1;
}
long double bs(long double l,long double r)
{
    long double ret = -1;
    for (int i=0;i<200;i++)
    {
        long double mid = (l+r)/2;
        if (check(mid))
            ret=mid,r=mid;
        else
            l=mid;
    }
    return ret;
}
int main()
{
    cin>>n>>m;
    for (int i=0;i<n;i++)
        cin>>a[i];
    for (int i=0;i<n;i++)
        cin>>b[i];
    long double ret =bs(0,1000000000);
    if (ret<0)
    cout<<-1<<endl;
    else
    cout<<setprecision(10)<<fixed<<ret<<endl;
}