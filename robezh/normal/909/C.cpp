#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int n;
char c[5005];
int dp[5005][5005];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){cin >> c[i];}
    for(int i = 0; i < 5005; i++){
        fill(dp[i], dp[i] + 5005, 0);
    }
    dp[0][0] = 1;
    for(int i = 1; i < n; i++){
//        if(c[i-1] != 'f' && c[i] == 'f'){
//            for(int j = 0; j <= n; j++){
//                dp[i][j] = dp[i-1][j];
//            }
//        }
        if(c[i-1] == 'f'){
            for(int j = 1; j <= n; j++){
                dp[i][j] = dp[i-1][j-1];
            }
        }
        else{
            int suf = 0;
            for(int j = n; j >= 0; j--){
                suf += dp[i-1][j];
                suf %= mod;
                dp[i][j] += suf;
                dp[i][j] %= mod;
            }
        }
    }
//    cout << "dp...." << endl;
//    for(int i = 0; i < n; i++){
//        for(int j = 0; j < n; j++){
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = (ans + dp[n-1][i]) % mod;
    }
    cout << ans;

}