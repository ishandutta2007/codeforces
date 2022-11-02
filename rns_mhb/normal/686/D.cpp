#include <bits/stdc++.h>
using namespace std;
#define N 300010

int n, q, wgh[N], fc[N], cen[N], p[N];
vector<int> adj[N];

int calc_dfs(int u) {
    wgh[u] = 1;
    for (int i = 0; i < adj[u].size(); i ++) wgh[u] += calc_dfs(adj[u][i]);
    return wgh[u];
}

void first_child() {
    for (int i = 1, mx; i <= n; i ++)
        if (!adj[i].empty()) {
            mx = 0;
            for (int k = 0; k < adj[i].size(); k ++)
                if (wgh[adj[i][k]] > mx) {
                    fc[i] = adj[i][k];
                    mx = wgh[fc[i]];
                }
        }
}

void find_dfs(int u) {
    for (int i = 0; i < adj[u].size(); i ++) find_dfs(adj[u][i]);
    if (!fc[u]) cen[u] = u;
    else {
        int v = fc[u];
        v = cen[v];
        while (wgh[v] * 2 < wgh[u]) v = p[v];
        cen[u] = v;
    }
}

int main(){
    scanf("%d %d", &n, &q);
    for (int i = 2; i <= n; i ++) {
        scanf("%d", p + i);
        adj[p[i]].push_back(i);
    }//input
    calc_dfs(1);//calculate weight of nodes
    first_child();//find heaviest child
    find_dfs(1);//find centroid
    int v;
    while (q --) {
        scanf("%d", &v);
        printf("%d\n", cen[v]);
    }//output for each query
}