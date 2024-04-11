#include <iostream>
using namespace std;
typedef long long LL;
const LL MOD = 998244353;
const int N = 1000000+10;
int n;
LL a[N],dp[N],sum[N];
LL mpow(LL a,LL x) {
    if(x==0) return 1;
    LL t=mpow(a,x>>1);
    if(x%2==0) return t*t%MOD;
    return t*t%MOD*a%MOD;
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
    }
    dp[0]=0,sum[0]=0;
    LL cur = 1;
    for(int i=1;i<=n;i++) {
        dp[i] = dp[i-1] + cur * (a[i]-a[i-1]) % MOD;
        cur = cur * mpow(2,MOD-2) % MOD;
        dp[i] %= MOD;
        sum[i]=(sum[i-1]+dp[i])%MOD;
    }
    cout<<sum[n]*mpow(2,n-1)%MOD<<endl;
}