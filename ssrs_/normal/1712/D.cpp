#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    int tv = 0, fv = 1000000001;
    while (fv - tv > 1){
      int mid = (tv + fv) / 2;
      vector<vector<vector<int>>> dp(2, vector<vector<int>>(2, vector<int>(n + 1, INF)));
      dp[0][0][0] = 0;
      for (int j = 0; j < n; j++){
        for (int k = 0; k < 2; k++){
          for (int l = 0; l < 2; l++){
            if (a[j] * 2 < mid){
              dp[k | l][1][j + 1] = min(dp[k | l][1][j + 1], dp[k][l][j] + 1);
            } else if (a[j] < mid){
              dp[k][0][j + 1] = min(dp[k][0][j + 1], dp[k][l][j]);
              dp[k | l][1][j + 1] = min(dp[k | l][1][j + 1], dp[k][l][j] + 1);
            } else {
              dp[k | l][1][j + 1] = min(dp[k | l][1][j + 1], dp[k][l][j]);
            }
          }
        }
      }
      if (min(dp[1][0][n], dp[1][1][n]) <= k){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    cout << tv << endl;
  }
}