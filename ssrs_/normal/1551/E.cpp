#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
      a[j]--;
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    dp[0][0] = 0;
    for (int j = 0; j < n; j++){
      for (int l = 0; l <= j; l++){
        if (a[j] == j - l){
          dp[j + 1][l] = max(dp[j + 1][l], dp[j][l] + 1);
        } else {
          dp[j + 1][l] = max(dp[j + 1][l], dp[j][l]);
        }
        dp[j + 1][l + 1] = max(dp[j + 1][l + 1], dp[j][l]);
      }
    }
    int ans = -1;
    for (int j = 0; j <= n; j++){
      if (dp[n][j] >= k){
        ans = j;
        break;
      }
    }
    cout << ans << endl;
  }  
}