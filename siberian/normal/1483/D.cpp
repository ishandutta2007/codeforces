#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()
#define mp make_pair

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

#define int ll
const int INF = 1e18;
const int N = 610;
int n, m;
int dist[N][N];
int dp[N][N];

struct Edge{
    int u, v, cost;
};

Edge edges[N * N];

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                dist[i][j] = INF;
            } else {
                dist[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        edges[i] = {u, v, w};
        chkmin(dist[u][v], w);
        chkmin(dist[v][u], w);
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                chkmin(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = -INF;
        }
    } 
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int u, v, l;
        cin >> u >> v >> l;
        --u;
        --v;
        for (int x = 0; x < n; ++x) {
            if (dist[u][x] > l) continue;
            chkmax(dp[x][v], l - dist[u][x]);
        }
        for (int x = 0; x < n; ++x) {
            if (dist[v][x] > l) continue;
            chkmax(dp[x][u], l - dist[v][x]);
        }
    }

    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].cost;
        bool ok = false;
        for (int to = 0; to < n; ++to) {
            if (dp[u][to] >= dist[v][to] + w) {
                ok = true;
            } else if (dp[v][to] >= dist[u][to] + w) {
                ok = true;
            }
        }
        if (ok) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}