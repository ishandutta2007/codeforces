// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;
#define int long long
const int N = (int) 205, mod = (int) 1e9 + 7;
int n, k, dp[N][N][N], odp[N][N];
vector<int> adj[N];
int sadd(int &x, int y) { x = (x + y) % mod; }
void dfs(int v, int p = 0) {
    for (int u : adj[v])
        if (u != p)
            dfs(u, v);
    dp[v][k + 1][k] = 1;
    dp[v][0][0] = 1;
    for (int u : adj[v]) if (u != p) {
        memcpy(odp, dp[v], sizeof odp);
        memset(dp[v], 0, sizeof dp[v]);
        for (int a = 0; a <= 2 * k; ++a)
            for (int b = 0; b <= k; ++b)
                for (int c = 0; c <= 2 * k; ++c)
                    for (int d = 0; d <= k; ++d) {
                        int v0 = (a + (d + 1) - k - 1), v1 = (b + 1 + c - k - 1);
                        if (v0 <= k) {
                            v0 = 0;
                        } else {
                            v0 = a;
                        }
                        if (v1 <= k) {
                            v1 = 0;
                        } else {
                            v1 = c + 1;
                        }
                        sadd(dp[v][max(v0, v1)][min(d + 1, b)], odp[a][b] * 1ll * dp[u][c][d] % mod);
                    }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    int res = 0;
    for (int i = 0; i <= k; ++i)
        for (int j = 0; j <= k; ++j)
            res = (res + dp[0][i][j]) % mod;
    cout << res << endl;
}