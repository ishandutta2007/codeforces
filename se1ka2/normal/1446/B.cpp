#include <iostream>
#include <string>
using namespace std;

int dp[5005][5005];

int main()
{
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = max(dp[i][j], dp[i - 1][j] - 1);
            dp[i][j] = max(dp[i][j], dp[i][j - 1] - 1);
            if(s[i - 1] == t[j - 1]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 2);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
}