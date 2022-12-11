#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
const ld EPS = 1e-10;
const ll INF = (ll)1e18 + 34;
const ll N = (ll)102;

void mne(ll &a, ll b) {
    a = min(a, b);
}

ll c[N];
ll p[N][N];
ll dp[N][N][N];
ll n, m, k;

int main() {

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int kk = 0; kk < N; kk++)
                dp[i][j][kk] = INF;

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> p[i][j];
    dp[0][m + 1][0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= m + 1; j++)
            for (int kk = 0; kk < n; kk++) {
                if (dp[i][j][kk] == INF)
                    continue;
                if (c[i]) {
                    mne(dp[i + 1][c[i]][c[i] == j ? kk : kk + 1], dp[i][j][kk]);
                    continue;
                }
                for (int nc = 1; nc <= m; nc++)
                    mne(dp[i + 1][nc][nc == j ? kk : kk + 1], dp[i][j][kk] + p[i][nc - 1]);
            }
    ll ans = INF;
    for (int i = 0; i <= m + 1; i++)
        mne(ans, dp[n][i][k]);
    cout << (ans == INF ? -1 : ans);
    return 0;
}