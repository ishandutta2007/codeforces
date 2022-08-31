#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> cnt(200001, 0);
    for (int j = 0; j < n; j++){
      cnt[a[j]]++;
    }
    vector<int> dp(200001, 0);
    dp[1] = cnt[1];
    int ans = dp[1];
    for (int j = 1; j <= 200000; j++){
      for (int k = j * 2; k <= 200000; k += j){
        dp[k] = max(dp[k], dp[j] + cnt[k]);
        ans = max(ans, dp[k]);
      }
    }
    cout << n - ans << endl;
  }
}