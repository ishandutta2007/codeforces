#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, a, b, c, dp[4001];
    cin >> n >> a >> b >> c;
    
    memset(dp, 0, sizeof(dp));
    for (int i=0; i<=n; i++) {
        if (i - a == 0 || i - b == 0 || i - c == 0)
            dp[i] = 1;
        if (i > a && dp[i-a] > 0)
            dp[i] = max(dp[i], dp[i-a] + 1);
        if (i > b && dp[i-b] > 0)
            dp[i] = max(dp[i], dp[i-b] + 1);
        if (i > c && dp[i-c] > 0)
            dp[i] = max(dp[i], dp[i-c] + 1);
    }
    
    cout << dp[n] << endl;
    
    return 0;
}