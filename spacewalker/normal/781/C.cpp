#include <bits/stdc++.h>

using namespace std;

vector<int> trav;
vector<bool> vis;

void makeTrav(int v, vector<vector<int>> &graph) {
    if (vis[v]) return;
    vis[v] = true;
    trav.push_back(v);
    for (int nxt : graph[v]) {
        if (vis[nxt]) continue;
        makeTrav(nxt, graph);
        trav.push_back(v);
    }
}

int main() {
    int n, m, k; scanf("%d %d %d", &n, &m, &k);
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v; scanf("%d %d", &u, &v);
        graph[--u].push_back(--v);
        graph[v].push_back(u);
    }
    vis.assign(n, false);
    makeTrav(0, graph);
    int tlen = trav.size();
    vector<int> lengths(k, tlen / k);
    for (int i = 0; i < (tlen % k); ++i) ++lengths[i];
    for (int cln = 0, cstart = 0; cln < k; cstart += lengths[cln++]) {
        printf("%d", lengths[cln]);
        for (int i = 0; i < lengths[cln]; ++i) printf(" %d", trav[i + cstart] + 1);
        printf("\n");
    }
    return 0;
}