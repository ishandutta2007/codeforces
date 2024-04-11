#include<bits/stdc++.h>
#define MAXN 300050
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll n,a[MAXN],sum[MAXN+1];
ll pow_mod(ll a,ll i)
{
    if(i==0) return 1;
     ll s=1;
    while(i>0)
     {
         if(i&1) s=(s*a)%MOD;
         a=(a*a)%MOD;
         i>>=1;
     }
     return s;
}
int main()
{
    scanf("%I64d",&n);
    sum[0]=0;
    for(int i=0;i<n;i++)
        scanf("%I64d",&a[i]);
    sort(a,a+n);
    for(int i=1;i<=n;i++)
        sum[i]=(sum[i-1]+a[i-1])%MOD;
    ll s=0;
    for(int i=0;i<n-1;i++)
        s=(s+((sum[n]-sum[n-i-1]-sum[i+1]+MOD)%MOD)*pow_mod(2,i))%MOD;
    printf("%I64d\n",(s+MOD)%MOD);
    return 0;
}