#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
int main(){
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> a[i][j];
    }
  }
  vector<vector<int>> dp(n + 1, vector<int>(k, -INF));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++){
    vector<vector<vector<int>>> dp2(m + 1, vector<vector<int>>(m / 2 + 1, vector<int>(k, -INF)));
    dp2[0][0][0] = 0;
    for (int j = 0; j < m; j++){
      dp2[j + 1] = dp2[j];
      for (int l = 0; l < m / 2; l++){
        for (int o = 0; o < k; o++){
          dp2[j + 1][l + 1][(o + a[i][j]) % k] = max(dp2[j + 1][l + 1][(o + a[i][j]) % k], dp2[j][l][o] + a[i][j]);
        }
      }
    }
    vector<int> mx(k, -INF);
    for (int j = 0; j < k; j++){
      for (int l = 0; l <= m / 2; l++){
        mx[j] = max(mx[j], dp2[m][l][j]);
      }
    }
    for (int j = 0; j < k; j++){
      for (int l = 0; l < k; l++){
        dp[i + 1][(j + l) % k] = max(dp[i + 1][(j + l) % k], dp[i][j] + mx[l]);
      }
    }
  }
  cout << dp[n][0] << endl;
}