#include <iostream>
using namespace std;

const int INF = 1000000000;

int t[502][502], r[502][502];
int dp[502][502][22];

int dfs(int x, int y, int k, int n, int m){
    if(k == 0) return 0;
    if(dp[x][y][k]) return dp[x][y][k];
    dp[x][y][k] = INF;
    if(x > 0) dp[x][y][k] = min(dp[x][y][k], dfs(x - 1, y, k - 2, n, m) + t[x - 1][y] * 2);
    if(y > 0) dp[x][y][k] = min(dp[x][y][k], dfs(x, y - 1, k - 2, n, m) + r[x][y - 1] * 2);
    if(x < n - 1) dp[x][y][k] = min(dp[x][y][k], dfs(x + 1, y, k - 2, n, m) + t[x][y] * 2);
    if(y < m - 1) dp[x][y][k] = min(dp[x][y][k], dfs(x, y + 1, k - 2, n, m) + r[x][y] * 2);
    return dp[x][y][k];
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m - 1; j++) cin >> r[i][j];
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m; j++) cin >> t[i][j];
    }
    if(k % 2){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) cout << -1 << " ";
            cout << endl;
        }
        return 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cout << dfs(i, j, k, n, m) << " ";
        cout << endl;
    }
}