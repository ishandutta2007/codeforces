#include <bits/stdc++.h>
using namespace std;
const int MAX = 500;
const int INF = 100000;
int main(){
  vector<vector<vector<vector<int>>>> dp(2, vector<vector<vector<int>>>(2, vector<vector<int>>(MAX + 1, vector<int>(MAX + 1, INF))));
  dp[0][1][0][0] = 0;
  dp[1][1][0][0] = 0;
  for (int i = 0; i <= MAX; i++){
    for (int j = 0; j <= MAX - i; j++){
      for (int l = 1; l >= 0; l--){
        for (int k = 1; k >= 0; k--){
          if (i > 0){
            dp[k][l][i][j] = min(dp[k][l][i][j], 1 - dp[0][l][i - 1][j + 1]);
          }
          if (j > 0){
            dp[k][l][i][j] = min(dp[k][l][i][j], 1 - dp[0][l][i][j - 1]);
          }
          if (k == 0 && j > 0){
            dp[k][l][i][j] = min(dp[k][l][i][j], -dp[1][l][i][j]);
          }
          if (l == 0){
            dp[k][l][i][j] = min(dp[k][l][i][j], 1 - dp[0][1][i][j]);
          }
        }
      }
    }
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int c = 1;
    if (n % 2 == 1){
      c = s[n / 2] - '0';
    }
    int a = 0, b = 0;
    for (int j = 0; j < n / 2; j++){
      int sum = (s[j] - '0') + (s[n - 1 - j] - '0');
      if (sum == 0){
        a++;
      }
      if (sum == 1){
        b++;
      }
    }
    int ans = dp[0][c][a][b];
    if (ans < 0){
      cout << "ALICE" << endl;
    } else if (ans > 0){
      cout << "BOB" << endl;
    } else {
      cout << "DRAW" << endl;
    }
  }
}