#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, h, l, r;
  cin >> n >> h >> l >> r;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  //dp
  vector<vector<int>> dp(n + 1, vector<int>(h, -1));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < h; j++){
      if (dp[i][j] == -1) continue;
      int x = (j + a[i]) % h;
      int y = (j + a[i] - 1) % h;
      dp[i + 1][x] = max(dp[i + 1][x], dp[i][j]);
      dp[i + 1][y] = max(dp[i + 1][y], dp[i][j]);
    }
    for (int j = l; j <= r; j++){
      if (dp[i + 1][j] >= 0){
        dp[i + 1][j]++;
      }
    }
  }
  int M = 0;
  for (int i = 0; i < h; i++){
    M = max(M, dp[n][i]);
  }
  cout << M;
}