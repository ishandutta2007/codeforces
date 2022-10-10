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

struct SCC {
    int n, ti;
    vector<int> num, id, stk;
    vector<vector<int>> adj, dag, comp;

    SCC(int _n) : n(_n), ti(0), num(n), id(n, -1), adj(n) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void init() {
        for (int u=0; u<n; u++)
            if (!num[u])
                dfs(u);
        dag.resize(comp.size());
        for (auto &c : comp)
            for (int u : c)
                for (int v : adj[u])
                    if (id[u] != id[v])
                        dag[id[u]].push_back(id[v]);
        for (auto &v : dag) {
            sort(v.begin(), v.end());
            v.erase(unique(v.begin(), v.end()), v.end());
        }
    }

    int dfs(int u) {
        int low = num[u] = ++ti;
        stk.push_back(u);
        for (int v : adj[u]) {
            if (!num[v])
                low = min(low, dfs(v));
            else if (id[v] == -1)
                low = min(low, num[v]);
        }
        if (low == num[u]) {
            comp.emplace_back();
            do {
                id[stk.back()] = (int) comp.size() - 1;
                comp.back().push_back(stk.back());
                stk.pop_back();
            } while (comp.back().back() != u);
        }
        return low;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    SCC scc(n);
    vector<vector<pair<int, int>>> adj(n);
    for (int i=0; i<m; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        a--, b--;
        scc.addEdge(a, b);
        adj[a].emplace_back(b, l);
    }

    scc.init();
    vector<long long> dist(n, -1), cycle(scc.comp.size());

    auto dfs = [&] (auto &self, int u) -> void {
        for (auto [v, w] : adj[u])
            if (scc.id[u] == scc.id[v]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + w;
                    self(self, v);
                }
                cycle[scc.id[u]] = __gcd(cycle[scc.id[u]], abs(dist[u] + w - dist[v]));
            }
    };

    for (int u=0; u<n; u++)
        if (dist[u] == -1) {
            dist[u] = 0;
            dfs(dfs, u);
        }

    int q;
    cin >> q;
    for (int i=0; i<q; i++) {
        int v, s, t;
        cin >> v >> s >> t;
        v--;
        cout << (s % __gcd(cycle[scc.id[v]], (long long) t) == 0 ? "YES" : "NO") << "\n";
    }

    return 0;
}