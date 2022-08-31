#include <bits/stdc++.h>
using namespace std;
int INF = 1000000000;
int main(){
  int N, K, s;
  cin >> N >> K >> s;
  vector<int> q(N);
  for (int i = 0; i < N; i++){
    cin >> q[i];
  }
  s = min(s, N * (N - 1) / 2);
  vector<vector<int>> dp(K + 1, vector<int>(s + 1, INF));
  dp[0][0] = 0;
  for (int i = 0; i < N; i++){
    vector<vector<int>> dp2 = dp;
    for (int j = 0; j < K; j++){
      for (int k = max(j - i, 0); k <= min(s - (i - j), s); k++){
        dp2[j + 1][k + i - j] = min(dp2[j + 1][k + i - j], dp[j][k] + q[i]);
      }
    }
    swap(dp, dp2);
  }
  int ans = INF;
  for (int i = 0; i <= s; i++){
    ans = min(ans, dp[K][i]);
  }
  cout << ans << endl;
}