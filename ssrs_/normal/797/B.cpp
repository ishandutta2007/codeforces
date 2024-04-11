#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<vector<int>> dp(n + 1, vector<int>(2, -INF));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < 2; j++){
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      int j2 = ((j + a[i]) % 2 + 2) % 2;
      dp[i + 1][j2] = max(dp[i + 1][j2], dp[i][j] + a[i]);
    }
  }
  cout << dp[n][1] << endl;
}