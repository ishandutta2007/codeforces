#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e6 + 5;
vector<int>g[N];
int par[N];
int up[20][N];
bool was[N];
 
void dfs(int u, int fa)
{
    par[u] = up[0][u] = fa;
    for(int i = 1;i < 20;i ++) up[i][u] = up[i-1][ up[i-1][u] ];
    for(int to:g[u]) if(to != fa) dfs(to, u);
}
 
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    was[n] = 1;
    for(int u, v, i = 1;i < n;i ++) {
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(n, n);
    int ost = n - 1 - k;
    for(int i = n - 1;i >= 1;i --) {
        if(was[i]) continue;
        int v = i, len = 0;
        for(int j = 19;j >= 0;j --) {
            if(!was[ up[j][v] ]) {
                v = up[j][v];
                len += 1 << j;
            }
        }
        len ++;
        if(len <= ost) {
            v = i;
            ost -= len;
            while(true) {
                if(was[v]) break;
                was[v] = 1;
                v = par[v];
            }
        }
    }
    for(int i = 1;i <= n; i++) if(!was[i]) printf("%d ",i);
    printf("\n");
    return 0;
}