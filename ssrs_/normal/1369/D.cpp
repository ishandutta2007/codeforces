#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
int main(){
  vector<long long> dp(2000000);
  dp[0] = 0;
  dp[1] = 0;
  dp[2] = 4;
  dp[3] = 4;
  for (int i = 4; i < 2000000; i++){
    if (i % 3 == 1){
      dp[i] = dp[i - 2] * 2 + dp[i - 1];
    } else {
      dp[i] = dp[i - 4] * 4 + dp[i - 3] * 4 + dp[i - 2] + 4;
    }
    dp[i] %= MOD;
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    cout << dp[n - 1] << endl;
  }
}