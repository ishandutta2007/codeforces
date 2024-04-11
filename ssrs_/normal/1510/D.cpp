#include <bits/stdc++.h>
using namespace std;
const double INF = 10000000;
const double EPS = 0.000001;
int main(){
  int n, d;
  cin >> n >> d;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<vector<double>> dp(n, vector<double>(10, -INF));
  for (int i = 0; i < n; i++){
    dp[i][a[i] % 10] = log(a[i]);
  }
  for (int i = 1; i < n; i++){
    for (int j = 0; j < 10; j++){
      if (dp[i - 1][j] != -INF){
        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        int j2 = j * a[i] % 10;
        dp[i][j2] = max(dp[i][j2], dp[i - 1][j] + log(a[i]));
      }
    }
  }
  if (dp[n - 1][d] == -INF){
    cout << -1 << endl;
  } else {
    vector<int> ans;
    for (int i = n - 1; i >= 1; i--){
      if (abs(dp[i - 1][d] - dp[i][d]) > EPS){
        ans.push_back(a[i]);
        for (int j = 0; j < 10; j++){
          if ((j * a[i]) % 10 == d){
            if (abs(dp[i - 1][j] - dp[i][d] + log(a[i])) < EPS){
              d = j;
              break;
            }
          }
        }
      }
      if (d == a[i - 1] % 10 && abs(dp[i - 1][d] - log(a[i - 1])) < EPS){
        ans.push_back(a[i - 1]);
        break;
      }
    }
    int k = ans.size();
    cout << k << endl;
    for (int i = 0; i < k; i++){
      cout << ans[i];
      if (i < k - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}