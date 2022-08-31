#include<stdio.h>
using namespace std;
typedef long long LL;
LL n;
LL ans=0;
LL max(LL a,LL b){if(a>b)return a;return b;}
LL gcd(LL a,LL b){if(!a||!b)return a+b;return gcd(b,a%b);}
LL LCM(LL a,LL b)
{
          return (a/gcd(a,b))*b;
}
int main()
{
    scanf("%I64d",&n);
    for(LL i=max(1,n-100);i<=n;i++)
    for(LL j=max(1,n-100);j<=n;j++)
    for(LL k=max(1,n-100);k<=n;k++)
    {
           LL reu=LCM(i,LCM(j,k));
           if(reu>ans)ans=reu;
           }
    printf("%I64d\n",ans);
    return 0;
}