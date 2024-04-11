#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

struct BinaryLift {
    int n, lg;
    vector<int> depth;
    vector<vector<int>> adj, up;

    BinaryLift(int _n) : n(_n), lg(__lg(n - 1) + 1), depth(n), adj(n), up(n, vector<int>(lg, -1)) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void init(int r = 0) {
        dfs(r);
        for (int j=1; j<lg; j++)
            for (int i=0; i<n; i++)
                if (up[i][j-1] != -1)
                    up[i][j] = up[up[i][j-1]][j-1];
    }

    void dfs(int u) {
        for (int v : adj[u])
            if (v != up[u][0]) {
                depth[v] = depth[u] + 1;
                up[v][0] = u;
                dfs(v);
            }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);
        for (int j=lg-1; j>=0; j--)
            if (depth[u] - (1 << j) >= depth[v])
                u = up[u][j];
        if (u == v)
            return u;
        for (int j=lg-1; j>=0; j--)
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        return up[u][0];
    }

    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

    int kthAnc(int u, int k) {
        if (k > depth[u])
            return -1;
        for (int j=0; j<lg; j++)
            if (k & (1 << j))
                u = up[u][j];
        return u;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    BinaryLift bl(n);
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        bl.addEdge(u, v);
    }

    bl.init();
    vector<int> cnt(n);
    vector<vector<pair<int, int>>> paths(n);
    vector<map<int, int>> mp1(n);
    vector<map<pair<int, int>, int>> mp2(n);
    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        int w = bl.lca(u, v);
        cnt[u]++;
        cnt[v]++;
        cnt[w]--;
        if (bl.up[w][0] != -1) cnt[bl.up[w][0]]--;
        int a = u == w ? -1 : bl.kthAnc(u, bl.depth[u] - bl.depth[w] - 1), b = v == w ? -1 : bl.kthAnc(v, bl.depth[v] - bl.depth[w] - 1);
        if (a > b) swap(a, b);
        paths[w].emplace_back(a, b);
        if (a != -1) mp1[w][a]++;
        if (b != -1) mp1[w][b]++;
        if (a != -1 && b != -1) mp2[w][{a, b}]++;
    }

    long long ret = 0;

    auto dfs = [&] (auto &self, int u, int p) -> void {
        for (int v : bl.adj[u])
            if (v != p) {
                self(self, v, u);
                cnt[u] += cnt[v];
            }
        for (auto [a, b] : paths[u]) {
            // same lca
            ret += (int) paths[u].size() - 1;
            if (a != -1) ret -= mp1[u][a] - 1;
            if (b != -1) ret -= mp1[u][b] - 1;
            if (a != -1 && b != -1) ret += mp2[u][{a, b}] - 1;
            // different lca
            ret += (cnt[u] - (int) paths[u].size()) * 2;
            if (a != -1) ret -= (cnt[a] - (int) paths[a].size() - mp1[u][a]) * 2;
            if (b != -1) ret -= (cnt[b] - (int) paths[b].size() - mp1[u][b]) * 2;
        }
    };

    dfs(dfs, 0, -1);
    assert(ret % 2 == 0);
    cout << ret / 2 << "\n";

    return 0;
}