#include <bits/stdc++.h>
using namespace std;
const int N = 19;
typedef long long ll;

ll dp[N][1 << N];
bool u[N][N];
int mask;
bool ok[1 << N];

ll cnt(int n) {
    ll res = 0;
    dp[n - 1][1 << (n - 1)] = 1;
    for (int msk = (1 << (n - 1)); msk < (1 << n); msk++)
    for (int v = 0; v < n; v++)
        if (msk & (1 << v)) {
            mask = msk ^ (1 << v);
            for (int w = 0; w < n; w++)
                if (msk & (1 << w) && u[w][v])
                    dp[v][msk] += dp[w][mask];
            if (ok[msk] && u[v][n - 1])
                res += dp[v][msk];
        }
    cerr << res << "\n";
    return res;
}

int main() {
    //freopen("a.in", "r", stdin);

    for (int i = 0; i < (1 << N); i++)
        ok[i] = (__builtin_popcount(i) > 2);

    int n, m, v1, v2;
    ll ans = 0;
    cin >> n >> m;
    while (m--) {
        cin >> v1 >> v2;
        v1--;
        v2--;
        u[v1][v2] = u[v2][v1] = true;
    }
    for (int i = n; i > 1; i--)
        ans += cnt(i);

    cout << ans / 2;

    return 0;
}