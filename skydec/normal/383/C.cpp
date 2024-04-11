#include<stdio.h>
#define MAXN 410000
using namespace std;
int n;int head[MAXN],next[MAXN],p[MAXN];
int st[MAXN],ed[MAXN];int dep[MAXN];int tot=0;
int odd[2][MAXN];int dt=0;int fa[MAXN];
int m;
int yl[MAXN];
int ask(int mod,int l)
{
    int ans=0;
    for(int x=dt;x;x-=x&-x)ans+=odd[mod][x];
    for(int x=l-1;x;x-=x&-x)ans-=odd[mod][x];
    return ans;
}
void add(int mod,int l,int r,int v)
{
     if(l>1)
     for(int x=l-1;x<=dt;x+=x&-x)odd[mod][x]-=v;
     for(int x=r;x<=dt;x+=x&-x)odd[mod][x]+=v;
}
void dfs(int x,int de)
{
     dep[x]=de;
     st[x]=++dt;
     for(int u=head[x];u;u=next[u])
     if(fa[x]!=p[u])fa[p[u]]=x,dfs(p[u],de+1);
     ed[x]=++dt;
}
void line(int a,int b)
{
     tot++;p[tot]=b;next[tot]=head[a];head[a]=tot;
}
void init()
{
     scanf("%d%d",&n,&m);
     for(int i=1;i<=n;i++)scanf("%d",&yl[i]);
     for(int i=1;i<=n-1;i++)
     {
             int a,b;scanf("%d%d",&a,&b);
             line(a,b);line(b,a);
             }
     dfs(1,0);
}
int main()
{
    init();
    for(int i=1;i<=m;i++)
    {
            int opt;scanf("%d",&opt);
            if(opt==1)
            {
                      int x,v;scanf("%d%d",&x,&v);
                      add(dep[x]&1,st[x],ed[x],v);
                      add(!(dep[x]&1),st[x],ed[x],-v);
                      }
            else
            {
                int x;scanf("%d",&x);
                printf("%d\n",yl[x]+ask(dep[x]&1,st[x]));
                }
                }
    return 0;
}