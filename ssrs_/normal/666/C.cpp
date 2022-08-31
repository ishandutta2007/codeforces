#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long modsub(long long a, long long b){
	return (a % MOD - b % MOD + MOD) % MOD;
}
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
map<int, vector<int>> mp;
void calc(vector<int> &f, int N){
  if (mp.count(N)){
    f = mp[N];
  } else {
    for (int i = 0; i <= 100000; i++){
      f[i] = modbinom(i + N - 1, N - 1) * modpow(25, i) % MOD;
    }
    for (int i = 1; i <= 100000; i++){
      f[i] = (f[i] + (long long) f[i - 1] * 26) % MOD;
    }
    mp[N] = f;
  }
}
int main(){
  int m;
  cin >> m;
  string s;
  cin >> s;
  vector<int> f(100001);
  calc(f, s.size());
  for (int i = 0; i < m; i++){
    int t;
    cin >> t;
    if (t == 1){
      cin >> s;
      calc(f, s.size());
    } else {
      int n;
      cin >> n;
      if (n < s.size()){
        cout << 0 << "\n";
      } else {
        cout << f[n - s.size()] << "\n";
      }
    }
  }
}