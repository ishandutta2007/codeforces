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

vector<int> adj[300005];
int depth[300005];
bool vis[300005], ban[300005], teach[300005];

void dfs(int u) {
    vis[u] = true;
    if (depth[u] % 2 == 0) {
        teach[u] = true;
        for (int v : adj[u])
            ban[v] = true;
    }
    for (int v : adj[u])
        if (!vis[v] && !(depth[u] % 2 && ban[v])) {
            depth[v] = depth[u] + 1;
            dfs(v);
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i=0; i<n; i++)
            adj[i].clear();
        for (int i=0; i<m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // find an arbitrary spanning tree, put teachers on even depths
        memset(vis, false, sizeof(bool) * n);
        memset(ban, false, sizeof(bool) * n);
        memset(teach, false, sizeof(bool) * n);
        depth[0] = 0;
        dfs(0);
        bool ok = true;
        for (int i=0; i<n; i++)
            ok &= vis[i];
        if (!ok) {
            cout << "NO\n";
            continue;
        }

        vector<int> ret;
        for (int i=0; i<n; i++)
            if (teach[i])
                ret.push_back(i);
        cout << "YES\n" << ret.size() << "\n";
        for (int u : ret)
            cout << u + 1 << " ";
        cout << "\n";
    }

    return 0;
}