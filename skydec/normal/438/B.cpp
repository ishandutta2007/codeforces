#include<stdio.h>
#include<algorithm>
#define MAXN 110000
using namespace std;
struct bmaps
{
       long u,v,w;
}bmap[MAXN];long pw[MAXN];
bool cmp(bmaps a,bmaps b){return a.w>b.w;}
long fa[MAXN];long size[MAXN];
long get(long x)
{
     return (x==fa[x])?(x):(fa[x]=get(fa[x]));
     }
void Union(long a,long b){long q=get(b);fa[get(b)]=get(a);size[get(a)]+=size[q];}
long long reu=0;
long n,m;
int main()
{
    scanf("%ld%ld",&n,&m);
    for(long i=1;i<=n;i++)scanf("%ld",&pw[i]);
    for(long i=1;i<=m;i++)
    {
             scanf("%ld%ld",&bmap[i].u,&bmap[i].v);
             bmap[i].w=min(pw[bmap[i].u],pw[bmap[i].v]);
             }
    sort(bmap+1,bmap+1+m,cmp);
    for(long i=1;i<=n;i++)fa[i]=i,size[i]=1;
    for(long i=1;i<=m;i++)
    if(get(bmap[i].u)!=get(bmap[i].v))
    {
                                      reu+=((long long)size[get(bmap[i].u)] )*((long long)size[get(bmap[i].v)] )*((long long)bmap[i].w );
                                      Union(bmap[i].u,bmap[i].v);
                                      }
    printf("%.7lf\n",(double)(reu*2ll)/((double)n*(double)(n-1)));
    return 0;
}