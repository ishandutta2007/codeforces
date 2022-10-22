#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    
    int m = 3;
    
    vector<int> cnt(m);
    cnt[0] = r / 3 - (l - 1) / 3;
    cnt[1] = (r + 2) / 3 - (l + 1) / 3;
    cnt[2] = (r + 1) / 3 - (l) / 3;
    
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0] = cnt;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m; j++)
            for(int l = 0; l < m; l++) {
                dp[i][(j + l) % 3] += dp[i - 1][j] * 1ll * cnt[l] % M;
                dp[i][(j + l) % 3] %= M;
            }
        
        
    }
    
    cout << dp[n - 1][0];
    
    /*int n, k;
    cin >> n >> k;
    
    string s;
    cin >> s;
    
    int ans = 0;
    for(char c = 'a'; c <= 'z'; c++) {
        int cur = 0, x = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == c)
                cur++;
            else
                cur = 0;
                
            if(cur == k){
                cur = 0;
                x++;
            }
        }
        
        ans = max(ans, x);
    }
    
    
    cout << ans;*/
}