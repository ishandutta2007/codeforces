#include <bits/stdc++.h>

using namespace std;

const int INF = 1111111;

int
main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        --u, --v;
        g[v].push_back({u, t});
    }
    // 0 - "optimal" path for white color
    // 1 - "optimal" path for black color
    // 2 - "optimal" path for any color
    vector<array<int, 3>> col_dp(n, {INF, INF, INF});
    vector<int> q(n);
    int qh = 0, qt = 0;
    col_dp[n - 1] = {0, 0, 0};
    q[qt++] = n - 1;
    while (qh < qt) {
        int v = q[qh++];
        int dist = col_dp[v][2] + 1;
        for (auto [to, e_col] : g[v]) {
            if (col_dp[to][2] != INF) continue;
            col_dp[to][e_col] = min(col_dp[to][e_col], dist);
            col_dp[to][2] = max(col_dp[to][0], col_dp[to][1]);
            if (col_dp[to][2] != INF) {
                q[qt++] = to;
            }
        }
    }
    cout << (col_dp[0][2] == INF ? -1 : col_dp[0][2]) << '\n';
    for (auto& col_dp_v : col_dp) {
        cout << (col_dp_v[0] >= col_dp_v[1] ? '0' : '1');
    }
    cout << '\n';
    return 0;
}