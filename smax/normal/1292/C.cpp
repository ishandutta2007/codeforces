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

int sz[3005][3005], par[3005][3005];
long long dp[3005][3005];
vector<int> adj[3005];

int dfs(int u, int root) {
    sz[root][u] = 1;
    for (int v : adj[u])
        if (v != par[root][u]) {
            par[root][v] = u;
            sz[root][u] += dfs(v, root);
        }
    return sz[root][u];
}

long long solve(int u, int v) {
    if (u == v)
        return 0;
    if (dp[u][v] != -1)
        return dp[u][v];
    return dp[u][v] = sz[u][v] * sz[v][u] + max(solve(par[v][u], v), solve(u, par[u][v]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i=0; i<n; i++) {
        par[i][i] = -1;
        dfs(i, i);
    }

    memset(dp, -1, sizeof(dp));
    long long ret = 0;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            ret = max(ret, solve(i, j));
    cout << ret << "\n";

    return 0;
}