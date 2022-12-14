#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=1000000007;
ll P(ll a, ll b)
{
    if (b==0)return 1;
    ll x = P(a,b/2);
    x*=x;
    x%=mod;
    if (b%2)return(x*a)%mod;
    return x;
}
ll inv(ll x)
{
    return P(x,mod-2);
}
ll fracToInt(ll a, ll b)
{
    if (a==0)return 0;
    return (a*inv(b))%mod;
}
ll dp[1000000];
ll a[1000000];
ll b[1000000];
ll n,m;
ll solve(int i)
{
    if (i>=n)
        return 0;
    ll &ret = dp[i];
    if (a[i]==0 && b[i]==0)
    {
        ll x = m*(m-1)/2;
        ll y = m*m;
        x%=mod;
        y%=mod;
        ret = fracToInt(x,y) + (fracToInt(m,(m*m)%mod)*solve(i+1))%mod;
        ret%=mod;
    }
    else if (a[i]==0)
    {
        ll x = m-b[i];
        ll y = m;
        ret = fracToInt(x,y) + (fracToInt(1,m)*solve(i+1))%mod;
        ret%=mod;
    }
    else if (b[i]==0)
    {
        ll x = a[i]-1;
        ll y = m;
        ret = fracToInt(x,y) + (fracToInt(1,m)*solve(i+1))%mod;
        ret%=mod;
    }
    else
    {
        if (a[i]==b[i])
            ret=solve(i+1);
        else if (b[i]>a[i])
            ret=0;
        else
            ret=1;
    }
    return ret;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>n>>m;
    for (int i=0;i<n;i++)
        cin>>a[i];
    for (int i=0;i<n;i++)
        cin>>b[i];
    cout<<solve(0)<<endl;
}