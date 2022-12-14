#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std ;
ll cost[1000000];
int main ()
{
    ll n,m;
    cin>>n>>m;
    for (ll i=0;i<n;i++)
        cost[i]=(i*(i+1))/2+((n-i-1)*(n-i))/2;
    ll mn=cost[0];
    ll mx=cost[0];
    for (int i=0;i<n;i++)
        mn=min(mn,cost[i]),mx=max(mx,cost[i]);
    ll sum=0;
    for (int i=0;i<m;i++)
    {
        ll x,d;
        cin>>x>>d;
        sum+=x*n;
        if (d<0)sum+=d*mn;
        else sum+=d*mx;
    }
    long double ret=sum;
    ret/=n;
    cout<<setprecision(10)<<fixed<<ret<<endl;
}