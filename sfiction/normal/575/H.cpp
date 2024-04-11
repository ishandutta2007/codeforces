#include <cstdio>

typedef long long ll;

const int MAXN = 2E6 + 100;
const ll MOD = 1E9 + 7;

ll inv[MAXN], fac[MAXN], facinv[MAXN];

int main(){
    inv[0] = 0, inv[1] = 1;
    fac[0] = fac[1] = 1;
    facinv[0] = facinv[1] = 1;
    for (int i = 2; i < MAXN; ++i){
        inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
        fac[i] = fac[i - 1] * i % MOD;
        facinv[i] = facinv[i - 1] * inv[i] % MOD;
    }

    int n;
    scanf("%d", &n);
    printf("%d", (int)((2 * fac[2 * n + 1] % MOD * facinv[n] % MOD * facinv[n + 1] % MOD - 1 + MOD) % MOD));
    return 0;
}