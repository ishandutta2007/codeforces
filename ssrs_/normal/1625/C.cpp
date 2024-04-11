#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main(){
  int n, l, k;
  cin >> n >> l >> k;
  vector<int> d(n);
  for (int i = 0; i < n; i++){
    cin >> d[i];
  }
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  d.push_back(l);
  vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));
  dp[0][0] = 0;
  for (int i = 0; i <= k; i++){
    for (int j = 0; j <= n; j++){
      for (int l = j + 1; l <= n; l++){
        int i2 = i + (l - j - 1);
        if (i2 <= k){
          dp[i2][l] = min(dp[i2][l], dp[i][j] + a[j] * (d[l] - d[j]));
        }
      }
    }
  }
  int ans = INF;
  for (int i = 0; i <= k; i++){
    ans = min(ans, dp[i][n]);
  }
  cout << ans << endl;
}