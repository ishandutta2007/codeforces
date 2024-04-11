#include <bits/stdc++.h>
using namespace std;
const int INF = 10000;
int main(){
  int n;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; i++){
    cin >> c[i];
  }
  vector<int> b;
  b.push_back(c[0]);
  for (int i = 1; i < n; i++){
    if (c[i] != c[i - 1]){
      b.push_back(c[i]);
    }
  }
  int m = b.size();
  vector<vector<int>> dp(m + 1, vector<int>(m + 1, INF));
  for (int i = 0; i < m; i++){
    dp[i][i + 1] = 0;
  }
  for (int d = 1; d < m; d++){
    for (int l = 0; l <= m - d; l++){
      int r = l + d;
      int L = -1;
      if (l > 0){
        L = b[l - 1];
        dp[l - 1][r] = min(dp[l - 1][r], dp[l][r] + 1);
      }
      int R = -1;
      if (r < m){
        R = b[r];
        dp[l][r + 1] = min(dp[l][r + 1], dp[l][r] + 1);
      }
      if (L == R){
        dp[l - 1][r + 1] = min(dp[l - 1][r + 1], dp[l][r] + 1);
      }
    }
  }
  cout << dp[0][m] << endl;
}