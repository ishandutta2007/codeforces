/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-27 23:30:55
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN],dp[MAXN];
ll fact[MAXN],invf[MAXN];
ll pow_mod(ll a,ll i)
{
    ll s=1;
    while(i)
    {
        if(i&1) s=s*a%MOD;
        a=a*a%MOD;
        i>>=1;
    }
    return s;
}
ll comb(ll n,ll k)
{
    return (fact[n]*invf[k]%MOD)*invf[n-k]%MOD;
}
int main()
{
    scanf("%lld",&n);
    fact[0]=invf[0]=1;
    for(ll i=1;i<=n;i++)
        fact[i]=fact[i-1]*i%MOD;
    invf[n]=pow_mod(fact[n],MOD-2);
    for(ll i=n-1;i>=1;i--)
        invf[i]=invf[i+1]*(i+1)%MOD;
    for(ll i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    memset(dp,0,sizeof(dp));
    dp[n+1]=1;
    for(ll i=n;i>=1;i--)
    {
        if(a[i]<=n-i&&a[i]>0) 
        {
            for(ll j=i+a[i]+1;j<=n+1;j++)
            {
                ll res=comb(j-i-1,a[i]);
                (dp[i]+=res*dp[j])%=MOD;
            }
        }
        //printf("%lld %lld\n",i,dp[i]);
    }
    ll ans=0;
    for(ll i=1;i<=n;i++) ans=(ans+dp[i])%MOD;
    printf("%lld\n",ans);
    return 0;
}