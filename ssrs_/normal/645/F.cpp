#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
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
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> a(n + q);
  for (int i = 0; i < n + q; i++){
    cin >> a[i];
  }
  vector<vector<int>> F(MAX + 1);
  for (int i = 1; i <= MAX; i++){
    for (int j = i; j <= MAX; j += i){
      F[j].push_back(i);
    }
  }
  vector<int> phi(MAX + 1);
  for (int i = 1; i <= MAX; i++){
    phi[i] = i;
  }
  for (int i = 2; i <= MAX; i++){
    if (phi[i] == i){
      for (int j = i; j <= MAX; j += i){
        phi[j] = phi[j] / i * (i - 1);
      }
    }
  }
  vector<long long> B(n + q + 1);
  for (int i = 0; i <= n + q; i++){
    B[i] = modbinom(i, k);
  }
  long long sum = 0;
  vector<long long> C(MAX + 1, 0);
  for (int i = 0; i < n + q; i++){
    for (int j : F[a[i]]){
      sum += MOD - B[C[j]] * phi[j] % MOD;
      C[j]++;
      sum += B[C[j]] * phi[j] % MOD;
    }
    sum %= MOD;
    if (i >= n){
      cout << sum << "\n";
    }
  }
}