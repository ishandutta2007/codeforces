#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int N = s.size();
    vector<vector<int>> dp(N + 1, vector<int>(27, INF));
    dp[0][26] = 0;
    for (int j = 0; j < N; j++){
      for (int k = 0; k < 27; k++){
        dp[j + 1][k] = min(dp[j + 1][k], dp[j][k] + 1);
      }
      int p = s[j] - 'a';
      dp[j + 1][p] = min(dp[j + 1][p], dp[j][26]);
      dp[j + 1][26] = min(dp[j + 1][26], dp[j][p]);
    }
    cout << dp[N][26] << endl;
  }
}