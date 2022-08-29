#include<stdio.h>
#include<algorithm>
#define MAXN 110000
using namespace std;
long n,x;long a[MAXN];
int main()
{
    scanf("%ld%ld",&n,&x);
    for(long i=1;i<=n;i++)scanf("%ld",&a[i]);
    sort(a+1,a+1+n);
    long long ans=0;
    for(long i=1;i<=n;i++)
    {
             ans+=x*1ll*a[i]*1ll;
             x--;
             if(x<1)x=1;
             }
    printf("%I64d\n",ans);
    return 0;
}