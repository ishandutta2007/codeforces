#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int m,k,d;
int dp[2][105];

int main() {
    cin >> m >> k >> d;
    for(int i = 0; i < 2; i++) fill(dp[i], dp[i]+105, 0);
    dp[0][0] = 1;
    dp[1][0] = 0;
//    for(int j = 0; j < 105; j++){
//        for(int t = j + 1; t <= min(102, j+d-1); t++){
//            dp[0][t] = (dp[0][t] + dp[0][j]) % mod;
//        }
//    }
//    int maxud = dp[0][m];
//    for(int j = 0; j < 105; j++){
//        for(int t = j + 1; t <= min(102, j+k); t++){
//            dp[1][t] = (dp[1][t] + dp[1][j]) % mod;
//        }
//    }
//    int maxall = dp[1][m];
//    cout << (maxall - maxud + mod) % mod;

    for(int j = 0; j < 105; j++){
        for(int t = j+d; t <= min(102, j+k); t++)
            dp[1][t] = (dp[1][t] + dp[0][j])  % mod;
        for(int t = j+1; t <= min(102, j+d-1); t++)
            dp[0][t] = (dp[0][t] + dp[0][j]) % mod;
        for(int t = j+1; t <= min(102, j+k); t++)
            dp[1][t] = (dp[1][t] + dp[1][j]) % mod;
    }
    cout << dp[1][m];
}