#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int tot,q,n,k,a[MAXN];
int pa[MAXN],dep[MAXN],sz[MAXN],wson[MAXN],top[MAXN],spos[MAXN],tpos[MAXN];
struct segtree
{
    ll sum[4*MAXN];
    int id[MAXN];
    void pushup(int k)
    {
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    void update(int k,int l,int r,int p,int v)
    {
        if(l==r)
        {
            sum[k]=v;
            return;
        }
        int mid=(l+r)/2;
        if(p<=mid) update(k*2,l,mid,p,v); else update(k*2+1,mid+1,r,p,v);
        pushup(k);
    }
    ll query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return sum[k];
        int mid=(l+r)/2;
        return query(k*2,l,mid,x,y)+query(k*2+1,mid+1,r,x,y);
    }
}seg;
vector<int> G[MAXN];
void dfs1(int v,int p,int d)
{
    dep[v]=d;pa[v]=p;sz[v]=1;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p) continue;
        dfs1(to,v,d+1);
        if(sz[to]>sz[wson[v]]) wson[v]=to;
        sz[v]+=sz[to];
    }
}
void dfs2(int v,int p,int num)
{
    top[v]=num;
    spos[v]=++tot;
    tpos[tot]=v;
    if(wson[v]) dfs2(wson[v],v,num);
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p||to==wson[v]) continue;
        dfs2(to,v,to);
    }
}
void init()
{
    tot=0;
    memset(wson,0,sizeof(wson));//important when multiple test cases!!!
    dfs1(1,1,1);
    dfs2(1,0,1);
}
ll query_sum(int u,int v)
{
    ll sum=0;
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        sum+=seg.query(1,1,n,spos[top[u]],spos[u]);
        u=pa[top[u]];
    }
    if(dep[u]<dep[v]) swap(u,v);
    sum+=seg.query(1,1,n,spos[v],spos[u]);
    return sum;
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    init();
    for(int i=1;i<=n;i++) 
    {
        a[i]=max(a[i],-a[i]);
        seg.update(1,1,n,spos[i],a[i]);
    }
    for(int i=0;i<q;i++)
    {
        int type,u,v;
        scanf("%d%d%d",&type,&u,&v);
        if(type==1)
        {
            a[u]=max(-v,v);
            seg.update(1,1,n,spos[u],a[u]); 
        }
        else
        {
            ll ans=2*query_sum(u,v);
            ans-=a[u]; ans-=a[v];
            printf("%lld\n",ans);
        }
    }
    return 0;
}