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

#define MAXN 100005
#define LOG 20

int sz[MAXN], par[MAXN], dist[LOG][MAXN], lg[MAXN];
bool visited[MAXN];
vector<int> adj[MAXN];

int dfsSz(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u])
        if (v != p && !visited[v])
            sz[u] += dfsSz(v, u);
    return sz[u];
}

int dfsCentroid(int u, int p, int s) {
    for (int v : adj[u])
        if (v != p && !visited[v] && sz[v] > s / 2)
            return dfsCentroid(v, u, s);
    return u;
}

void dfsCalc(int u, int p, int l) {
    for (int v : adj[u])
        if (v != p && !visited[v]) {
            dist[l][v] = dist[l][u] + 1;
            dfsCalc(v, u, l);
        }
}

void dfsMain(int u, int p, int l) {
    u = dfsCentroid(u, -1, dfsSz(u, -1));
    par[u] = p;
    lg[u] = l;
    dfsCalc(u, -1, l);
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v])
            dfsMain(v, u, l + 1);
}

int ans[MAXN];

void update(int u) {
    int v = u;
    while (v != -1) {
        ans[v] = min(ans[v], dist[lg[v]][u]);
        v = par[v];
    }
}

int query(int u) {
    int ret = INT_MAX, v = u;
    while (v != -1) {
        ret = min(ret, ans[v] + dist[lg[v]][u]);
        v = par[v];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfsMain(0, -1, 0);
    memset(ans, 127, sizeof(ans));
    update(0);

    for (int i=0; i<m; i++) {
        int t, v;
        cin >> t >> v;
        v--;
        if (t == 1)
            update(v);
        else
            cout << query(v) << "\n";
    }

    return 0;
}