/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-25 02:11:52
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,k,sz[MAXN];
P dp[MAXN][2];//0: not chosen 1:chosen
vector<int> G[MAXN];
void add(ll &a,ll b) {a+=b; if(a>=MOD) a-=MOD;}
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
void dfs(ll v,ll p)
{
    dp[v][0]=P(1,0);dp[v][1]=P(0,0);sz[v]=1;
    ll cur1=1,ans1=0,ans2=0;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v); 
        sz[v]+=sz[to];
        cur1=1LL*(2*dp[to][1].F+dp[to][0].F)*cur1%MOD;
    }
    for(auto to:G[v])
    {
        if(to==p) continue;
        add(ans1,1LL*pow_mod(2,sz[v]-sz[to])*dp[to][1].S%MOD);
        add(ans1,1LL*pow_mod(2,sz[v]-sz[to]-1)*dp[to][0].S%MOD);
        add(ans2,1LL*pow_mod(2,sz[v]-sz[to])*(dp[to][0].S+dp[to][1].S)%MOD);
    }
    dp[v][0].F=cur1;
    dp[v][1].F=(pow_mod(2,sz[v]-1)-cur1+MOD)%MOD;
    dp[v][0].S=ans1;
    dp[v][1].S=(ans2-ans1+dp[v][1].F+MOD)%MOD;
    //printf("%lld %lld %lld %lld %lld\n",v,dp[v][0].F,dp[v][0].S,dp[v][1].F,dp[v][1].S);
}
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<n;i++)
    {
        ll u,v;scanf("%lld%lld",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    dfs(1,0);
    printf("%lld\n",2LL*(dp[1][0].S+dp[1][1].S)%MOD);
    return 0;
}