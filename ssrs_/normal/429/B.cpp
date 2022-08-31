#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> a[i][j];
    }
  }
  vector<vector<long long>> dp1(n, vector<long long>(m, 0));
  dp1[0][0] = a[0][0];
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (i > 0){
        dp1[i][j] = max(dp1[i][j], dp1[i - 1][j] + a[i][j]);
      }
      if (j > 0){
        dp1[i][j] = max(dp1[i][j], dp1[i][j - 1] + a[i][j]);
      }
    }
  }
  vector<vector<long long>> dp2(n, vector<long long>(m, 0));
  dp2[n - 1][0] = a[n - 1][0];
  for (int i = n - 1; i >= 0; i--){
    for (int j = 0; j < m; j++){
      if (i < n - 1){
        dp2[i][j] = max(dp2[i][j], dp2[i + 1][j] + a[i][j]);
      }
      if (j > 0){
        dp2[i][j] = max(dp2[i][j], dp2[i][j - 1] + a[i][j]);
      }
    }
  }
  vector<vector<long long>> dp3(n, vector<long long>(m, 0));
  dp3[0][m - 1] = a[0][m - 1];
  for (int i = 0; i < n; i++){
    for (int j = m - 1; j >= 0; j--){
      if (i > 0){
        dp3[i][j] = max(dp3[i][j], dp3[i - 1][j] + a[i][j]);
      }
      if (j < m - 1){
        dp3[i][j] = max(dp3[i][j], dp3[i][j + 1] + a[i][j]);
      }
    }
  }
  vector<vector<long long>> dp4(n, vector<long long>(m, 0));
  dp4[n - 1][m - 1] = a[n - 1][m - 1];
  for (int i = n - 1; i >= 0; i--){
    for (int j = m - 1; j >= 0; j--){
      if (i < n - 1){
        dp4[i][j] = max(dp4[i][j], dp4[i + 1][j] + a[i][j]);
      }
      if (j < m - 1){
        dp4[i][j] = max(dp4[i][j], dp4[i][j + 1] + a[i][j]);
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i < n - 1; i++){
    for (int j = 1; j < m - 1; j++){
      ans = max(ans, dp1[i - 1][j] + dp2[i][j - 1] + dp3[i][j + 1] + dp4[i + 1][j]);
      ans = max(ans, dp1[i][j - 1] + dp2[i + 1][j] + dp3[i - 1][j] + dp4[i][j + 1]);
    }
  }
  cout << ans << endl;
}