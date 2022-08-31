#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> f(n);
  for (int i = 1; i < n; i++){
    cin >> f[i];
    f[i]--;
  }
  vector<vector<int>> c(n);
  for (int i = 1; i < n; i++){
    c[f[i]].push_back(i);
  }
  int k = 0;
  for (int i = 0; i < n; i++){
    if (c[i].empty()){
      k++;
    }
  }
  vector<int> dp(n, 0);
  for (int i = n - 1; i >= 0; i--){
    if (c[i].empty()){
      dp[i] = 1;
    } else {
      if (a[i] == 0){
        for (int j : c[i]){
          dp[i] += dp[j];
        }
      }
      if (a[i] == 1){
        dp[i] = INF;
        for (int j : c[i]){
          dp[i] = min(dp[i], dp[j]);
        }
      }
    }
  }
  cout << k - dp[0] + 1 << endl;
}