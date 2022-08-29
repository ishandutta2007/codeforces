#include <bits/stdc++.h>
using namespace std;
const int INF = 100000000;
int main(){
  cout << fixed << setprecision(15);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++){
    cin >> a[i] >> b[i];
  }
  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(10001, -INF)));
  dp[0][0][0] = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j <= i; j++){
      for (int k = 0; k < 10001; k++){
        dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + b[i]);
        if (k + a[i] <= 10000){
          dp[i + 1][j + 1][k + a[i]] = max(dp[i + 1][j + 1][k + a[i]], dp[i][j][k] + b[i] * 2);
        }
      }
    }
  }
  for (int i = 1; i <= n; i++){
    double ans = 0;
    for (int j = 0; j <= 10000; j++){
      ans = max(ans, min(dp[n][i][j] / (double) 2, (double) j));
    }
    cout << ans << endl;
  }
}