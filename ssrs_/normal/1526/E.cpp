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
  int n, k;
  cin >> n >> k;
  vector<int> s(n);
  for (int i = 0; i < n; i++){
    cin >> s[i];
  }
  vector<int> p(n + 1);
  for (int i = 0; i < n; i++){
    p[s[i]] = i;
  }
  p[n] = -1;
  int cnt = 1;
  for (int i = 0; i < n - 1; i++){
    if (p[s[i] + 1] > p[s[i + 1] + 1]){
      cnt++;
    }
  }
  cout << modbinom(n + k - cnt, k - cnt) << endl;
}