#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
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
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, l, r;
    cin >> n >> l >> r;
    l--;
    r--;
    vector<int> mn(n), mx(n);
    for (int j = 0; j < n; j++){
      mn[j] = l - j;
      mx[j] = r - j;
    }
    int m = INF;
    for (int j = 0; j < n; j++){
      m = min(m, max(-mn[j], mx[j]));
    }
    vector<int> x;
    x.push_back(1);
    x.push_back(m + 1);
    for (int j = 0; j < n; j++){
      if (mn[j] > -m){
        x.push_back(-mn[j] + 1);
      }
      if (mx[j] < m){
        x.push_back(mx[j] + 1);
      }
    }
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    int cnt = x.size();
    vector<int> imos_p(cnt + 1, 0), imos_n(cnt + 1, 0);
    for (int j = 0; j < n; j++){
      if (mn[j] > -m){
        int p = lower_bound(x.begin(), x.end(), -mn[j] + 1) - x.begin();
        imos_p[p]++;
        imos_p[cnt]--;
      }
      if (mx[j] < m){
        int p = lower_bound(x.begin(), x.end(), mx[j] + 1) - x.begin();
        imos_n[p]++;
        imos_n[cnt]--;
      }
    }
    for (int j = 0; j < cnt; j++){
      imos_p[j + 1] += imos_p[j];
      imos_n[j + 1] += imos_n[j];
    }
    long long ans = 0;
    for (int j = 0; j < cnt - 1; j++){
      if (n % 2 == 0){
        ans += modbinom(n - imos_p[j] - imos_n[j], n / 2 - imos_p[j]) * (x[j + 1] - x[j]) % MOD;
      } else {
        ans += modbinom(n - imos_p[j] - imos_n[j], n / 2 - imos_p[j]) * (x[j + 1] - x[j]) % MOD;
        ans += modbinom(n - imos_p[j] - imos_n[j], n / 2 + 1 - imos_p[j]) * (x[j + 1] - x[j]) % MOD;
      }
    }
    ans %= MOD;
    cout << ans << endl;
  }
}