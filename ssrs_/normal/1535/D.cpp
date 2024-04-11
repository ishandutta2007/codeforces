#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int k;
  cin >> k;
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  int n = (1 << k) * 2 - 1;
  vector<int> dp(n, 0);
  for (int i = 0; i < (1 << k); i++){
    dp[(1 << k) - 1 + i] = 1;
  }
  for (int i = (1 << k) - 2; i >= 0; i--){
    if (s[i] == '1' || s[i] == '?'){
      dp[i] += dp[i * 2 + 1];
    }
    if (s[i] == '0' || s[i] == '?'){
      dp[i] += dp[i * 2 + 2];
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    int p;
    char c;
    cin >> p >> c;
    p = (1 << k) - 1 - p;
    s[p] = c;
    dp[p] = 0;
    if (s[p] == '1' || s[p] == '?'){
      dp[p] += dp[p * 2 + 1];
    }
    if (s[p] == '0' || s[p] == '?'){
      dp[p] += dp[p * 2 + 2];
    }
    while (p > 0){
      p = (p - 1) / 2;
      dp[p] = 0;
      if (s[p] == '1' || s[p] == '?'){
        dp[p] += dp[p * 2 + 1];
      }
      if (s[p] == '0' || s[p] == '?'){
        dp[p] += dp[p * 2 + 2];
      }
    }
    cout << dp[0] << "\n";
  }
}