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

int color[500005], dist[500005];
vector<pair<int, int>> adj[500005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        u--, v--;
        adj[v].emplace_back(u, t);
    }

    memset(color, -1, sizeof(color));
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    dist[n-1] = 0;
    q.push(n-1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &e : adj[u]) {
            if (color[e.first] == -1)
                color[e.first] = !e.second;
            else if (color[e.first] == e.second && dist[e.first] == -1) {
                dist[e.first] = dist[u] + 1;
                q.push(e.first);
            }
        }
    }

    cout << dist[0] << "\n";
    for (int i=0; i<n; i++)
        cout << (color[i] == -1 || color[i]);
    cout << "\n";

    return 0;
}