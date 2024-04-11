#include<stdio.h>
#include<cstring>
#define lowbit(x) ((x)&(-x))
using namespace std;
typedef long long LL;
long qcnt[110000];
LL cnt[110000];
long n,m,k;
long a[110000];
long l[110000],r[110000],d[110000];
int main()
{
    scanf("%ld%ld%ld",&n,&m,&k);
    for(long i=1;i<=n;i++)scanf("%ld",&a[i]);
    for(long i=1;i<=m;i++)scanf("%ld%ld%ld",&l[i],&r[i],&d[i]);
    for(long i=1;i<=k;i++)
    {
        long x,y;scanf("%ld%ld",&x,&y);
        for(;y<=m;y+=lowbit(y))qcnt[y]++;
        if(x-1>0)for(x=x-1;x<=m;x+=lowbit(x))qcnt[x]--;
    }
    memset(cnt,0,sizeof cnt);
    for(long i=1;i<=m;i++)
    {
        long tot=0;
        for(long j=m;j;j-=lowbit(j))tot+=qcnt[j];
        for(long j=i-1;j;j-=lowbit(j))tot-=qcnt[j];
        long x,y;x=l[i];y=r[i];
        for(;y<=n;y+=lowbit(y))cnt[y]+=(LL)tot*(LL)d[i];
        if(x-1>0)for(x=x-1;x<=n;x+=lowbit(x))cnt[x]-=(LL)tot*(LL)d[i];
    }
    for(long i=1;i<=n;i++)
    {
        LL ans=0;
        for(long j=n;j;j-=lowbit(j))ans+=cnt[j];
        for(long j=i-1;j;j-=lowbit(j))ans-=cnt[j];
        printf("%I64d ",ans+(LL)a[i]);
    }
    return 0;
}