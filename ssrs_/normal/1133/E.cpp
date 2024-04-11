#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<int> next(n);
  for (int i = 0; i < n; i++){
    next[i] = upper_bound(a.begin(), a.end(), a[i] + 5) - a.begin();
  }
  vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
  for (int i = 0; i < n; i++){
    for (int j = 0; j <= k; j++){
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      if (j < k){
        dp[next[i]][j + 1] = max(dp[next[i]][j + 1], dp[i][j] + (next[i] - i));
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= k; i++){
    ans = max(ans, dp[n][i]);
  }
  cout << ans << endl;
}