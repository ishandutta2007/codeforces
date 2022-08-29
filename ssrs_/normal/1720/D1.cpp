#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> dp(n, 1);
    int ans = 0;
    for (int j = 1; j < n; j++){
      for (int k = j - 1; k >= max(j - 256, 0); k--){
        if ((a[k] ^ j) < (a[j] ^ k)){
          dp[j] = max(dp[j], dp[k] + 1);
        }
      }
      ans = max(ans, dp[j]);
    }
    cout << ans << endl;
  }
}