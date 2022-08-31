#include<stdio.h>
#define MAXN 510000
using namespace std;
typedef long long LL;
LL sum[MAXN];
int n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
            scanf("%I64d",&sum[i]);
            sum[i]+=sum[i-1];
            }
    if(sum[n]%3!=0)
    {
                   printf("0\n");
                   return 0;
                   }
    LL ans=0;int s1=0;
    for(int i=1;i<=n-1;i++)
    {
            if(sum[i]==2ll*(sum[n]/3))ans+=1ll*s1;
            if(sum[i]==sum[n]/3)s1++;
            }
    printf("%I64d\n",ans);
    return 0;
}