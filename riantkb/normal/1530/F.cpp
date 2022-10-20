#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
using namespace std;

const uint16_t mod = 31607;


int powmod(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    vector<int> inv(mod, -1);
    for (int i = 0; i < mod; ++i) {
        inv[i] = powmod(i, mod - 2);
    }
    int n;
    cin >> n;
    int N = n + 2;
    vector<uint16_t> dp(1 << N);
    dp[(1 << N) - 1] = 1;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            a[i][j] = a[i][j] * inv[10000] % mod;
        }
    }

    vector<vector<vector<vector<uint16_t>>>> p(n, vector(n, vector(2, vector(mod, (uint16_t)0))));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < mod; ++k) {
                p[i][j][0][k] = a[i][j] * k % mod;
                p[i][j][1][k] = (1 + mod - a[i][j]) * k % mod;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        vector<uint16_t> dp2 = dp;
        int al = 1;
        for (int j = 0; j < n; ++j) {
            int mask = (1 << N) - 1;
            mask &= ~(1 << j);
            if (i == j) {
                mask &= ~(1 << n);
            }
            if (i + j == n - 1) {
                mask &= ~(1 << (n + 1));
            }
            for (int k = 0; k < (1 << N); ++k) {
                uint16_t l = dp2[k];
                dp2[k] = p[i][j][0][l];
                dp2[k & mask] += p[i][j][1][l];
                if (dp2[k & mask] >= mod) {
                    dp2[k & mask] -= mod;
                }
            }
            // prev = nex;
            al = al * a[i][j] % mod;
        }
        for (int k = 0; k < (1 << N); ++k) {
            dp[k] = (dp2[k] + mod - dp[k] * al % mod) % mod;
        }

    }
    cout << (1 + mod - dp[0]) % mod << '\n';

    return 0;
}