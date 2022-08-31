#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
int main(){
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++){
    cin >> s[i];
  }
  vector<int> sum(n, 0);
  vector<int> mn(n, 1);
  vector<map<int, int>> mp(n);
  for (int i = 0; i < n; i++){
    int L = s[i].size();
    for (int j = 0; j < L; j++){
      if (s[i][j] == '('){
        sum[i]++;
      }
      if (s[i][j] == ')'){
        sum[i]--;
      }
      if (sum[i] < mn[i]){
        mn[i] = sum[i];
      }
      if (sum[i] == mn[i]){
        mp[i][mn[i]]++;
      }
    }
  }
  int ans = 0;
  vector<int> dp(1 << n, -INF);
  dp[0] = 0;
  for (int i = 0; i < (1 << n); i++){
    int p = 0;
    for (int j = 0; j < n; j++){
      if ((i >> j & 1) == 1){
        p += sum[j];
      }
    }
    if (p >= 0){
      for (int j = 0; j < n; j++){
        if ((i >> j & 1) == 0){
          int i2 = i | (1 << j);
          if (p > -mn[j]){
            dp[i2] = max(dp[i2], dp[i]);
          } else if (p == -mn[j]){
            dp[i2] = max(dp[i2], dp[i] + mp[j][mn[j]]);
            ans = max(ans, dp[i2]);
          } else {
            ans = max(ans, dp[i] + mp[j][-p]);
          }
        }
      }
    }
  }
  cout << ans << endl;
}