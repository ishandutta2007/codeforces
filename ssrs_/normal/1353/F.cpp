#include <bits/stdc++.h>
using namespace std;
long long INF = 1000000000000000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> a(n, vector<long long>(m));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        cin >> a[j][k];
        a[j][k] -= (j + k);
      }
    }
    set<long long> h;
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        h.insert(a[j][k]);
      }
    }
    long long ans = INF;
    for (long long x : h){
      vector<vector<long long>> b(n, vector<long long>(m, INF));
      for (int j = 0; j < n; j++){
        for (int k = 0; k < m; k++){
          if (a[j][k] >= x){
            b[j][k] = a[j][k] - x;
          }
        }
      }
      if (b[0][0] == INF){
        continue;
      }
      vector<vector<long long>> dp(n, vector<long long>(m, INF));
      dp[0][0] = b[0][0];
      for (int j = 1; j < n; j++){
        if (b[j][0] != INF && dp[j - 1][0] != INF){
          dp[j][0] = dp[j - 1][0] + b[j][0];
        }
      }
      for (int k = 1; k < m; k++){
        if (b[0][k] != INF && dp[0][k - 1] != INF){
          dp[0][k] = dp[0][k - 1] + b[0][k];
        }
      }
      for (int j = 1; j < n; j++){
        for (int k = 1; k < m; k++){
          if (b[j][k] != INF){
            if (dp[j - 1][k] != INF){
              dp[j][k] = min(dp[j][k], dp[j - 1][k] + b[j][k]);
            }
            if (dp[j][k - 1] != INF){
              dp[j][k] = min(dp[j][k], dp[j][k - 1] + b[j][k]);
            }
          }
        }
      }
      ans = min(ans, dp[n - 1][m - 1]);
    }
    cout << ans << endl;
  }
}