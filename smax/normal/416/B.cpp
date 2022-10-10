#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n, t[50000][5], dp[50000][5];
    cin >> m >> n;
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            cin >> t[i][j];
    
    dp[0][0] = t[0][0];
    for (int i=1; i<m; i++)
        dp[i][0] = dp[i-1][0] + t[i][0];
    for (int j=1; j<n; j++)
        dp[0][j] = dp[0][j-1] + t[0][j];
    for (int i=1; i<m; i++)
        for (int j=1; j<n; j++)
            dp[i][j] = max(dp[i-1][j] + t[i][j], dp[i][j-1] + t[i][j]);
    
    for (int i=0; i<m; i++)
        cout << dp[i][n-1] << " ";
    cout << endl;
    
    return 0;
}