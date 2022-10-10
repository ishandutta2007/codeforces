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
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, r, b;
    cin >> n >> m >> r >> b;
    vector<int> x(n), y(n);
    map<int, int> mpX, mpY;
    for (int i=0; i<n; i++) {
        cin >> x[i] >> y[i];
        mpX[x[i]];
        mpY[y[i]];
    }
    vector<array<int, 3>> constr;
    for (int i=0; i<m; i++) {
        int t, l, d;
        cin >> t >> l >> d;
        if (t == 1) mpX[l];
        else mpY[l];
        constr.push_back({t, l, d});
    }

    int id = 0;
    vector<int> side;
    for (auto &p : mpX) {
        p.second = id++;
        side.push_back(0);
    }
    for (auto &p : mpY) {
        p.second = id++;
        side.push_back(1);
    }

    int s = id, t = id + 1;
    Dinic dinic(id + 4, id + 2, id + 3);

    vector<int> deg(id);
    for (int i=0; i<n; i++) {
        dinic.addEdge(mpX[x[i]], mpY[y[i]], 1);
        deg[mpX[x[i]]]++;
        deg[mpY[y[i]]]++;
    }

    vector<int> diff = deg;
    for (auto [tp, l, d] : constr) {
        if (tp == 1) diff[mpX[l]] = min(diff[mpX[l]], d);
        else diff[mpY[l]] = min(diff[mpY[l]], d);
    }

    vector<long long> in(id + 2), out(id + 2);
    for (int i=0; i<id; i++) {
        int l = max((deg[i] - diff[i] + 1) / 2, 0), u = (deg[i] + diff[i]) / 2;
        if (l > u) {
            cout << "-1\n";
            return 0;
        }
        if (side[i]) {
            dinic.addEdge(i, t, u - l);
            in[t] += l;
            out[i] += l;
        } else {
            dinic.addEdge(s, i, u - l);
            in[i] += l;
            out[s] += l;
        }
    }

    for (int i=0; i<id+2; i++) {
        dinic.addEdge(dinic.s, i, in[i]);
        dinic.addEdge(i, dinic.t, out[i]);
    }
    dinic.addEdge(t, s, 1e18);

    if (dinic.maxFlow() < accumulate(in.begin(), in.end(), 0LL)) {
        cout << "-1\n";
        return 0;
    }

    dinic.s = s;
    dinic.t = t;
    long long ret = dinic.maxFlow();
    cout << ret * min(r, b) + (n - ret) * max(r, b) << "\n";
    for (int i=0; i<n; i++) {
        if (dinic.edges[2*i].flow ^ (r > b)) cout << 'r';
        else cout << 'b';
    }

    return 0;
}