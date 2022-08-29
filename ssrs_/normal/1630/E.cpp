#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int gcd(int x, int y){
  if (y == 0){
    return x;
  } else {
    return gcd(y, x % y);
  }
}
long long f(long long x){
  return x * (x - 1) / 2 % MOD;
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
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
      a[j]--;
    }
    vector<int> cnt(n, 0);
    for (int j = 0; j < n; j++){
      cnt[a[j]]++;
    }
    int g = 0;
    for (int j = 0; j < n; j++){
      g = gcd(g, cnt[a[j]]);
    }
    if (g == n){
      cout << 1 << "\n";
    } else {
      map<int, int> mp;
      for (int j = 0; j < n; j++){
        mp[cnt[j]]++;
      }
      vector<long long> p(g + 1, 0);
      vector<long long> cnt(g + 1, 1);
      for (int j = 1; j <= g; j++){
        if (g % j == 0){
          int n2 = n / g * j;
          p[j] = f(n2);
          for (auto P : mp){
            p[j] -= f(P.first / g * j) * P.second % MOD;
            if (p[j] < 0){
              p[j] += MOD;
            }
          }
          p[j] *= modinv(f(n2));
          p[j] %= MOD;
          cnt[j] *= modfact(n2);
          for (auto P : mp){
            cnt[j] *= modpow(modfactinv(P.first / g * j), P.second);
            cnt[j] %= MOD;
          }
        }
      }
      long long sum1 = 0, sum2 = 0;
      for (int j = 0; j < n; j++){
        int group = n / gcd(n, j);
        if (g % group == 0){
          sum1 += p[g / group] * n % MOD * cnt[g / group] % MOD;
          sum2 += cnt[g / group];
        }
      }
      sum1 %= MOD;
      sum2 %= MOD;
      cout << sum1 * modinv(sum2) % MOD << "\n";
    }
  }
}