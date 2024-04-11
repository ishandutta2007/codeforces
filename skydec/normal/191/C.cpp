#include<stdio.h>
#define MAXN 210000
using namespace std;
int l[MAXN],r[MAXN],lazy[MAXN],val[MAXN],fa[MAXN];bool rev[MAXN];
int n,k;
bool top(int x){return (!fa[x])||(l[fa[x]]!=x&&r[fa[x]]!=x);}
void down(int x)
{
     if(rev[x])
     {
               int tmp=l[x];l[x]=r[x];r[x]=tmp;
               rev[l[x]]^=1;
               rev[r[x]]^=1;
               rev[x]=0;
               }
     lazy[l[x]]+=lazy[x];
     lazy[r[x]]+=lazy[x];
     val[l[x]]+=lazy[x];
     val[r[x]]+=lazy[x];
     lazy[x]=0;
}
void left(int x)
{
     int y=fa[x];int z=fa[y];
     r[y]=l[x];if(l[x])fa[l[x]]=y;
     fa[x]=z;if(l[z]==y)l[z]=x;else if(r[z]==y)r[z]=x;
     fa[y]=x;l[x]=y;
}
void right(int x)
{
     int y=fa[x];int z=fa[y];
     l[y]=r[x];if(r[x])fa[r[x]]=y;
     fa[x]=z;if(l[z]==y)l[z]=x;else if(r[z]==y)r[z]=x;
     fa[y]=x;r[x]=y;
}
int st[MAXN];
void splay(int x)
{
     st[st[0]=1]=x;
     for(int u=x;!top(u);u=fa[u])st[++st[0]]=fa[u];
     for(int i=st[0];i>=1;i--)down(st[i]);
     while(!top(x))
     {
                   int y=fa[x];int z=fa[y];
                   if(top(y))
                   {
                             if(l[y]==x)right(x);else left(x);
                             }
                   else
                   {
                       if(l[z]==y)
                       {
                                  if(l[y]==x)right(y),right(x);
                                  else left(x),right(x);
                                  }
                       else
                       {
                           if(r[y]==x)left(y),left(x);
                           else right(x),left(x);
                           }
                           }
                           }
}
int access(int x)
{
    int y=0;
    for(;x;y=x,x=fa[x])
    {
                       splay(x);
                       r[x]=y;
                       }
    return x;
}
void evert(int x){access(x);splay(x);rev[x]^=1;}
void link(int a,int b)
{
     evert(b);splay(b);fa[b]=a;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++)
    {
            int a,b;scanf("%d%d",&a,&b);
            link(a,i+n);link(i+n,b);
            }
    scanf("%d",&k);
    while(k--)
    {
              int a,b;scanf("%d%d",&a,&b);
              evert(a);access(b);splay(b);
              val[b]++;lazy[b]++;
              }
    for(int i=1;i<=n-1;i++)
    {
            splay(i+n);printf("%d ",val[i+n]);
            }
    return 0;
}