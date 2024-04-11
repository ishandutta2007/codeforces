#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main(){
  int n;
  cin >> n;
  vector<string> s(2);
  cin >> s[0];
  cin >> s[1];
  s[0] += '0';
  s[1] += '0';
  vector<vector<int>> dp(n + 1, vector<int>(2, -INF));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < 2; j++){
      if (s[j ^ 1][i] == '0' && s[j][i + 1] == '0'){
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      }
      if (s[j ^ 1][i] == '0' && s[j][i + 1] == '1'){
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + 1);
      }
      if (s[j ^ 1][i] == '1' && s[j][i + 1] == '0'){
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        dp[i + 1][j ^ 1] = max(dp[i + 1][j ^ 1], dp[i][j] + 1 + (s[j ^ 1][i + 1] - '0'));
      }
      if (s[j ^ 1][i] == '1' && s[j][i + 1] == '1'){
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + 1);
        dp[i + 2][j ^ 1] = max(dp[i + 2][j ^ 1], dp[i][j] + 1 + (s[j ^ 1][i + 1] - '0') + (s[j ^ 1][i + 2] - '0'));
      }
    }
  }
  cout << max(dp[n][0], dp[n][1]) << endl;
}