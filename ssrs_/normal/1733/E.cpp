#include <bits/stdc++.h>
using namespace std;
long long solve(long long t, int x, int y){
  vector<vector<long long>> dp(x + 1, vector<long long>(y + 1, 0));
  dp[0][0] = t;
  for (int i = 0; i <= x; i++){
    for (int j = 0; j <= y; j++){
      if (i > 0){
        dp[i][j] += dp[i - 1][j] / 2;
      }
      if (j > 0){
        dp[i][j] += (dp[i][j - 1] + 1) / 2;
      }
    }
  }
  return dp[x][y];
}
int main(){
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    long long t, x, y;
    cin >> t >> x >> y;
    if (x + y > t){
      cout << "NO" << endl;
    } else {
      if (solve(t - x - y + 1, x, y) > solve(t - x - y, x, y)){
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}