#include<bits/stdc++.h>
using namespace std;

#define N 200010
const int mod = 1e9 + 7;

int inverse(int a, int b = mod - 2)  {
    int ans = 1;
    for( ; b; b >>= 1, a = 1ll * a * a % mod) if(b & 1) ans = 1ll * ans * a % mod;
    return ans;
}

int fac[N], inv[N];

void prepare() {
    fac[0] = 1;
    for(int i = 1; i < N; i ++) fac[i] = 1ll * fac[i - 1] * i % mod;
    inv[N - 1] = inverse(fac[N - 1]);
    for(int i = N - 1; i > 0; i --) inv[i - 1] = 1ll * inv[i] * i % mod;
}

int com(int a, int b) {
    if(a < 0 || a < b || b < 0) return 0;
    return 1ll * fac[a] * inv[b] % mod * inv[a - b] % mod;
}

int t, n, k;

int main() {
    prepare();
    for(scanf("%d", &t); t --; ) {
        scanf("%d%d", &n, &k);
        long long ans = 0;
        for(int m = 1; (m - 1) * (k - 1) <= n; m ++) {
            long long d = 0;
            d += 1ll * m * (m + 1) % mod * (com(n - (m - 1) * (k - 1), m + 1) - com(n - m * (k - 1), m + 1)) % mod;
            d -= 1ll * (m - 1) * (n - k * m) % mod * (com(n - (m - 1) * (k - 1), m) - com(n - m * (k - 1), m)) % mod;
            d = (d % mod + mod) % mod;
            ans += d * fac[n - m - 1] % mod * fac[m + 1] % mod;
        }
        ans = (ans % mod + mod) % mod;
        ans = ans * inv[n] % mod;
        printf("%d\n", ans);
    }
}