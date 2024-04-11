#include<bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

#define N 200010

vector <pii> adj[N];
int n, sz[N];
long long G, B;

void dfs(int x, int p) {
    sz[x] = 1;
    for(int i = 0; i < adj[x].size(); i ++) {
        int y = adj[x][i].first, z = adj[x][i].second;
        if(y == p) continue;
        dfs(y, x);
        if(sz[y] & 1) G += z;
        B += 1ll * z * min(sz[y], n-sz[y]);
        sz[x] += sz[y];
    }
}

void solve() {
    scanf("%d", &n);
    n <<= 1;
    for(int i = 1; i <= n; i ++) adj[i].clear();
    for(int i = 1, x, y, z; i < n; i ++) {
        scanf("%d%d%d", &x, &y, &z);
        adj[x].push_back(pii(y, z));
        adj[y].push_back(pii(x, z));
    }
    G = B = 0;
    dfs(1, 0);
    cout << G << ' ' << B << endl;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t --) solve();
}