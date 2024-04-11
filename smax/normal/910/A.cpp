#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, d, dp[100];
    string s;
    cin >> n >> d >> s;
    
    dp[0] = 0;
    for (int i=1; i<n; i++) {
        dp[i] = 100;
        for (int j=1; j<=d && i-j>=0; j++)
            if (s[i-j] == '1')
                dp[i] = min(dp[i], dp[i-j] + 1);
    }
    
    cout << (dp[n-1] >= 100 ? -1 : dp[n-1]) << endl;
    
    return 0;
}