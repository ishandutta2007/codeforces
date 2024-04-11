#include <bits/stdc++.h>
using namespace std;
const int INF = 100000000;
int main(){
  int n, k;
  cin >> n >> k;
  int m;
  cin >> m;
  if (k > n || m < k - 1){
    cout << -1 << endl;
  } else if (k == 1){
    cout << 0 << endl;
  } else {
    vector<vector<pair<int, int>>> E(n);
    for (int i = 0; i < m; i++){
      int u, v, c;
      cin >> u >> v >> c;
      u--;
      v--;
      E[u].push_back(make_pair(c, v));
    }
    vector<vector<vector<int>>> dp(k, vector<vector<int>>(n + 1, vector<int>(n + 2, INF)));
    for (int i = 0; i < n; i++){
      dp[0][i + 1][0] = 0;
    }
    for (int i = 0; i < n; i++){
      dp[0][i + 1][n + 1] = 0;
    }
    for (int i = 0; i < k - 1; i++){
      for (int j = 1; j < n + 1; j++){
        for (int l = 0; l < n + 2; l++){
          if (dp[i][j][l] != INF){
            for (auto edge : E[j - 1]){
              int c = edge.first;
              int w = edge.second + 1;
              if (j < w && w < l || j > w && w > l){
                dp[i + 1][w][j] = min(dp[i + 1][w][j], dp[i][j][l] + c);
                //cout << i + 1 << ' ' << w << ' ' << j << ", dp = " << dp[i + 1][w][j] << endl;
                dp[i + 1][w][l] = min(dp[i + 1][w][l], dp[i][j][l] + c);
                //cout << i + 1 << ' ' << w << ' ' << l << ", dp = " << dp[i + 1][w][l]<< endl;
              }
            }
          }
        }
      }
    }
    int ans = INF;
    for (int i = 1; i < n + 1; i++){
      for (int j = 0; j < n + 2; j++){
        ans = min(ans, dp[k - 1][i][j]);
      }
    }
    if (ans == INF){
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  }
}