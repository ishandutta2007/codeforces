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

int p[100000], h[100000], sz[100000], numGood[100000];
vector<int> adj[100000];

bool dfs(int u, int par) {
    sz[u] = p[u];
    for (int v : adj[u])
        if (v != par) {
            if (!dfs(v, u))
                return false;
            sz[u] += sz[v];
        }
    if ((h[u] + sz[u]) % 2)
        return false;
    numGood[u] = (h[u] + sz[u]) / 2;
    if (numGood[u] < 0 || numGood[u] > sz[u])
        return false;
    int tot = 0;
    for (int v : adj[u])
        if (v != par)
            tot += numGood[v];
    return tot <= numGood[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i=0; i<n; i++) {
            cin >> p[i];
            adj[i].clear();
        }
        for (int i=0; i<n; i++)
            cin >> h[i];
        for (int i=0; i<n-1; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        cout << (dfs(0, -1) ? "YES" : "NO") << "\n";
    }

    return 0;
}