#include <bits/stdc++.h>
using namespace std;
 
#define INF 1000
 
int main() {
    int n, dp[101][3];
    cin >> n;
    dp[0][0] = 0;
    for (int i=1; i<=n; i++) {
        int a;
        cin >> a;
        dp[i][0] = min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2])) + 1;
        dp[i][1] = (a == 0 || a == 1) ? INF : min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = (a == 0 || a == 2) ? INF : min(dp[i-1][0], dp[i-1][1]);
    }
    cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << endl;
    
    return 0;
}