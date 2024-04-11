#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<vector<bool>> dp(n + 1, vector<bool>(k * 2 + 1, false));
  dp[0][k] = true;
  for (int i = 0; i < n; i++){
    for (int j = 0; j <= k * 2; j++){
      if (dp[i][j]){
        if (s[i] == 'W' || s[i] == '?'){
          if (j < k * 2){
            if (!(i < n - 1 && j + 1 == k * 2)){
              dp[i + 1][j + 1] = true;
            }
          }
        }
        if (s[i] == 'D' || s[i] == '?'){
          dp[i + 1][j] = true;
        }
        if (s[i] == 'L' || s[i] == '?'){
          if (j > 0){
            if (!(i < n - 1 && j - 1 == 0)){
              dp[i + 1][j - 1] = true;
            }
          }
        }
      }
    }
  }
  if (!dp[n][0] && !dp[n][k * 2]){
    cout << "NO" << endl;
  } else {
    int p;
    if (dp[n][0]){
      p = 0;
    }
    if (dp[n][k * 2]){
      p = k * 2;
    }
    for (int i = n - 1; i >= 0; i--){
      if (s[i] == 'W'){
        p--;
      }
      if (s[i] == 'L'){
        p++;
      }
      if (s[i] == '?'){
        int p2;
        if (p > 0){
          if (dp[i][p - 1]){
            p2 = p - 1;
          }
        }
        if (dp[i][p]){
          p2 = p;
        }
        if (p < k * 2){
          if (dp[i][p + 1]){
            p2 = p + 1;
          }
        }
        if (p2 == p - 1){
          s[i] = 'W';
        }
        if (p2 == p){
          s[i] = 'D';
        }
        if (p2 == p + 1){
          s[i] = 'L';
        }
        p = p2;
      }
    }
    cout << s << endl;
  }
}