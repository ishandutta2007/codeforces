#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
pair<long double,long double> p[1000000];
int n;
    int mn=1e9;
    int mx=-1e9;
bool check(long double mid)
{
    long double l=-1e9,r=1e9;
    long double y=mid;
    if (mn<0)
        y=-mid;
    for (int i=0;i<n;i++)
    {
        if (fabs(y-p[i].second)>mid)
            return 0;
        long double can = sqrt((mid - (y-p[i].second))*(mid+y-p[i].second));
        l=max(l,p[i].first-can);
        r=min(r,p[i].first+can);
    }
    return (r+1e-6)>=l;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int X,Y;
        cin>>X>>Y;
        p[i].first = X;
        p[i].second= Y;
        mn=min(mn,Y);
        mx=max(mx,Y);
    }
    if (mn<0 && mx>0)
    {
        cout<<-1<<endl;
        return 0;
    }
    sort(p,p+n);
    check(0.5);
    long double l=0,r=1e15;
    long double ans=-100;
    for (int i=0;i<100;i++)
    {
        long double mid=(l+r)/2;
        if (check(mid))
            ans=mid,r=mid;
        else
            l=mid;
    }
    if (ans<-10)
    {
        cout<<-1<<endl;
    }
    else cout<<setprecision(10)<<fixed<<ans<<endl;
}