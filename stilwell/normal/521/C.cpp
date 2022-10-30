#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define p 1000000007
using namespace std;

int n,m,i,j,k;
long long fac[100005],fac_inv[100005],sum,tmp,ans;
char s[100005];

long long Power(long long a,long long b)
{
    long long ans=1;
    while(b)
    {
        if(b%2)ans=ans*a%p;
        a=a*a%p;
        b/=2;
    }
    return ans;
}
long long C(int n,int m)
{
    if(m>n)return 0;if(m<0||n<0)return 0;
    return fac[n]*fac_inv[m]%p*fac_inv[n-m]%p;
}

int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    fac[0]=1;
    for(i=1;i<=n;++i)fac[i]=fac[i-1]*i%p;
    fac_inv[n]=Power(fac[n],p-2);
    for(i=n;i>=1;--i)fac_inv[i-1]=fac_inv[i]*i%p;
    tmp=1;
    for(i=n;i>=1;--i)
    {
        ans=(ans+sum*(s[i]-'0')%p+tmp*C(i-1,m)%p*(s[i]-'0')%p)%p;
        sum=(sum+C(i-2,m-1)*tmp%p)%p;
        tmp=tmp*10%p;
    }
    printf("%I64d\n",ans);
}