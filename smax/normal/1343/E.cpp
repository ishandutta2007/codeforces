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

int p[200000], distA[200000], distB[200000], distC[200000];
long long pref[200001];
vector<int> adj[200000];

void bfs(int s, int *dist) {
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, m, a, b, c;
        cin >> n >> m >> a >> b >> c;
        a--, b--, c--;

        memset(distA, 127, sizeof(int) * n);
        memset(distB, 127, sizeof(int) * n);
        memset(distC, 127, sizeof(int) * n);
        for (int i=0; i<n; i++)
            adj[i].clear();

        for (int i=0; i<m; i++)
            cin >> p[i];
        for (int i=0; i<m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        sort(p, p + m);
        for (int i=0; i<m; i++)
            pref[i+1] = pref[i] + p[i];

        bfs(a, distA);
        bfs(b, distB);
        bfs(c, distC);

        long long ret = LLONG_MAX;
        for (int i=0; i<n; i++)
            if (distA[i] + distB[i] + distC[i] <= m)
                ret = min(ret, pref[distA[i] + distB[i] + distC[i]] + pref[distB[i]]);

        cout << ret << "\n";
    }

    return 0;
}