/*************************************************************************
    > File Name: H.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-24 23:28:55
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 400005
#define MAXLOGN 20
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m,q,C,root;
vector<ll> G[MAXN];
ll dep[MAXN],c[MAXN],f[MAXN],fa[MAXN];
ll cnt[MAXN],sum[MAXN],sum2[MAXN];
bool centroid[MAXN];
ll sz[MAXN];
ll st[MAXLOGN][2*MAXN];
ll vs[MAXN*2-1];
ll depth[MAXN*2-1];
ll id[MAXN];
map<ll,ll> mp1[MAXN],mp2[MAXN],num[MAXN];
void dfs(ll v,ll p,ll d,ll &k)
{
    id[v]=k;
    vs[k]=v;
    depth[k++]=d;
    for(ll i=0;i<(int)G[v].size();i++)
    {
        if(G[v][i]!=p)
        {
            dfs(G[v][i],v,d+1,k);
            vs[k]=v;
            depth[k++]=d;
        }
    }
}
ll getMin(ll x, ll y)
{
    return depth[x]<depth[y]?x:y;
}

void rmq_init(ll n)
{
    for(ll i=1;i<=n;++i) st[0][i]=i;
    for(ll i=1;1<<i<n;++i)
        for(ll j=1;j+(1<<i)-1<=n;++j)
            st[i][j]=getMin(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
void init(ll V)
{
    ll k=0;
    dfs(1,0,0,k);
    rmq_init(V*2-1);
}
ll query(ll l, ll r)
{
    ll k=31-__builtin_clz(r-l+1);
    return getMin(st[k][l],st[k][r-(1<<k)+1]);
}
ll lca(ll u,ll v)
{
    if(u==v) return u;
    return vs[query(min(id[u],id[v]),max(id[u],id[v]))];
}
ll dis(ll u,ll v)
{
    return depth[id[u]]+depth[id[v]]-2*depth[id[lca(u,v)]];
}
void Dfs(ll v,ll p,ll d)
{
    dep[v]=d;
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(to==p) continue;
        Dfs(to,v,d+1);
    }
}
P getroot(ll v,ll p,ll t)//search_centroid
{
    P res=P(INT_MAX,-1);
	ll m=0;
    sz[v]=1;
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(to==p||centroid[to]) continue;
        res=min(res,getroot(to,v,t));
        m=max(m,sz[to]);
        sz[v]+=sz[to];
    }
    m=max(m,t-sz[v]);
    res=min(res,P(m,v));
    return res;
}
void build(ll v,ll p)
{
    centroid[v]=true;fa[v]=p;
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(centroid[to]) continue;
        root=getroot(to,v,sz[to]).S;
        build(root,v);
    }
    root=v;
}
void Update(ll v,ll k,ll sgn)
{
    ll t=v;num[v][k]+=sgn;
    while(fa[v])
    {
        num[fa[v]][k]+=sgn;
        mp1[fa[v]][k]+=sgn*dis(fa[v],t);
        mp2[v][k]+=sgn*dis(fa[v],t);
        v=fa[v];
    }
}
ll Query(ll v,ll k)
{
    ll t=v,ans=mp1[v][k];
    while(fa[v])
    {
        ans+=mp1[fa[v]][k]-mp2[v][k];
        ans+=(num[fa[v]][k]-num[v][k])*dis(fa[v],t);
        v=fa[v];
    }
    return ans;
}
void pre()
{
    init(n);
    root=getroot(1,0,n).S;
    build(root,0);
}
int main()
{
    scanf("%lld%lld%lld%lld",&n,&m,&q,&C);
    for(ll i=1;i<=n;i++) scanf("%lld",&f[i]);
    for(ll i=2;i<=n;i++) 
    {
        ll v;scanf("%lld",&v);
        G[v].push_back(i);G[i].push_back(v);
    }
    Dfs(1,0,1);
    for(ll i=1;i<=m;i++) scanf("%lld",&c[i]);
    for(ll i=1;i<=n;i++)
    {
        cnt[f[i]]++;
        sum[f[i]]+=dep[i];
    }
    pre();
    for(ll i=1;i<=n;i++)
    {
        Update(i,f[i],1);
        sum2[f[i]]+=Query(i,f[i]);
    }
    ll type,x,y,k;
    while(q--)
    {
        scanf("%lld",&type);
        if(type==1)
        {
            scanf("%lld%lld",&x,&y);
            cnt[f[x]]--;cnt[y]++;
            sum[f[x]]-=dep[x];sum[y]+=dep[x];
            sum2[f[x]]-=Query(x,f[x]);
            Update(x,f[x],-1);
            Update(x,y,1);
            sum2[y]+=Query(x,y);
            f[x]=y;
        }
        else
        {
            scanf("%lld",&k);
            ll ans=C*C*n;
            ll res=(-2*C*c[k]+c[k]*c[k]*cnt[k])*sum[k];
            ans+=res;
            ans-=c[k]*c[k]*sum2[k];
            printf("%.10Lf\n",(long double)ans/n);
        }
    }
    return 0;
}