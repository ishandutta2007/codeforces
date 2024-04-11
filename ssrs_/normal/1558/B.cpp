#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<long long> dp(n + 1, 0);
  dp[n] = 1;
  vector<long long> dpS(n + 2, 0);
  dpS[n] = 1;
  for (int j = n - 1; j >= 1; j--){
    dp[j] = dpS[j + 1] - dpS[n + 1];
    for (int k = 2; j * k <= n; k++){
      dp[j] += dpS[j * k] - dpS[min((j + 1) * k, n + 1)];
      dp[j] += m;
    }
    dp[j] %= m;
    dpS[j] = (dpS[j + 1] + dp[j]) % m;
  }
  cout << dp[1] << endl;
}