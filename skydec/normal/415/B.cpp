#include<stdio.h>
using namespace std;
typedef long long LL;
LL a,b,n,c;
int main()
{
    scanf("%I64d%I64d%I64d",&n,&a,&b);
    for(LL i=1;i<=n;i++)
    {
           scanf("%I64d",&c);
           LL t=a*c/b;LL y;
           if(t*b%a==0)y=t*b/a;else y=t*b/a+1;
           printf("%I64d ",c-y);
           }
    return 0;
}