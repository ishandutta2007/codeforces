#include<stdio.h>
#include<algorithm>
#include<map>
#include<cstring>
#define MAXN 110000
using namespace std;
long n,maxb,t;
long a[MAXN];
map<long,long>ls;
long tmp[MAXN];
long f[MAXN];
long cnt[MAXN];
long ask(long x)
{
     long reu=0;
     for(;x;x-=x&-x)
     {
                    
                    if(cnt[x]>reu)reu=cnt[x];
                    }
     return reu;
}
void insert(long x,long v)
{
     for(;x<=maxb;x+=x&-x)
     {
                          
                          if(v>cnt[x])cnt[x]=v;
                          }
}
void work()
{
     for(long i=1;i<=t;i++)
     {
              for(long j=1;j<=n;j++)
              {
                       long pp=ask(a[j]-1)+1;
                       if(pp>f[j])
                       {          f[j]=pp;
                       insert(a[j],f[j]);}
                       }
              }
     long ans=0;
     for(long i=1;i<=n;i++)if(f[i]>ans)ans=f[i];
     printf("%ld\n",ans);
}
void read(long &x)
{
     char p=getchar();x=0;
     while(!(p<='9'&&p>='0'))p=getchar();
     while(p<='9'&&p>='0')x*=10,x+=p-48,p=getchar();
}
int main()
{
    long k;scanf("%ld",&k);
    scanf("%ld%ld%ld",&n,&maxb,&t);
    while(k--)
    {
              memset(cnt,0,sizeof cnt);
              memset(f,0,sizeof f);
              for(long i=1;i<=n;i++)read(a[i]);
              if(t>=maxb)
              {
                         sort(a+1,a+n+1);
                         printf("%d\n",unique(a+1,a+n+1)-(a+1));
                         continue;
                         }
              work();
              }
 
    return 0;
}