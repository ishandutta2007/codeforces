#include<stdio.h>
#define MAXN 110000
using namespace std;
long head[MAXN],p[MAXN*2],next[MAXN*2];
long d[MAXN];long n,m,h,t;
long ansx,ansy;long tot=0;
void line(long a,long b){tot++;p[tot]=b;next[tot]=head[a];head[a]=tot;}
long cnt[MAXN];
long cnt2[MAXN];
long tt=0;
long t1[MAXN],t2[MAXN],t3[MAXN];
void read(long &x)
{
     char ps=getchar();x=0;
     while(!(ps<='9'&&ps>='0'))ps=getchar();
     while(ps<='9'&&ps>='0')x=x*10,x+=ps-48,ps=getchar();
}
int main()
{
    scanf("%ld%ld%ld%ld",&n,&m,&h,&t);
    for(long i=1;i<=m;i++)
    {
             long a,b;read(a);read(b);
             line(a,b);line(b,a);
             d[a]++;d[b]++;
             }
    for(long i=1;i<=n;i++)
    if(d[i]-1>=h)
    {
             for(long u=head[i];u;u=next[u])cnt[p[u]]=i;
             for(long u=head[i];u;u=next[u])
             if(d[p[u]]-1>=t)
             {
                      long ans=d[i]-1+d[p[u]]-1;tt++;
                      for(long v=head[p[u]];v;v=next[v])
                      {
                               if(cnt[p[v]]==i)
                               {
                                               ans--;
                                               cnt2[p[v]]=tt;
                                               }
                                               }
                      if(ans>=h+t)
                      if(d[i]-1>=h&&d[p[u]]-1>=t)
                      {
                                   printf("YES\n");
                                   printf("%ld %ld\n",i,p[u]);
                                   for(long v=head[p[u]];v;v=next[v])
                                   if(p[v]!=i)
                                   {
                                              if(cnt[p[v]]==i)
                                              {
                                                              t2[++t2[0]]=p[v];
                                                              cnt2[p[v]]=tt;
                                                              }
                                              else t3[++t3[0]]=p[v];
                                              }
                                   for(long v=head[i];v;v=next[v])
                                   if(p[v]!=p[u])
                                   {
                                              if(cnt2[p[v]]!=tt)
                                              {
                                                              t1[++t1[0]]=p[v];
                                                              
                                                              }
                                              }
                                   long j=h;
                                   while(j&&t1[0])
                                   {
                                                  j--;
                                                  printf("%ld ",t1[t1[0]--]);
                                                  }
                                   while(j&&t2[0])
                                   {
                                                  j--;
                                                  printf("%ld ",t2[t2[0]--]);
                                                  }
                                   printf("\n");
                                   j=t;
                                   while(j&&t3[0])
                                   {
                                                  j--;
                                                  printf("%ld ",t3[t3[0]--]);
                                                  }
                                   while(j&&t2[0])
                                   {
                                                  j--;
                                                  printf("%ld ",t2[t2[0]--]);
                                                  }
                                   return 0;
                                   
                                    }
                                    }
                                    }
    printf("NO\n");
    return 0;
}