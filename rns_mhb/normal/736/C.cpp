#include <bits/stdc++.h>
using namespace std;

#define N 105

const int mod = 1e9 + 7;

int n, k, ans;
vector<int> v[N];
int dp[N][N], tmp[N];

void dfs(int x, int par = 0) {
    dp[x][0] = dp[x][k+1] = 1;
    for (int ii = 0; ii < v[x].size(); ii ++) {
        int y = v[x][ii];
        if (y == par) continue;
        dfs(y, x);
        memset(tmp, 0, sizeof tmp);
        for (int i = 0; i <= 2 * k; i ++)
        for (int j = 0; j <= 2 * k; j ++) {
            int t = i + j <= 2 * k ? min(i, j + 1) : max(i, j + 1);
            (tmp[t] += 1ll * dp[x][i] * dp[y][j] % mod) %= mod;
        }
        for (int i = 0; i <= 2 * k; i ++) dp[x][i] = tmp[i];
    }
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i < n; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    for (int i = 0; i <= k; i ++) (ans += dp[1][i]) %= mod;
    printf("%d\n", ans);
    return 0;
}