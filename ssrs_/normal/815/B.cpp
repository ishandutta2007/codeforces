#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
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
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int c = (n - 1) % 4 + 1;
  vector<long long> tmp(c);
  int bn = (n - 1) / 4 * 2;
  for (int i = 0; i < c; i++){
    int pos = i;
    for (int r = 0; r <= bn; r++){
      tmp[i] += modbinom(bn, r) * a[pos] % MOD;
      tmp[i] %= MOD;
      pos += 2;
    }
  }
  /*
  for (int i = 0; i < c; i++){
    cout << tmp[i] << ' ';
  }
  */
  if (c == 1){
    cout << tmp[0] << endl;
  } else if (c == 2){
    cout << (tmp[0] + tmp[1]) % MOD << endl;
  } else if (c == 3){
    cout << modsub(tmp[0] + tmp[1] * 2, tmp[2]) << endl;
  } else {
    cout << modsub(tmp[0] + tmp[2], tmp[1] + tmp[3]) << endl;
  }
}