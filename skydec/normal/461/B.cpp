#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#define jsb 1000000007
#define MAXN 210000
using namespace std;
int color[MAXN];
int head[MAXN],next[MAXN],p[MAXN],fa[MAXN];
int f[MAXN][2];int tot=0;
int n;
int Pow(int a,int b)
{
    int c=1;
    for(;b;b>>=1,a=a*1ll*a%jsb)
    if(b&1)c=c*1ll*a%jsb;
    return c;
}
void line(int a,int b)
{
     tot++;p[tot]=b;next[tot]=head[a];head[a]=tot;
}
void dfs(int x)
{
     for(int u=head[x];u;u=next[u])
     if(p[u]!=fa[x])
     {
                    fa[p[u]]=x;
                    dfs(p[u]);
                    }
     if(color[x]==1)
     {
                    f[x][1]=1;
                    for(int u=head[x];u;u=next[u])
                    if(p[u]!=fa[x])
                    f[x][1]=f[x][1]*1ll*((f[p[u]][0]+f[p[u]][1])%jsb)%jsb;
                    }
     else
     {
         f[x][0]=1;
         for(int u=head[x];u;u=next[u])
         if(p[u]!=fa[x])
         f[x][0]=f[x][0]*1ll*((f[p[u]][0]+f[p[u]][1])%jsb)%jsb;
         f[x][1]=0;
         for(int u=head[x];u;u=next[u])
         if(p[u]!=fa[x])
         {
                        f[x][1]=(f[x][1]+f[x][0])%jsb;
                        int del=f[x][0]*1ll*Pow((f[p[u]][1]+f[p[u]][0])%jsb,jsb-2)%jsb;
                        del=del*1ll*f[p[u]][0]%jsb;
                        f[x][1]=(f[x][1]-del)%jsb;
                        }
         }
}
int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
            int ps;scanf("%d",&ps);ps++;
            line(i,ps);
            line(ps,i);
            }
    for(int i=1;i<=n;i++)scanf("%d",&color[i]);
    dfs(1);
    if(f[1][1]<0)f[1][1]+=jsb;
    printf("%d\n",f[1][1]);
    return 0;
}