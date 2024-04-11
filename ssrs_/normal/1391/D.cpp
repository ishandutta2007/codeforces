#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<char>> a(n, vector<char>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> a[i][j];
    }
  }
  if (n >= 4 && m >= 4){
    cout << -1 << endl;
  } else {
    vector<vector<char>> b;
    if (n > m){
      swap(n, m);
      b = vector<vector<char>>(n, vector<char>(m));
      for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
          b[i][j] = a[j][i];
        }
      }
    } else {
      b = vector<vector<char>>(n, vector<char>(m));
      for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
          b[i][j] = a[i][j];
        }
      }
    }
    vector<vector<int>> dp(m, vector<int>(1 << n, INF));
    for (int i = 0; i < (1 << n); i++){
      dp[0][i] = 0;
      for (int j = 0; j < n; j++){
        if ((i >> j & 1) != a[j][0] - '0'){
          dp[0][i]++;
        }
      }
    }
    for (int i = 1; i < m; i++){
      for (int j = 0; j < (1 << n); j++){
        for (int k = 0; k < (1 << n); k++){
          bool ok = true;
          for (int l = 0; l < n - 1; l++){
            int a = j >> l & 1;
            int b = j >> (l + 1) & 1;
            int c = k >> l & 1;
            int d = k >> (l + 1) & 1;
            if ((a + b + c + d) % 2 != 1){
              ok = false;
            }
          }
          if (ok){
            int tmp = dp[i - 1][j];
            for (int l = 0; l < n; l++){
              if ((k >> l & 1) != a[l][i] - '0'){
                tmp++;
              }
            }
            dp[i][k] = min(dp[i][k], tmp);
          }
        }
      }
    }
    int ans = INF;
    for (int i = 0; i < (1 << n); i++){
      ans = min(ans, dp[m - 1][i]);
    }
    cout << ans << endl;
  }
}