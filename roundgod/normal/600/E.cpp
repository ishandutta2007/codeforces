/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-12 00:26:00
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,t,c[MAXN],sz[MAXN],st[MAXN],ed[MAXN],cnt[MAXN],rev[MAXN],sum[MAXN],maxi,ans[MAXN];
vector<int> G[MAXN];
void dfs(ll v,ll p)
{
    st[v]=++t;rev[t]=v;
    sz[v]=1;
    for(ll i=0;i<(int)G[v].size();i++)
    {
        if(G[v][i]==p) continue;
        dfs(G[v][i],v);
        sz[v]+=sz[G[v][i]];
    }
    ed[v]=t;
    return;
}
void dfs2(ll v,ll p,bool keep)
{
    ll mx=-1,wson=-1;
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(to==p) continue;
        if(sz[to]>mx) {mx=sz[to]; wson=to;}
    }
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(to==p||to==wson) continue;
        dfs2(to,v,0);
    }
    if(wson!=-1) dfs2(wson,v,1);
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(to==p||to==wson) continue;
        for(ll j=st[to];j<=ed[to];j++)
        {
            ll q=cnt[c[rev[j]]];
            cnt[c[rev[j]]]++;
            maxi=max(maxi,q+1);
            sum[q]-=c[rev[j]];
            sum[q+1]+=c[rev[j]];
        }
    }
    ll q=cnt[c[v]];
    cnt[c[v]]++;
    maxi=max(maxi,q+1);
    sum[q]-=c[v];sum[q+1]+=c[v];
    /*printf("%lld\n",v);
    for(ll i=1;i<=n;i++)
        printf("%lld ",cnt[i]);
    puts("");*/
    ans[v]=sum[maxi];
    //answer queries here
    if(!keep) 
    {
        for(ll j=st[v];j<=ed[v];j++)
        {
            ll q=cnt[c[rev[j]]];
            cnt[c[rev[j]]]--;
            sum[q]-=c[rev[j]];
            sum[q-1]+=c[rev[j]];
        }
        maxi=0;
    }
}
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) scanf("%lld",&c[i]);
    for(ll i=0;i<n-1;i++)
    {
        ll u,v;
        scanf("%lld%lld",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    dfs(1,0);
    maxi=0;
    dfs2(1,0,1);
    for(ll i=1;i<=n;i++) printf("%lld ",ans[i]);
    return 0;
}