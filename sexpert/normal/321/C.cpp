#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int sz[MAXN], dead[MAXN];
vector<int> adj[MAXN];
char rk[MAXN];

int getsz(int u, int p = 0) {
    sz[u] = 1;
    for(auto v : adj[u]) {
        if(!dead[v] && v != p) sz[u] += getsz(v, u);
    }
    return sz[u];
}

int getcentroid(int u, int p, int treesz) {
    for(auto v : adj[u]) {
        if(v != p && !dead[v] && 2*sz[v] > treesz)
            return getcentroid(v, u, treesz);
    }
    return u;
}

void cd(int u, char c) {
    getsz(u);
    int cen = getcentroid(u, u, sz[u]);
    rk[cen] = c;
    dead[cen] = 1;
    for(auto v : adj[cen])
        if(!dead[v]) cd(v, c + 1);
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cd(1, 'A');
    for(int i = 1; i <= n; i++)
        cout << rk[i] << " ";
    cout << endl;
}