#include<stdio.h>
#include<cstring>
#define MAXN 1020000
using namespace std;
int head[MAXN],next[MAXN],p[MAXN],fa[MAXN];int tot=0;
int st[MAXN],ed[MAXN];
int n,q;int dt=0;
void line(int a,int b){tot++;p[tot]=b;next[tot]=head[a];head[a]=tot;}
int max[MAXN*4];int bg[MAXN];
int max2[MAXN*4];int bg2[MAXN];
void dfs(int x)
{
     st[x]=++dt;
     for(int u=head[x];u;u=next[u])
     if(p[u]!=fa[x])fa[p[u]]=x,dfs(p[u]);
     ed[x]=++dt;
}
void build1(int now,int l,int r)
{
     if(l==r)
     {
             bg[l]=now;
             return;
             }
     int mid=(l+r)>>1;
     build1(now*2,l,mid);
     build1(now*2+1,mid+1,r);
}
void build2(int now,int l,int r)
{
     if(l==r)
     {
             bg2[l]=now;
             return;
             }
     int mid=(l+r)>>1;
     build2(now*2,l,mid);
     build2(now*2+1,mid+1,r);
}
void addto(int now,int l,int r,int x,int y,int tt)
{
     if(l>=x&&r<=y)
     {
                   if(tt>max[now])max[now]=tt;
                   return;
                   }
     int mid=(l+r)>>1;
     if(x<=mid)addto(now*2,l,mid,x,y,tt);
     if(y>mid)addto(now*2+1,mid+1,r,x,y,tt);
}
void add1(int l,int r,int tt)
{
     addto(1,1,dt,l,r,tt);
}
int ask1(int x)
{
     int ans=0;
     int u=bg[x];
     while(u)
     {
             //if(x==st[3])printf("%d %d\n",u,max[u]);
             if(max[u]>ans)ans=max[u];
             u/=2;
             }
     return ans;
}
void add2(int x,int tt)
{
     int u=bg2[x];
     while(u)
     {
             if(tt>max2[u])max2[u]=tt;
             u/=2;
             }
}
int asker(int now,int l,int r,int x,int y)
{
    if(l>=x&&r<=y)return max2[now];
    int ans=0;
    int mid=(l+r)>>1;
    if(x<=mid)
    {
              int d=asker(now*2,l,mid,x,y);
              if(d>ans)ans=d;
              }
    if(y>mid)
    {
             int d=asker(now*2+1,mid+1,r,x,y);
             if(d>ans)ans=d;
             }
    return ans;
}
int ask2(int x)
{
   return asker(1,1,dt,st[x],ed[x]);
}  
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++)
    {
            int a,b;scanf("%d%d",&a,&b);
            line(a,b);line(b,a);
            }
    dfs(1);
    build1(1,1,dt);
    build2(1,1,dt);
    int q;scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
              int opt,v;scanf("%d%d",&opt,&v);
              if(opt==1)
              {
                        add1(st[v],ed[v],i);
                        //printf("__%d %d %d\n",st[2],ed[2],st[3]);
                        }
              else if(opt==2) add2(st[v],i);
              else
              {
                  int t1=ask1(st[v]);
                  int t2=ask2(v);
                  if(t2>=t1)printf("0\n");else printf("1\n");
                  //printf("___%d %d\n",t1,t2);
                  }
                  }
    return 0;
}