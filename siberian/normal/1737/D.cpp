#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

#define int ll

struct BaseEdge{
    int u, v, w;
};

const int N = 510, M = 2.5e5 + 10;
const ll INF = 1e18;
int n, m;
BaseEdge edges[M];
bool g[N][N];
int dist[N][N];

ll ans;

ll calc(int id) {
    int u = edges[id].u;
    int v = edges[id].v;
    ll cost = edges[id].w;
    ll ans = INF;
    for (int it = 0; it < 2; ++it) {
        chkmin(ans, dist[u][0] + dist[v][n - 1]);
        for (int mid = 0; mid < n; ++mid) {
            chkmin(ans, dist[v][mid] + 1 + dist[mid][0] + dist[mid][n - 1]);
        }
        swap(u, v);
    }
    return (ans + 1) * cost; 
}

void solve() {
    cin >> n >> m;
    for (int v = 0; v < n; ++v) {
        for (int u = 0; u < n; ++u) {
            dist[v][u] = INF;
            g[u][v] = false;
        }
        dist[v][v] = 0;
        g[v][v] = true;
    }
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        g[u][v] = g[v][u] = true;
        edges[i] = {u, v, w};
        dist[u][v] = dist[v][u] = 1;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                chkmin(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    ans = INF;
    // cerr << "ans = " << ans << endl;
    for (int i = 0; i < m; ++i) {
        ll fans = calc(i);
        // cerr << "fans = " << fans << endl;
        chkmin(ans, fans);
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}