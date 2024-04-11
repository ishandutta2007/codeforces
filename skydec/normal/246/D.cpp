#include<stdio.h>
#include<algorithm>
#define MAXN 110000
using namespace std;
long color[MAXN];
long n,m;
long head[MAXN*2],next[MAXN*2],p[MAXN*2];long tot=0;
void line(long a,long b)
{
     tot++;p[tot]=b;next[tot]=head[a];head[a]=tot;
}
long ans[MAXN],an[MAXN*4],ap[MAXN*4];long t2=0;
void add(long a,long b)
{
     t2++;ap[t2]=b;an[t2]=ans[a];ans[a]=t2;
}
long tmp[MAXN*4];
bool have[MAXN]={false};
int main()
{
    scanf("%ld%ld",&n,&m);
    for(long i=1;i<=n;i++)
    {
             scanf("%ld",&color[i]);
             have[color[i]]=true;
             }
    for(long i=1;i<=m;i++)
    {
             long a,b;scanf("%ld%ld",&a,&b);
             line(a,b);line(b,a);
             }
    long reu=0;long aa=0;
    for(long i=1;i<=n;i++)
    for(long u=head[i];u;u=next[u])
    add(color[i],color[p[u]]);
    for(long i=1;i<=100000;i++)
    if(have[i])
    {
             tmp[0]=1;tmp[1]=i;
             for(long u=ans[i];u;u=an[u])
             tmp[++tmp[0]]=ap[u];
             sort(tmp+1,tmp+1+tmp[0]);
             long tot=1;
             for(long j=2;j<=tmp[0];j++)
             if(tmp[j]!=tmp[j-1])tot++;
             if(reu<tot){reu=tot;aa=i;}
             }
    printf("%ld\n",aa);
    return 0;
}