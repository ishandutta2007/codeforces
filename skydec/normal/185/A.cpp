#include<stdio.h>
#define jsb 1000000007
using namespace std;
typedef long long LL;
LL n;
LL Pow(LL a,LL b)
{
          LL c=1;
          for(;b;b>>=1,a=a*a%jsb)
          if(b&1)c=c*a%jsb;
          return c;
}
int main()
{
    scanf("%I64d",&n);
    if(!n)
    {
          printf("1");
          return 0;
          }
    LL ans=Pow(2,2ll*n-1)-1;
    ans-=Pow(2,n-1)-1;ans+=Pow(2,n);
    ans%=jsb;
    if(ans<0)ans+=jsb;
    printf("%I64d\n",ans);
    return 0;
}