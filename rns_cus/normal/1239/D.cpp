#include <bits/stdc++.h>
using namespace std;
#define N 1000100
int n, m, C, col[N], ord[N], ft;
bool vis[N];
vector <int> v[N], rv[N];
void init() {
    for (int i = 1; i <= n; i ++) v[i].clear(), rv[i].clear(), vis[i] = 0, col[i] = 0;
}
void dfs(int x) {
    vis[x] = 1;
    for (int i = 0; i < v[x].size(); i ++) if (!vis[v[x][i]]) dfs(v[x][i]);
    ord[ft--] = x;
}
void rdfs(int x) {
    col[x] = C;
    for (int i = 0; i < rv[x].size(); i ++) if (!col[rv[x][i]]) rdfs(rv[x][i]);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &n, &m);
        init();
        while (m --) {
            int x, y;
            scanf("%d %d", &x, &y);
            if (x == y) continue;
            v[x].push_back(y);
            rv[y].push_back(x);
        }
        ft = n;
        for (int i = 1; i <= n; i ++) if (!vis[i]) dfs(i);
        C = 0;
        for (int i = 1; i <= n; i ++) if (!col[ord[i]]) C ++, rdfs(ord[i]);
        if (C == 1) puts("No");
        else {
            puts("Yes");
            vector <int> jury, cat;
            for (int i = 1; i <= n; i ++) if (col[i] == C) jury.push_back(i); else cat.push_back(i);
            printf("%d %d\n", (int)jury.size(), (int)cat.size());
            for (auto x : jury) printf("%d ", x); puts("");
            for (auto x : cat) printf("%d ", x); puts("");
        }
    }
    return 0;
}