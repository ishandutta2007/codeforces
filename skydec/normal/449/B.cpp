#include<stdio.h>
#include<cstring>
#define MAXN 210000
using namespace std;
int head[MAXN],next[MAXN*7],dis[MAXN],w[MAXN*7],p[MAXN*7];int tot=0;
int number[MAXN*7];int cho[MAXN]={0};
int use[MAXN];
int n,m,k;
int q[MAXN*50];bool inq[MAXN]={0};
int bs[MAXN];
void spfa()
{
     memset(dis,63,sizeof dis);dis[1]=0;inq[1]=1;q[q[0]=1]=1;
     for(int i=1;i<=q[0];i++)
     {
             int x=q[i];
             for(int u=head[x];u;u=next[u])
             if((dis[p[u]]>dis[x]+w[u]))
             {
                                      dis[p[u]]=dis[x]+w[u];
                                      use[p[u]]=number[u];
                                      if(!inq[p[u]])
                                      {
                                                    inq[p[u]]=1;
                                                    q[++q[0]]=p[u];
                                                    if(dis[p[u]]<dis[q[i+1]])
                                                    {
                                                                          int tmp=q[i+1];
                                                                          q[i+1]=q[q[0]];
                                                                          q[q[0]]=tmp;
                                                                          }
                                                                          
                                                    }
                                                    }
             else if(dis[p[u]]==dis[x]+w[u])
             {
                  if(!number[u])
                  use[p[u]]=0;
                  }
             inq[x]=0;
             }
}
void line(int a,int b,int v)
{
     tot++;p[tot]=b;next[tot]=head[a];head[a]=tot;w[tot]=v;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
            int a,b,v;
            scanf("%d%d%d",&a,&b,&v);
            line(a,b,v);
            line(b,a,v);
            }
    for(int i=1;i<=k;i++)
    {
            int b,v;
            scanf("%d%d",&b,&v);
            line(1,b,v);
            number[tot]=i;
            line(b,1,v);
            number[tot]=i;
            bs[b]=v;
            }
    spfa();
    for(int i=1;i<=n;i++)cho[use[i]]++;
    int ans=0;
    for(int i=1;i<=k;i++)if(!cho[i])ans++;
    printf("%d\n",ans);
    return 0;
}