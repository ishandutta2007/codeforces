#include<stdio.h>
#include<cstring>
#define MAXN 110000
using namespace std;
typedef long long LL;
LL sum[MAXN*4];LL pos[MAXN*4];LL max[MAXN*4];
long n,m;
#define MAX(a,b) ((a)>(b)?(a):(b))
void up(long x)
{
     sum[x]=sum[x*2]+sum[x*2+1];
     max[x]=MAX(max[x*2],max[x*2+1]);
}
void build(long now,long l,long r)
{
     if(l==r)
     {
             pos[l]=now;
             return;
             }
     long mid=(l+r)>>1;
     build(now*2,l,mid);
     build(now*2+1,mid+1,r);
}
void change(long now,long l,long r,long x,long y,long v)
{
     if(l==r)
     {
             //printf("%I64d\n",max[now]);
             sum[now]%=v;
             max[now]%=v;
             return;
             }
     if(x<=l&&r<=y&&max[now]<v)return;
     long mid=(l+r)>>1;
     if(y>mid)change(now*2+1,mid+1,r,x,y,v);
     if(mid>=x)change(now*2,l,mid,x,y,v);
     up(now);
}
LL query(long now,long l,long r,long x,long y)
{
              if(x<=l&&r<=y)return sum[now];
              long mid=(l+r)>>1;LL reu=0;
              if(x<=mid)reu+=query(now*2,l,mid,x,y);
              if(y>mid)reu+=query(now*2+1,mid+1,r,x,y);
              return reu;
}
int main()
{
    scanf("%ld%ld",&n,&m);
    build(1,1,n);
    for(long i=1;i<=n;i++)
    {
             scanf("%I64d",&sum[pos[i]]);
             max[pos[i]]=sum[pos[i]];
             long s=pos[i]/2;
             while(s)up(s),s/=2;
             }
    for(long i=1;i<=m;i++)
    {
             long opt;scanf("%ld",&opt);
             if(opt==1)
             {
                       long l,r;scanf("%ld%ld",&l,&r);
                       printf("%I64d\n",query(1,1,n,l,r));
                       }
             else
             if(opt==2)
             {
                       long l,r,x;scanf("%ld%ld%ld",&l,&r,&x);
                       change(1,1,n,l,r,x);
                       }
             else
             {
                       long k,x;scanf("%ld%ld",&k,&x);
                       max[pos[k]]=sum[pos[k]]=x;
                       long s=pos[k]/2;
                       while(s)up(s),s/=2;
                       }
                       }
     return 0;
}