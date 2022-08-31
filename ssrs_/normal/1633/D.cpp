#include <bits/stdc++.h>
using namespace std;
const int INF = 100000;
int main(){
  vector<int> dp(1001, INF);
  dp[1] = 0;
  for (int i = 1; i <= 1000; i++){
    for (int j = 1; j <= i; j++){
      int i2 = i + i / j;
      if (i2 <= 1000){
        dp[i2] = min(dp[i2], dp[i] + 1);
      }
    }
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      cin >> b[j];
    }
    vector<int> c(n);
    for (int j = 0; j < n; j++){
      cin >> c[j];
    }
    int S = 0;
    for (int j = 0; j < n; j++){
      S += dp[b[j]];
    }
    vector<vector<int>> dp2(n + 1, vector<int>(S + 1, 0));
    for (int j = 0; j < n; j++){
      for (int l = 0; l <= S; l++){
        dp2[j + 1][l] = max(dp2[j + 1][l], dp2[j][l]);
        if (l + dp[b[j]] <= S){
          dp2[j + 1][l + dp[b[j]]] = max(dp2[j + 1][l + dp[b[j]]], dp2[j][l] + c[j]);
        }
      }
    }
    int ans = 0;
    for (int j = 0; j <= min(k, S); j++){
      ans = max(ans, dp2[n][j]);
    }
    cout << ans << endl;
  }
}