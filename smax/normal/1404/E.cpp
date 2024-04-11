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
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

struct Matching {
    int n, m;
    vector<int> matchL, matchR, dist;
    vector<vector<int>> adj;

    Matching(int _n, int _m) : n(_n), m(_m), matchL(n + 1), matchR(m + 1), dist(n + 1), adj(n + 1) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    bool bfs() {
        queue<int> q;
        for (int u=1; u<=n; u++) {
            if (!matchL[u]) {
                dist[u] = 0;
                q.push(u);
            } else {
                dist[u] = INT_MAX;
            }
        }
        dist[0] = INT_MAX;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (dist[u] < dist[0])
                for (int v : adj[u])
                    if (dist[matchR[v]] == INT_MAX) {
                        dist[matchR[v]] = dist[u] + 1;
                        q.push(matchR[v]);
                    }
        }
        return dist[0] != INT_MAX;
    }

    bool dfs(int u) {
        if (u != 0) {
            for (int v : adj[u])
                if (dist[matchR[v]] == dist[u] + 1 && dfs(matchR[v])) {
                    matchL[u] = v;
                    matchR[v] = u;
                    return true;
                }
            dist[u] = INT_MAX;
            return false;
        }
        return true;
    }

    int solve() {
        int ret = 0;
        while (bfs())
            for (int u=1; u<=n; u++)
                if (!matchL[u] && dfs(u))
                    ret++;
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (string &s : grid)
        cin >> s;

    auto encode = [&] (int r, int c) -> int {
        return r * m + c + 1;
    };

    int ret = 0;
    Matching matching(n * m, n * m);
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (grid[i][j] == '#') {
                ret++;
                if (i + 1 < n && grid[i+1][j] == '#') {
                    ret--;
                    if (j > 0) {
                        if (grid[i][j-1] == '#')
                            matching.addEdge(encode(i, j), encode(i, j - 1));
                        if (grid[i+1][j-1] == '#')
                            matching.addEdge(encode(i, j), encode(i + 1, j - 1));
                    }
                    if (j + 1 < m) {
                        if (grid[i][j+1] == '#')
                            matching.addEdge(encode(i, j), encode(i, j));
                        if (grid[i+1][j+1] == '#')
                            matching.addEdge(encode(i, j), encode(i + 1, j));
                    }
                }
                if (j + 1 < m && grid[i][j+1] == '#')
                    ret--;
            }
    cout << ret + matching.solve() << "\n";

    return 0;
}