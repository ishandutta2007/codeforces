#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<string> dp(1 << n);
  for (int i = (1 << (n - 1)); i < (1 << n); i++){
    dp[i] = string(1, s[i - 1]);
  }
  for (int i = (1 << (n - 1)) - 1; i >= 1; i--){
    dp[i] = string(1, s[i - 1]) + min(dp[i * 2] + dp[i * 2 + 1], dp[i * 2 + 1] + dp[i * 2]);
  }
  long long ans = 1;
  for (int i = 1; i < (1 << (n - 1)); i++){
    if (dp[i * 2] != dp[i * 2 + 1]){
      ans *= 2;
      ans %= MOD;
    }
  }
  cout << ans << endl;
}