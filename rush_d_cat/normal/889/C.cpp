#include <iostream>
using namespace std;

const int N = 1000000+10;
typedef long long LL;
const LL MOD = 1000000007;

LL mpow(LL a, LL x) {
    if (x == 0) return 1;
    LL t = mpow(a, x/2);
    if (x&1) return t*t%MOD*a%MOD;
    return t*t%MOD;
}

int n, k;
LL dp[N], val[N], fac[N], inv[N], sum[N];

LL C(LL a, LL b) {
    return fac[a] * inv[b] % MOD * inv[a-b] % MOD;
}

void init() {

    fac[0] = 1; inv[0] = 1;
    for (int i = 1; i <= n + 1; i ++) {
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = mpow(fac[i], MOD-2);
    }

    for (int i = 1; i <= k; i ++) {
        dp[i] = fac[i]; 
        val[i] = dp[i] * inv[i] % MOD;
        sum[i] = (sum[i-1] + val[i]) % MOD;
    }
    dp[0] = 1;

    for (int i = k+1; i <= n; i ++) {

        dp[i] = (sum[i-1] - sum[i-k-1]) * fac[i-1] % MOD; dp[i] = (dp[i] + MOD) % MOD;
        val[i] = dp[i] * inv[i] % MOD;
        sum[i] = (sum[i-1] + val[i]) % MOD;
    } 

}

int main() {
    scanf("%d %d", &n, &k);

    if (k > n || (k == 1 && n == 1)) {
        printf("0\n");
        return 0;
    }

    init();

    LL ans = 0;
    for (int x = 0; x < n; x ++) {
        ans += C(n-1,x) * fac[x] % MOD * dp[n-x-1] % MOD;
        //printf("%d %lld\n", x, C(n-1,x) * fac[x] % MOD * dp[n-x-1] % MOD);
        ans %= MOD;
    }


    ans = ((fac[n] - ans) % MOD + MOD) % MOD;
    printf("%lld\n", ans);

}