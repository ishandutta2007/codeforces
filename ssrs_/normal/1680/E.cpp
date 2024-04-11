#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    int L;
    for (int j = 0; j < n; j++){
      if (s1[j] == '*' || s2[j] == '*'){
        L = j;
        break;
      }
    }
    int R;
    for (int j = n - 1; j >= 0; j--){
      if (s1[j] == '*' || s2[j] == '*'){
        R = j;
        break;
      }
    }
    R++;
    s1 = s1.substr(L, R - L);
    s2 = s2.substr(L, R - L);
    n = R - L;
    vector<vector<int>> dp(4, vector<int>(n + 1, INF));
    dp[0][0] = 0;
    for (int j = 0; j < n; j++){
      for (int k = 0; k < 4; k++){
        for (int l = 0; l < 4; l++){
          bool ok = true;
          if (j > 0 && (k & l) == 0){
            ok = false;
          }
          if ((l & 1) == 0 && s1[j] == '*'){
            ok = false;
          }
          if ((l & 2) == 0 && s2[j] == '*'){
            ok = false;
          }
          if (ok){
            dp[l][j + 1] = min(dp[l][j + 1], dp[k][j] + __builtin_popcount(l));
          }
        }
      }
    }
    int ans = INF;
    for (int j = 0; j < 4; j++){
      ans = min(ans, dp[j][n]);
    }
    cout << ans - 1 << endl;
  }
}