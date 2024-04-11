#include <iostream>
#include <cstring>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LL;
const int N = 5000000 + 10;
vector<int> g[N];
int n,m,d;
char s[100000+10][52];
int id(int u,int t){
    return (u-1)*d + t + 1;
}
int dp[N];
struct SCC {
    bool has[N];
    int pre[N], low[N], sccno[N], dfs_clock, scc_cnt;
    vector<int> sccg[N]; int cnt[N], pr[N];
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
        dfs_clock = scc_cnt = 0;
        for (int i = 1 ;i <= n; i ++)
            if (pre[i] == 0) dfs(i);

        for (int i = 1; i <= n; i ++) {
            if(has[i]) {
                if(pr[sccno[i]] != (i-1+d) / d) {
                    cnt[sccno[i]] ++;
                    pr[sccno[i]] = (i-1+d) / d;
                }
            }
            for (int j = 0; j < g[i].size(); j ++) {
                if (sccno[i] != sccno[g[i][j]]) {
                    sccg[sccno[i]].push_back(sccno[g[i][j]]);
                }
            }
        }
    }
    int solve(int u) {
        if(dp[u] != -1) return dp[u];
        dp[u] = cnt[u];
        for (auto v: sccg[u]) {
            dp[u] = max(dp[u], solve(v) + cnt[u]);
        }
        return dp[u];
    }
} Saber;

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d%d%d",&n,&m,&d);
    for(int i=1;i<=m;i++){
        int u,v; 
        scanf("%d%d",&u,&v);
        for(int j=0;j<d;j++){
            g[id(u,j)].push_back(id(v,(j+1)%d));
        }
    }
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]);
        for(int j=0;j<d;j++){
            if(s[i][j] == '1') Saber.has[id(i,j)] = 1;
        }
    }
    n = n * d;
    Saber.Excalibur(n);
    cout << Saber.solve(Saber.sccno[id(1,0)]) << endl;
}