#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int A[1000000];
#define R x*2
#define L R+1
#define mid (l+r)/2
int num[1000000],beg[1000000],en[1000000],lev[1000000];
vector<int> adj[1000000];
bool vis[1000000];
int tim=0;
void dfs(int v)
{
    vis[v]=1;
    tim++;
    beg[v]=tim;
    num[v]=tim;
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if (vis[u])continue;
        lev[u]=lev[v]+1;
        dfs(u);
    }
    en[v]=tim;
}
long long tree[1000000][2];
long long lazy[1000000][2];
void build(int x,int l,int r)
{
    if (l==r)
    {
        tree[x][0]=tree[x][1]=A[l];
       // cout<<"A: "<<x<<" "<<l<<endl;
    }
    else
    {
        build(R,l,mid);
        build(L,mid+1,r);
        tree[x][0]=tree[R][0]+tree[L][0];
        tree[x][1]=tree[R][1]+tree[L][1];
    }
}
void lzy(int x,int l,int r,bool p)
{
    tree[x][p]+=(r-l+1)*lazy[x][p];
    lazy[R][p]+=lazy[x][p];
    lazy[L][p]+=lazy[x][p];
    lazy[x][p]=0;
}
void upd(int x,int l,int r,int s,int e,int val,bool p)
{
    lzy(x,l,r,p);
    if (s>r || e<l)
        return;
    if (l>=s && r<=e)
    {
        lazy[x][p]=val;
        lzy(x,l,r,p);
        return;
    }
    upd(R,l,mid,s,e,val,p);
    upd(L,mid+1,r,s,e,val,p);
    tree[x][p]=tree[L][p]+tree[R][p];
}
long long query(int x,int l,int r,int s,int e,bool p)
{
    lzy(x,l,r,p);
    if (e<l || s>r)
        return 0;
    if (l>=s && r<=e)
        return tree[x][p];
    return query(R,l,mid,s,e,p)+query(L,mid+1,r,s,e,p);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for (int i=0;i<n-1;i++)
    {
        int s,e;
        scanf("%d%d",&s,&e);
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    dfs(1);
    for (int i=1;i<=n;i++)
        A[num[i]]=a[i];
    build(1,1,n);
    while(m--)
    {
        int typ;
        scanf("%d",&typ);
        if (typ==1)
        {
            int v,val;
            scanf("%d%d",&v,&val);
            upd(1,1,n,beg[v],en[v],val,lev[v]%2);
            upd(1,1,n,beg[v],en[v],-val,1-(lev[v]%2));
        }
        else
        {
            int v;
            scanf("%d",&v);
            printf("%I64d\n",query(1,1,n,num[v],num[v],lev[v]%2));
        }
    }
}