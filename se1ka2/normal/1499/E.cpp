#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll dp[1002][1002][3][3][2];

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j][1][0][0] = 1;
            if(i >= 2 && s[i - 1] != s[i - 2]){
                dp[i][j][1][0][0] = (dp[i][j][1][0][0] + dp[i - 1][j][1][0][0]) % MOD;
            }
            dp[i][j][0][1][1] = 1;
            if(j >= 2 && t[j - 1] != t[j - 2]){
                dp[i][j][0][1][1] = (dp[i][j][0][1][1] + dp[i][j - 1][0][1][1]) % MOD;
            }
            if(i && j){
                if(s[i - 1] != t[j - 1]){
                    dp[i][j][1][1][0] = (dp[i - 1][j][0][1][1] + dp[i - 1][j][1][1][1]) % MOD;
                    dp[i][j][1][1][1] = (dp[i][j - 1][1][0][0] + dp[i][j - 1][1][1][0]) % MOD;
                }
                if(i >= 2 && s[i - 1] != s[i - 2]){
                    dp[i][j][1][1][0] = (dp[i][j][1][1][0] + dp[i - 1][j][1][1][0]) % MOD;
                }
                if(j >= 2 && t[j - 1] != t[j - 2]){
                    dp[i][j][1][1][1] = (dp[i][j][1][1][1] + dp[i][j - 1][1][1][1]) % MOD;
                }
            }
            if(i && j){
                for(int o = 0; o < 2; o++){
                    dp[i][j][2][2][o] = (dp[i - 1][j][2][2][o] + dp[i][j - 1][2][2][o] + MOD -
                                         dp[i - 1][j - 1][2][2][o] + dp[i][j][1][1][o]) % MOD;
                }
            }
        }
    }
    cout << (dp[n][m][2][2][0] + dp[n][m][2][2][1]) % MOD << endl;
}