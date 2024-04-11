#include <bits/stdc++.h>
using namespace std;

#define N 1005

int n, m, k, ans, mx;
vector<int> v[N], w[N];
int t;
int sz[N], rt[N];
bool vis[N];
bool con[N][N];

void dfs(int x, int root) {
    vis[x] = 1;
    w[root].push_back(x);
    for (int i = 0; i < v[x].size(); i ++) {
        int y = v[x][i];
        if (vis[y]) continue;
        dfs(y, root);
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < k; i ++) {
        scanf("%d", &rt[i]);
    }
    for (int i = 0; i < m; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
        con[x][y] = con[y][x] = 1;
    }
    for (int i = 0; i < k; i ++) {
        dfs(rt[i], i);
        sz[i] = w[i].size();
        mx = max(mx, sz[i]);
        for (int j = 0; j < w[i].size(); j ++)
        for (int l = j + 1; l < w[i].size(); l ++) {
            int jj = w[i][j], ll = w[i][l];
            if (!con[jj][ll]) ans ++;
        }
    }
    int rest = 0;
    for (int i = 1; i <= n; i ++) if (!vis[i]) rest ++;
    int cnt = k;
    for (int i = 1; i <= n; i ++) {
        if (vis[i]) continue;
        rt[cnt++] = i;
        dfs(i, cnt-1);
        sz[cnt-1] = w[cnt-1].size();
        for (int j = 0; j < w[cnt-1].size(); j ++)
        for (int l = j + 1; l < w[cnt-1].size(); l ++) {
            int jj = w[cnt-1][j], ll = w[cnt-1][l];
            if (!con[jj][ll]) ans ++;
        }
    }
    ans += rest * mx;
    for (int i = k; i < cnt; i ++)
    for (int j = i + 1; j < cnt; j ++) ans += sz[i] * sz[j];
    printf("%d\n", ans);
}