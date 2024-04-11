#include <bits/stdc++.h>
using namespace std;

#define N 100005

template <class T> bool chkmax(T &a, T b) { return a < b ? a = b, 1 : 0; }
template <class T> bool chkmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
const int inf = 1e9;
int n, timp;
vector<int> v[N];
bool vis[N];
int sz[N], ver[N], mx[N], ans[N];

void dfs(int x, int par = 0) {
    sz[x] = 1;
    mx[x] = 0;
    ver[timp++] = x;
    for (int i = 0; i < v[x].size(); i ++) {
        int y = v[x][i];
        if (y == par) continue;
        if (vis[y]) continue;
        dfs(y, x);
        sz[x] += sz[y];
        chkmax(mx[x], sz[y]);
    }
}

void solve(int x, int dep) {
    timp = 0;
    dfs(x);
    int mn = inf, rt;
    for (int i = 0; i < timp; i ++) {
        chkmax(mx[ver[i]], timp - sz[ver[i]]);
        if (chkmin(mn, mx[ver[i]])) rt = ver[i];
    }
    ans[rt] = dep;
    vis[rt] = 1;
    for (int i = 0; i < v[rt].size(); i ++) if (!vis[v[rt][i]]) solve(v[rt][i], dep + 1);
}

int main() {
    scanf("%d", &n);
    for (int i = 1, x, y; i < n; i ++) {
        scanf("%d %d", &x, &y);
        v[x].push_back(y), v[y].push_back(x);
    }
    solve(1, 0);
    for (int i = 1; i <= n; i ++) printf("%c ", 'A' + ans[i]);
    return 0;
}