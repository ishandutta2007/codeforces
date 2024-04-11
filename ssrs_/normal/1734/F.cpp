#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long n, m;
    cin >> n >> m;
    vector<vector<vector<vector<long long>>>> dp(61, vector<vector<vector<long long>>>(2, vector<vector<long long>>(2, vector<long long>(2, 0))));
    dp[0][1][0][0] = 1;
    for (int j = 0; j < 60; j++){
      for (int s = 0; s < 2; s++){
        for (int p = 0; p < 2; p++){
          for (int c = 0; c < 2; c++){
            for (int d = 0; d < 2; d++){
              int s2 = s;
              if (d != (m >> j & 1)){
                s2 = d;
              }
              int p2 = 0;
              int c2 = c;
              if ((n >> j & 1) + d + p >= 2){
                p2 = 1;
                c2 = 1 - c;
              }
              dp[j + 1][s2][p2][c2] += dp[j][s][p][c];
            }
          }
        }
      }
    }
    int p = __builtin_parityll(n);
    cout << dp[60][0][0][1 - p] + dp[60][0][1][1 - p] << endl;
  }  
}