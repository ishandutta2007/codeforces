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
  int n, k;
  cin >> n >> k;
  long long ans = 0;
  for (int i = 1; i * k <= n; i++){
    ans += modbinom(n / i - 1, k - 1);
    ans %= MOD;
  }
  cout << ans << endl;
}