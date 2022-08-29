#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, M;
  cin >> n >> M;
  vector<vector<long long>> dp1(n + 1, vector<long long>(n + 1, 0));
  vector<vector<long long>> dp2(n + 1, vector<long long>(n + 1, 0));
  dp2[1][0] = 1;
  for (int i = 0; i < n - 1; i++){
    vector<vector<long long>> imos1(n + 1, vector<long long>(n + 2, 0));
    vector<vector<long long>> imos2(n + 1, vector<long long>(n + 2, 0));
    for (int j = 1; j <= i + 1; j++){
      imos2[j + 1][0] += dp1[j][n];
      imos2[j + 1][j + 1] += M - dp1[j][n];
      for (int k = 0; k < j; k++){
        imos1[j + 1][k + 1] += dp1[j][k];
        imos1[j + 1][j + 1] += M - dp1[j][k];
        imos1[j][n] += dp1[j][k];
        imos1[j][n + 1] += M - dp1[j][k];
        imos2[j + 1][0] += dp2[j][k];
        imos2[j + 1][k + 1] += M - dp2[j][k];
        imos1[j + 1][k + 1] += dp2[j][k];
        imos1[j + 1][j + 1] += M - dp2[j][k];
        imos1[j][n] += dp2[j][k];
        imos1[j][n + 1] += M - dp2[j][k];
      }
    }
    for (int j = 0; j <= n; j++){
      for (int k = 0; k <= n; k++){
        imos1[j][k] %= M;
        imos1[j][k + 1] += imos1[j][k];
        imos2[j][k] %= M;
        imos2[j][k + 1] += imos2[j][k];
      }
    }
    for (int j = 0; j <= n; j++){
      for (int k = 0; k <= n; k++){
        dp1[j][k] = imos1[j][k];
        dp2[j][k] = imos2[j][k];
      }
    }
  }
  long long ans = 0;
  for (int j = 0; j <= n; j++){
    for (int k = 0; k < n; k++){
      ans += dp1[j][k];
      ans += dp2[j][k];
    }
  }
  ans %= M;
  cout << ans << endl;
}