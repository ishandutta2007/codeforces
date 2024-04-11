#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int NICO = 100002;
int f[NICO][30], n, m;
int dep[NICO], lg[NICO];
int u, v, w;

vector<int> g[NICO];
void dfs(int x, int p) {
    f[x][0] = p;// cout << x << " : " << dep[x] << endl;
    for(int i=0;i<g[x].size();i++) {
        if(g[x][i] == p) continue;
        dep[g[x][i]] = dep[x] + 1;
        dfs(g[x][i], x);
    }
}
void init() {
    dep[1] = 0; f[1][0] = 1;
    dfs(1, 1);
    for(int i=1;i<20;i++)for(int j=1;j<=n;j++)f[j][i]=f[f[j][i-1]][i-1];

}
int lca(int x, int y) {
    //cout << x << " " << y << endl;
    if(dep[x] < dep[y]) swap(x, y);
    for(int i=19;i>=0;i--)if((dep[x]-dep[y]>>i)&1)x=f[x][i];
    if(x == y) return x;
    for(int k = 19; k >= 0; k --) {
        if(f[x][k] != f[y][k]) 
            x = f[x][k], y = f[y][k];// printf("(%d, %d)\n", x, y);
    }
    return f[x][0];
}

int cac(int u, int v, int w) {
    if(dep[lca(u, v)] == dep[lca(u, w)]) {
        return dep[u] + dep[lca(v, w)] - 2*dep[lca(u, v)];
    }
    return dep[u] - max(max(dep[lca(u, v)], dep[lca(u, w)]), dep[lca(v, w)]);
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for(int i=2;i<=n;i++) {
        cin >> u; g[i].push_back(u); g[u].push_back(i);
    }

    init();
  
    for(int i=1;i<=m;i++) {   
        cin >> u >> v >> w;
        cout << max(max(cac(u, v, w), cac(v, w, u)), cac(w, u, v)) + 1 << endl;
    }


}