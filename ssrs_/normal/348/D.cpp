#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<string> S(n);
  for (int i = 0; i < n; i++){
    cin >> S[i];
  }
  if (S[0][1] == '#' || S[1][0] == '#' || S[n - 2][m - 1] == '#' || S[n - 1][m - 2] == '#'){
    cout << 0 << endl;
  } else {
    vector<vector<int>> dp1(n, vector<int>(m, 0));
    vector<vector<int>> dp2(n, vector<int>(m, 0));
    dp1[0][1] = 1;
    dp2[1][0] = 1;
    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
        if (i < n - 1){
          if (S[i + 1][j] == '.'){
            dp1[i + 1][j] += dp1[i][j];
            dp1[i + 1][j] %= MOD;
            dp2[i + 1][j] += dp2[i][j];
            dp2[i + 1][j] %= MOD;
          }
        }
        if (j < m - 1){
          if (S[i][j + 1] == '.'){
            dp1[i][j + 1] += dp1[i][j];
            dp1[i][j + 1] %= MOD;
            dp2[i][j + 1] += dp2[i][j];
            dp2[i][j + 1] %= MOD;
          }
        }
      }
    }
    long long cnt1 = (long long) dp1[n - 2][m - 1] * dp2[n - 1][m - 2] % MOD;
    long long cnt2 = (long long) dp1[n - 1][m - 2] * dp2[n - 2][m - 1] % MOD;
    cout << (cnt1 - cnt2 + MOD) % MOD << endl;
  }
}