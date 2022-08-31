#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
  int n, l, r;
  cin >> n >> l >> r;
  l--;
  vector<int> c(3, 0);
  for (int i = 0; i < 3; i++){
    c[i] = (r + 3 - i) / 3 - (l + 3 - i) / 3;
  }
  vector<vector<long long>> dp(n + 1, vector<long long>(3, 0));
  dp[0][0] = 1;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < 3; j++){
      for (int k = 0; k < 3; k++){
        dp[i + 1][(j + k) % 3] += dp[i][j] * c[k];
        dp[i + 1][(j + k) % 3] %= MOD;
      }
    }
  }
  cout << dp[n][0] << endl;
}