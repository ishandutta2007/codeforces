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
	if (n < 0){
		return 0;
	} else if (mfi.size() > n){
		return mfi[n];
	} else {
		return modinv(modfact(n));
	}
}
int main(){
  int n, x, pos;
  cin >> n >> x >> pos;
  vector<int> A(n);
  vector<bool> used(n, false);
  int l = 0, r = n;
  while (l < r){
    int mid = (l + r) / 2;
    used[mid] = true;
    if (mid <= pos){
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  int a = 0;
  for (int i = 0; i < pos; i++){
    if (used[i]){
      a++;
    }
  }
  int b = 0;
  for (int i = pos + 1; i < n; i++){
    if (used[i]){
      b++;
    }
  }
  long long ans = 1;
  ans *= modfact(x - 1);
  ans *= modfactinv(x - 1 - a);
  ans %= MOD;
  ans *= modfact(n - x);
  ans %= MOD;
  ans *= modfactinv(n - x - b);
  ans %= MOD;
  ans *= modfact(n - a - b - 1);
  ans %= MOD;
  cout << ans << endl;
}