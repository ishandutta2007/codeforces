#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;

ll modexp(ll b, ll e = MOD - 2) {
    if (e == 0) return 1;
    else return (e & 1 ? b : 1) * modexp(b * b % MOD, e / 2) % MOD;
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    vector<vector<int>> dist(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) scanf("%d", &dist[i][j]);
    }
    ll factn = 1;
    for (int i = 1; i <= n; ++i) factn = (factn * i) % MOD;
    ll invfactn = modexp(factn);
    ll ans = 0;
    for (int i = 0; i < m; ++i) {
        // for j not to capture i, 
        // j's (start from 0) index must be >= n - dist[i][j] + 1
        vector<int> ayuda(n);
        for (int j = 0; j < n; ++j) {
            int giveAt = n - dist[j][i] + 1;
            if (giveAt < n) ++ayuda[giveAt];
        }
        ll escapeCapture = 1;
        ll cCand = 0;
        for (int j = 0; j < n; ++j) {
            cCand += ayuda[j];
            escapeCapture = (escapeCapture * cCand--) % MOD;
        }
        ans = (ans + (factn - escapeCapture + MOD) % MOD * invfactn % MOD) % MOD;
    }
    printf("%lld\n", ans);
}