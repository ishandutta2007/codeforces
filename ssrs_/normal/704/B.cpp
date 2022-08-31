#include <bits/stdc++.h>
using namespace std;
long long INF = 1000000000000000;
int main(){
  int n, s, e;
  cin >> n >> s >> e;
  s--;
  e--;
  vector<long long> x(n);
  for (int i = 0; i < n; i++){
    cin >> x[i];
  }
  vector<long long> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<long long> b(n);
  for (int i = 0; i < n; i++){
    cin >> b[i];
  }
  vector<long long> c(n);
  for (int i = 0; i < n; i++){
    cin >> c[i];
  }
  vector<long long> d(n);
  for (int i = 0; i < n; i++){
    cin >> d[i];
  }
  for (int i = 0; i < n; i++){
    a[i] += x[i];
    b[i] -= x[i];
    c[i] += x[i];
    d[i] -= x[i];
  }
  vector<long long> dp(n * 2 + 1, INF);
  dp[0] = 0;
  for (int i = 0; i < n; i++){
    vector<long long> dp2(n * 2 + 1, INF);
    if (i == s){
      for (int j = 0; j <= n * 2; j++){
        if (dp[j] != INF){
          if (j > 0){
            dp2[j - 1] = min(dp2[j - 1], dp[j] + c[i]);
          }
          if (j < n * 2){
            dp2[j + 1] = min(dp2[j + 1], dp[j] + d[i]);
          }
        }
      }
    } else if (i == e){
      for (int j = 0; j <= n * 2; j++){
        if (dp[j] != INF){
          if (j > 0){
            dp2[j - 1] = min(dp2[j - 1], dp[j] + a[i]);
          }
          if (j < n * 2){
            dp2[j + 1] = min(dp2[j + 1], dp[j] + b[i]);
          }
        }
      }
    } else {
      for (int j = 0; j <= n * 2; j++){
        if (dp[j] != INF){
          if (j > 1){
            dp2[j - 2] = min(dp2[j - 2], dp[j] + a[i] + c[i]);
          }
          if (!(j == 1 && e < i && i < s)){
            dp2[j] = min(dp2[j], dp[j] + a[i] + d[i]);
          }
          if (!(j == 1 && s < i && i < e)){
            dp2[j] = min(dp2[j], dp[j] + b[i] + c[i]);
          }
          if (j < n * 2 - 1){
            dp2[j + 2] = min(dp2[j + 2], dp[j] + b[i] + d[i]);
          }
        }
      }
    }
    if (i < n - 1){
      dp2[0] = INF;
    }
    swap(dp, dp2);
  }
  cout << dp[0] << endl;
}