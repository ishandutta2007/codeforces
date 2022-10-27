#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 300000 + 10;
typedef long long LL;
int T;
int n,deg[N]; 
vector<int> g[N];
LL down[N], ans;
void dfs(int u, int p) {
    LL mx1=0,mx2=0;
    for(auto v: g[u]) {
        if (v==p) continue;
        dfs(v, u);
        down[u] = max(down[v], down[u]);
        if(down[v]>mx1) {
            mx2=mx1;
            mx1=down[v];
        } else if(down[v]>mx2) {
            mx2=down[v];
        }
    }
    down[u] += deg[u];
    ans = max(ans, deg[u] + mx1 + mx2);
    //printf("u=%d, deg=%d, down=%d [%d,%d]\n", u,deg[u],down[u],mx1,mx2);
}
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for(int i=1;i<=n;i++) {
            g[i].clear(); deg[i]=0; down[i]=0;
        }
        for(int i=1;i<n;i++) {
            int u,v; scanf("%d%d",&u,&v);
            g[u].push_back(v); g[v].push_back(u); deg[u]++, deg[v]++;
        }
        for(int i=1;i<=n;i++) deg[i]--;  ans=0;
        dfs(1,1);
        printf("%lld\n", ans + 2);
    }
}