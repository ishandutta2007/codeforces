#include <bits/stdc++.h>

const int mod = 1e9 + 7;

const int N = 256;

int n, k, pwrk[N], pwrd[N], c[N][N], f[N][N];

int main() {
    std::cin >> n >> k; f[0][0] = 1;
    for (int i = pwrk[0] = pwrd[0] = 1; i <= n; i++) {
        pwrk[i] = 1ll * pwrk[i - 1] * k % mod;
        pwrd[i] = 1ll * pwrd[i - 1] * (k - 1) % mod;
    }
    for (int i = 0; i <= n; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= j; k++) {
                int now = f[i - 1][k];
                now = 1ll * now * c[n - k][j - k] % mod;
                if (j == k) {
                    now = 1ll * now * (pwrk[k] + mod - pwrd[k]) % mod;
                } else {
                    now = 1ll * now * pwrk[k] % mod;
                }
                now = 1ll * now * pwrd[n - j] % mod;
                f[i][j] = (f[i][j] + now) % mod;
            }
        }
    } printf("%d\n", f[n][n]);
    return 0;
}