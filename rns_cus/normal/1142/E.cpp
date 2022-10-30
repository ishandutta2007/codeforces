#include <bits/stdc++.h>
using namespace std;
#define N 100100
int n, m, C, col[N], ord[N], ft, uu[N], vv[N], indeg[N];
bool vis[N];
vector <int> v[N], rv[N], adj[N];
stack <int> stk[N];
void init() {
    for (int i = 1; i <= n; i ++) v[i].clear(), rv[i].clear(), col[i] = 0;
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
    scanf("%d %d", &n, &m);
    init();
    for (int i = 0; i < m; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        rv[y].push_back(x);
        uu[i] = x, vv[i] = y;
    }
    ft = n;
    for (int i = 1; i <= n; i ++) if (!vis[i]) dfs(i);
    C = 0;
    for (int i = 1; i <= n; i ++) if (!col[ord[i]]) C ++, rdfs(ord[i]);
    for (int i = 1; i <= n; i ++) stk[col[i]].push(i);
    for (int i = 0; i < m; i ++) {
        int x = col[uu[i]], y = col[vv[i]];
        if (x != y) adj[x].push_back(y), indeg[y] ++;
    }
    vector <int> top;
    for (int i = 1; i <= C; i ++) if (!indeg[i]) top.push_back(i);
    while (1) {
        int sz = top.size();
        if (sz == 1) break;
        int x = stk[top[sz-1]].top(), y = stk[top[sz-2]].top();
        printf("? %d %d\n", x, y);
        fflush(stdout);
        int dir;
        scanf("%d", &dir);
        if (dir) {
            int k = top[sz-2];
            stk[k].pop();
            if (stk[k].size() == 0) {
                swap(top[sz-2], top[sz-1]);
                top.pop_back();
                for (auto v : adj[k]) {
                    indeg[v] --;
                    if (!indeg[v]) top.push_back(v);
                }
            }
        }
        else {
            int k = top[sz-1];
            stk[k].pop();
            if (stk[k].size() == 0) {
                top.pop_back();
                for (auto v : adj[k]) {
                    indeg[v] --;
                    if (!indeg[v]) top.push_back(v);
                }
            }
        }
    }
    printf("! %d\n", stk[top[0]].top());
    fflush(stdout);

    return 0;
}