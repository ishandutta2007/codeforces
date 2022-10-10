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

const int MAXN = 2e5 + 5;

struct Node {
    int u, mn, mx;
    long long d;

    Node(int _u, int _mn, int _mx, long long _d) : u(_u), mn(_mn), mx(_mx), d(_d) {}

    bool operator < (const Node &other) const {
        return tie(d, u, mn, mx) > tie(other.d, other.u, other.mn, other.mx);
    }
};

long long dist[MAXN][2][2];
vector<pair<int, int>> adj[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    memset(dist, 127, sizeof(dist));
    priority_queue<Node> pq;
    dist[0][0][0] = 0;
    pq.emplace(0, 0, 0, 0);
    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();
        if (cur.d > dist[cur.u][cur.mn][cur.mx])
            continue;
        for (auto [v, w] : adj[cur.u]) {
            if (cur.d + w < dist[v][cur.mn][cur.mx])
                pq.emplace(v, cur.mn, cur.mx, dist[v][cur.mn][cur.mx] = cur.d + w);
            if (!cur.mn && cur.d + 2 * w < dist[v][1][cur.mx])
                pq.emplace(v, 1, cur.mx, dist[v][1][cur.mx] = cur.d + 2 * w);
            if (!cur.mx && cur.d < dist[v][cur.mn][1])
                pq.emplace(v, cur.mn, 1, dist[v][cur.mn][1] = cur.d);
        }
    }

    for (int i=1; i<n; i++)
        cout << min(dist[i][0][0], dist[i][1][1]) << " ";
    cout << "\n";

    return 0;
}