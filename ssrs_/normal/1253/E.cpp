#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> x(n), s(n);
  for (int i = 0; i < n; i++){
    cin >> x[i] >> s[i];
    x[i]--;
  }
  vector<pair<int, int>> P(n);
  for (int i = 0; i < n; i++){
    P[i] = make_pair(max(x[i] - s[i], 0), min(x[i] + s[i], m - 1));
  }
  sort(P.begin(), P.end());
  vector<int> L(n), R(n);
  for (int i = 0; i < n; i++){
    L[i] = P[i].first, 0;
    R[i] = P[i].second + 1;
  }
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++){
    dp[i + 1] = dp[i];
    for (int j = L[i], k = R[i]; j >= 0 || k <= m; j--, k++){
      dp[i + 1][min(k, m)] = min(dp[i + 1][min(k, m)], dp[i][max(j, 0)] + (L[i] - j));
    }
    for (int j = m - 1; j >= 0; j--){
      dp[i + 1][j] = min(dp[i + 1][j], dp[i + 1][j + 1]);
    }
  }
  cout << dp[n][m] << endl;
}