#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
int main(){
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    int n;
    cin >> n;
    vector<int> t(n);
    for (int j = 0; j < n; j++){
      cin >> t[j];
    }
    sort(t.begin(), t.end());
    vector<vector<int>> dp(400, vector<int>(n + 1, INF));
    dp[0][0] = 0;
    for (int j = 1; j < 400; j++){
      dp[j] = dp[j - 1];
      for (int k = 0; k < n; k++){
        dp[j][k + 1] = min(dp[j][k + 1], dp[j - 1][k] + abs(j - t[k]));
      }
    }
    cout << dp[399][n] << endl;
  }
}