#include <iostream>
#include <vector>
using namespace std;
const int N = 1000000 + 10;
vector<int> g[N];
int dep[N], par[N][22];
int n, k;
int mark[N];

void dfs(int u, int p) {
    par[u][0] = p;
    for(int i=1;i<21;i++)
        par[u][i] = par[par[u][i-1]][i-1];

    for(int i=0;i<g[u].size();i++) {
        int v = g[u][i];
        if (v == p) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

int main() {
    scanf("%d %d",&n,&k);
    for(int i=1;i<n;i++) {
        int u,v; scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(n, n);
    mark[n] = 1;
    int cnt = 1;
    for (int i = n-1; i >= 1; i --) {
        if (mark[i]) continue;
        int now = i;
        for (int j = 20; j >= 0; j --) {
            if (mark[par[now][j]] == 0)
                now = par[now][j];
        }
        now = par[now][0];

        //printf("i = %d, now = %d \n", i, now);
        if (cnt + dep[i] - dep[now] <= n - k) {
            cnt = cnt + dep[i] - dep[now];
            int paiGuLong = i;
            while (paiGuLong != now) {
                mark[paiGuLong] = 1;
                paiGuLong = par[paiGuLong][0];
            }
        }
    }

    for (int i=1;i<=n;i++)
        if (mark[i]==0)
            printf("%d ", i);
}