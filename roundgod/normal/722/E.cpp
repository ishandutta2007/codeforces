/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-31 20:06:20
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define MAXM 25
#define INF 1000000000
#define MOD 1000000007
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,m,k,s;
P a[MAXN];
ll dp[MAXM][MAXN];
ll fact[MAXN],invf[MAXN];
ll ans[MAXM];
ll pow_mod(ll a,ll i)
{
    ll s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
ll comb(ll n,ll k)
{
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int main()
{
    scanf("%lld%lld%lld%lld",&n,&m,&k,&s);
    bool f=false;
    for(ll i=0;i<k;i++) 
    {
        scanf("%lld%lld",&a[i].x,&a[i].y);
        if(a[i].x==n&&a[i].y==m) f=true;
    }
    if(!f) { a[k].x=n; a[k].y=m; k++;}
    sort(a,a+k);
    fact[0]=invf[0]=1;
    for(ll i=1;i<=200000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[200000]=pow_mod(fact[200000],MOD-2);
    for(ll i=199999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD; 
    for(int i=0;i<k;i++) dp[0][i]=comb(a[i].x+a[i].y-2,a[i].x-1);
    for(int i=1;i<k;i++)
        for(int j=0;j<i;j++)
        {
            dp[0][i]=((dp[0][i]-1LL*dp[0][j]*comb(a[i].x+a[i].y-a[j].x-a[j].y,a[i].x-a[j].x))%MOD+MOD)%MOD;
        }
    for(ll i=1;i<23;i++)
        for(ll j=0;j<k;j++)
        {
            dp[i][j]=comb(a[j].x+a[j].y-2,a[j].x-1);
            for(ll p=0;p<j;p++)
            {
                dp[i][j]=(dp[i][j]-1LL*dp[i][p]*comb(a[j].x+a[j].y-a[p].x-a[p].y,a[j].x-a[p].x))%MOD;
            }
            for(ll p=0;p<i;p++) dp[i][j]=(dp[i][j]-dp[p][j]+MOD)%MOD; 
        }
    ll ANS=0;
    //for(ll i=0;i<=21;i++) printf("%lld ",dp[i][k-1]);
    ll sum=comb(a[k-1].x+a[k-1].y-2,a[k-1].x-1);
    for(ll i=0;i<23;i++) sum=(sum-dp[i][k-1]+MOD)%MOD;
    if(f)
    {
        for(ll i=0;i<23;i++)
        {
            s=(s+1)/2;
            ANS=(ANS+1LL*s*dp[i][k-1])%MOD;
        }
    }
    else
    {
        for(ll i=0;i<23;i++)
        {
            ANS=(ANS+1LL*s*dp[i][k-1])%MOD;
            s=(s+1)/2;
        }
    }
    //printf("%lld\n",sum);
    ANS=(ANS+sum)%MOD;
    printf("%lld\n",1LL*ANS*pow_mod(comb(n+m-2,n-1),MOD-2)%MOD);
    return 0;
}