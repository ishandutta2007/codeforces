#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int mod = 1e9 + 7;

int bin_pow(int a, int b) {
    if (b == 0) {
        return 1;
    }
    if (b % 2) {
        return bin_pow(a, b - 1) * a % mod;
    }
    int res = bin_pow(a, b / 2);
    return res * res % mod;
}

int inv(int a) {
    return bin_pow(a, mod - 2);
}

int P[210][210];
int g[210][210];

int32_t main() {
    int half = 5e8 + 4;
    for (int i = 1; i < 210; i++) {
        P[0][i] = 1;
    }
    for (int i = 1; i < 210; i++) {
        for (int j = 1; j < 210; j++) {
            P[i][j] = half * (P[i - 1][j] + P[i][j - 1]) % mod;
        }
    }
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = 2e18;
        }
        g[i][i] = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x][y] = g[y][x] = 1;
    }
    forn (k, n) {
        forn (i, n) {
            forn (j, n) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    int ans = 0;
    forn (i, n) {
        forn (j, i) {
            forn (k, n) {
                /*cerr << k + 1 << ":\n";
                cerr << i + 1 << ' ' << g[k][i] << '\n';
                cerr << j + 1 << ' ' << g[k][j] << '\n';
                cerr << P[g[k][i]][g[k][j]] << '\n';*/
                int a = g[i][j];
                int b = g[i][k];
                int c = g[j][k];
                int x = (a + b - c) / 2;
                int y = (a + c - b) / 2;
                (ans += P[x][y]) %= mod;
            }
        }
    }
    cout << ans * inv(n) % mod;
}