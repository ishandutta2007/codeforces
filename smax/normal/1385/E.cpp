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

#define MAXN 200005

int indegree[MAXN], order[MAXN];
vector<int> adj[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        memset(indegree, 0, sizeof(int) * n);
        for (int i=0; i<n; i++)
            adj[i].clear();
        vector<array<int, 3>> edges;
        for (int i=0; i<m; i++) {
            int t, x, y;
            cin >> t >> x >> y;
            x--, y--;
            if (t == 1) {
                adj[x].push_back(y);
                indegree[y]++;
            }
            edges.push_back({t, x, y});
        }

        queue<int> q;
        for (int i=0; i<n; i++)
            if (indegree[i] == 0)
                q.push(i);

        int cnt = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            order[u] = cnt++;
            for (int v : adj[u])
                if (--indegree[v] == 0)
                    q.push(v);
        }
        if (cnt < n) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for (auto &e : edges) {
            if (e[0] == 1 || (e[0] == 0 && order[e[1]] < order[e[2]]))
                cout << e[1] + 1 << " " << e[2] + 1 << "\n";
            else
                cout << e[2] + 1 << " " << e[1] + 1 << "\n";
        }
    }

    return 0;
}