#include <iostream>
#include <vector>
#include "algorithm"
#include "string"
#define int long long
using namespace std;
signed main() {
    int n;
    int mod = 998244353;
    string s, k;
    cin >> s >> k;
    n = s.size();
    int m = k.size();
    string help(n-m, '?');
    k += help;
    vector<vector<int>> dp(n + 1, vector<int>(n+1, 0));
    dp[0] = vector<int>(n+1, 1);
    for (int i = 1; i <= n; ++i) {
        char elem = s[i - 1];
        for (int j = 0; j < n; ++j) {
            if(elem == k[j] or k[j] == '?'){
                dp[i][j] += dp[i-1][j+1];
                dp[i][j] %= mod;
                if(j + 1 >= i){
                    dp[i][j - i + 1] += dp[i-1][j-i + 1];
                    dp[i][j-i+1] %= mod;
                }
            }
        }
    }
    int res = 0;
    //for (int i = 0; i <= n; ++i) {
        //for(int j = 0; j < n; ++j){
            //cout << dp[i][j] << ' ';
        //}
        //cout << endl;
    //}
    for(int i = m; i <= n; ++i)
        {res += dp[i][0];res%=mod;}
    cout << res;
}