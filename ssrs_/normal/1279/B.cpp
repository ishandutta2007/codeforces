#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(2, INF));
    dp[0][0] = 0;
    for (int j = 0; j < n; j++){
      dp[j + 1][0] = dp[j][0] + a[j];
      dp[j + 1][1] = min(dp[j][1] + a[j], dp[j][0]);
    }
    int mx = 0;
    for (int j = 0; j <= n; j++){
      if (dp[j][0] <= s){
        mx = max(mx, j);
      }
      if (dp[j][1] <= s){
        mx = max(mx, j - 1);
      }
    }
    int ans = -1;
    if (dp[mx][0] <= s){
      ans = 0;
    } else {
      ans = max_element(a.begin(), a.begin() + mx + 1) - a.begin() + 1;
    }
    cout << ans << endl;
  }
}