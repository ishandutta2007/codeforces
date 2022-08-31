#include<stdio.h>
using namespace std;
typedef long long LL;
LL n,m,k;
#define max(a,b)(((a)<(b))?(b):(a))
#define min(a,b)(((a)<(b))?(a):(b))
int main()
{
    scanf("%I64d%I64d%I64d",&n,&m,&k);
    LL l,r,ans;ans=0;
    l=1;r=n*m;
    while(l<r)
    {
              LL mid=(l+r)>>1;
              LL reu=0;
              for(int i=1;i<=min(n,m);i++)
              reu+=min(mid/(1ll*i),max(n,m));
              if(reu>=k)
              {
                        ans=mid;
                        r=mid;
                        }
              else l=mid+1;
              }
    LL reu=0;
              for(int i=1;i<=min(n,m);i++)
              reu+=min(l/(1ll*i),max(n,m));
    if(reu>=k)
              {
                        ans=l;
                        }
    printf("%I64d\n",ans);
    return 0;
}