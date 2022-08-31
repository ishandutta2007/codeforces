#include <bits/stdc++.h>
using namespace std;
const int INF = 100000;
int main(){
  int n;
  cin >> n;
  n++;
  vector<int> a(n);
  a[0] = 0;
  for (int i = 1; i < n; i++){
    cin >> a[i];
  }
  vector<vector<int>> dp(n, vector<int>(n, INF));
  dp[0][0] = 0;
  for (int i = 1; i < n; i++){
    for (int j = 0; j < i; j++){
      if (a[i] > 0){
        dp[i][j] = dp[i - 1][j] + 1;
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
    int mn = INF;
    for (int j = i - 1; j >= 0; j--){
      if (mn >= a[j]){
        dp[i][i] = min(dp[i][i], dp[i - 1][j] + max(a[i] - a[j], 0));
      }
      mn = min(mn, a[j]);
    }
  }
  int ans = INF;
  for (int i = 0; i < n; i++){
    ans = min(ans, dp[n - 1][i]);
  }
  cout << ans << endl;
}