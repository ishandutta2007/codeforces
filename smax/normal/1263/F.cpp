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

template<typename T>
struct RMQ {
    vector<vector<T>> spt;

    RMQ(const vector<T> &a) : spt(1, a) {
        int n = (int) a.size();
        for (int j=1; 1<<j<=n; j++) {
            spt.emplace_back(n - (1 << j) + 1);
            for (int i=0; i+(1<<j)<=n; i++)
                spt[j][i] = min(spt[j-1][i], spt[j-1][i+(1<<(j-1))]);
        }
    }

    T query(int i, int j) {
        int k = __lg(j - i + 1);
        return min(spt[k][i], spt[k][j-(1<<k)+1]);
    }
};

struct LCA {
    vector<int> pos, depth, path, ret;
    vector<vector<int>> adj;
    RMQ<int> rmq;

    LCA(int n) : pos(n), depth(n), adj(n), rmq({}) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void init(int r = 0) {
        dfs(r, -1);
        rmq = RMQ<int>(ret);
    }

    void dfs(int u, int p) {
        pos[u] = (int) path.size();
        path.push_back(u);
        ret.push_back(pos[u]);
        for (int v : adj[u])
            if (v != p) {
                depth[v] = depth[u] + 1;
                dfs(v, u);
                path.push_back(u);
                ret.push_back(pos[u]);
            }
    }

    int lca(int u, int v) {
        if (pos[u] > pos[v])
            swap(u, v);
        return path[rmq.query(pos[u], pos[v])];
    }

    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a;
    cin >> a;
    LCA top(a);
    for (int i=1; i<a; i++) {
        int p;
        cin >> p;
        p--;
        top.addEdge(p, i);
    }
    vector<int> x(n);
    for (int i=0; i<n; i++) {
        cin >> x[i];
        x[i]--;
    }
    int b;
    cin >> b;
    LCA bot(b);
    for (int i=1; i<b; i++) {
        int q;
        cin >> q;
        q--;
        bot.addEdge(q, i);
    }
    vector<int> y(n);
    for (int i=0; i<n; i++) {
        cin >> y[i];
        y[i]--;
    }

    top.init();
    bot.init();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    auto solve = [&] (auto &self, int u, int v) -> int {
        int nxt = max(u, v);
        if (nxt == n)
            return 0;
        int &ret = dp[u][v];
        if (ret != -1)
            return ret;
        // take top
        ret = self(self, nxt + 1, v) + (u == 0 ? top.depth[x[nxt]] : top.dist(top.lca(x[u-1], x[nxt]), x[nxt]));
        // take bottom
        ret = min(ret, self(self, u, nxt + 1) + (v == 0 ? bot.depth[y[nxt]] : bot.dist(bot.lca(y[v-1], y[nxt]), y[nxt])));
        return ret;
    };

    cout << a + b - 2 - solve(solve, 0, 0) << "\n";

    return 0;
}