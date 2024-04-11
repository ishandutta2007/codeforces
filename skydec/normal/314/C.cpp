#include<stdio.h>
#include<cstring>
#define jsb 1000000007
#define MAXN 1000005
using namespace std;
typedef long long LL;
LL cnt[MAXN];
LL a[MAXN];
LL f[MAXN];
long n;
void insert(long x,LL v)
{
     v%=jsb;if(v<0)v+=jsb;
     for(;x<=1000000;x+=x&-x)cnt[x]=(cnt[x]+v)%jsb;
}
LL sum(long x)
{
            LL reu=0;
            for(;x;x-=x&-x)reu=(reu+cnt[x])%jsb;
            return reu;
}
int main()
{
    memset(f,-1,sizeof f);
    scanf("%ld",&n);
    for(long i=1;i<=n;i++)
    {
             scanf("%I64d",&a[i]);
             if(f[a[i]]==-1)
             {
                            f[a[i]]=(sum(a[i])*a[i]%jsb+a[i])%jsb;
                            insert(a[i],f[a[i]]);
                            }
             else
             {
                 LL tmp=(sum(a[i])*a[i]%jsb+a[i])%jsb;
                 insert(a[i],tmp-f[a[i]]);
                 f[a[i]]=tmp;
                 }
                 }
    LL ans=sum(1000000)%jsb;
    if(ans<0)ans+=jsb;
    printf("%I64d\n",ans);
    return 0;
}