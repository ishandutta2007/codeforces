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

int dist[200000];
vector<int> adj[200000], path;

pair<int, int> dfs1(int u, int p, int d) {
    pair<int, int> ret(u, d);
    for (int v : adj[u])
        if (v != p) {
            auto p = dfs1(v, u, d + 1);
            if (p.second > ret.second)
                ret = p;
        }
    return ret;
}

bool dfs2(int u, int p, int t) {
    path.push_back(u);
    if (u == t)
        return true;
    bool ret = false;
    for (int v : adj[u])
        if (v != p)
            ret |= dfs2(v, u, t);
    if (!ret)
        path.pop_back();
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int a = dfs1(0, -1, 0).first;
    auto p = dfs1(a, -1, 0);
    int b = p.first, ret = p.second;

    dfs2(a, -1, b);
    queue<int> q;
    memset(dist, -1, sizeof(dist));
    for (int u : path) {
        dist[u] = 0;
        q.push(u);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
    }

    int c, mx = -1;
    for (int i=0; i<n; i++)
        if (i != a && i != b && dist[i] > mx) {
            c = i;
            mx = dist[i];
        }

    cout << ret + mx << "\n" << a + 1 << " " << b + 1 << " " << c + 1 << "\n";

    return 0;
}