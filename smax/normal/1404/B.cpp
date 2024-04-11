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

const int INF = 1e9;

int a, b, da, db;
vector<int> adj[100005];

pair<int, int> dfs(int u, int p, int d) {
    if (d > 0 && u == b && d <= da)
        return {INF, INF};
    pair<int, int> ret(0, u);
    for (int v : adj[u])
        if (v != p) {
            auto pi = dfs(v, u, d+1);
            if (pi.first + 1 > ret.first) {
                ret.first = pi.first + 1;
                ret.second = pi.second;
            }
        }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n >> a >> b >> da >> db;
        a--, b--;
        for (int i=0; i<n; i++)
            adj[i].clear();
        for (int i=0; i<n-1; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if (db <= 2 * da) {
            cout << "Alice\n";
            continue;
        }

        int r = dfs(a, -1, 0).second;
        if (r >= INF) {
            cout << "Alice\n";
            continue;
        }
        int d = dfs(r, -1, -INF).first;
//        DEBUG(dfs(r, -1).second + 1, r + 1)
//        DEBUG(d)
        cout << (da >= (d + 1) / 2 ? "Alice" : "Bob") << "\n";
    }

    return 0;
}