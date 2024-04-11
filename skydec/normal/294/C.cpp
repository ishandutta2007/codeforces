#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long LL;
#define JSB 1000000007
#define JJJ 1000000005
LL f[1005];LL ans=1;
LL n,m;LL d[1005];
LL pow(LL a,LL b)
{
    LL c=1;
    for(;b;b>>=1,a=a*a%JSB)if(b&1)c=c*a%JSB;
    return c;
}
void init()
{
    f[0]=1;
    for(LL i=1;i<=1000;i++)
    {
        f[i]=f[i-1]*i%JSB;
    }
}
int main()
{
    init();
    scanf("%I64d%I64d",&n,&m);
    ans=f[n-m];
    for(LL i=1;i<=m;i++)scanf("%I64d",&d[i]);
    sort(d+1,d+1+m);
    for(LL i=2;i<=m;i++)
    if(d[i]-d[i-1]!=1)
    ans=ans*pow(2,d[i]-d[i-1]-2)%JSB*pow(f[d[i]-d[i-1]-1],JJJ)%JSB;
    if(d[1]!=1)ans=ans*pow(f[d[1]-1],JJJ)%JSB;
    if(d[m]!=n)ans=ans*pow(f[n-d[m]],JJJ)%JSB;
    printf("%I64d",ans);
    //for(;;);
    return 0;
}