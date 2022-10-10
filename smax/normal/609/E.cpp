#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) cerr << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {os << "["; for (int i=0; i<(int)v.size(); i++) {if (i) os << ", "; os << v[i];} return os << "]";}
void debug() {cerr << "\n";} template<typename T, typename... Args> void debug(T x, Args... args) {cerr << x << "; "; debug(args...);}

#define MAXN 200000
#define LOG 18

template<int SZ>
struct DSU {
    int parent[SZ], Size[SZ];

    void init(int n) {
        for (int i=0; i<n; i++) {
            parent[i] = i;
            Size[i] = 1;
        }
    }

    int Find(int u) {
        if (u != parent[u])
            parent[u] = Find(parent[u]);
        return parent[u];
    }

    void Union(int u, int v) {
        u = Find(u);
        v = Find(v);
        if (u != v) {
            if (Size[u] < Size[v])
                swap(u, v);
            parent[v] = u;
            Size[u] += Size[v];
        }
    }
};

int n, depth[MAXN], dp[MAXN][LOG], mx[MAXN][LOG];
vector<pair<int, int>> adj[MAXN];

void dfs(int u, int d) {
    depth[u] = d;
    for (auto e : adj[u])
        if (e.first != dp[u][0]) {
            dp[e.first][0] = u;
            mx[e.first][0] = e.second;
            dfs(e.first, d + 1);
        }
}

void preprocess() {
    memset(dp, -1, sizeof(dp));
    dfs(0, 0);

    for (int j=1; 1<<j<=n; j++)
        for (int i=0; i<n; i++)
            if (dp[i][j-1] != -1) {
                dp[i][j] = dp[dp[i][j-1]][j-1];
                mx[i][j] = max(mx[i][j-1], mx[dp[i][j-1]][j-1]);
            }
}

int maxEdge(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);

    int ret = 0;
    for (int j=LOG-1; j>=0; j--)
        if (depth[u] - (1 << j) >= depth[v]) {
            ret = max(ret, mx[u][j]);
            u = dp[u][j];
        }

    if (u == v)
        return ret;

    for (int j=LOG-1; j>=0; j--)
        if (dp[u][j] != dp[v][j]) {
            ret = max({ret, mx[u][j], mx[v][j]});
            u = dp[u][j];
            v = dp[v][j];
        }

    return max({ret, mx[u][0], mx[v][0]});
}

pair<int, pair<int, int>> in[MAXN], edges[MAXN];
DSU<MAXN> ds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        in[i] = edges[i] = {w, {u-1, v-1}};
    }

    sort(edges, edges + m);
    ds.init(n);
    long long tot = 0;
    for (auto e : edges)
        if (ds.Find(e.second.first) != ds.Find(e.second.second)) {
            ds.Union(e.second.first, e.second.second);
            tot += e.first;
            adj[e.second.first].emplace_back(e.second.second, e.first);
            adj[e.second.second].emplace_back(e.second.first, e.first);
        }

    preprocess();

    for (int i=0; i<m; i++)
        cout << tot + in[i].first - maxEdge(in[i].second.first, in[i].second.second) << "\n";

    return 0;
}