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

int to[200000];
bool in[200000], out[200000], vis[200000];
vector<pair<int, int>> adj[200000];

void dfs(int u) {
    if (vis[u])
        return;
    vis[u] = true;
    assert(in[u] || out[u]);
    for (auto &e : adj[u]) {
        if (to[e.second] == -1) {
            if (in[u]) {
                to[e.second] = u;
                out[e.first] = true;
            } else {
                to[e.second] = e.first;
                in[e.first] = true;
            }
        }
        dfs(e.first);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
        edges.emplace_back(u, v);
    }

    // case 1: node 0 is in
    memset(to, -1, sizeof(to));
    in[0] = true;
    for (auto &e : adj[0]) {
        to[e.second] = 0;
        out[e.first] = true;
    }
    dfs(0);
    bool ok = true;
    for (int i=0; i<n; i++)
        if (in[i] && out[i]) {
            ok = false;
            break;
        }

    if (ok) {
        cout << "YES\n";
        for (int i=0; i<m; i++)
            cout << (to[i] == edges[i].first);
        cout << "\n";
        return 0;
    }

    memset(to, -1, sizeof(to));
    memset(in, false, sizeof(in));
    memset(out, false, sizeof(out));
    memset(vis, false, sizeof(vis));
    out[0] = true;
    for (auto &e : adj[0]) {
        to[e.second] = e.first;
        in[e.first] = true;
    }
    dfs(0);
    ok = true;
    for (int i=0; i<n; i++)
        if (in[i] && out[i]) {
            ok = false;
            break;
        }

    if (ok) {
        cout << "YES\n";
        for (int i=0; i<m; i++)
            cout << (to[i] == edges[i].first);
        cout << "\n";
        return 0;
    }
    cout << "NO\n";

    return 0;
}