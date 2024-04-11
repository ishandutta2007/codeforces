#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int N = s.size();
  bool x = false;
  int ans = 0;
  for (int i = 0; i < 10; i++){
    string t = s;
    for (int j = 0; j < N; j++){
      if (s[j] == 'X'){
        x = true;
        t[j] = '0' + i;
      }
    }
    if (N == 1 || t[0] != '0'){
      vector<vector<int>> dp(N + 1, vector<int>(25, 0));
      dp[0][0] = 1;
      for (int j = 0; j < N; j++){
        for (int k = 0; k < 25; k++){
          for (int l = 0; l < 10; l++){
            if (!(N > 1 && j == 0 && l == 0) && (t[j] == '_' || t[j] == '0' + l)){
              int k2 = (k * 10 + l) % 25;
              dp[j + 1][k2] += dp[j][k];
            }
          }
        }
      }
      ans += dp[N][0];
    }
  }
  if (!x){
    ans /= 10;
  }
  cout << ans << endl;
}