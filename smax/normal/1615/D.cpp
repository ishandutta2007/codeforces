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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<array<int, 3>> edges;
        vector<vector<pair<int, int>>> adj(n);
        for (int i=0; i<n-1; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            edges.push_back({u, v, w});
            if (w != -1) {
                adj[u].emplace_back(v, __builtin_parity(w));
                adj[v].emplace_back(u, __builtin_parity(w));
            }
        }
        for (int i=0; i<m; i++) {
            int a, b, p;
            cin >> a >> b >> p;
            a--, b--;
            adj[a].emplace_back(b, p);
            adj[b].emplace_back(a, p);
        }

        vector<int> color(n, -1);

        auto dfs = [&] (auto &self, int u, int c) -> bool {
            if (color[u] != -1)
                return color[u] == c;
            color[u] = c;
            for (auto [v, w] : adj[u])
                if (!self(self, v, c ^ w))
                    return false;
            return true;
        };

        bool ok = true;
        for (int i=0; i<n; i++)
            if (color[i] == -1 && !dfs(dfs, i, 0)) {
                ok = false;
                break;
            }

        if (ok) {
            cout << "YES\n";
            for (auto [u, v, w] : edges)
                cout << u + 1 << " " << v + 1 << " " << (w == -1 ? color[u] ^ color[v] : w) << "\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}