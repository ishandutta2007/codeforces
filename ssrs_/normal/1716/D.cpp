#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main(){
  int n, k;
  cin >> n >> k;
  vector<long long> dp(n + 1, 0);
  dp[0] = 1;
  vector<long long> ans(n + 1, 0);
  for (int i = k; i <= n; i++){
    vector<long long> dp2(n + 1, 0);
    bool ok = false;
    for (int j = i; j <= n; j++){
      dp2[j] = (dp2[j - i] + dp[j - i]) % MOD;
    }
    for (int j = 0; j <= n; j++){
      ans[j] += dp2[j];
      ans[j] %= MOD;
    }
    swap(dp, dp2);
    if (dp == vector<long long>(n + 1, 0)){
      break;
    }
  }
  for (int i = 1; i <= n; i++){
    cout << ans[i];
    if (i < n){
      cout << ' ';
    }
  }
  cout << endl;
}