#include<stdio.h>
#include<cstring>
#define MAXN 610000
using namespace std;
int n,m,qs;
int fa[MAXN];
int head[MAXN],next[MAXN*2],p[MAXN*2];int tot=0;
int path[MAXN];
void line(int a,int b){tot++;p[tot]=b;next[tot]=head[a];head[a]=tot;}
int get(int x){if(x==fa[x])return x;return fa[x]=get(fa[x]);}
int q[MAXN];
int flag[MAXN];
int dis[MAXN];
int find(int x)
{
    dis[x]=0;
    flag[x]=x;q[q[0]=1]=x;
    int yuan=x;
    for(int i=1;i<=q[0];i++)
    {
            int y=q[i];
            for(int u=head[y];u;u=next[u])
            if(flag[p[u]]!=x)
            {
                             flag[p[u]]=x;
                             q[++q[0]]=p[u];
                             dis[p[u]]=dis[y]+1;
                             if(dis[p[u]]>dis[yuan])yuan=p[u];
                             }
                             }
    int y2=yuan;dis[yuan]=0;q[q[0]=1]=yuan;flag[yuan]=yuan;
    for(int i=1;i<=q[0];i++)
    {
            int y=q[i];
            for(int u=head[y];u;u=next[u])
            if(flag[p[u]]!=yuan)
            {
                             flag[p[u]]=yuan;
                             q[++q[0]]=p[u];
                             dis[p[u]]=dis[y]+1;
                             if(dis[p[u]]>dis[y2])y2=p[u];
                             }
                             }
    return dis[y2];
}   
int main()
{
    scanf("%d%d%d",&n,&m,&qs);
    for(int i=1;i<=n;i++)fa[i]=i,path[i]=0;
    for(int i=1;i<=m;i++)
    {
            int a,b;scanf("%d%d",&a,&b);
            line(a,b);
            line(b,a);
            fa[get(a)]=get(b);
            }
    for(int i=1;i<=n;i++)if(i==get(i))path[i]=find(i);
    for(int i=1;i<=qs;i++)
    {
            int opt;scanf("%d",&opt);
            if(opt==1)
            {
                      int x;scanf("%d",&x);
                      printf("%d\n",path[get(x)]);
                      }
            else
            {
                int x,y;scanf("%d%d",&x,&y);
                if(get(x)==get(y))continue;
                x=get(x);y=get(y);
                int u1=path[x];
                int u2=path[y];
                fa[x]=y;
                path[y]=((path[y]+1)/2)+((path[x]+1)/2)+1;
                if(path[y]<u1)path[y]=u1;
                if(path[y]<u2)path[y]=u2;
                }
                }
    return 0;
}