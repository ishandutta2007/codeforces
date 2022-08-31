#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;
long long modsub(long long a, long long b){
	a %= MOD;
	b %= MOD;
	if (a >= b){
		return (a - b) % MOD;
	} else {
		return MOD - (b - a) % MOD;
	}
}
long long modpow(long long a, long long b){
	a %= MOD;
	long long res = 1;
	while (b > 0){
		if (b % 2 == 1) res = res * a % MOD;
		a = a * a % MOD;
		b = b / 2;
	}
	return res;
}
long long modinv(long long a){
	return modpow(a, MOD - 2);
}
vector<long long> mf;
long long modfact(long long n){
	if (n < mf.size()){
		return mf[n];
	} else {
		if (mf.empty()) mf.push_back(1);
		long long res = mf.back();
		for (int i = mf.size(); i <= n; i++){
			res = res * i % MOD;
			mf.push_back(res);
		}
		return res;
	}
}
long long modbinom(long long n, long long r){
	long long res;
	res = modfact(n);
	res = res * modinv(modfact(r)) % MOD;
	res = res * modinv(modfact(n - r)) % MOD ;
	return res;
}
int main(){
  int n;
  long long k;
  cin >> n >> k;
  if (k >= n){
    cout << 0 << endl;
  } else {
    long long ans = 0;
    for (int i = 0; i <= n - k; i++){
      long long tmp = modpow(i, n) * modbinom(n - k, i) % MOD;
      if ((n - k) % 2 == i % 2){
        ans = (ans + tmp) % MOD;
      } else {
        ans = modsub(ans, tmp);
      }
    }
    ans *= modbinom(n, k);
    ans %= MOD;
    if (k != 0){
      ans *= 2;
      ans %= MOD;
    }
    cout << ans << endl;
  }
}