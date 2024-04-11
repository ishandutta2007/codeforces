#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> r(m), c(m);
    for (int j = 0; j < m; j++){
      cin >> r[j] >> c[j];
      r[j]--;
      c[j]--;
    }
    vector<pair<int, int>> ct(m);
    for (int j = 0; j < m; j++){
      ct[j] = make_pair(c[j], j);
    }
    sort(ct.begin(), ct.end());
    vector<int> d(m - 1);
    for (int j = 0; j < m - 1; j++){
      d[j] = ct[j + 1].first - ct[j].first;
      if (d[j] >= 4){
        d[j] = d[j] % 2 + 2;
      }
    }
    ct[0].first %= 2;
    for (int j = 0; j < m - 1; j++){
      ct[j + 1].first = ct[j].first + d[j];
    }
    int n2 = ct[m - 1].first + 2;
    for (int j = 0; j < m; j++){
      c[ct[j].second] = ct[j].first;
    }
    vector<int> s(n2, 0);
    for (int j = 0; j < m; j++){
      s[c[j]] |= 1 << r[j];
    }
    vector<vector<bool>> dp(n2 + 1, vector<bool>(4, false));
    dp[0][0] = true;
    for (int j = 0; j < n2; j++){
      if (dp[j][0] || dp[j][3]){
        dp[j + 1][0] = true;
        dp[j + 1][3] = true;
      }
      if (dp[j][1]){
        dp[j + 1][2] = true;
      }
      if (dp[j][2]){
        dp[j + 1][1] = true;
      }
      for (int k = 0; k < 4; k++){
        if ((k & s[j]) == s[j]){
          dp[j + 1][k] = dp[j + 1][k - s[j]];
        }
      }
      for (int k = 0; k < 4; k++){
        if ((k & s[j]) != s[j]){
          dp[j + 1][k] = false;
        }
      }
    }
    if (dp[n2][3]){
      cout << "YES" << endl;
    } else {
      cout << "NO"  << endl;
    }
  }
}