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
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

struct Dinic {
    struct Edge {
        int u, v;
        long long cap, flow;

        Edge(int _u, int _v, long long _cap) : u(_u), v(_v), cap(_cap), flow(0) {}
    };

    int m, s, t;
    vector<int> level, ptr;
    vector<Edge> edges;
    vector<vector<int>> adj;

    Dinic(int n, int _s, int _t) : m(0), s(_s), t(_t), level(n), ptr(n), adj(n) {}

    void addEdge(int u, int v, long long cap, long long rcap = 0) {
        edges.emplace_back(u, v, cap);
        edges.emplace_back(v, u, rcap);
        adj[u].push_back(m++);
        adj[v].push_back(m++);
    }

    bool bfs() {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int e : adj[u])
                if (edges[e].flow < edges[e].cap && level[edges[e].v] == -1) {
                    level[edges[e].v] = level[u] + 1;
                    q.push(edges[e].v);
                }
        }
        return level[t] != -1;
    }

    long long dfs(int u, long long f) {
        if (f == 0 || u == t)
            return f;
        while (ptr[u] < (int) adj[u].size()) {
            int e = adj[u][ptr[u]], v = edges[e].v;
            long long nf;
            if (level[u] + 1 == level[v] && edges[e].flow < edges[e].cap && (nf = dfs(v, min(f, edges[e].cap - edges[e].flow))) > 0) {
                edges[e].flow += nf;
                edges[e^1].flow -= nf;
                return nf;
            }
            ptr[u]++;
        }
        return 0;
    }

    long long maxFlow(long long limit = LLONG_MAX) {
        long long ret = 0;
        while (limit > 0 && bfs()) {
            fill(ptr.begin(), ptr.end(), 0);
            while (long long f = dfs(s, limit)) {
                ret += f;
                limit -= f;
            }
        }
        return ret;
    }
};

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--, t--;
    vector<array<int, 3>> edges;
    vector<vector<pair<int, int>>> adj(n), rev(n);
    Dinic dinic(n, s, t);
    for (int i=0; i<m; i++) {
        int u, v, g;
        cin >> u >> v >> g;
        u--, v--;
        edges.push_back({u, v, g});
        if (g) {
            adj[u].emplace_back(v, i);
            rev[v].emplace_back(u, i);
            dinic.addEdge(u, v, 1, INF);
        } else {
            dinic.addEdge(u, v, INF);
        }
    }

    vector<int> f(m);
    vector<bool> vis(n);

    auto dfs1 = [&] (auto &self, int u, int b, const vector<vector<pair<int, int>>> &adj) -> bool {
        if (u == b)
            return true;
        vis[u] = true;
        for (auto [v, i] : adj[u])
            if (!vis[v] && self(self, v, b, adj)) {
                f[i]++;
                return true;
            }
        return false;
    };

    for (int i=0; i<m; i++) {
        auto [u, v, g] = edges[i];
        if (g) {
            f[i]++;
            fill(vis.begin(), vis.end(), false);
            if (!dfs1(dfs1, v, u, adj)) {
                fill(vis.begin(), vis.end(), false);
                dfs1(dfs1, u, s, rev);
                fill(vis.begin(), vis.end(), false);
                dfs1(dfs1, v, t, adj);
            }
        }
    }

    auto dfs2 = [&] (auto &self, int u) -> void {
        vis[u] = true;
        for (int e : dinic.adj[u])
            if (!vis[dinic.edges[e].v] && dinic.edges[e].flow < dinic.edges[e].cap)
                self(self, dinic.edges[e].v);
    };

    cout << dinic.maxFlow() << "\n";
    fill(vis.begin(), vis.end(), false);
    dfs2(dfs2, s);
    for (int i=0; i<m; i++)
        cout << f[i] << " " << f[i] + (!vis[edges[i][0]] || vis[edges[i][1]]) << "\n";

    return 0;
}