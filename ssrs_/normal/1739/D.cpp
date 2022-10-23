#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int j = 1; j < n; j++){
      cin >> p[j];
      p[j]--;
    }
    int tv = n, fv = 0;
    while (tv - fv > 1){
      int mid = (tv + fv) / 2;
      int cnt = 0;
      vector<int> dp(n, 0);
      for (int j = n - 1; j >= 1; j--){
        if (p[j] != 0 && dp[j] >= mid - 1){
          cnt++;
        } else {
          dp[p[j]] = max(dp[p[j]], dp[j] + 1);
        }
      }
      if (cnt <= k){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    cout << tv << endl;
  }
}