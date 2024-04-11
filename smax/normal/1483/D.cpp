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

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> edge(n, vector<int>(n));
    vector<vector<long long>> dist(n, vector<long long>(n, INF));
    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edge[u][v] = edge[v][u] = dist[u][v] = dist[v][u] = w;
    }

    for (int i=0; i<n; i++)
        dist[i][i] = 0;
    for (int k=0; k<n; k++)
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int q;
    cin >> q;
    vector<vector<int>> queries(n, vector<int>(n));
    for (int i=0; i<q; i++) {
        int x, y, l;
        cin >> x >> y >> l;
        x--, y--;
        queries[x][y] = queries[y][x] = l;
    }

    vector<vector<bool>> useful(n, vector<bool>(n));
    for (int i=0; i<n; i++)
        for (int u=0; u<n; u++) {
            long long mx = -INF;
            for (int v=0; v<n; v++)
                mx = max(mx, queries[i][v] - dist[u][v]);
            for (int v=0; v<n; v++)
                if (edge[u][v] && dist[i][v] + edge[u][v] <= mx)
                    useful[u][v] = useful[v][u] = true;
        }

    int ret = 0;
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
            ret += useful[i][j];
    cout << ret << "\n";

    return 0;
}