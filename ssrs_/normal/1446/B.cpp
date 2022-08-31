#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  string A;
  cin >> A;
  string B;
  cin >> B;
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  int ans = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (A[i] == B[j]){
        dp[i + 1][j + 1] = dp[i][j] + 2;
      } else {
        dp[i + 1][j + 1] = max(max(dp[i + 1][j], dp[i][j + 1]) - 1, 0);
      }
      ans = max(ans, dp[i + 1][j + 1]);
    }
  }
  cout << ans << endl;
}