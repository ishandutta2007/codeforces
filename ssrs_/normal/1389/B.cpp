#include <bits/stdc++.h>
using namespace std;
int INF = 1100000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int N, K, z;
    cin >> N >> K >> z;
    vector<int> a(N);
    for (int j = 0; j < N; j++){
      cin >> a[j];
    }
    vector<vector<vector<int>>> dp(K + 1, vector<vector<int>>(z + 1, vector<int>(2, -INF)));
    dp[0][0][1] = a[0];
    for (int j = 0; j < K; j++){
      for (int k = 0; k <= z; k++){
        int pos = j - k * 2;
        if (pos < 0){
          continue;
        }
        if (pos > 0){
          if (k < z){
            dp[j + 1][k + 1][1] = max(dp[j + 1][k + 1][1], dp[j][k][0] + a[pos - 1]);
          }
        }
        if (pos < N - 1){
          dp[j + 1][k][0] = max(dp[j + 1][k][0], dp[j][k][0] + a[pos + 1]);
          dp[j + 1][k][0] = max(dp[j + 1][k][0], dp[j][k][1] + a[pos + 1]);
        }
      }
    }
    int ans = 0;
    for (int j = 0; j <= z; j++){
      ans = max(ans, dp[K][j][0]);
      ans = max(ans, dp[K][j][1]);
    }
    cout << ans << endl;
  }
}