#include <bits/stdc++.h>
using namespace std;
int main(){
  cout << fixed << setprecision(10);
  int n, k;
  cin >> n >> k;
  vector<double> p(n);
  for (int i = 0; i < n; i++){
    cin >> p[i];
  }
  int cnt = 0;
  for (int i = 0; i < n; i++){
    if (p[i] >= 0.001){
      cnt++;
    }
  }
  k = min(k, cnt);
  vector<double> dp(1 << n, 0);
  dp[0] = 1;
  for (int i = 0; i < (1 << n) - 1; i++){
    double s = 0;
    for (int j = 0; j < n; j++){
      if (!(i >> j & 1)){
        s += p[j];
      }
    }
    if (s <= 0.001) continue;
    double q = dp[i] / s;
    for (int j = 0; j < n; j++){
      if (!(i >> j & 1)){
        dp[i | (1 << j)] += q * p[j];
      }
    }
  }
  vector<long double> ans(n, 0);
  for (int i = 0; i < (1 << n); i++){
    if (__builtin_popcount(i) == k){
      for (int j = 0; j < n; j++){
        if (i >> j & 1){
          ans[j] += dp[i];
        }
      }
    }
  }
  for (int i = 0; i < n; i++){
    cout << ans[i];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}