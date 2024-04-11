#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
const int N = 1000000 + 10;

int n, m, t, vis[N];
vector<int> g[N], res;
struct SCC {
    int pre[N], low[N], sccno[N], dfs_clock, scc_cnt;
    int in[N], out[N], sz[N];
    stack<int> S;
    void dfs(int u) {
        pre[u] = low[u] = ++dfs_clock;
        S.push(u);
        for (int i = 0; i < g[u].size(); i ++) {
            int v = g[u][i];
            if (! pre[v]) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            } else if (!sccno[v]) {
                low[u] = min(low[u], pre[v]);
            }
        }
        if (low[u] == pre[u]) {
            scc_cnt ++;
            for (;;) {
                int x = S.top(); S.pop();
                sccno[x] = scc_cnt;                                                                        
                if (x == u) break;
            }
        }
    }
    void Excalibur(int n) {
        for (int i = 0; i <= n; i ++) {
            pre[i] = low[i] = sccno[i] = in[i] = out[i] = 0;
        }
        dfs_clock = scc_cnt = 0;

        for (int i = 1 ;i <= n; i ++)
            if (pre[i] == 0) dfs(i);
        
        for (int i = 1; i <= n; i ++) {
              sz[sccno[i]] ++;
            for (int j = 0; j < g[i].size(); j ++) {
                if (sccno[i] != sccno[g[i][j]])
                    out[sccno[i]] ++, in[sccno[g[i][j]]] ++;
            }
        }
        for(int i = 1; i <= scc_cnt; i ++) {
            if (out[i] == 0) {
                for (int j = 1; j <= n; j ++) if (sccno[j] == i) vis[j] = 1;
                    break;
            }
        }
    }
} Saber;

int main() {
    scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i ++) {
            g[i].clear(); vis[i] = 0;
        }
        for (int i = 1; i <= m; i ++) {
            int u, v; scanf("%d%d", &u, &v);
            g[u].push_back(v);
        }

        Saber.Excalibur(n);

        if (Saber.scc_cnt == 1) {
            printf("No\n"); continue;
        }
        printf("Yes\n");
        int cnt = 0;
        for (int i = 1; i <= n; i ++) if (vis[i] == 1) cnt ++;
        printf("%d %d\n", cnt, n - cnt);
        for (int i = 1; i <= n; i ++) if (vis[i] == 1) printf("%d ", i); printf("\n");
        for (int i = 1; i <= n; i ++) if (vis[i] == 0) printf("%d ", i); printf("\n");

    }
}