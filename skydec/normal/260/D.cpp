#include<stdio.h>
#define MAXN 110000
using namespace std;
long c[MAXN],sum[MAXN];long fa[MAXN];
long n;
long white[MAXN];
long black[MAXN];
long size[MAXN];
#define min(a,b) ((a)<(b)?(a):(b))
long get(long x)
{
     if(x==fa[x])return x;
     return fa[x]=get(fa[x]);
}
void Union(long a,long b)
{
     fa[get(a)]=get(b);
}
int main()
{
    scanf("%ld",&n);
    for(long i=1;i<=n;i++)
    {
             fa[i]=i;
             scanf("%ld%ld",&c[i],&sum[i]);
             if(c[i])black[++black[0]]=i;
             else white[++white[0]]=i;
             }
    long p=1;long q=1;
    while(true)
    {
               if(p>black[0]||q>white[0])break;
               printf("%ld %ld %ld\n",black[p],white[q],min(sum[black[p]],sum[white[q]]));
               long uu=min(sum[black[p]],sum[white[q]]);
               sum[black[p]]-=uu;
               sum[white[q]]-=uu;
               Union(black[p],white[q]);
               if(!sum[black[p]])p++;else q++;
               }
    for(long i=1;i<=n;i++)size[get(i)]++;
    long uu=0;
    for(long i=1;i<=n;i++)if(size[i]>1)uu=i;
    long w,b;
    for(long i=1;i<=n;i++)
    if(get(i)==uu)
    {
                  if(c[i]==1)b=i;
                  else w=i;
                  }
    for(long i=1;i<=n;i++)
    if(get(i)!=uu)
    {
                  if(c[i]==0)
                  {
                             Union(i,b);
                             printf("%ld %ld 0\n",i,b,0);
                             }
                  else
                  {
                             printf("%ld %ld 0\n",i,w,0);
                             Union(i,w);
                             }
                             }
    return 0;
}