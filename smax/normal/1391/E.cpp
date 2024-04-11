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

int n, depth[500005];
vector<int> adj[500005];

bool dfs(int u) {
    if (depth[u] + 1 >= (n + 1) / 2) {
        cout << "PATH\n" << depth[u] + 1 << "\n" << u + 1 << " ";
        return true;
    }
    for (int v : adj[u])
        if (depth[v] == -1) {
            depth[v] = depth[u] + 1;
            if (dfs(v)) {
                cout << u + 1 << " \n"[depth[u]==0];
                return true;
            }
        }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int m;
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

        memset(depth, -1, sizeof(int) * n);
        depth[0] = 0;
        if (!dfs(0)) {
            int ret = 0;
            vector<vector<int>> nodes(n);
            for (int i=0; i<n; i++)
                nodes[depth[i]].push_back(i);
            for (int i=0; i<n; i++)
                ret += nodes[i].size() / 2;

            assert(2 * ret >= (n + 1) / 2);
            cout << "PAIRING\n" << ret << "\n";
            for (int i=0; i<n; i++)
                for (int j=0; j+1<nodes[i].size(); j+=2)
                    cout << nodes[i][j] + 1 << " " << nodes[i][j+1] + 1 << "\n";
        }
    }

    return 0;
}