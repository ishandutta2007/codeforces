#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

long long dist[300000];
bool visited[300000];
array<long long, 3> pred[300000];
vector<array<int, 3>> adj[300000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u-1].push_back({v-1, w, i+1});
        adj[v-1].push_back({u-1, w, i+1});
    }
    int u;
    cin >> u;
    u--;

    memset(dist, 127, sizeof(dist));
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[u] = 0;
    pq.push({0, u});
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        if (p.first > dist[p.second])
            continue;

        for (auto e : adj[p.second])
            if (p.first + e[1] < dist[e[0]] || (p.first + e[1] == dist[e[0]] && e[1] < pred[e[0]][0])) {
                dist[e[0]] = p.first + e[1];
                pred[e[0]] = {e[1], e[2], p.second};
                pq.push({dist[e[0]], e[0]});
            }
    }

    long long ret = 0;
    vector<int> edges;
    for (int i=0; i<n; i++) {
        int v = i;
        while (!visited[v]) {
            visited[v] = true;
            DEBUG(v, pred[v])
            if (pred[v][0] != 0) {
                ret += pred[v][0];
                edges.push_back(pred[v][1]);
                v = pred[v][2];
            }
        }
    }

    cout << ret << "\n";
    for (int i : edges)
        cout << i << " ";
    cout << "\n";

    return 0;
}