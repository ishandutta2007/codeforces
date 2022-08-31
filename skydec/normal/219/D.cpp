#include<stdio.h>
#include<cstring>
#define MAXN 410000
using namespace std;
int head[MAXN],next[MAXN],p[MAXN],from[MAXN],fa[MAXN];
int n;int tot=0;int f2[MAXN];
int up[MAXN],down[MAXN],li[MAXN];
int q[MAXN];
void line(int a,int b,int c)
{
     tot++;from[tot]=c;p[tot]=b;next[tot]=head[a];head[a]=tot;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
            int a,b;scanf("%d%d",&a,&b);
            line(a,b,a);
            line(b,a,a);
            }
    q[q[0]=1]=1;
    for(int i=1;i<=q[0];i++)
    {
            int x=q[i];
            for(int u=head[x];u;u=next[u])
            if(p[u]!=fa[x])
            {
                           q[++q[0]]=p[u];
                           fa[p[u]]=x;
                           f2[p[u]]=from[u];
                           }
                           }
    for(int i=q[0];i>=1;i--)
    {
            int x=q[i];
            for(int u=head[x];u;u=next[u])
            if(p[u]!=fa[x])
            {
                           down[x]+=down[p[u]];
                           down[x]+=(from[u]!=x);
                           //if(p[u]==2)printf("_%d\n",from[u]);
                           }
                           }
    for(int i=1;i<=q[0];i++)
    {
            int x=q[i];
            if(!fa[x])continue;
            up[x]=up[fa[x]];
            up[x]+=down[fa[x]];
            up[x]-=down[x];
            up[x]-=(f2[x]!=fa[x]);
            up[x]+=(f2[x]==fa[x]);
            }
    //printf("%d\n",q[0]);
    int min=n+1;
    for(int i=1;i<=n;i++)
    if(up[i]+down[i]<min)min=up[i]+down[i];
    printf("%d\n",min);
    for(int i=1;i<=n;i++)
    {
            if(up[i]+down[i]==min)printf("%d ",i);
            //printf("%d %d\n",up[i],down[i]);
            }
    return 0;
}