#include<stdio.h>
#include<cstring>
#define MAXN 110000
using namespace std;
typedef long long LL;
LL data[MAXN];
int n;
bool check(LL x)
{
     LL sum=0;
     data[0]=x;
     if(sum<0)return 0;
     for(int i=1;i<=n;i++)
     {
             sum+=data[i-1]-data[i];
             if(sum<0)return 0;
             }
     return 1;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%I64d",&data[i]);
    LL l=0;LL r=1e10;LL ans=0;
    while(l<r)
    {
              LL mid=(l+r)>>1;
              if(check(mid))ans=mid,r=mid;
              else l=mid+1;
              }
    if(check(l))ans=l;
    printf("%I64d\n",ans);
    return 0;
}