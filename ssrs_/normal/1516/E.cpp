#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
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
long long modbinom(long long n, int r){
	if (n < 0 || r < 0 || r > n){
		return 0;
	}
	long long ans = 1;
	for (int i = 0; i < r; i++){
		ans = ans * ((n - i) % MOD) % MOD;
		ans = ans * modinv(i + 1) % MOD;
	}
	return ans;
}
int main(){
  int n, k;
  cin >> n >> k;
  vector<long long> INV(k + 1);
  for (int i = 1; i <= k; i++){
    INV[i] = modinv(i);
  }
  vector<vector<long long>> binom(k * 2 + 1, vector<long long>(k + 2));
  for (int i = 0; i <= k * 2; i++){
    for (int j = 0; j <= k + 1; j++){
      binom[i][j] = modbinom(n - i, j);
    }
  }
  vector<vector<long long>> dp(k + 1, vector<long long>(k + 1, 0));
  dp[0][0] = 1;
  for (int i = 1; i <= k; i++){
    for (int j = k - i; j >= 0; j--){
      for (int c = 0; c < k; c++){
        if (dp[j][c] > 0){
          long long p = 1;
          int c2 = j + c;
          int cnt = 0;
          for (int j2 = j + i; j2 <= k; j2 += i){
            c2 += i + 1;
            if (c2 > n){
              break;
            }
            cnt++;
            if (c + cnt > k){
              break;
            }
            p *= binom[c2 - (i + 1)][i + 1];
            p %= MOD;
            p *= modfact(i);
            p %= MOD;
            p *= INV[cnt];
            p %= MOD;
            dp[j2][c + cnt] += dp[j][c] * p;
            dp[j2][c + cnt] %= MOD;
          }
        }
      }
    }
  }
  vector<long long> ans(k + 1, 0);
  for (int i = 0; i <= k; i++){
    for (int j = 0; j <= k; j++){
      ans[i] += dp[i][j];
      ans[i] %= MOD;
    }
  }
  for (int i = 0; i < k - 1; i++){
    ans[i + 2] += ans[i];
    ans[i + 2] %= MOD;
  }
  for (int i = 1; i <= k; i++){
    cout << ans[i];
    if (i < k){
      cout << ' ';
    }
  }
  cout << endl;
}