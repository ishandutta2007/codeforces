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
long long modbinom(long long n, int k){
	if (n < 0 || k < 0 || k > n){
		return 0;
	} else {
		return modfact(n) * modfactinv(k) % MOD * modfactinv(n - k) % MOD;
	}
}
int main(){
  int f, w, h;
  cin >> f >> w >> h;
  if (w == 0){
    cout << 1 << endl;
  } else if (f == 0){
    if (w <= h){
      cout << 0 << endl;
    } else {
      cout << 1 << endl;
    }
  } else if (h == 0){
    cout << 1 << endl;
  } else {
    long long ans1 = 0, ans2 = 0;
    for (int fc = 1; fc <= f; fc++){
      for (int wc = fc - 1; wc <= fc + 1; wc++){
        if (0 < wc && wc <= w){
          long long M = 1;
          if (fc == wc){
            M = 2;
          }
          long long c1 = modbinom(f - 1, fc - 1);
          long long c2 = modbinom(w - 1, wc - 1);
          ans1 += M * c1 * c2 % MOD;
          long long c3 = modbinom(w - (long long) wc * h - 1, wc - 1);
          ans2 += M * c1 * c3 % MOD;
        }
      }
    }
    ans1 %= MOD;
    ans2 %= MOD;
    cout << ans2 * modinv(ans1) % MOD << endl;
  }
}