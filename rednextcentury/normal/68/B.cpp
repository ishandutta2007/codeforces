#include<bits/stdc++.h>
using namespace std;
long double a[100000];
int n,k;
bool check(long double mid)
{
    long double X=0;
    for (int i=n-1;i>=0;i--)
    {
        if (a[i]>mid)
            X+=(a[i]-mid)-(a[i]-mid)*k/100.0;
        else
            X-=(mid-a[i]);
    }
    return X>=0;
}
long double bs(long double l,long double r)
{
    long double ret;
    for (int i=0;i<100;i++)
    {
        long double mid=(l+r)/2;
        if (check(mid))
            ret=mid,l=mid;
        else r=mid;
    }
    return ret;
}
int main()
{
    cin>>n>>k;
    for (int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    check(4);
    cout<<setprecision(10)<<fixed<<bs(0,1000)<<endl;
}