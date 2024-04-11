#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000000;
int main(){
  vector<vector<int>> t(3, vector<int>(3));
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      cin >> t[i][j];
    }
  }
  int n;
  cin >> n;
  vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(3, vector<long long>(3, INF)));
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      if (i != j){
        int k = 3 - i - j;
        dp[0][i][j] = min(t[i][j], t[i][k] + t[k][j]);
      }
    }
  }
  for (int i = 0; i < n - 1; i++){
    for (int j = 0; j < 3; j++){
      for (int k = 0; k < 3; k++){
        if (j != k){
          int l = 3 - j - k;
          dp[i + 1][j][k] = min(dp[i][j][l] + t[j][k] + dp[i][l][k], dp[i][j][k] + t[j][l] + dp[i][k][j] + t[l][k] + dp[i][j][k]);
        }
      }
    }
  }
  cout << dp[n - 1][0][2] << endl;
}