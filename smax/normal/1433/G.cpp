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

int n, m, k, x[1005], y[1005], w[1005], a[1005], b[1005], ans[1005];
vector<pair<int, int>> adj[1005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

vector<int> dijkstra(int s1, int s2) {
    vector<int> dist(n, INF);
    dist[s1] = dist[s2] = 0;
    pq.emplace(0, s1);
    pq.emplace(0, s2);
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

    cin >> n >> m >> k;
    for (int i=0; i<m; i++) {
        cin >> x[i] >> y[i] >> w[i];
        x[i]--, y[i]--;
        adj[x[i]].emplace_back(y[i], w[i]);
        adj[y[i]].emplace_back(x[i], w[i]);
    }
    long long ret = 0;
    for (int i=0; i<k; i++) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        vector<int> dist = dijkstra(a[i], a[i]);
        ans[i] = dist[b[i]];
        ret += ans[i];
    }

    for (int i=0; i<m; i++) {
        long long cur = 0;
        vector<int> dist = dijkstra(x[i], y[i]);
        for (int j=0; j<k; j++)
            cur += min(ans[j], dist[a[j]] + dist[b[j]]);
        ret = min(ret, cur);
    }
    cout << ret << "\n";

    return 0;
}