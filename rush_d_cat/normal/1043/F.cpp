#include <iostream>
using namespace std;
const int N=300000+10;
const int MOD=1e9+7;
typedef long long LL;
LL fac[N],inv[N];
LL C(int n,int k){
    if(n<k)return 0;
    return fac[n] * inv[k] % MOD * inv[n-k] % MOD;
}
int n,a[N],cnt[N],dp[N][10]; 
LL g[N],f[N];
bool check(int k) {
    for(int i=1;i<N;i++){
        g[i] = C(cnt[i],k);
        //if(g[i])
        //printf("g[%d]=%d\n", i,g[i]);
    }
    // g[i] = f[i] + f[2i] + f[3i] + ......
    for(int i=N;i>=1;i--){
        f[i] = g[i];
        for(int j=2*i;j<N;j+=i) {
            f[i] -= f[j];
            f[i] = (f[i]%MOD+MOD)%MOD;
        }
    }
    return f[1]?1:0;
}
int main() {
    inv[1]=1,fac[1]=1,inv[0]=1,fac[0]=1;
    for(int i=2;i<N;i++){
        inv[i]=(MOD-(MOD/i))*inv[MOD%i]%MOD;
    }
    for(int i=2;i<N;i++){
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=inv[i-1]*inv[i]%MOD;
    }
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]); cnt[a[i]]++;
    }
    for(int i=1;i<N;i++)
    for(int j=i+i;j<N;j+=i) cnt[i]+=cnt[j];

    for(int i=1;i<=7;i++) {
        if(check(i))
            return !printf("%d\n", i);
    }
    printf("-1\n");
}