#include<bits/stdc++.h>
using namespace std;
long long dp[2][209][2];
long long mod =998244353;
int a[100009];
main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 0; i <= 200; i++)
        dp[0][i][1] = 1;
    for(int i = 1; i <= n; i++){
            int i1 = (i+1)&1;
            int i0 = i &1;

            dp[i0][0][1] = 0;
        for(int j = 1; j <= 200; j++){

            if(a[i] != -1 && a[i] != j) {dp[i0][j][0] = 0, dp[i0][j][1] = 0;} else{
            dp[i0][j][0] = dp[i1][j - 1][0] + dp[i1][j - 1][1];
            dp[i0][j][1] = dp[i1][200][1] - dp[i1][j - 1][1] + dp[i1][j][0] - dp[i1][j - 1][0] + mod + mod;
            }
            dp[i0][j][0] += dp[i0][j-1][0];
            dp[i0][j][1] += dp[i0][j-1][1];
           dp[i0][j][0] %= mod;
           dp[i0][j][1] %=mod;


        }
    }
    cout<<dp[n%2][200][1] << endl;
}