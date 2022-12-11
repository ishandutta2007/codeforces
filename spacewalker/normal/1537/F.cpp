#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll diffToParent(int v, int cColor, vector<int> &color, vector<int> &src, vector<int> &dst, vector<vector<int>> &graph) {
    if (color[v] != 0) return 0;
    color[v] = cColor;
    ll cval = src[v];
    for (int u : graph[v]) {
        cval += diffToParent(u, -cColor, color, src, dst, graph);
    }
    return dst[v] - cval;
}

bool solve() {
    int n, m; scanf("%d %d", &n, &m);
    vector<int> src(n), dst(n);
    for (int i = 0; i < n; ++i) scanf("%d", &src[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &dst[i]);
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int x, y; scanf("%d %d", &x, &y); --x; --y;
        graph[x].emplace_back(y);
        graph[y].emplace_back(x);
    }
    ll sumBefore = 0, sumAfter = 0;
    for (int v : src) sumBefore += v;
    for (int v : dst) sumAfter += v;
    if ((sumBefore - sumAfter) % 2 != 0) return false;
    vector<int> colors(n, 0);
    ll allDiff = diffToParent(0, 1, colors, src, dst, graph);
    bool isBipartite = true;
    for (int i = 0; i < n; ++i) for (int j : graph[i])
        if (colors[i] == colors[j]) isBipartite = false;
    if (!isBipartite) return true;
    else return allDiff == 0;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) printf("%s\n", solve() ? "YES" : "NO");
}