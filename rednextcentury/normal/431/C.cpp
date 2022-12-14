#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define go ios::sync_with_stdio(0)
ll n,k,d,dp[1011][7];
ll mod=1e9+7;
ll rec(ll s,ll f)
{
    ll &ret=dp[s][f];
    if(ret+1)
        return ret;
    if(s>n)
        return 0;
    if(s==n)
    {
        if(f)
            return 1;
        return 0;
    }
    ret=0;
    for(ll i=1;i<=k;i++)
    {
        if(i>=d)
            ret+=rec(s+i,1)%mod;
        else
            ret+=rec(s+i,f)%mod;
        ret%=mod;
    }
    ret%=mod;
    return ret;
}
int main()
{
    go;
    cin>>n>>k>>d;
    memset(dp,-1,sizeof dp);
    cout<<rec(0,0);
    return 0;
}