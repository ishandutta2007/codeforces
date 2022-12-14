# include <bits/stdc++.h>
# include <vector>
# include <stdio.h>
#include <limits.h>
#include <stack>
#include <algorithm>
using namespace std;
long double x[1000000];
long double v[1000000];
long double mxR[1000000];
long double mxL[1000000];
int n;

pair<long double,long double> a[1000000];
bool check(long double m)
{
    for (int i=0;i<n;i++)
    {
        mxR[i]=a[i].first+a[i].second*m;
        mxL[i]=a[i].first-a[i].second*m;
    }
    for (int i=1;i<n;i++)
    {
        mxR[i]=min(mxR[i],mxR[i-1]);
    }
    for (int i=n-1;i>=0;i--)
    {
        mxL[i]=max(mxL[i],mxL[i+1]);
    }
    for (int i=0;i<n-1;i++)
    {
        if (min(mxR[i],a[i+1].first)>=max(mxL[i+1],a[i].first))
            return 1;
    }
    return 0;
}
long double bs(long double l,long double r)
{
    long double ans=r;
    for (int i=0;i<300;i++)
    {
        long double mid=(l+r)/2;
        if (check(mid))
            ans=mid,r=mid;
        else l=mid;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i].first;
    for (int i=0;i<n;i++)
        cin>>a[i].second;
    sort(a,a+n);
    check(1.15);
    long double ans=bs(0,1000000000);
  	cout<<setprecision(10)<<fixed<<ans<<endl;
}