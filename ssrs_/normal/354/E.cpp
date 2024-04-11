#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &c, vector<int> &a, int sum, int p){
  if (p == 6){
    c[sum] = a;
  } else {
    a[p] = 0;
    dfs(c, a, sum, p + 1);
    a[p] = 4;
    dfs(c, a, sum + 4, p + 1);
    a[p] = 7;
    dfs(c, a, sum + 7, p + 1);
  }
}
int main(){
  vector<vector<int>> c(43);
  vector<int> a(6);
  dfs(c, a, 0, 0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(43, false));
    vector<vector<int>> pr(n + 1, vector<int>(43, -1));
    dp[0][0] = true;
    for (int j = 0; j < n; j++){
      for (int k = 0; k < 43; k++){
        if (dp[j][k]){
          int p = k * 10 + (s[j] - '0');
          for (int l = 0; l < 43; l++){
            if (0 <= p - l && p - l <= 42 && !c[l].empty()){
              dp[j + 1][p - l] = true;
              pr[j + 1][p - l] = k;
            }
          }
        }
      }
    }
    if (!dp[n][0]){
      cout << -1 << endl;
    } else {
      vector<vector<int>> a(n, vector<int>(6, 0));
      int curr = 0;
      for (int j = n - 1; j >= 0; j--){
        int p = pr[j + 1][curr];
        int sum = p * 10 + (s[j] - '0') - curr;
        for (int k = 0; k < 6; k++){
          a[j][k] = c[sum][k];
        }
        curr = p;
      }
      vector<long long> ans(6, 0);
      for (int j = 0; j < n; j++){
        for (int k = 0; k < 6; k++){
          ans[k] = ans[k] * 10 + a[j][k];
        }
      }
      for (int j = 0; j < 6; j++){
        cout << ans[j];
        if (j < 5){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}