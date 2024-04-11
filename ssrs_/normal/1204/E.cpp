#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244853;
long long modsub(long long a, long long b){
	return (a % MOD - b % MOD + MOD) % MOD;
}
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
vector<long long> mf = {1};
vector<long long> mfi = {1};
long long modfact(int n){
	if (mf.size() > n){
		return mf[n];
	} else {
		for (int i = mf.size(); i <= n; i++){
			long long next = mf.back() * i % MOD;
			mf.push_back(next);
			mfi.push_back(modinv(next));
		}
		return mf[n];
	}
}
long long modfactinv(int n){
	if (mfi.size() > n){
		return mfi[n];
	} else {
		return modinv(modfact(n));
	}
}
long long modbinom(int n, int k){
	if (n < 0 || k < 0 || k > n){
		return 0;
	} else {
		return modfact(n) * modfactinv(k) % MOD * modfactinv(n - k) % MOD;
	}
}
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<long long>> dp(2001, vector<long long>(2001, 0));
  dp[0][0] = 1;
  for (int i = 0; i < 2001; i++){
    for (int j = 0; j < 2001; j++){
      if (i < 2000){
        dp[i + 1][j] += dp[i][j];
        dp[i + 1][j] %= MOD;
      }
      if (j < 2000){
        if (j + 1 <= i){
          dp[i][j + 1] += dp[i][j];
          dp[i][j + 1] %= MOD;
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++){
    for (int j = 0; j <= n + m; j++){
      if ((i + j) % 2 != 0 || j < i){
        continue;
      }
      int po = (j + i) / 2;
      int ne = (j - i) / 2;
      if (po > n || ne > m){
        continue;
      }
      ans += dp[po - 1][ne] * dp[m - ne][n - po] % MOD * i % MOD;
    }
  }
  ans %= MOD;
  cout << ans << endl;
}