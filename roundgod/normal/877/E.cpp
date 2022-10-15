#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
int n,m,st[MAXN],ed[MAXN],a[MAXN],tot;
vector<int> G[MAXN];
void dfs(int v,int p)
{
    st[v]=++tot;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
    }
    ed[v]=tot;
    return;
}
struct segtree
{
    int len[4*MAXN],sum[4*MAXN],lazy[4*MAXN];
    void pushup(int k)
    {
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    void flip(int k)
    {
        lazy[k]^=1;
        sum[k]=len[k]-sum[k];
    }
    void pushdown(int k)
    {
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++) flip(i);
        lazy[k]=0;
    }
    void build(int k,int l,int r)
    {
        len[k]=r-l+1;
        if(l==r)
        {
            sum[k]=a[l];
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
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
    int query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return sum[k];
        pushdown(k);
        int mid=(l+r)/2;
        return query(k*2,l,mid,x,y)+query(k*2+1,mid+1,r,x,y);
    }
}seg;
int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        int u,v;
        scanf("%d",&u);
        G[u].push_back(i);
        G[i].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++) scanf("%d",&a[st[i]]);
    seg.build(1,1,n);
    scanf("%d",&m);
    char str[5];
    for(int i=0;i<m;i++)
    {
        int v;
        scanf("%s%d",str,&v);
        if(str[0]=='p') seg.update(1,1,n,st[v],ed[v]); else printf("%d\n",seg.query(1,1,n,st[v],ed[v]));
    }
    return 0;
}