#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<climits>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<cmath>

using namespace std;

#define N 100010
long long n,k;
long long fac[N],ifac[N];
#define mo 1000000007ll
char s[N];
long long Power(long long a,long long b)
{
    long long nowans=1;for(;b;b>>=1,a=1ll*a*a%mo)if(b&1)nowans=1ll*nowans*a%mo;
    return nowans;
}
long long a[N],f[N];
long long c(long long n,long long m){
    return 1ll*fac[n]*ifac[m]%mo*ifac[n-m]%mo;
}

long long Sum[N];
long long power[N];

long long Change(long long S,long long t)
{
    return (Sum[t]-Sum[S-1]*power[t-S+1]%mo+mo)%mo;
}

int main()
{
    scanf("%I64d%I64d",&n,&k);
    scanf("%s",s+1);
    fac[0]=1;for(long long i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mo;
    ifac[0]=1;ifac[n]=Power(fac[n],mo-2);
    for(long long i=n-1;i;i--)ifac[i]=1ll*ifac[i+1]*(i+1)%mo;
    for(long long i=1;i<=n;i++)a[i]=s[i]-'0';
    for(long long i=1;i<=n;i++)Sum[i]=a[i];
    power[0]=1;
    for(int i=1;i<=n;i++)power[i]=(power[i-1]*10ll)%mo;
    for(long long i=2;i<=n;i++)Sum[i]=(Sum[i]+Sum[i-1]*10ll%mo)%mo;
    for(long long i=2;i<=n;i++)(a[i]+=a[i-1])%=mo;
    f[1]=a[n]%mo;
    for(long long i=2;i<=n;i++)f[i]=((1ll*f[i-1]*10ll%mo+(a[n]-a[i-1])%mo)%mo-1ll*Change(n-i+2,n)*10%mo+mo)%mo;
    if(k==0)printf("%I64d",f[n]);
    else if(k==1)
    {
        long long nowans=0;for(long long i=1;i<=n-1;i++)(nowans+=Change(1,i)+Change(n-i+1,n))%=mo;
        printf("%I64d",nowans);
    }
    else
    {
        long long nowans=0;for(long long i=1;i<=n-2-(k-2);i++)
        {
            nowans=(1ll*nowans+1ll*f[i]*c(n-i-2,k-2)%mo)%mo;
        }
        for(long long i=1;i<=n-2-(k-2);i++)
        {
            nowans=((1ll*nowans-1ll*Change(1,i)*c(n-i-2,k-2)%mo+mo)%mo-1ll*Change(n-i+1,n)*c(n-i-2,k-2)%mo+mo)%mo;
        }
        for(long long i=1;i<=n-k;i++){
            nowans=(1ll*nowans+1ll*(Change(1,i)+Change(n-i+1,n))*c(n-i-1,k-1)%mo)%mo;
        }printf("%I64d",nowans);
    }
}