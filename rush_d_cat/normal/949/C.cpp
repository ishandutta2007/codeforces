#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
const int N = 200000+10;
int n, m, h;
int u[N], x, y;
vector<int> g[N];

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
        memset(pre, 0, sizeof pre);
        memset(low, 0, sizeof low);
        memset(sccno, 0, sizeof sccno);
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
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

        int ans = n, id = -1;

        for (int i = 1; i <= scc_cnt; i ++) {
        
            if (out[i] == 0) {
                if (sz[i] <= ans) {
                    ans = sz[i];
                    id = i;
                }
            }
        }

        printf("%d\n", ans);
        for (int i = 1; i <= n; i ++)
            if (sccno[i] == id)
                printf("%d ", i);
    }

} Saber;


int main() {
    scanf("%d %d %d", &n, &m, &h);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &u[i]);
    }
    for (int i = 1; i <= m; i ++) {
        scanf("%d %d", &x, &y);
        if ((u[x]+1)%h == u[y]) {
            g[x].push_back(y);
        }
        if ((u[y]+1)%h == u[x]) {
            g[y].push_back(x);
        }
    }
    Saber.Excalibur(n);
}