#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main(){
  int n;
  cin >> n;
  if (n == 1){
    cout << 1 << endl;
  } else {
    vector<int> f(n + 1, 0);
    for (int i = 2; i <= n; i++){
      for (int j = i * 2; j <= n; j += i){
        f[j]++;
      }
    }
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    long long sum = 2;
    for (int i = 2; i <= n; i++){
      dp[i] = sum + 1 + f[i];
      dp[i] %= MOD;
      sum += dp[i];
      sum %= MOD;
    }
    cout << dp[n] << endl;
  }
}