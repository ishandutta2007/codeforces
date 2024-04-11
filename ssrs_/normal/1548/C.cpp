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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  long long INV = modinv(3);
  vector<long long> a(n * 3 + 1);
  a[1] = 0;
  for (int i = 3; i <= n * 3; i += 3){
    a[1] += i;
    a[1] %= MOD;
  }
  a[2] = 0;
  for (int i = 3; i <= n * 3; i += 3){
    a[2] += (long long) i * (i - 1) / 2 % MOD;
    a[2] %= MOD;
  }
  for (int i = 4; i <= n * 3 + 1; i++){
    a[i - 1] = (modbinom(n * 3 + 3, i) - 3 * a[i - 2] - a[i - 3] + MOD * 4) % MOD * INV % MOD;
  }
  for (int i = 0; i < q; i++){
    int x;
    cin >> x;
    cout << a[x] << "\n";
  }
}