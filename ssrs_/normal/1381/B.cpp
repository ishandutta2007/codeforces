#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> p(n * 2);
    for (int j = 0; j < n * 2; j++){
      cin >> p[j];
    }
    int mx = -1;
    vector<int> len;
    for (int j = 0; j < n * 2; j++){
      if (p[j] > mx){
        mx = p[j];
        len.push_back(1);
      } else {
        len.back()++;
      }
    }
    int cnt = len.size();
    vector<vector<bool>> dp(cnt + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int j = 0; j < cnt; j++){
      for (int k = 0; k <= n; k++){
        if (dp[j][k]){
          dp[j + 1][k] = true;
          if (k + len[j] <= n){
            dp[j + 1][k + len[j]] = true;
          }
        }
      }
    }
    if (dp[cnt][n]){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}