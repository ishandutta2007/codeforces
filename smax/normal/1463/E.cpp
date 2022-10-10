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

const int MAXN = 3e5 + 5;

int p[MAXN], in[MAXN], par[MAXN], sz[MAXN], head[MAXN], tail[MAXN], nxt[MAXN];
bool vis[MAXN];
vector<int> adj[MAXN];

int find(int u) {
    return par[u] == u ? u : par[u] = find(par[u]);
}

bool unite(int x, int y) {
    int u = find(x), v = find(y);
    if (x != tail[u] || y != head[v] || u == v)
        return false;
    int nh = head[u], nt = tail[v];
    nxt[x] = y;
    if (sz[u] < sz[v])
        swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
    head[u] = nh;
    tail[u] = nt;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> edges;
    for (int i=0; i<n; i++) {
        cin >> p[i];
        if (--p[i] != -1)
            edges.emplace_back(p[i], i);
    }

    for (int i=0; i<n; i++) {
        par[i] = head[i] = tail[i] = i;
        sz[i] = 1;
        nxt[i] = -1;
    }

    for (int i=0; i<k; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (!unite(x, y)) {
            cout << "0\n";
            return 0;
        }
    }

    for (auto [u, v] : edges) {
        u = find(u);
        v = find(v);
        if (u != v) {
            adj[u].push_back(v);
            in[v]++;
        }
    }

    queue<int> q;
    for (int i=0; i<n; i++)
        if (i == par[i] && in[i] == 0)
            q.push(i);
    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : adj[u])
            if (--in[v] == 0)
                q.push(v);
    }

    vector<int> ret;
    for (int x : order) {
        int u = head[x];
        while (u != -1) {
            if (p[u] != -1 && !vis[p[u]]) {
                cout << "0\n";
                return 0;
            }
            vis[u] = true;
            ret.push_back(u);
            u = nxt[u];
        }
    }
    if ((int) ret.size() != n) {
        cout << "0\n";
        return 0;
    }

    for (int x : ret)
        cout << x + 1 << " ";
    cout << "\n";

    return 0;
}