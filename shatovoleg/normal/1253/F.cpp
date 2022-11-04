#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back
#define kek pop_back
#define mp make_pair
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define int ll

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int INF = 1e18;

template<class t1, class t2>
bool cmin(t1 &a, const t2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class t1, class t2>
bool cmax(t1 &a, const t2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

#ifndef LOCAL
void UseFiles(const string &s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
#else
void UseFiles(const string&) {}
#endif

void run();

signed main() {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

struct dsu {
    vector<int> l, h;

    dsu(int n) : l(n), h(n, 1) {
        iota(all(l), 0);
    }

    int get_root(int v) {
        if (l[v] == v) {
            return v;
        }
        return l[v] = get_root(l[v]);
    }

    bool Union(int u, int v) {
        u = get_root(u);
        v = get_root(v);
        if (u == v) {
            return false;
        }
        if (h[u] > h[v]) {
            swap(u, v);
        }
        l[u] = v;
        if (h[u] == h[v]) {
            ++h[v];
        }
        return true;
    }
};

int n;
vector<vector<pii>> g;
vector<int> color, dst;

vector<tuple<int, int, int>> dijkstra(int k) {
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for (int i = 0; i < k; ++i) {
        color[i] = i;
        dst[i] = 0;
        q.push({0, i});
    }
    while (len(q)) {
        auto [d, v] = q.top();
        q.pop();
        if (dst[v] != d) {
            continue;
        }
        for (auto &[u, w] : g[v]) {
            if (cmin(dst[u], d + w)) {
                color[u] = color[v];
                q.push({dst[u], u});
            }
        }
    }
    map<pii, int> m;
    for (int i = 0; i < n; ++i) {
        for (auto &[v, w] : g[i]) {
            if (color[v] > color[i]) {
                if (m.count({color[i], color[v]})) {
                    cmin(m[{color[i], color[v]}], dst[i] + dst[v] + w);
                } else {
                    m[{color[i], color[v]}] = dst[i] + dst[v] + w;
                }
            }
        }
    }
    vector<tuple<int, int, int>> edges;
    for (auto &[x, y] : m) {
        edges.pb({y, x.first, x.second});
    }
    sort(all(edges));
    return edges;
}

const int maxlg = 20;
vector<vector<pii>> tree;
vector<vector<int>> up, mup;
vector<int> d;

void dfs(int v, int p = -1, int pw = 0, int cur_d = 0) {
    d[v] = cur_d;
    mup[v][0] = pw;
    up[v][0] = p;
    if (p == -1) {
        up[v][0] = v;
    }
    for (int i = 1; i < maxlg; ++i) {
        up[v][i] = up[up[v][i - 1]][i - 1];
        mup[v][i] = max(mup[v][i - 1], mup[up[v][i - 1]][i - 1]);
    }
    for (auto &[u, w] : tree[v]) {
        if (u == p) {
            continue;
        }
        dfs(u, v, w, cur_d + 1);
    }
}

int lca(int u, int v) {
    if (d[u] < d[v]) {
        swap(u, v);
    }
    int ans = 0;
    for (int i = maxlg - 1; i >= 0; --i) {
        if (d[up[u][i]] >= d[v]) {
            cmax(ans, mup[u][i]);
            u = up[u][i];
        }
    }
    if (u == v) {
        return ans;
    }
    for (int i = maxlg - 1; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            cmax(ans, mup[u][i]);
            cmax(ans, mup[v][i]);
            u = up[u][i];
            v = up[v][i];
        }
    }
    cmax(ans, mup[v][0]);
    cmax(ans, mup[u][0]);
    return ans;
}

void run() {
    int m, k, q;
    cin >> n >> m >> k >> q;
    g.resize(n);
    color.resize(n, -1);
    dst.resize(n, INF);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    vector<tuple<int, int, int>> edges = dijkstra(k);
    tree.resize(k);
    up.resize(k, vector<int>(maxlg, -1));
    mup.resize(k, vector<int>(maxlg, -1));
    d.resize(k, -1);
    dsu D(k);
    for (auto &[w, u, v] : edges) {
        if (D.Union(u, v)) {
            tree[u].pb({v, w});
            tree[v].pb({u, w});
        }
    }
    dfs(0);
    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        cout << lca(u, v) << " ";
    }
    cout << endl;
}