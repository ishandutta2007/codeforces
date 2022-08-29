#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
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
map<long long, long long> inv;
long long modinv(long long a){
  if (!inv.count(a)){
    inv[a] = modpow(a, MOD - 2);
  }
  return inv[a];
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
long long modbinom2(long long n, long long r){
	long long res = 1;
	for (int i = 0; i < r; i++){
		res = res * (n - i) % MOD;
		res = res * modinv(i + 1) % MOD;
	}
	return res;
}
int main(){
  long long N, K;
  cin >> N >> K;
  vector<long long> pow(K + 1);
  for (int i = 1; i <= K; i++){
    pow[i] = modpow(i, K);
  }
  vector<vector<long long>> binom(K + 1, vector<long long>(K + 1));
  binom[0][0] = 1;
  for (int i = 1; i <= K; i++){
    binom[i][0] = 1;
    binom[i][i] = 1;
  }
  for (int i = 2; i <= K; i++){
    for (int j = 1; j < i; j++){
      binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % MOD;
    }
  }
  vector<long long> binom2(K + 1);
  binom2[0] = 1;
  for (int i = 1; i <= K; i++){
    binom2[i] = binom2[i - 1] * (N - i + 1) % MOD * modinv(i) % MOD;
    if (i == N){
      break;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= min(N, K); i++){
    long long tmp = 0;
    for (int j = i; j >= 1; j--){
      if ((i - j) % 2 == 0){
        tmp += pow[j] * binom[i][j] % MOD;
        tmp %= MOD;
      } else {
        tmp = modsub(tmp, pow[j] * binom[i][j] % MOD);
      }
    }
    tmp *= modpow(2, N - i);
    tmp %= MOD;
    tmp *= binom2[i];
    tmp %= MOD;
    ans += tmp;
  }
  ans %= MOD;
  cout << ans << endl;
}