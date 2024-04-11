#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> tag(n);
    for (int j = 0; j < n; j++){
      cin >> tag[j];
    }
    vector<int> s(n);
    for (int j = 0; j < n; j++){
      cin >> s[j];
    }
    vector<long long> dp(n, 0);
    for (int j = 1; j < n; j++){
      for (int k = j - 1; k >= 0; k--){
        if (tag[j] != tag[k]){
          long long tmp1 = dp[k] + abs(s[k] - s[j]);
          long long tmp2 = dp[j] + abs(s[k] - s[j]);
          dp[j] = max(dp[j], tmp1);
          dp[k] = max(dp[k], tmp2);
        }
      }
    }
    long long ans = 0;
    for (int j = 0; j < n; j++){
      ans = max(ans, dp[j]);
    }
    cout << ans << endl;
  }
}