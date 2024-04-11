#include <bits/stdc++.h>
using namespace std;
long long f(int x, int y){
  //a+b=a^b,0<=a<x,0<=b<y
  vector<vector<vector<long long>>> dp(31, vector<vector<long long>>(2, vector<long long>(2, 0)));
  dp[30][0][0] = 1;
  for (int i = 29; i >= 0; i--){
    for (int j = 0; j < 2; j++){
      for (int k = 0; k < 2; k++){
        for (int d1 = 0; d1 < 2; d1++){
          for (int d2 = 0; d2 < 2; d2++){
            if (d1 == 1 && d2 == 1){
              continue;
            }
            if (j == 0 && d1 == 1 && !(x >> i & 1)){
              continue;
            }
            if (k == 0 && d2 == 1 && !(y >> i & 1)){
              continue;
            }
            int j2 = j;
            if (d1 == 0 && (x >> i & 1)){
              j2 = 1;
            }
            int k2 = k;
            if (d2 == 0 && (y >> i & 1)){
              k2 = 1;
            }
            dp[i][j2][k2] += dp[i + 1][j][k];
          }
        }
      }
    }
  }
  return dp[0][1][1];
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int l, r;
    cin >> l >> r;
    r++;
    cout << f(r, r) - f(r, l) - f(l, r) + f(l, l) << endl;
  }
}