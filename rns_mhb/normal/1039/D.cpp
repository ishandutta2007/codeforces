#include<bits/stdc++.h>
using namespace std;

#define N 100010

vector <int> adj[N], v;
int n, f[N], a[N], b[N], c[N];

void dfs(int x, int p) {
    v.push_back(x);
    int j = -1;
    for(int i = 0; i < adj[x].size(); i ++) {
        int y = adj[x][i];
        if(y == p) continue;
        f[y] = x;
        dfs(y, x);
    }
}

int calc(int k) {
    for(int i = 1; i <= n; i ++) a[i] = 0, b[i] = 0, c[i] = 0;
    for(int i = v.size() - 1; i >= 0; i --) {
        int x = v[i];
        int y = f[x];
        if(a[x] + b[x] + 1 >= k) a[x] = 0, b[x] = 0, c[x] ++;
        else a[x] ++;
        if(a[x] > b[y]) {
            b[y] = a[x];
            if(b[y] > a[y]) swap(b[y], a[y]);
        }
        c[y] += c[x];
    }
    return c[1];
}

int ans[N];

void solve(int l, int r) {
    if(ans[l] == -1) ans[l] = calc(l);
    if(ans[r] == -1) ans[r] = calc(r);
    if(ans[l] == ans[r]) {
        for(int i = l + 1; i < r; i ++) ans[i] = ans[r];
        return;
    }
    int mid = l + r >> 1;
    solve(l, mid);
    solve(mid + 1, r);
}

int main() {
    scanf("%d", &n);
    for(int i = 1, x, y; i < n; i ++) {
        scanf("%d%d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);
    memset(ans, -1, sizeof ans);
    solve(1, n);
    for(int i = 1; i <= n; i ++) printf("%d\n", ans[i]);
}