#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -1));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j <= i; j++){
      if (dp[i][j] >= 0){
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        if (dp[i][j] + a[i] >= 0){
          dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + a[i]);
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= n; i++){
    if (dp[n][i] >= 0){
      ans = i;
    }
  }
  cout << ans << endl;
}