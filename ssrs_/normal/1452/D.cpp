#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main(){
  int n;
  cin >> n;
  vector<long long> dp(n + 1, 0);
  dp[0] = 1;
  long long odd = 0, even = 1;
  for (int i = 1; i <= n; i++){
    if (i % 2 == 1){
      dp[i] = even;
      odd = (odd + dp[i]) % MOD;
    } else {
      dp[i] = odd;
      even = (even + dp[i]) % MOD;
    }
  }
  long long ans = dp[n];
  for (int i = 0; i < n; i++){
    ans *= 499122177;
    ans %= MOD;
  }
  cout << ans << endl;
}