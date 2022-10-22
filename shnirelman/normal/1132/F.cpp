#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    string t;
    cin >> t;
    
    string s;
    s += t[0];
    for(int i = 1; i < n; i++) {
        if(t[i - 1] != t[i])
            s += t[i];
    }
    
    n = s.length();
    
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++)
        dp[i][i] = 1;
    
    for(int len = 2; len <= n; len++) {
        for(int i = 0; i + len <= n; i++) {
            int j = i + len - 1;
            dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]) + 1;
            for(int l = i + 1; l <= j; l++) {
                if(s[l] == s[i]) {
                    dp[i][j] = min(dp[i][j], dp[i][l - 1] + (l + 1 > j ? 0 :dp[l + 1][j]));
                    
                } 
                
                
            }
            
            //cout << i << ' ' << j << ' ' << dp[i][j] << endl;
        }
    }
    
    cout << dp[0][n - 1];
}