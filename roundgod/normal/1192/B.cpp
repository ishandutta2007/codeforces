#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{ll to,cost;};
ll n,q,w;
ll st[MAXN],ed[MAXN];
vector<edge> G[MAXN];
struct edge2
{
    ll u,v,cost;
}edges[MAXN];
ll tot,dep[2*MAXN];
void add_edge(ll u,ll v,ll cost)
{
    G[u].push_back((edge){v,cost});
    G[v].push_back((edge){u,cost});
}
struct node
{
    node() {val[0]=val[1]=val[2]=val[3]=val[4]=-INF;}
    ll val[5];
    /*  0: a
        1: -2b
        2: a-2b
        3: -2b+c
        4: a-2b+c */
    void init(ll x)
    {
        val[0]=x;
        val[1]=-2*x;
        val[2]=val[3]=-x;
        val[4]=0;
    }
    void add(ll x)
    {
        val[0]+=x; val[1]-=2*x; val[2]-=x; val[3]-=x;
    }
    void update(const node &lhs,const node &rhs)
    {
        for(ll i=0;i<5;i++) val[i]=max(lhs.val[i],rhs.val[i]);
        val[2]=max(val[2],lhs.val[0]+rhs.val[1]);
        val[3]=max(val[3],lhs.val[1]+rhs.val[0]);
        val[4]=max(val[4],max(lhs.val[0]+rhs.val[3],lhs.val[2]+rhs.val[0]));
    }
};
void dfs(ll v,ll p,ll d)
{
    dep[++tot]=d;
    st[v]=tot;
    for(auto e:G[v])
    {
        if(e.to==p) continue;
        dfs(e.to,v,d+e.cost);
        dep[++tot]=d;
    }
    ed[v]=tot;
}
struct segtree
{
    node maxi[8*MAXN];
    ll lazy[8*MAXN];
    void pushup(ll k)
    {
        maxi[k].update(maxi[k*2],maxi[k*2+1]);
    }
    void pushdown(ll k)
    {
        if(!lazy[k]) return;
        for(ll i=k*2;i<=k*2+1;i++)
        {
            maxi[i].add(lazy[k]);
            lazy[i]+=lazy[k];
        }
        lazy[k]=0;
    }
    void build(ll k,ll l,ll r)
    {
        if(l==r)
        {
            maxi[k].init(dep[l]);
            return;
        }
        ll mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(ll k,ll l,ll r,ll x,ll y,ll v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y)
        {
            maxi[k].add(v);
            lazy[k]+=v;
            return;
        }
        pushdown(k);
        ll mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    node query(ll k,ll l,ll r,ll x,ll y)
    {
        if(l>y&&x>r) return node();
        if(l>=x&&r<=y) return maxi[k];
        pushdown(k);
        ll mid=(l+r)/2;
        node ret;
        ret.update(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
        return ret;
    }
}seg;
void update_edge(ll id,ll cost)
{
    ll delta=cost-edges[id].cost;
    ll v=(st[edges[id].u]<st[edges[id].v]?edges[id].v:edges[id].u);
    seg.update(1,1,tot,st[v],ed[v],delta);
    edges[id].cost=cost;
}
int main()
{
    scanf("%lld%lld%lld",&n,&q,&w);
    for(ll i=0;i<n-1;i++)
    {
        ll u,v,cost;
        scanf("%lld%lld%lld",&u,&v,&cost);
        edges[i].u=u; edges[i].v=v; edges[i].cost=cost;
        add_edge(u,v,cost);
    }
    dfs(1,0,0);
    assert(tot==2*n-1);
    seg.build(1,1,tot);
    ll last=0,d,e;
    for(ll i=0;i<q;i++)
    {
        scanf("%lld%lld",&d,&e);
        d=(d+last)%(n-1);
        e=(e+last)%w;
        update_edge(d,e);
        last=seg.query(1,1,tot,1,tot).val[4];
        printf("%lld\n",last);
    }
    return 0;
}