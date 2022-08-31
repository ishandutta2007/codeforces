#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> S(n + 1, 0);
  for (int i = 0; i < n; i++){
    S[i + 1] = S[i] + a[i];
  }
  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(m + 1, INF)));
  dp[0][0][m] = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j <= m; j++){
      int mn = INF;
      for (int k = m; k >= 0; k--){
        mn = min(mn, dp[i][j][k]);
        if (j + k <= m){
          dp[i + 1][j + k][k] = min(dp[i + 1][j + k][k], mn + abs(S[i + 1] - (j + k)));
        }
      }
    }
  }
  int ans = INF;
  for (int i = 0; i <= m; i++){
    ans = min(ans, dp[n][m][i]);
  }
  cout << ans << endl;
}