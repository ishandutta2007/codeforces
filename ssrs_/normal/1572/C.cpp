#include <bits/stdc++.h>
using namespace std;
const int INF = 10000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
      a[j]--;
    }
    vector<vector<int>> p(n);
    for (int j = 0; j < n; j++){
      p[a[j]].push_back(j);
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int j = 0; j < n; j++){
      dp[j][j] = 0;
    }
    for (int j = n; j >= 0; j--){
      for (int k = j + 1; k <= n; k++){
        dp[j][k] = max(dp[j + 1][k], dp[j][k - 1]);
        for (int l : p[a[j]]){
          if (j < l && l < k){
            dp[j][k] = max(dp[j][k], dp[j + 1][l] + dp[l][k] + 1);
          }
        }
      }
    }
    cout << n - dp[0][n] - 1 << endl;
  }
}