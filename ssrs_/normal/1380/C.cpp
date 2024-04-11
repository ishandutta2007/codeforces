#include <bits/stdc++.h>
using namespace std;
int INF = 1000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    sort(a.begin(), a.end());
    vector<int> next(n + 1);
    for (int j = 0; j < n; j++){
      next[j] = j + (x + a[j] - 1) / a[j];
    }
    vector<int> dp(n + 1, -INF);
    dp[n] = 0;
    for (int j = n - 1; j >= 0; j--){
      if (next[j] <= n){
        dp[j] = dp[next[j]] + 1;
      }
    }
    int ans = 0;
    for (int j = 0; j < n; j++){
      ans = max(ans, dp[j]);
    }
    cout << ans << endl;
  }
}