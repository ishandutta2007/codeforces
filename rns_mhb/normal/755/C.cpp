#include <bits/stdc++.h>
using namespace std;

#define N 10005

int n;
vector<int> v[N];
bool vis[N];

void dfs(int x) {
    vis[x] = 1;
    for (int i = 0; i < v[x].size(); i ++) {
        int u = v[x][i];
        if (vis[u]) continue;
        dfs(u);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        int x;
        scanf("%d", &x);
        if (x == i) continue;
        v[x].push_back(i);
        v[i].push_back(x);
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++) if (!vis[i]) ans ++, dfs(i);
    printf("%d\n", ans);
}