#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
long long modpow(long long a, long long b){
	long long ans = 1;
	while (b > 0){
		if (b % 2 == 1){
			ans *= a;
			ans %= MOD;
		}
		a *= a;
		a %= MOD;
		b /= 2;
	}
	return ans;
}
long long modinv(long long a){
	return modpow(a, MOD - 2);
}
int main(){
  int n, k, l;
  cin >> n >> k >> l;
  vector<vector<long long>> dp1(n * 2 + 1, vector<long long>(n + 1, 0));
  vector<vector<long long>> dp2(n * 2 + 1, vector<long long>(n + 1, 0));
  dp1[0][0] = 1;
  for (int i = 0; i < n * 2; i++){
    for (int j = 0; j <= n; j++){
      dp1[i + 1][j] += dp1[i][j] * (2 * j - i);
      dp1[i + 1][j] %= MOD;
      dp2[i + 1][j] += dp2[i][j] * (2 * j - i);
      if (2 * j - (i + 1) >= k){
        dp2[i + 1][j] += dp1[i][j] * (2 * j - i);
      }
      dp2[i + 1][j] %= MOD;
      if (j < n){
        dp1[i + 1][j + 1] += dp1[i][j];
        dp1[i + 1][j + 1] %= MOD;
        dp2[i + 1][j + 1] += dp2[i][j];
        if (2 * (j + 1) - (i + 1) >= k){
          dp2[i + 1][j + 1] += dp1[i][j];
        }
        dp2[i + 1][j + 1] %= MOD;
      }
    }
  }
  long long L = l * modinv(n * 2 + 1) % MOD;
  cout << dp2[n * 2][n] * L % MOD * modinv(dp1[n * 2][n]) % MOD << endl;
}