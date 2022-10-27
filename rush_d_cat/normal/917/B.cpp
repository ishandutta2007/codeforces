#include <iostream>
using namespace std;
const int N = 100+10;
int dp[N][N][N], vs[N][N][N], mp[N][N], n, m, u, v; char c;
int dfs(int a, int b, int c) {
    if (vs[a][b][c]) return dp[a][b][c];
    dp[a][b][c] = 0; vs[a][b][c] = 1;
    for (int i = 1; i <= n; i ++) {
        if (mp[a][i] >= max(c,1) && !dfs(b, i, mp[a][i]))
            dp[a][b][c] = 1;
    }
    return dp[a][b][c];
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        cin >> u >> v >> c;
        mp[u][v] = c-'a'+1;
    }
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            printf("%c%s", dfs(i,j,0)?'A':'B', j==n?"\n":"");
}