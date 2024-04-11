#include <bits/stdc++.h>
using namespace std;
int INF = 100000000;
int main(){
  int r, n;
  cin >> r >> n;
  vector<int> t(n + 1), x(n + 1), y(n + 1);
  t[0] = 0;
  x[0] = 1;
  y[0] = 1;
  for (int i = 1; i <= n; i++){
    cin >> t[i] >> x[i] >> y[i];
  }
  vector<int> dp(n + 1, -INF);
  dp[0] = 0;
  vector<int> dpm(n + 1, -INF);
  dpm[0] = 0;
  for (int i = 1; i <= n; i++){
    for (int j = i - 1; j >= 0; j--){
      if (t[i] - t[j] >= r * 2){
        dp[i] = max(dp[i], dpm[j] + 1);
        break;
      }
      if (t[i] - t[j] >= abs(x[j] - x[i]) + abs(y[j] - y[i])){
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    dpm[i] = max(dpm[i - 1], dp[i]);
  }
  cout << dpm[n] << endl;
}