#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

typedef tuple<long long, int, int> node;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<vector<long long>> dist(n, vector<long long>(51, INF));
    priority_queue<node, vector<node>, greater<node>> pq;
    pq.emplace(dist[0][0] = 0, 0, 0);
    while (!pq.empty()) {
        auto [d, u, w] = pq.top();
        pq.pop();
        if (d > dist[u][w])
            continue;
        for (auto [v, nw] : adj[u])
            if (d + (w == 0 ? 0 : (w + nw) * (w + nw)) < dist[v][w == 0 ? nw : 0])
                pq.emplace(dist[v][w == 0 ? nw : 0] = d + (w == 0 ? 0 : (w + nw) * (w + nw)), v, w == 0 ? nw : 0);
    }

    for (int i=0; i<n; i++)
        cout << (dist[i][0] == INF ? -1 : dist[i][0]) << " ";
    cout << "\n";

    return 0;
}