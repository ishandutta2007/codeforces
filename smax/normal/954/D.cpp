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

int n;
bool edge[1005][1005];
vector<int> adj[1005];

vector<int> bfs(int s) {
    vector<int> dist(n, INF);
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, s, t;
    cin >> n >> m >> s >> t;
    s--, t--;
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edge[u][v] = edge[v][u] = true;
    }

    vector<vector<int>> dist(n);
    for (int i=0; i<n; i++)
        dist[i] = bfs(i);

    int ret = 0;
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
            if (!edge[i][j] && min(dist[i][s] + dist[j][t], dist[i][t] + dist[j][s]) + 1 >= dist[s][t])
                ret++;
    cout << ret << "\n";

    return 0;
}