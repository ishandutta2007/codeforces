#include<stdio.h>
#include<cstring>
#include<vector>
#define pb push_back
#define MAXN 210000
using namespace std;
int head[MAXN],p[MAXN],next[MAXN];int ans[MAXN];int fa[MAXN];
int n,q;int v[MAXN];int tot=0;
int dep[MAXN];
vector<int> pri[2000002];
vector<int> temp[2000002];
void line(int a,int b)
{
     tot++;p[tot]=b;next[tot]=head[a];head[a]=tot;
}
void dfs(int x)
{
     for(int i=0;i<pri[v[x]].size();i++)
     {
             int ss=pri[v[x]][i];
             if(temp[ss].size())
             if(!ans[x]||dep[ans[x]]<dep[temp[ss][temp[ss].size()-1]])ans[x]=temp[ss][temp[ss].size()-1];
             temp[ss].pb(x);
             }
     for(int u=head[x];u;u=next[u])
     if(p[u]!=fa[x])
     {
             dfs(p[u]);
             }
     for(int i=0;i<pri[v[x]].size();i++)
     {
             int ss=pri[v[x]][i];
             temp[ss].pop_back();
             }
}    
void work()
{
     memset(ans,0,sizeof ans);
     dfs(1);
}
bool pf[2000001];
void init()
{
     int MAX=2000000;
     for(int i=2;i<=MAX;i++)
     if(!pf[i])
     {
               for(int j=i;j<=MAX;j+=i)
               pri[j].pb(i),pf[j]=1;
               }
}
void d1(int x)
{
     for(int u=head[x];u;u=next[u])
     if(p[u]!=fa[x])
     {
                    fa[p[u]]=x;
                    dep[p[u]]=dep[x]+1;
                    d1(p[u]);
                    }
}
int main()
{
    init();
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%d",&v[i]);
    for(int i=1;i<n;i++)
    {
            int a,b;scanf("%d%d",&a,&b);
            line(a,b);
            line(b,a);
    }
    d1(1);
    work();
    while(q--)
    {
              int opt;scanf("%d",&opt);
              if(opt==1)
              {
                        int x;scanf("%d",&x);
                        if(ans[x])
                        printf("%d\n",ans[x]);
                        else printf("-1\n");
                        }
              else
              {
                  int x,w;scanf("%d%d",&x,&w);
                  v[x]=w;
                  work();
                  }
                  }
    return 0;
}