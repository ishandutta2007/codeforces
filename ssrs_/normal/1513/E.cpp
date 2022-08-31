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
  long long sum = 0;
  for (int i = 0; i < n; i++){
    sum += a[i];
  }
  if (sum % n != 0){
    cout << 0 << endl;
  } else {
    int avg = sum / n;
    int small = 0, large = 0;
    for (int i = 0; i < n; i++){
      if (a[i] > avg){
        large++;
      }
      if (a[i] < avg){
        small++;
      }
    }
    long long ans = 1;
    if (small == 1){
      ans = modfact(large + 1);
    }
    if (large == 1){
      ans = modfact(small + 1);
    }
    if (small >= 2 && large >= 2){
      ans = modfact(small) * modfact(large) % MOD * 2 % MOD;
    }
    ans *= modbinom(n, small + large);
    ans %= MOD;
    map<int, int> mp;
    for (int i = 0; i < n; i++){
      mp[a[i]]++;
    }
    for (auto P : mp){
      int cnt = P.second;
      if (P.first != avg){
        ans *= modfactinv(cnt);
      }
      ans %= MOD;
    }
    cout << ans << endl;
  }
}