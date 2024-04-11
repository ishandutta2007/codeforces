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

const long long INF = 1e18;

int n, m;
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

vector<long long> dijkstra(int s, const vector<vector<pair<int, int>>> &adj) {
    vector<long long> dist(n, INF);
    dist[s] = 0;
    pq.emplace(0, s);
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u])
            continue;
        for (auto [v, w] : adj[u])
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    cin >> n >> m >> x >> y;
    x--, y--;
    vector<vector<pair<int, int>>> adj(n);
    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    vector<int> t(n), c(n);
    for (int i=0; i<n; i++)
        cin >> t[i] >> c[i];

    vector<vector<long long>> dist(n);
    for (int i=0; i<n; i++)
        dist[i] = dijkstra(i, adj);

    vector<vector<pair<int, int>>> nadj(n);
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (i != j && t[i] >= dist[i][j])
                nadj[i].emplace_back(j, c[i]);

    vector<long long> ret = dijkstra(x, nadj);
    cout << (ret[y] == INF ? -1 : ret[y]) << "\n";

    return 0;
}