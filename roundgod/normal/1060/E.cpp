/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-04 15:36:48
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,sz[MAXN],odd;
vector<int> G[MAXN];
ll ans,res;
void dfs(ll v,ll p,ll d)
{
    sz[v]=1;if(d&1) odd++; 
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(to==p) continue;
        dfs(to,v,d+1);
        sz[v]+=sz[to];
    }
    ans+=sz[v]*(n-sz[v]);
}
int main()
{
    scanf("%lld",&n);
    for(ll i=0;i<n-1;i++)
    {
        ll u,v;
        scanf("%lld%lld",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    dfs(1,0,0);
    ans+=odd*(n-odd);
    printf("%lld\n",ans/2);
    return 0;
}