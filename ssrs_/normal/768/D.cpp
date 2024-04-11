#include <bits/stdc++.h>
using namespace std;
int main(){
  int k, q;
  cin >> k >> q;
  vector<vector<double>> dp(8001, vector<double>(k + 1, 0));
  dp[0][0] = 1;
  for (int i = 0; i < 8000; i++){
    for (int j = 0; j <= k; j++){
      dp[i + 1][j] += dp[i][j] * j / k;
      if (j < k){
        dp[i + 1][j + 1] += dp[i][j] * (k - j) / k;
      }
    }
  }
  for (int i = 0; i < q; i++){
    double p;
    cin >> p;
    p /= 2000;
    int tv = 8000, fv = 0;
    while (tv - fv > 1){
      int mid = (tv + fv) / 2;
      if (dp[mid][k] >= p){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    cout << tv << endl;
  }
}