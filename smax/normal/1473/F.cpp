#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

struct Edge {
    int u, v;
    long long cap, flow;

    Edge(int _u, int _v, long long _cap) : u(_u), v(_v), cap(_cap), flow(0) {}
};

struct Dinic {
    int m, s, t;
    vector<int> level, ptr;
    vector<Edge> edges;
    vector<vector<int>> adj;

    Dinic(int n, int _s, int _t) : m(0), s(_s), t(_t), level(n), ptr(n), adj(n) {}

    void addEdge(int u, int v, long long cap) {
        edges.emplace_back(u, v, cap);
        edges.emplace_back(v, u, 0);
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
                if (edges[e].cap - edges[e].flow > 0 && level[edges[e].v] == -1) {
                    level[edges[e].v] = level[u] + 1;
                    q.push(edges[e].v);
                }
        }
        return level[t] != -1;
    }

    long long dfs(int u, long long f) {
        if (u == t)
            return f;
        while (ptr[u] < (int) adj[u].size()) {
            int e = adj[u][ptr[u]], v = edges[e].v;
            long long nf;
            if (level[u] + 1 == level[v] && edges[e].cap - edges[e].flow > 0 && (nf = dfs(v, min(f, edges[e].cap - edges[e].flow))) > 0) {
                edges[e].flow += nf;
                edges[e^1].flow -= nf;
                return nf;
            }
            ptr[u]++;
        }
        return 0;
    }

    long long maxFlow() {
        long long ret = 0;
        while (bfs()) {
            fill(ptr.begin(), ptr.end(), 0);
            while (long long f = dfs(s, LLONG_MAX))
                ret += f;
        }
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<n; i++)
        cin >> b[i];

    int s = n, t = n + 1, ret = 0;
    Dinic dc(n + 2, s, t);
    vector<int> last(105, -1);
    for (int i=0; i<n; i++) {
        if (b[i] > 0) {
            dc.addEdge(s, i, b[i]);
            ret += b[i];
        } else {
            dc.addEdge(i, t, -b[i]);
        }
        for (int j=1; j<=a[i]; j++)
            if (a[i] % j == 0 && last[j] != -1)
                dc.addEdge(i, last[j], LLONG_MAX);
        last[a[i]] = i;
    }

    cout << ret - dc.maxFlow() << "\n";

    return 0;
}