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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> c(30, 0);
  for (int i = 0; i < n; i++){
    c[__builtin_ctz(a[i])]++;
  }
  long long ans = modpow(2, n) - modpow(2, n - c[0]) + MOD;
  for (int i = 1; i < 30; i++){
    if (c[i] > 0){
      long long add = 0;
      for (int j = 2; j <= c[i]; j += 2){
        add += modbinom(c[i], j);
      }
      add %= MOD;
      for (int j = i + 1; j < 30; j++){
        add *= modpow(2, c[j]);
        add %= MOD;
      }
      ans += add;
    }
  }
  ans %= MOD;
  cout << ans << endl;
}