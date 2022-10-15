#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,V[MAXN];
vector<ll> G[MAXN];
ll odd[MAXN],even[MAXN],todd[MAXN],teven[MAXN];
bool used[MAXN];
ll ans=0;
void dfs1(ll v,ll p)
{
    for(ll i=0;i<(ll)G[v].size();i++)
    {
        if(G[v][i]==p) continue;
        dfs1(G[v][i],v);
        odd[v]+=even[G[v][i]];
        even[v]+=odd[G[v][i]];
    }
    odd[v]++;
    //printf("%I64d%I64d%I64d\n",v,odd[v],even[v]);
}
void dfs2(ll v,ll p,bool flag)
{
    if(flag) {todd[v]=odd[0]; teven[v]=even[0];}
    else {todd[v]=even[0]; teven[v]=odd[0];}
    for(ll i=0;i<(ll)G[v].size();i++)
    {
        if(G[v][i]==p) continue;
        dfs2(G[v][i],v,!flag);
    }
}
void dfs3(ll v,ll p)
{
    ll res=0;
    res=(res-(V[v]*even[v]%MOD)*even[v]%MOD+MOD)%MOD;
    res=(res+(V[v]*odd[v]%MOD)*odd[v]%MOD)%MOD;
    for(ll i=0;i<(ll)G[v].size();i++)
    {
        if(G[v][i]==p) continue;
        res-=V[v]*even[G[v][i]]*even[G[v][i]];
        res+=V[v]*odd[G[v][i]]*odd[G[v][i]];
    }
    ans=(ans+res-V[v]+MOD)%MOD;
    //printf("%I64d \n",ans);
    for(ll i=0;i<(ll)G[v].size();i++)
    {
        if(G[v][i]==p) continue;
        dfs3(G[v][i],v);
    }
}
void dfs4(ll v,ll p)
{
    if(v!=0)
    {
        ans=(ans+(V[v]*(teven[p]-odd[v])%MOD)*odd[v]*2%MOD)%MOD;
        ans=(ans-(V[v]*(todd[p]-even[v])%MOD)*even[v]*2%MOD)%MOD;
    }
    for(ll i=0;i<G[v].size();i++)
    {
        if(G[v][i]==p) continue;
        dfs4(G[v][i],v);
    }
}
int main()
{
    scanf("%I64d",&n);
    for(ll i=0;i<n;i++)
        scanf("%I64d",&V[i]);
    for(ll i=0;i<n-1;i++)
    {
        ll u,v;
        scanf("%I64d%I64d",&u,&v);
        u--;v--;
        G[u].push_back(v);G[v].push_back(u);
    }
    memset(odd,0,sizeof(odd));
    memset(even,0,sizeof(even));
    memset(todd,0,sizeof(todd));
    memset(teven,0,sizeof(teven));
    dfs1(0,-1);
    dfs2(0,-1,true);
    dfs3(0,-1);
    //printf("%I64d \n",ans);
    dfs4(0,-1);
    for(ll i=0;i<n;i++)
        ans=(ans+V[i])%MOD;
    ans=(ans+MOD)%MOD;
    printf("%I64d\n",ans);
    return 0;
}