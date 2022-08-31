#include<stdio.h>
using namespace std;
typedef long long LL;
LL a,b,ans;
int main()
{
    ans=0;scanf("%I64d%I64d",&a,&b);
    while(a!=0&&b!=0)
    {
               ans+=a/b;
               a%=b;
               LL tmp=a;a=b;b=tmp;
               }
    printf("%I64d\n",ans);
    return 0;
}