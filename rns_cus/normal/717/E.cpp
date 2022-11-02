#include <bits/stdc++.h>
using namespace std;

const int M = 1000001;

int c[M], d[M];
vector<int> v[M];
int fa[M];

void dfs(int u, int pa) {
    for(int i = 0; i < v[u].size(); i ++) {
        int x = v[u][i];
        if(x == pa) continue;
        fa[x] = u;
        dfs(x, u);
        d[u] ++;
    }
}

void DFS(int u, int pa) {
    int last;
    for(int i = 0; i < v[u].size(); i ++) {
        int x = v[u][i];
        if(x == pa) continue;
        last = x;
        if(d[x] == 0) {
            if(c[x] == 1) continue;
            else printf("%d %d ", x, u), c[u] = -c[u];
            continue;
        }
        c[x] = -c[x];
        printf("%d ", x);
        DFS(x, u);
        printf("%d ", u);
        c[u] = -c[u];
    }
    if(c[u] == -1 && u != 1) {
        c[u] = 1;
        c[fa[u]] = -c[fa[u]];
        printf("%d %d ", fa[u], u);
    }
}

int main() {
    ///freopen("e.in", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &c[i]);
    for(int i = 1; i < n; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 0);
    printf("1 ");
    DFS(1, 0);
    if(c[1] == -1) {
        printf("%d %d %d\n", v[1][0], 1, v[1][0]);
    }
}