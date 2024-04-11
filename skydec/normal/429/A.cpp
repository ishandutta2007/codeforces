#include<stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;
long dfsodd[210000];
long dfsoss[210000];
long tota=0,totb=0;
long st[110000],ed[110000];
long dep[110000];long head[110000],next[210000],p[210000];long tot=0;
long start[110000],end[110000];
long q[110000];long ans[110000];
long n;
long lowbit(long x){return x&-x;}
void line(long a,long b)
{
     tot++;p[tot]=b;next[tot]=head[a];head[a]=tot;
}
void dfs(long x)
{
     if(dep[x]&1)st[x]=++tota;else st[x]=++totb;
     for(long u=head[x];u;u=next[u])
     if(!dep[p[u]])
     {
                   dep[p[u]]=dep[x]+1;
                   dfs(p[u]);
                   }
     if(dep[x]&1)ed[x]=++tota;else ed[x]=++totb;
}
int main()
{
    scanf("%ld",&n);
    for(long i=1;i<=n-1;i++)
    {
             long a,b;scanf("%ld%ld",&a,&b);
             line(a,b);line(b,a);
             }
    dep[1]=1;
    dfs(1);
    for(long i=1;i<=n;i++)scanf("%ld",&start[i]);
    for(long i=1;i<=n;i++)scanf("%ld",&end[i]);
    q[0]=1;q[1]=1;ans[0]=0;
    for(long i=1;i<=q[0];i++)
    {
             long x=q[i];
             if(dep[x]&1)
             {
                         long reu=0;
                         for(long j=tota;j;j-=lowbit(j))reu+=dfsodd[j];
                         for(long j=ed[x]-1;j;j-=lowbit(j))reu-=dfsodd[j];
                         if((reu&1)^(start[x]^end[x]))
                         {
                                                      if(st[x]-1!=0)
                                                      for(long j=st[x]-1;j<=tota;j+=lowbit(j))
                                                      dfsodd[j]--;
                                                      for(long j=ed[x];j<=tota;j+=lowbit(j))
                                                      dfsodd[j]++;
                                                      ans[++ans[0]]=x;
                                                      }
                         }
             else
             {
                         long reu=0;
                         for(long j=totb;j;j-=lowbit(j))reu+=dfsoss[j];
                         for(long j=ed[x]-1;j;j-=lowbit(j))reu-=dfsoss[j];
                         if((reu&1)^(start[x]^end[x]))
                         {
                                                      if(st[x]-1!=0)
                                                      for(long j=st[x]-1;j<=totb;j+=lowbit(j))
                                                      dfsoss[j]--;
                                                      for(long j=ed[x];j<=totb;j+=lowbit(j))
                                                      dfsoss[j]++;
                                                      ans[++ans[0]]=x;
                                                      }
                                                      }
             for(long u=head[x];u;u=next[u])
             if(dep[p[u]]>dep[x])
             {
                                 q[++q[0]]=p[u];
                                 }
                                 }
    printf("%ld\n",ans[0]);
    sort(ans+1,ans+1+ans[0]);
    for(long i=1;i<=ans[0];i++)printf("%ld\n",ans[i]);
    //for(;;);
    return 0;
}