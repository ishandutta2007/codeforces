#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(501, vector<int>(501, INF)));
    dp[0][a[0]][x] = 0;
    if (a[0] > x){
      dp[0][x][a[0]] = 1;
    }
    for (int j = 1; j < n; j++){
      for (int k = 0; k <= 500; k++){
        for (int l = 0; l <= 500; l++){
          if (k <= a[j]){
            dp[j][a[j]][l] = min(dp[j][a[j]][l], dp[j - 1][k][l]);
          }
          if (k <= l && a[j] > l){
            dp[j][l][a[j]] = min(dp[j][l][a[j]], dp[j - 1][k][l] + 1);
          }
        }
      }
    }
    int ans = INF;
    for (int j = 0; j <= 500; j++){
      for (int k = 0; k <= 500; k++){
        ans = min(ans, dp[n - 1][j][k]);
      }
    }
    if (ans == INF){
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  }
}