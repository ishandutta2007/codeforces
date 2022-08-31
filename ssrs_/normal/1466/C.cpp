#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int n = s.size();
    if (n == 1){
      cout << 0 << endl;
    } else {
      vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, INF)));
      if (s[0] != s[1]){
        dp[1][0][0] = 0;
      }
      dp[1][0][1] = 1;
      dp[1][1][0] = 1;
      dp[1][1][1] = 2;
      for (int j = 2; j < n; j++){
        for (int k = 0; k < 2; k++){
          for (int l = 0; l < 2; l++){
            for (int m = 0; m < 2; m++){
              bool ok = true;
              if (s[j - 1] == s[j] && l == 0 && m == 0){
                ok = false;
              }
              if (s[j - 2] == s[j] && k == 0 && m == 0){
                ok = false;
              }
              if (ok){
                dp[j][l][m] = min(dp[j][l][m], dp[j - 1][k][l] + m);
              }
            }
          }
        }
      }
      int ans = INF;
      for (int j = 0; j < 2; j++){
        for (int k = 0; k < 2; k++){
          ans = min(ans, dp[n - 1][j][k]);
        }
      }
      cout << ans << endl;
    }
  }
}