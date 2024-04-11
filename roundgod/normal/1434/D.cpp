#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int eu[MAXN],ev[MAXN],ew[MAXN];
int n,q,tot,st[MAXN],ed[MAXN];
int val[2][MAXN],dist[2][MAXN];
int dep[MAXN];
vector<P> G[MAXN];
void add_edge(int u,int v,int w)
{
    G[u].push_back(P(v,w));
    G[v].push_back(P(u,w));
}
void dfs(int v,int p,int d,bool flag=false)
{
    if(flag) st[v]=++tot;
    dep[v]=d;
    for(auto e:G[v])
    {
        int to=e.F;
        if(to==p) continue;
        dfs(to,v,d+1,flag);
    }
    if(flag) ed[v]=tot;
}
void dfs2(int v,int p,int d,int sgn,int id)
{
    val[id][st[v]]=sgn; dist[id][st[v]]=d;
    for(auto e:G[v])
    {
        int to=e.F,x=e.S;
        if(to==p) continue;
        dfs2(to,v,d+1,sgn^x,id);
    }
}
struct segtree
{
    int lazy[4*MAXN];
    int maxi[2][4*MAXN];
    void pushup(int k)
    {
        for(int i=0;i<2;i++) maxi[i][k]=max(maxi[i][k*2],maxi[i][k*2+1]);
    }
    void flip(int k)
    {
        swap(maxi[0][k],maxi[1][k]);
        lazy[k]^=1;
    }
    void pushdown(int k)
    {
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++) flip(i);
        lazy[k]=0;
    }
    void build(int k,int l,int r,int id)
    {
        lazy[k]=0;
        if(l==r)
        {
            if(val[id][l]==0) 
            {
                maxi[0][k]=dist[id][l];
                maxi[1][k]=-INF;
            }
            else
            {
                maxi[0][k]=-INF;
                maxi[1][k]=dist[id][l];
            }
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid,id); build(k*2+1,mid+1,r,id);
        pushup(k);
    }
    void update(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y) 
        {
            flip(k);
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y); update(k*2+1,mid+1,r,x,y);
        pushup(k);
    }
    int query()
    {
        return maxi[0][1];
    }
}seg[2];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&eu[i],&ev[i],&ew[i]);
        add_edge(eu[i],ev[i],ew[i]);
    }
    dfs(1,0,0,true);
    int maxd=-INF,u=-1,v=-1;
    for(int i=1;i<=n;i++)
    {
        if(dep[i]>maxd)
        {
            maxd=dep[i];
            u=i;
        }
    }
    dfs(u,0,0);
    maxd=-INF;
    for(int i=1;i<=n;i++)
    {
        if(dep[i]>maxd)
        {
            maxd=dep[i];
            v=i;
        }
    }
    dfs(1,0,0);
    dfs2(u,0,0,0,0);
    dfs2(v,0,0,0,1);
    seg[0].build(1,1,n,0);
    seg[1].build(1,1,n,1);
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int id;
        scanf("%d",&id);
        id--;
        int uu=eu[id],vv=ev[id];
        if(dep[uu]>dep[vv]) swap(uu,vv);
        int l=st[vv],r=ed[vv];
        if(st[u]>=l&&st[u]<=r)
        {
            seg[0].update(1,1,n,1,l-1);
            seg[0].update(1,1,n,r+1,n);
        }
        else
        {
            seg[0].update(1,1,n,l,r);
        }
        if(st[v]>=l&&st[v]<=r)
        {
            seg[1].update(1,1,n,1,l-1);
            seg[1].update(1,1,n,r+1,n);
        }
        else
        {
            seg[1].update(1,1,n,l,r);
        }
        printf("%d\n",max(seg[0].query(),seg[1].query()));
    }
    return 0;
}