#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> graph[1000005];
int idx[1000005]; int low[1000005];
int stk[1000005]; int stknext = 1;
int dfsnext = 1; int sccnext = 1;
int scc[1000005]; bool onstk[1000005];
int outdeg[1000005];

void tarjan(int node)
{
    low[node] = idx[node] = dfsnext++;
    stk[stknext++] = node; onstk[node] = true;
    for (int i = 0; i < graph[node].size(); i++) {
        int nxt = graph[node][i];
        if (!idx[nxt]) {
            tarjan(nxt); low[node] = min(low[node], low[nxt]);
        } else if (onstk[nxt]) {
            low[node] = min(low[node], idx[nxt]);
        }
    }
    if (low[node] == idx[node]) {
        while (1) {
            stknext--;
            scc[stk[stknext]] = sccnext; onstk[stk[stknext]] = false;
            if (stk[stknext] == node) break;
        }
        sccnext++;
        onstk[node] = false;
    }
}

void work(void)
{
    scanf("%d%d", &n, &m); dfsnext = sccnext = 1;
    for (int i = 1; i <= n; i++) {
        graph[i].clear(); idx[i] = low[i] = outdeg[i] = 0;
    }
    for (int i = 1; i <= m; i++){
        int u, v; scanf("%d%d", &u, &v);
        graph[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!idx[i]) tarjan(i);
    }
    if (sccnext == 2) {
        printf("No\n");
    } else {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                int n2 = graph[i][j];
                if (scc[i] != scc[n2]) {
                    outdeg[scc[i]]++;
                }
            }
        }
        int goodscc = 0;
        for (int i = 1; i < sccnext; i++) {
            if (!outdeg[i]) goodscc = i;
        }
        vector<int> jury, cats;
        for (int i = 1; i <= n; i++) {
            (scc[i] == goodscc ? jury : cats).push_back(i);
        }
        printf("Yes\n");
        printf("%d %d\n", (int)jury.size(), (int)cats.size());
        for (int i = 0; i < jury.size(); i++) {
            printf("%d ", jury[i]);
        }
        printf("\n");
        for (int i = 0; i < cats.size(); i++) {
            printf("%d ", cats[i]);
        }
        printf("\n");
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        work();
    }
    return 0;
}