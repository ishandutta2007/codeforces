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

    int n1, n2, m, q;
    cin >> n1 >> n2 >> m >> q;
    map<pair<int, int>, int> mp;
    Matching matching(n1, n2);
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        mp[{x, y}] = i + 1;
        matching.addEdge(x, y);
    }

    matching.solve();
    vector<bool> visL(n1 + 1), visR(n2 + 1);

    auto dfs = [&] (auto &self, int u) -> void {
        visL[u] = true;
        for (int v : matching.adj[u])
            if (v != matching.matchL[u] && !visR[v]) {
                visR[v] = true;
                if (matching.matchR[v] && !visL[matching.matchR[v]])
                    self(self, matching.matchR[v]);
            }
    };

    for (int u=1; u<=n1; u++)
        if (!matching.matchL[u])
            dfs(dfs, u);

    vector<int> mvc, edges;
    long long ret = 0;
    for (int i=1; i<=n1; i++)
        if (!visL[i]) {
            mvc.push_back(i);
            edges.push_back(mp[{i, matching.matchL[i]}]);
            ret += edges.back();
        }
    for (int i=1; i<=n2; i++)
        if (visR[i]) {
            mvc.push_back(-i);
            edges.push_back(mp[{matching.matchR[i], i}]);
            ret += edges.back();
        }

    for (int i=0; i<q; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            ret -= edges.back();
            cout << "1\n" << mvc.back() << "\n" << ret << endl;
            mvc.pop_back();
            edges.pop_back();
        } else {
            cout << edges.size() << "\n";
            for (int x : edges)
                cout << x << " ";
            cout << endl;
        }
    }

    return 0;
}