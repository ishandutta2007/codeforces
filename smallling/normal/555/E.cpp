#include<map>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<algorithm>

#define N 200020

using namespace std;

struct lhy{
    int color,lazy;
}tree[N*4];

map<pair<int,int>,int>Cnt,flag;

vector<int>a[N],g[N];
int f[N],dfn[N],low[N],color[N];
int fa[N],top[N],size[N],deep[N],start[N],mson[N];
int cnt,tot,nowcolor,s,t,n,m,q,x,y,lca;

int getf(int v)
{
    if(f[v]==v)return v;
    return f[v]=getf(f[v]);
}

void dfs(int x,int fa)
{
    dfn[x]=low[x]=++cnt;
    for(int i=0;i<(int)a[x].size();i++)
        if(a[x][i]!=fa)
        {
            int y=a[x][i];
            if(dfn[y])
            {
                low[x]=min(low[x],dfn[y]);
                continue;
            }
            dfs(y,x);
            low[x]=min(low[x],low[y]);
            if(low[y]<=dfn[x])f[getf(y)]=getf(x);
        }
}

void Dfs(int x)
{
    color[x]=nowcolor;
    for(int i=0;i<(int)g[x].size();i++)
        if(g[x][i]!=fa[x])
        {
            int y=g[x][i];
            deep[y]=deep[x]+1;
            fa[y]=x;
            Dfs(y);
            if(size[y]>size[mson[x]])mson[x]=y;
            size[x]+=size[y];
        }
    size[x]++;
}

void DFS(int x,int y)
{
    start[x]=++tot;
    top[x]=y;
    if(mson[x])DFS(mson[x],y);
    for(int i=0;i<(int)g[x].size();i++)
    {
        int Y=g[x][i];
        if(Y==fa[x]||Y==mson[x])continue;
        DFS(Y,Y);
    }
}

int Lca(int u,int v)
{
    while(top[u]^top[v])
    {
        if(deep[top[u]]<deep[top[v]])swap(u,v);
        u=fa[top[u]];
    }
    if(deep[u]<deep[v])swap(u,v);
    return v;
}

inline void down(int k)
{
    if(!tree[k].lazy)return;
    if(tree[k<<1].color&&tree[k<<1].color!=tree[k].lazy)
    {
        puts("No");
        exit(0);
    }
    if(tree[k<<1|1].color&&tree[k<<1|1].color!=tree[k].lazy)
    {
        puts("No");
        exit(0);
    }
    tree[k<<1].color=tree[k<<1|1].color=tree[k<<1].lazy=tree[k<<1|1].lazy=tree[k].lazy;
    tree[k].lazy=0;
}

inline void up(int k)
{
    tree[k].color=0;
    if(tree[k<<1].color==3||tree[k<<1|1].color==3)
    {
        tree[k].color=3;
        return;
    }
    if(tree[k<<1].color&&tree[k<<1|1].color&&tree[k<<1].color!=tree[k<<1|1].color)
    {
        tree[k].color=3;
        return;
    }
    if(tree[k<<1].color)tree[k].color=tree[k<<1].color;
    if(tree[k<<1|1].color)tree[k].color=tree[k<<1|1].color;
}

void add(int k,int l,int r,int ll,int rr,int nowcolor)
{
    if(ll<=l&&r<=rr)
    {
        if(tree[k].color&&tree[k].color!=nowcolor)
        {
            puts("No");
            exit(0);
        }
        tree[k].color=nowcolor;
        tree[k].lazy=nowcolor;
        return;
    }
    down(k);
    int mid=(l+r)>>1;
    if(mid>=ll)add(k<<1,l,mid,ll,rr,nowcolor);
    if(mid<rr)add(k<<1|1,mid+1,r,ll,rr,nowcolor);
    up(k);
}

void Add(int k,int l,int r,int ll,int o)
{
    if(l==r)
    {
        tree[k].color=tree[k].lazy=o;
        return;
    }
    down(k);
    int mid=(l+r)>>1;
    if(mid>=ll)Add(k<<1,l,mid,ll,o);
    else Add(k<<1|1,mid+1,r,ll,o);
    up(k);
}

void ask(int k,int l,int r,int ll)
{
    if(l==r)
    {
        nowcolor=tree[k].color;
        tree[k].color=0;
        return;
    }
    down(k);
    int mid=(l+r)>>1;
    if(mid>=ll)ask(k<<1,l,mid,ll);
    else ask(k<<1|1,mid+1,r,ll);
    up(k);
}

void check(int k,int l,int r)
{
    if(l==r)return;
    down(k);
    int mid=(l+r)>>1;
    check(k<<1,l,mid);
    check(k<<1|1,mid+1,r);
}

int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        if(x>y)swap(x,y);
        Cnt[make_pair(x,y)]++;
        if(Cnt[make_pair(x,y)]>=2)
        {
            f[getf(y)]=getf(x);
            continue;
        }
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])dfs(i,0);
    for(int i=1;i<=n;i++)getf(i);
    for(int x=1;x<=n;x++)
        for(int i=0;i<(int)a[x].size();i++)
        {
            y=a[x][i];
            if(f[x]!=f[y])
            {
                if(flag[make_pair(f[x],f[y])])continue;
                flag[make_pair(f[x],f[y])]=flag[make_pair(f[y],f[x])]=1;
                g[f[x]].push_back(f[y]),g[f[y]].push_back(f[x]);
            }
        }
    for(int x=1;x<=n;x++)
        if(!color[f[x]])nowcolor++,Dfs(f[x]),DFS(f[x],f[x]);
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",&s,&t);
        s=f[s],t=f[t];
        if(s==t)continue;
        if(color[s]!=color[t])return puts("No"),0;
        lca=Lca(s,t);
        ask(1,1,n,start[lca]);
        while(1)
        {
            if(deep[top[s]]>deep[top[lca]])add(1,1,n,start[top[s]],start[s],1);
            else
            {
                add(1,1,n,start[lca],start[s],1);
                break;
            }
            s=fa[top[s]];
        }
        Add(1,1,n,start[lca],0);
        while(1)
        {
            if(deep[top[t]]>deep[top[lca]])add(1,1,n,start[top[t]],start[t],2);
            else
            {
                add(1,1,n,start[lca],start[t],2);
                break;
            }
            t=fa[top[t]];
        }
        Add(1,1,n,start[lca],nowcolor);
    }
    check(1,1,n);
    puts("Yes");
}