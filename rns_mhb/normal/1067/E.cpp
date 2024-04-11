#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;

#define N 500010

vector <int> adj[N];
int n, pw[N], sz[N], a[N], b[N];

void dfs(int x, int p) {
    sz[x] = 1, b[x] = 1;
    for(int i = 0; i < adj[x].size(); i ++) {
        int y = adj[x][i];
        if(y == p) continue;
        dfs(y, x);
        sz[x] += sz[y];
        b[x] = 1ll * b[x] * (pw[sz[y]-1] + b[y]) % mod;
    }
    b[x] = pw[sz[x]-1] - b[x];
    if(b[x] < 0) b[x] += mod;
}

int main() {
    pw[0] = 1;
    for(int i = 1; i < N; i ++) pw[i] = pw[i-1] * 2 % mod;
    scanf("%d", &n);
    for(int i = 1, x, y; i < n; i ++) {
        scanf("%d%d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);
    int ans = 0;
    for(int i = 1; i <= n; i ++) ans = (ans + 2ll * b[i] * pw[n-sz[i]]) % mod;
    printf("%d\n", ans);
}