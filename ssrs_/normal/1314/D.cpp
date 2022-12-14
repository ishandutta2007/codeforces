#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main(){
  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
  int n, k;
  cin >> n >> k;
  vector<vector<int>> c(n, vector<int>(n));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> c[i][j];
    }
  }
  int ans = INF;
  for (int i = 0; i < 10000; i++){
    vector<int> p(n);
    for (int j = 0; j < n; j++){
      p[j] = mt() % 2;
    }
    vector<vector<int>> dp(k + 1, vector<int>(n, INF));
    dp[0][0] = 0;
    for (int j = 0; j < k; j++){
      for (int u = 0; u < n; u++){
        for (int v = 0; v < n; v++){
          if (p[u] != p[v] && u != v){
            dp[j + 1][v] = min(dp[j + 1][v], dp[j][u] + c[u][v]);
          }
        }
      }
    }
    ans = min(ans, dp[k][0]);
  }
  cout << ans << endl;
}