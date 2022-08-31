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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
    a[i]--;
  }
  vector<int> cnt(n, 0);
  for (int i = 0; i < n; i++){
    cnt[a[i]]++;
  }
  vector<vector<long long>> dp(n, vector<long long>(n, 0));
  for (int i = 0; i < n; i++){
    dp[1][a[i]] += modinv(n);
  }
  long long ans = 0;
  for (int i = 1; i < n; i++){
    long long P = modinv(n - i);
    long long sum = 0;
    for (int j = 0; j < n; j++){
      if (cnt[j] > 0){
        ans += dp[i][j] * (cnt[j] - 1) % MOD * P % MOD;
      }
      if (i < n - 1){
        dp[i + 1][j] = sum * cnt[j] % MOD * P % MOD;
        sum += dp[i][j];
        sum %= MOD;
      }
    }
  }
  ans %= MOD;
  cout << ans << endl;
}