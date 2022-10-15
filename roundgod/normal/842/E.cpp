#include<bits/stdc++.h>
#define MAXN 600005
#define MAXLOGN 20
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int st[MAXN],ed[MAXN];
vector<int> G[MAXN];
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
struct segtree
{
    P maxi[4*MAXN]; int lazy[4*MAXN];
    void pushup(int k)
    {
        if(maxi[k*2].F==maxi[k*2+1].F) maxi[k]=P(maxi[k*2].F,maxi[k*2].S+maxi[k*2+1].S);
        else maxi[k]=max(maxi[k*2],maxi[k*2+1]);
    }
    void add(int k,int v)
    {
        maxi[k].F+=v;
        lazy[k]+=v;
    }
    void pushdown(int k)
    {
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++) add(i,lazy[k]);
        lazy[k]=0;
    }
    void build(int k,int l,int r)
    {
        lazy[k]=0;
        if(l==r)
        {
            maxi[k]=P(-INF,1);
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y)
        {
            add(k,v);
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    void update2(int k,int l,int r,int pos,int v)
    {
        if(l==r)
        {
            maxi[k]=P(v,1);
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        if(pos<=mid) update2(k*2,l,mid,pos,v); else update2(k*2+1,mid+1,r,pos,v);
        pushup(k);
    }
}seg;
int pa[MAXLOGN][MAXN];
int depth[MAXN];
int n,q,tot;
void dfs(int v,int p,int d)
{
    pa[0][v]=p; st[v]=++tot;
    depth[v]=d;
    for(int i=0;i<(int)G[v].size();i++)
        if(G[v][i]!=p) dfs(G[v][i],v,d+1);
    ed[v]=tot;
}
void init(int V)
{
    dfs(1,-1,0);
    for(int k=0;k+1<MAXLOGN;k++)
    {
        for(int v=1;v<=V;v++)
        {
            if(pa[k][v]<0) pa[k+1][v]=-1;
            else pa[k+1][v]=pa[k][pa[k][v]];
        }
    }
}
int get(int v,int x)
{
    for(int k=0;k<MAXLOGN;k++)
        if((x>>k)&1)
            v=pa[k][v];
    return v;
}
int lca(int u,int v)
{
    if(depth[u]>depth[v]) swap(u,v);
    v=get(v,depth[v]-depth[u]);
    if(u==v) return u;
    for(int k=MAXLOGN-1;k>=0;k--)
    {
        if(pa[k][u]!=pa[k][v])
        {
            u=pa[k][u];
            v=pa[k][v];
        }
    }
    return pa[0][u];
}
int dis(int u,int v)
{
    return depth[u]+depth[v]-2*depth[lca(u,v)];
}
bool isanc(int u,int v)
{
    return st[u]<=st[v]&&ed[u]>=ed[v];
}
int main()
{
    scanf("%d",&n);
    n++;
    for(int i=2;i<=n;i++)
    {
        int fa; scanf("%d",&fa);
        add_edge(fa,n-1+i);
        add_edge(n-1+i,i);
    }
    init(2*n-1);
    seg.build(1,1,2*n-1);
    seg.update2(1,1,2*n-1,st[1],0);
    int now=1,dist=0;
    for(int i=2;i<=n;i++)
    {
        seg.update2(1,1,2*n-1,st[i],dis(now,i));
        seg.update2(1,1,2*n-1,st[n-1+i],dis(now,n-1+i));
        if(seg.maxi[1].F>dist)
        {
            dist++;
            if(!isanc(now,i))
            {
                seg.update(1,1,2*n-1,1,2*n-1,-1);
                seg.update(1,1,2*n-1,st[now],ed[now],2);
                now=pa[0][now];
            }
            else
            {
                int nxt=get(i,depth[i]-depth[now]-1);
                seg.update(1,1,2*n-1,1,2*n-1,1);
                seg.update(1,1,2*n-1,st[nxt],ed[nxt],-2);
                now=nxt;
            }
        }
        //assert(dist==seg.maxi[1].F);
        printf("%d\n",seg.maxi[1].S);
    }
    return 0;
}