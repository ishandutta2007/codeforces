#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
int main(){
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<vector<int>> S(k, vector<int>(n + 1));
  for (int i = 0; i < k; i++){
    S[i][0] = 0;
    for (int j = 0; j < n; j++){
      S[i][j + 1] = S[i][j];
      if (s[j] == (char) ('a' + i) || s[j] == '?'){
        S[i][j + 1]++;
      }
    }
  }
  int tv = 0, fv = n + 1;
  while (fv - tv > 1){
    int mid = (tv + fv) / 2;
    vector<vector<int>> L(k);
    for (int i = 0; i < k; i++){
      for (int j = 0; j <= n - mid; j++){
        if (S[i][j + mid] - S[i][j] == mid){
          L[i].push_back(j);
        }
      }
    }
    vector<int> dp(1 << k, INF);
    dp[0] = 0;
    for (int i = 0; i < (1 << k); i++){
      if (dp[i] != INF){
        for (int j = 0; j < k; j++){
          if ((i >> j & 1) == 0){
            auto itr = lower_bound(L[j].begin(), L[j].end(), dp[i]);
            if (itr != L[j].end()){
              int i2 = i | (1 << j);
              dp[i2] = min(dp[i2], *itr + mid);
            }
          }
        }
      }
    }
    if (dp[(1 << k) - 1] <= n){
      tv = mid;
    } else {
      fv = mid;
    }
  }
  cout << tv << endl;
}