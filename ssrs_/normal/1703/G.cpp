#include <bits/stdc++.h>
using namespace std;
const int LOG = 30;
const long long INF = 1000000000000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<vector<long long>> dp(LOG + 1, vector<long long>(n + 1, -INF));
    dp[0][0] = 0;
    for (int j = 0; j < n; j++){
      for (int l = 0; l <= LOG; l++){
        if (dp[l][j] != -INF){
          dp[l][j + 1] = max(dp[l][j + 1], dp[l][j] - k + (a[j] >> l));
          int l2 = min(l + 1, LOG);
          dp[l2][j + 1] = max(dp[l2][j + 1], dp[l][j] + (a[j] >> l2));
        }
      }
    }
    long long ans = 0;
    for (int j = 0; j <= LOG; j++){
      ans = max(ans, dp[j][n]);
    }
    cout << ans << endl;
  }
}