#include <bits/stdc++.h>
using namespace std;
pair<long double,int> a[1000000];
pair<long double,int> b[1000000];
long double x[1000000];
long double y[1000000];
int main ()
{
    long double x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    int n;
    cin>>n;
    long double ret=0;
    for (int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
        ret+=hypot(x[i]-x3,y[i]-y3)*2;
        a[i]=make_pair(-hypot(x[i]-x3,y[i]-y3)+hypot(x[i]-x1,y[i]-y1),i);
        b[i]=make_pair(-hypot(x[i]-x3,y[i]-y3)+hypot(x[i]-x2,y[i]-y2),i);
    }
    sort(a,a+n);
    sort(b,b+n);
    long double ans=1e18;
    for (int i=0;i<min(n,5);i++)
    {
        ans=min(ans,ret+a[i].first);
        for (int j=0;j<min(n,5);j++)
        {
            ans=min(ans,ret+b[j].first);
            if (a[i].second!=b[j].second)
                ans=min(ans,ret+a[i].first+b[j].first);
        }
    }
    cout<<setprecision(10)<<fixed<<ans<<endl;
}