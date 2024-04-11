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

const int MOD = 1e9 + 7;

int n, sz[100005];
long long p[100005], wt[100005];

struct Edge {
    int u, v, idx;

    bool operator < (const Edge &other) const {
        if (wt[idx] == wt[other.idx])
            return idx < other.idx;
        return wt[idx] > wt[other.idx];
    }
} edges[100005];
vector<Edge> adj[100005];

int dfs(int u, int p) {
    sz[u] = 1;
    for (Edge &e : adj[u]) {
        int v = (u == e.u ? e.v : e.u);
        if (v != p) {
            sz[u] += dfs(v, u);
            wt[e.idx] = 1LL * sz[v] * (n - sz[v]);
        }
    }
    return sz[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i<n; i++)
            adj[i].clear();
        for (int i=0; i<n-1; i++) {
            cin >> edges[i].u >> edges[i].v;
            edges[i].u--, edges[i].v--;
            edges[i].idx = i;
            adj[edges[i].u].push_back(edges[i]);
            adj[edges[i].v].push_back(edges[i]);
        }
        int m;
        cin >> m;
        for (int i=0; i<m; i++)
            cin >> p[i];
        for (int i=m; i<n-1; i++)
            p[i] = 1;

//        for (int i=0; i<n-1; i++)
//            DEBUG(i, p[i])

        sort(p, p + max(n - 1, m));
        if (m > n - 1) {
            int idx = m - 2;
            while (idx >= n - 2) {
                p[idx] = p[idx] * p[idx + 1] % MOD;
                idx--;
            }
        }

        dfs(0, -1);

        sort(edges, edges + n - 1);
        long long ret = 0;
        for (int i=0, j=n-2; i<n-1; i++, j--) {
//            DEBUG(wt[edges[i].idx], p[j])
            ret += wt[edges[i].idx] % MOD * p[j] % MOD;
            if (ret >= MOD) ret -= MOD;
        }
        cout << ret << "\n";
    }

    return 0;
}