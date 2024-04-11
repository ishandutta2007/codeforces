#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()
#define int ll
template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

const int N = 2e5 + 10;
int n, m;
vector<int> g[N];
int w[N];
int root;

void read() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> root;
    root--;
}

set<pair<int, int>> bridges;

void addBridge(int u, int v) {
    if (u > v) swap(u, v);
    bridges.insert({u, v});
}

bool used[N];
int tin[N], up[N], timer = 0;

void dfsBridges(int v, int p) {
    used[v] = true;
    tin[v] = up[v] = timer++;
    for (auto i : g[v]) {
        if (i == p) continue;
        if (used[i]) {
            chkmin(up[v], tin[i]);
        } else {
            dfsBridges(i, v);
            chkmin(up[v], up[i]);
            if (up[i] > tin[v]) {
                addBridge(i, v);
            }
        }
    }
}

bool checkBridge(int u, int v) {
    if (u > v) swap(u, v);
    return bridges.count({u, v}); 
}

int color[N];
ll cost[N];
int sz[N];

void dfsColor(int v, int c) {
    color[v] = c;
    cost[c] += w[v];
    sz[c]++;
    for (auto i : g[v]) {
        if (color[i] != -1) continue;
        if (checkBridge(i, v)) continue;
        dfsColor(i, c);
    }
}

void build() {
    dfsBridges(root, -1);
    fill(cost, cost + n, 0);
    fill(sz, sz + n, 0);
    fill(color, color + n, -1);
    int c = 0;
    dfsColor(root, c++);
    for (int i = 0; i < n; i++) {
        if (color[i] != -1) continue;
        dfsColor(i, c++);
    }
    for (int i = 0; i < n; i++) {
        g[i].clear();
    }
    n = c;
    for (auto [u, v] : bridges) {
        int myU = color[u];
        int myV = color[v];
        g[myU].push_back(myV);
        g[myV].push_back(myU);
    }
    //cout << "n = " << n << endl;

}

const ll INF = -1e18;
ll ans;
ll dp[N][2];

void dfsDp(int v, int p) {
    for (auto i : g[v]) {
        if (i == p) continue;
        dfsDp(i, v);
    }
    bool ok = false;
    ll sum0 = 0;
    for (auto i : g[v]) {
        if (i == p) continue;
        if (dp[i][0] == INF) continue;
        sum0 += dp[i][0];
        ok = true;
    }
    dp[v][0] = INF;
    dp[v][1] = cost[v] + sum0;
    if (ok || sz[v] > 1) {
        dp[v][0] = sum0 + cost[v];
    }
    for (auto i : g[v]) {
        if (i == p) continue;
        sum0 -= max(0LL, dp[i][0]);
        chkmax(dp[v][1], dp[i][1] + sum0 + cost[v]);
        sum0 += max(0LL, dp[i][0]);
    }
}

void calcDp() {
    dfsDp(0, -1);
    ans = max(dp[0][0], dp[0][1]);
}

void run() {
    build();
    calcDp();
}

void write() {
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    read();
    run();
    write();
    return 0;
}