#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 505, INF = 0x3c3c3c3c;
int t, n, m, res, dp[N][N], adj[N][N];

void Enter() {
    cin >> n >> m;
    FOR(i, 1, n) FOR(j, 1, n) dp[i][j] = adj[i][j] = INF;
    FOR(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        dp[u][v] = dp[v][u] = 1;
        adj[u][v] = adj[v][u] = min(adj[u][v], w);
    }
    FOR(i, 1, n) dp[i][i] = 0;
}

void Process() {
    FOR(k, 1, n) FOR(i, 1, n) FOR(j, 1, n) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

    long long res = 1e18;
    FOR(i, 1, n) {
        int tmp = INF;
        FOR(j, 1, n) tmp = min(tmp, dp[1][j] + dp[j][n] + dp[i][j] + 1);
        FOR(j, 1, n) if (adj[i][j] != INF) {
            int tmp2 = min({tmp + 1, dp[1][i] + dp[n][j] + 1, dp[1][j] + dp[n][i] + 1});
            res = min(res, 1LL * adj[i][j] * tmp2);
        }
    }
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        Enter();
        Process();
    }
}