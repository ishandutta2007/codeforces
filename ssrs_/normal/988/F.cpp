#include <bits/stdc++.h>
using namespace std;
const long long INF = 10000000000000;
int main(){
  int a, n, m;
  cin >> a >> n >> m;
  vector<int> l(n), r(n);
  for (int i = 0; i < n; i++){
    cin >> l[i] >> r[i];
  }
  vector<int> x(m), p(m);
  for (int i = 0; i < m; i++){
    cin >> x[i] >> p[i];
  }
  vector<bool> rain(a, false);
  for (int i = 0; i < n; i++){
    for (int j = l[i]; j < r[i]; j++){
      rain[j] = true;
    }
  }
  vector<long long> w(a + 1, INF);
  for (int i = 0; i < m; i++){
    w[x[i]] = min(w[x[i]], (long long) p[i]);
  }
  vector<vector<long long>> dp(a + 1, vector<long long>(m + 1, INF));
  dp[0][m] = 0;
  for (int i = 0; i < m; i++){
    if (x[i] == 0){
      dp[0][i] = 0;
    }
  }
  for (int i = 0; i < a; i++){
    if (!rain[i]){
      dp[i + 1][m] = dp[i][m];
    }
    for (int j = 0; j < m; j++){
      dp[i + 1][j] = dp[i][j] + p[j];
      dp[i + 1][m] = min(dp[i + 1][m], dp[i][j] + p[j]);
    }
    for (int j = 0; j < m; j++){
      if (x[j] == i + 1){
        dp[i + 1][j] = min(dp[i + 1][j], dp[i + 1][m]);
      }
    }
  }
  long long ans = INF;
  for (int i = 0; i <= m; i++){
    ans = min(ans, dp[a][i]);
  }
  if (ans == INF){
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}