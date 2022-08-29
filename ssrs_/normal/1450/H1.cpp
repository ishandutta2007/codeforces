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
  string s;
  cin >> s;
  int d = 0;
  int odd = 0, even = 0;
  for (int i = 0; i < n; i++){
    if (s[i] == 'b'){
      if (i % 2 == 0){
        d++;
      } else {
        d--;
      }
    }
    if (s[i] == '?'){
      if (i % 2 == 0){
        even++;
      } else {
        odd++;
      }
    }
  }
  int cnt = odd + even;
  long long ans = 0;
  for (int i = 0; i <= cnt; i++){
    int d2 = d - odd + i;
    if (d2 % 2 == 0){
      ans += abs(d2) / 2 * modbinom(cnt, i) % MOD;
    }
  }
  ans %= MOD;
  ans *= modinv(modpow(2, odd + even - 1));
  ans %= MOD;
  cout << ans << endl;
}