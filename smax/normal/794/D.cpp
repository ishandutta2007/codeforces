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

    map<vector<int>, int> mp;
    vector<int> id(n);
    vector<vector<int>> comp;
    for (int i=0; i<n; i++) {
        adj[i].push_back(i);
        sort(adj[i].begin(), adj[i].end());
        if (!mp.count(adj[i])) {
            mp[adj[i]] = (int) comp.size();
            comp.emplace_back();
        }
        id[i] = mp[adj[i]];
        comp[id[i]].push_back(i);
    }

    vector<int> x(n);
    vector<bool> vis(n);

    auto dfs = [&] (auto &self, int u, int p, int sign) -> bool {
        vis[u] = true;
        vector<int> all;
        for (int v : adj[comp[u][0]])
            if (id[v] != u)
                all.push_back(id[v]);
        sort(all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());
        if (all.size() >= 3)
            return false;
        for (int v : all)
            if (v != p) {
                if (vis[v])
                    return false;
                x[v] = x[u] + sign;
                if (!self(self, v, u, sign))
                    return false;
                sign = -sign;
            }
        return true;
    };

    x[0] = n;
    if (dfs(dfs, 0, -1, 1)) {
        cout << "YES\n";
        for (int i=0; i<n; i++)
            cout << x[id[i]] << " ";
        cout << "\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}