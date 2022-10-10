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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int sq = ceil(sqrt(n));
    vector<bool> vis(n), taken(n);
    vector<int> depth(n), par(n), indep;

    auto dfs = [&] (auto &self, int u) -> void {
        vis[u] = true;
        for (int v : adj[u])
            if (v != par[u]) {
                if (vis[v] && depth[u] - depth[v] + 1 >= sq) {
                    vector<int> ret{v};
                    while (u != v) {
                        ret.push_back(u);
                        u = par[u];
                    }
                    assert((int) ret.size() >= sq);
                    cout << "2\n" << ret.size() << "\n";
                    for (int x : ret)
                        cout << x + 1 << " ";
                    cout << "\n";
                    exit(0);
                } else if (!vis[v]) {
                    depth[v] = depth[u] + 1;
                    par[v] = u;
                    self(self, v);
                }
            }
        bool ok = true;
        for (int v : adj[u])
            ok &= !taken[v];
        if (ok) {
            taken[u] = true;
            indep.push_back(u);
        }
    };

    par[0] = -1;
    dfs(dfs, 0);
    assert((int) indep.size() >= sq);
    cout << "1\n";
    for (int i=0; i<sq; i++)
        cout << indep[i] + 1 << " ";
    cout << "\n";

    return 0;
}