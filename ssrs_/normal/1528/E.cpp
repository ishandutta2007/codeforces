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
long long modbinom2(long long n, int r){
	long long ans = 1;
	for (int i = 0; i < r; i++){
		ans = ans * ((n - i) % MOD) % MOD;
		ans = ans * modinv(i + 1) % MOD;
	}
	return ans;
}
int main(){
  int n;
  cin >> n;
  vector<long long> dp(n);
  dp[0] = 1;
  long long sum = 2;
  for (int i = 1; i < n; i++){
    long long a = sum;
    long long b = (sum + MOD - dp[i - 1]) % MOD;
    dp[i] = a * (a + 1) / 2 % MOD - b * (b + 1) / 2 % MOD;
    dp[i] += MOD;
    dp[i] %= MOD;
    sum += dp[i];
    sum %= MOD;
  }
  long long ans = 0;
  ans += modbinom2(sum + 2, 3);
  sum += MOD - dp[n - 1];
  sum %= MOD;
  ans += MOD - modbinom2(sum + 2, 3);
  ans %= MOD;
  ans *= 2;
  ans %= MOD;
  ans += MOD - 1;
  ans %= MOD;
  for (int i = 1; i < n - 1; i++){
    long long tmp = 1;
    tmp *= dp[i] + MOD - 1;
    tmp %= MOD;
    tmp *= dp[n - 1 - i] - dp[n - 2 - i] + MOD;
    tmp %= MOD;
    ans += tmp;
    ans %= MOD;
  }
  cout << ans << endl;
}