#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#include "queue"
#define all(x) (x).begin(), (x).end()

using namespace std;
vector<vector<int>> g;
vector<int> fnd(int v) {
    int n = g.size();
    vector<int> dst(n, -1);
    queue<pair<int, int>> que;
    que.push({v, 0});
    while (!que.empty()) {
        int v1 = que.front().first;
        int val = que.front().second;
        que.pop();
        if (dst[v1] != -1)
            continue;
        dst[v1] = val;
        for (auto u : g[v1]) {
            que.push({u, val + 1});
        }
    }
    return dst;
}
vector<vector<int>> dist;
vector<pair<int, int>> edges;
bool dfscyc(int v, int p, vector<int> &seen, vector<vector<int>> &g2) {
    if (seen[v])
        return 0;
    seen[v] = 1;
    for (auto u : g2[v]) {
        if (u == p)
            continue;
        if (dfscyc(u, v, seen, g2) == 0)
            return 0;
    }
    return 1;
}
bool dfs(int t, int v, int p, vector<int> &add, vector<vector<int>> &g2) {
    if (v == t)
        return 1;
    for (auto u : g2[v]) {
        if (u == p)
            continue;
        add.push_back(u);
        if (dfs(t, u, v, add, g2)) {
            return 1;
        }
        add.pop_back();
    }
    return 0;
}
long long solve(int v, int u) {
    int n = g.size();
    vector<vector<int>> g1(n);
    vector<int> g2(n);
    //cerr << "V U" << v << ' ' << u << endl;
    for (auto [a1, a2] : edges) {
        if (abs(dist[v][a1] - dist[v][a2]) == 1 and abs(dist[u][a2] - dist[u][a1]) == 1) {
            if (dist[v][a1] - dist[v][a2] + dist[u][a1] - dist[u][a2] == 2) {
                g2[a1]++;
            }
            if (dist[v][a1] - dist[v][a2] + dist[u][a1] - dist[u][a2] == -2) {
                g2[a2]++;
            }
            if (dist[v][a1] - dist[v][a2] + dist[u][a1] - dist[u][a2] == 0) {
                g1[a1].push_back(a2);
                g1[a2].push_back(a1);
               // cerr << a1 << ' ' << a2 << endl;
            }
        }
    }
    vector<int> elems = {v};
    if (v != u) {
        vector<int> seen(n);
        bool a = dfscyc(v, -1, seen,g1);
        if (a == 0)
            return 0;
        a = dfs(u, v, -1, elems,g1);
        if (a == 0)
            return 0;
    }
   // return 179;
    vector<int> seen2(n);
    for (auto i : elems) {
        seen2[i] = 1;
    }
    long long res = 1;
    for (int i = 0; i < n; ++i) {
        if (seen2[i] == 0) {
            res *= g2[i];
            res %= 998244353;
        }
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    g.assign(n, {});
    dist.assign(n, {});
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        edges.push_back({a, b});
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        dist[i] = fnd(i);
    }
    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            ans[i][j] = ans[j][i] = solve(i, j);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}