#include <iostream>
#include <vector>
using namespace std;

const int N = 200000 + 10;
typedef long long LL;
const LL inf = 1e18;
int n, a[N], p[N];
vector<int> g[N];

LL dp[N][2];

void dfs(int u) {
    dp[u][0] = 0, dp[u][1] = - inf;
    for (auto v: g[u]) {
        dfs(v);
        LL tmp[2] = {0}; tmp[0] = - inf, tmp[1] = -inf;
        for (int i = 0; i < 2; i ++) for (int j = 0; j < 2; j ++) {
            tmp[(i+j)%2] = max(tmp[(i+j)%2], dp[u][i] + dp[v][j]);
        }
        for (int i = 0; i < 2; i ++) dp[u][i] = tmp[i];
    }
    dp[u][1] = max(dp[u][1], a[u] + dp[u][0]);
}

int main() {
    for (int i = 0; i < N; i ++) for (int j = 0; j < 2; j ++) dp[i][j] = - inf;
    scanf("%d", &n);
    int rt = 0; a[0] = 0;
    for (int i = 1; i <= n; i ++) {
        scanf("%d%d", &p[i], &a[i]);
        if (p[i] != -1) {
            g[p[i]].push_back(i);
        } else {
            g[rt].push_back(i);
        }
    } 
    dfs(rt);
    LL ans = max(dp[0][1], dp[0][0]);
    cout << ans << endl;
}