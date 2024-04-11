#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[405][405], bin[405][405], p2[405], inv[405], M;
int n;

void add(ll &x, ll y) {
    x += y;
    if(x > M)
        x -= M;
}

ll _inv(ll b) {
    ll e = M - 2, res = 1;
    for(ll k = 1; k <= e; k *= 2) {
        if(k & e) res = (res * b) % M;
        b = (b * b) % M;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> M;

    bin[0][0] = 1;
    p2[0] = 1;
    for(int i = 1; i <= n; i++) {
        bin[i][0] = 1;
        p2[i] = p2[i - 1];
        add(p2[i], p2[i - 1]);
        for(int j = 1; j <= n; j++) {
            bin[i][j] = bin[i - 1][j - 1];
            add(bin[i][j], bin[i - 1][j]);
        }
    }

    dp[0][0] = dp[1][1] = 1;
    for(int sz = 2; sz <= n; sz++) {
        for(int op = 1; op <= sz - 1; op++) {
            for(int k = 1; k <= op - 1; k++) {
                add(dp[sz][op], ((dp[sz - k - 1][op - k] * bin[op][k]) % M * p2[k - 1]) % M);
            }
        }
        add(dp[sz][sz], p2[sz - 1]);
    }

    ll ans = 0;
    for(int op = 1; op <= n; op++)
        add(ans, dp[n][op]);

    cout << ans << '\n';
}