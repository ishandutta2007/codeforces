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

struct Point {
    int x, y, i;
} pt[100005];
long long dist[100005];
vector<pair<int, int>> adj[100005];

void addEdge(int u, int v, int w) {
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, sx, sy, fx, fy;
    cin >> n >> m >> sx >> sy >> fx >> fy;
    for (int i=1; i<=m; i++) {
        cin >> pt[i].x >> pt[i].y;
        pt[i].i = i;
        addEdge(0, i, min(abs(sx - pt[i].x), abs(sy - pt[i].y)));
        addEdge(m + 1, i, abs(fx - pt[i].x) + abs(fy - pt[i].y));
    }

    addEdge(0, m + 1, abs(sx - fx) + abs(sy - fy));
    sort(pt + 1, pt + m + 1, [] (const Point &a, const Point &b) {
        if (a.x == b.x)
            return a.i < b.i;
        return a.x < b.x;
    });
    for (int i=1; i<m; i++)
        addEdge(pt[i].i, pt[i+1].i, pt[i+1].x - pt[i].x);
    sort(pt + 1, pt + m + 1, [] (const Point &a, const Point &b) {
        if (a.y == b.y)
            return a.i < b.i;
        return a.y < b.y;
    });
    for (int i=1; i<m; i++)
        addEdge(pt[i].i, pt[i+1].i, pt[i+1].y - pt[i].y);

    memset(dist, 127, sizeof(dist));
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[0] = 0;
    pq.emplace(0, 0);
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
    cout << dist[m+1] << "\n";

    return 0;
}