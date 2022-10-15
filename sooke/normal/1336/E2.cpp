#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353, inv2 = 499122177;
const int M = 64;

int n, m, k, p[M], c[M][M];
long long a[M], b[M], f[M];

void dfs(int i, long long x) {
    if (i == k) { p[__builtin_popcountll(x)]++; return; }
    dfs(i + 1, x); dfs(i + 1, x ^ a[i]);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        long long x; cin >> x;
        for (int j = m; j >= 0; j--) {
            if (x >> j & 1) {
                if (!f[j]) { f[j] = x; break; }
                x ^= f[j];
            }
        }
    }
    for (int i = 0; i < m; i++) {
        if (f[i]) {
            for (int j = 0; j < i; j++) {
                if (f[i] >> j & 1) { f[i] ^= f[j]; }
            }
            for (int j = 0; j < m; j++) {
                if (!f[j]) { a[k] = a[k] * 2 + (f[i] >> j & 1); }
            }
            a[k] |= 1ll << m - 1 - k; k++;
        }
    }
    if (k <= 26) {
        dfs(0, 0);
        for (int i = 0; i <= m; i++) {
            int ans = p[i];
            for (int j = 0; j < n - k; j++) { ans = ans * 2 % mod; }
            cout << ans << " ";
        }
    } else {
        k = m - k; swap(a, b);
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < m - k; j++) {
                if (b[j] >> i & 1) { a[i] |= 1ll << j; }
            }
            a[i] |= 1ll << m - 1 - i;
        }
        dfs(0, 0);
        for (int i = 0; i <= m; i++) {
            c[i][0] = 1;
            for (int j = 1; j <= i; j++) { c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod; }
        }
        for (int i = 0; i <= m; i++) {
            int ans = 0;
            for (int j = 0; j <= m; j++) {
                int coef = 0;
                for (int k = 0; k <= i; k++) {
                    coef = (coef + (k & 1 ? -1ll : 1ll) * c[m - j][i - k] * c[j][k] % mod + mod) % mod;
                }
                ans = (ans + 1ll * coef * p[j]) % mod;
            }
            for (int j = 0; j < k; j++) { ans = 1ll * ans * inv2 % mod; }
            for (int j = 0; j < n - m + k; j++) { ans = ans * 2 % mod; }
            cout << ans << " ";
        }
    }
    return 0;
}