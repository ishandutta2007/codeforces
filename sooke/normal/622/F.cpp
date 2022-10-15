#include <cstdio>

const int mod = 1e9 + 7;

inline int add(int x, int y) {
    return x + y >= mod ? x + y - mod : x + y;
}
inline int power(int x, int y) {
    int res = 1;
    for (; y; y >>= 1, x = 1ll * x * x % mod) {
        if (y & 1) { res = 1ll * res * x % mod; }
    }
    return res;
}

const int N = 1e6 + 5;

int n, m, k, np, pri[N], pwr[N], sum[N];
int pre[N], suf[N], inv[N], invf[N], invg[N];
bool vis[N];

void sieve(int n) {
    pwr[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) { pri[np++] = i; pwr[i] = power(i, k); }
        for (int j = 0; j < np; j++) {
            int k = i * pri[j];
            if (k > n) { break; }
            vis[k] = true;
            pwr[k] = 1ll * pwr[i] * pwr[pri[j]] % mod;
            if (i % pri[j] == 0) { break; }
        }
    }
    for (int i = 1; i <= n; i++) { sum[i] = add(sum[i - 1], pwr[i]); }
}

int lagrange(int n) {
    pre[0] = suf[m + 1] = 1;
    for (int i = 1; i <= m; i++) { pre[i] = suf[i] = n - i; }
    for (int i = 1; i <= m; i++) { pre[i] = 1ll * pre[i - 1] * pre[i] % mod; }
    for (int i = m; i >= 1; i--) { suf[i] = 1ll * suf[i + 1] * suf[i] % mod; }
    inv[1] = invf[0] = invg[0] = 1;
    for (int i = 2; i <= m; i++) { inv[i] = 1ll * inv[mod % i] * (mod - mod / i) % mod; }
    for (int i = 1; i <= m; i++) { invf[i] = 1ll * invf[i - 1] * inv[i] % mod; }
    for (int i = 1; i <= m; i++) { invg[i] = 1ll * invg[i - 1] * (mod - inv[i]) % mod; }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        int res = sum[i];
        res = 1ll * res * pre[i - 1] % mod * suf[i + 1] % mod;
        res = 1ll * res * invf[i - 1] % mod * invg[m - i] % mod;
        ans = add(ans, res);
    }
    return ans;
}

int main() {
    scanf("%d%d", &n, &k); m = k + 2; sieve(m);
    printf("%d\n", n <= m ? sum[n] : lagrange(n));
    return 0;
}