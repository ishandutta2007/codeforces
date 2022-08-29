#include <bits/stdc++.h>
using namespace std;
int bit(string s){
  int ans = 0;
  for (int i = 0; i < s.size(); i++){
    ans *= 2;
    ans += s[i] - '0';
  }
  return ans;
}
int main(){
  vector<int> NUM(10);
  NUM[0] = 0b1110111;
  NUM[1] = 0b0010010;
  NUM[2] = 0b1011101;
  NUM[3] = 0b1011011;
  NUM[4] = 0b0111010;
  NUM[5] = 0b1101011;
  NUM[6] = 0b1101111;
  NUM[7] = 0b1010010;
  NUM[8] = 0b1111111;
  NUM[9] = 0b1111011;
  int n;
  cin >> n;
  int K;
  cin >> K;
  vector<string> s(n);
  for (int i = 0; i < n; i++){
    cin >> s[i];
  }
  vector<int> v(n);
  for (int i = 0; i < n; i++){
    v[i] = bit(s[i]);
  }
  vector<vector<bool>> P(n, vector<bool>(8, false));
  for (int i = 0; i < n; i++){
    for (int d = 0; d < 10; d++){
      if ((v[i] | NUM[d]) == NUM[d]){
        int diff = __builtin_popcount(NUM[d]) - __builtin_popcount(v[i]);
        P[i][diff] = true;
      }
    }
  }
  vector<vector<bool>> dp(n + 1, vector<bool>(K + 1, false));
  dp[0][0] = true;
  for (int i = 0; i < n; i++){
    for (int j = 0; j <= K; j++){
      if (dp[i][j]){
        for (int k = 0; k < 8; k++){
          if (P[n - 1 - i][k]){
            if (j + k <= K){
              dp[i + 1][j + k] = true;
            }
          }
        }
      }
    }
  }
  /*
  for (int i = 0; i <= n; i++){
    for (int j = 0; j <= K; j++){
      cout << dp[i][j] << ' ';
    }
    cout << endl;
  }
  */
  if (!dp[n][K]){
    cout << -1 << endl;
  } else {
    string res;
    for (int i = 0; i < n; i++){
      for (int d = 9; d >= 0; d--){
        if ((v[i] | NUM[d]) == NUM[d]){
          int diff = __builtin_popcount(NUM[d]) - __builtin_popcount(v[i]);
          if (K - diff >= 0){
            if (dp[n - 1 - i][K - diff]){
              res += '0' + d;
              K -= diff;
              break;
            }
          }
        }
      }
    }
    cout << res << endl;
  }
}