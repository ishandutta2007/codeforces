#include <bits/stdc++.h>
using namespace std;

#define N 3030

int b[N], n, m, up[N];
vector <int> adj[N];
typedef long long ll;
typedef pair <int, ll> pil;
pil dp[N][N], tmp[N];

template <class T>
inline void chkmax(T &x, T y) {
    if (x < y) x = y;
}

void dfs(int u, int pa = 0) {
    dp[u][1] = pil(0, b[u]), up[u] = 1;
    for (auto v : adj[u]) {
        if (v == pa) continue;
        dfs(v, u);
        for (int i = 1; i <= up[u]; i ++) tmp[i] = dp[u][i];
        for (int i = 1; i <= up[u] + up[v]; i ++) dp[u][i] = pil(-1, 0);
        for (int i = 1; i <= up[u]; i ++) {
            for (int j = 1; j <= up[v]; j ++) {
                int x = tmp[i].first + dp[v][j].first;
                chkmax(dp[u][i+j-1], pil(x, tmp[i].second + dp[v][j].second));
                chkmax(dp[u][i+j], pil(x + (dp[v][j].second > 0), tmp[i].second));
            }
        }
        up[u] += up[v];
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &n, &m);
        for (int i = 1, x; i <= n; i ++) scanf("%d", &x), b[i] = -x, adj[i].clear();
        for (int i = 1, x; i <= n; i ++) scanf("%d", &x), b[i] += x, up[i] = 0;
        for (int i = 1, u, v; i < n; i ++) {
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1);
        printf("%d\n", dp[1][m].first + (dp[1][m].second > 0));
    }

    return 0;
}