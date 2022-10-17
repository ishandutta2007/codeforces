#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
const int MAXN=1110000;
const int INF=1e15;
int n,m,k;
int ans[MAXN];
int f[MAXN],X[MAXN],Y[MAXN],D[MAXN],book[MAXN];
int tot,front[MAXN],to[MAXN],nxt[MAXN],di[MAXN];
int fa[MAXN],dep[MAXN],siz[MAXN],son[MAXN],top[MAXN],w[MAXN],totw,b[MAXN];
int data[MAXN],maxn[MAXN*4],flag[MAXN*4];
void init(int u,int v,int d)
{
    to[++tot]=v;
    nxt[tot]=front[u];
    di[tot]=d;
    front[u]=tot;
}
int find(int x)
{
    if(f[x]!=x)f[x]=find(f[x]);
    return f[x];
}
void dfs(int u,int father)
{
    fa[u]=father;
    dep[u]=dep[father]+1;
    siz[u]=1;
    for(int i=front[u];i;i=nxt[i])
    {
        int v=to[i];
        if(v==fa[u])continue;
        data[v]=di[i];
        dfs(v,u);
        siz[u]+=siz[v];
        if(siz[v]>siz[son[u]])
            son[u]=v;
    }
}
void dfs(int u)
{
    if(son[u])
    {
        w[son[u]]=++totw;
        top[son[u]]=top[u];
        b[totw]=son[u];
        dfs(son[u]);
    }
    for(int i=front[u];i;i=nxt[i])
    {
        int v=to[i];
        if(v==fa[u]||v==son[u])continue;
        w[v]=++totw;
        top[v]=v;
        b[totw]=v;
        dfs(v);
    }
}
void build(int root,int l,int r)
{
    if(l==r)
    {
        maxn[root]=data[b[l]];
        return;
    }
    int mid=(l+r)>>1;
    build(root*2,l,mid);
    build(root*2+1,mid+1,r);
    maxn[root]=max(maxn[root*2],maxn[root*2+1]);
}
void pushdown(int root)
{
    if(flag[root]<=maxn[root*2])
        maxn[root*2]=flag[root],flag[root*2]=flag[root];
    if(flag[root]<=maxn[root*2+1])
        maxn[root*2+1]=flag[root],flag[root*2+1]=flag[root];
    flag[root]=0;
}
void chg(int root,int l,int r,int xl,int xr,int d)
{
    if(d>maxn[root])return;
    if(l==xl&&r==xr)
    {
        maxn[root]=d;
        flag[root]=d;
        return;
    }
    if(flag[root])pushdown(root);
    int mid=(l+r)>>1;
    if(xr<=mid)chg(root*2,l,mid,xl,xr,d);
    else
        if(xl>mid)chg(root*2+1,mid+1,r,xl,xr,d);
        else    
        {
            chg(root*2,l,mid,xl,mid,d);
            chg(root*2+1,mid+1,r,mid+1,xr,d);
        }
    maxn[root]=max(maxn[root*2],maxn[root*2+1]);
}
void change(int u,int v,int d)
{
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]])swap(u,v);
        chg(1,1,n,w[top[u]],w[u],d);
        u=fa[top[u]];
    }
    if(u==v)return;
    if(dep[u]<dep[v])swap(u,v);
    chg(1,1,n,w[v]+1,w[u],d);
}
int lca(int u,int v)
{
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]])swap(u,v);
        u=fa[top[u]];
    }
    if(dep[u]>dep[v])return v;
    return u;
}
void check(int root,int l,int r)
{
    if(l==r)
    {
        ans[b[l]]=maxn[root];
        return;
    }
    if(flag[root])pushdown(root);
    int mid=(l+r)>>1;
    check(root*2,l,mid);
    check(root*2+1,mid+1,r);
}
signed main()
{
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    scanf("%I64d%I64d%I64d",&n,&k,&m);
    for(int i=1;i<=n;i++)f[i]=i;
    int cnt=0;
    for(int i=1,x,y;i<=k;i++)
    {
        scanf("%I64d%I64d",&x,&y);
        if(find(x)!=find(y))
        {
            f[find(x)]=find(y);
            init(x,y,INF);
            init(y,x,INF);
            cnt++;
        }
    }
    int ans2=0;
    for(int i=1;i<=m;i++)
    {
        scanf("%lld%lld%lld",&X[i],&Y[i],&D[i]);
        if(find(X[i])!=find(Y[i]))
        {
            f[find(X[i])]=find(Y[i]);
            init(X[i],Y[i],0);
            init(Y[i],X[i],0);
            cnt++;
            book[i]=1;
        }
    }
    dfs(1,0);
    w[1]=++totw;
    top[1]=1;
    b[totw]=1;
    dfs(1);
    build(1,1,n);
    for(int i=1;i<=m;i++)
        if(!book[i])
        {
            int tmp=lca(X[i],Y[i]);
            change(X[i],tmp,D[i]);
            change(Y[i],tmp,D[i]);
        }
    check(1,1,n);
    for(int i=1;i<=n;i++)
    {
        if(ans[i]==INF)
        {
            printf("-1");
            return 0;
        }
        ans[i]+=ans[i-1];
    }
    printf("%I64d",ans[n]-ans2);
    return 0;
}