#include <iostream>
#include <vector>
using namespace std;
const int N = 102;
int n, m;
int u, v, w, col[N], vis[N], T;
vector< pair<int, int> > g[N];
vector<int> upd;
bool dfs(int x, int c) {
    if (vis[x]) return col[x] == c;
    upd.push_back(x);
    vis[x] = 1, col[x] = c;
    for (int i = 0; i < g[x].size(); i ++) {
        if ( !dfs(g[x][i].first, (1 - g[x][i].second) ^ c ) )
            return 0;
    }
    return 1;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= m; i ++) {
        scanf("%d %d %d", &u, &v, &w);
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }

    for (int i = 1; i <= n; i ++) if (!vis[i]) {
        if ( !dfs(i, 0) ) {
            for (int j = 0; j < upd.size(); j ++)
                vis[upd[j]] = 0;
            
            if ( !dfs(i, 1) ) {
                return !printf("Impossible\n");
            }
            upd.clear();
        }
        upd.clear();
    }
    int cnt = 0;
    for (int i = 1; i <= n; i ++)
        if (col[i]) cnt ++;

    printf("%d\n", cnt);
    for (int i = 1; i <= n; i ++)
        if (col[i]) printf("%d ", i);
    printf("\n");
}