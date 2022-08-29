#include <bits/stdc++.h>
using namespace std;
const long long BASE1 = 123456789;
const long long BASE2 = 987654321;
const long long MOD = 998244353;
const int INF = 1000000;
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
int main(){
  int n;
  cin >> n;
  vector<string> w(n);
  for (int i = 0; i < n; i++){
    cin >> w[i];
  }
  vector<string> w2 = w;
  sort(w2.begin(), w2.end());
  w2.erase(unique(w2.begin(), w2.end()), w2.end());
  int cnt = w2.size();
  map<string, int> mp;
  for (int i = 0; i < cnt; i++){
    mp[w2[i]] = i;
  }
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    a[i] = mp[w[i]] + 1;
  }
  vector<long long> pow(n);
  pow[0] = 1;
  for (int i = 1; i < n; i++){
    pow[i] = pow[i - 1] * BASE1 % MOD;
  }
  vector<long long> pow2(n);
  pow2[0] = 1;
  for (int i = 1; i < n; i++){
    pow2[i] = pow2[i - 1] * BASE2 % MOD;
  }
  vector<long long> inv(n);
  inv[n - 1] = modinv(pow[n - 1]);
  for (int i = n - 2; i >= 0; i--){
    inv[i] = inv[i + 1] * BASE1 % MOD;
  }
  vector<long long> inv2(n);
  inv2[n - 1] = modinv(pow2[n - 1]);
  for (int i = n - 2; i >= 0; i--){
    inv2[i] = inv2[i + 1] * BASE2 % MOD;
  }
  vector<long long> b(n);
  for (int i = 0; i < n; i++){
    b[i] = a[i] * pow[i] % MOD;
  }
  vector<long long> b2(n);
  for (int i = 0; i < n; i++){
    b2[i] = a[i] * pow2[i] % MOD;
  }
  vector<long long> S(n + 1);
  S[0] = 0;
  for (int i = 0; i < n; i++){
    S[i + 1] = (S[i] + b[i]) % MOD;
  }
  vector<long long> S2(n + 1);
  S2[0] = 0;
  for (int i = 0; i < n; i++){
    S2[i + 1] = (S2[i] + b2[i]) % MOD;
  }
  int sum = n - 1;
  for (int i = 0; i < n; i++){
    sum += w[i].size();
  }
  int ans = sum;
  for (int i = 0; i < n; i++){
    for (int j = i + 1; j <= n; j++){
      long long hash = (S[j] + MOD - S[i]) % MOD * inv[i] % MOD;
      long long hash2 = (S2[j] + MOD - S2[i]) % MOD * inv2[i] % MOD;
      int sub = j - i - 1;
      for (int k = i; k < j; k++){
        sub += w[k].size() - 1;
      }
      int L = j - i;
      vector<int> dp(n + 1, 0);
      for (int k = L; k <= n; k++){
        dp[k] = dp[k - 1];
        if ((S[k] + MOD - S[k - L]) % MOD * inv[k - L] % MOD == hash){
          if ((S2[k] + MOD - S2[k - L]) % MOD * inv2[k - L] % MOD == hash2){
            dp[k] = max(dp[k], dp[k - L] + 1);
          }
        }
      }
      if (dp[n] >= 2){
        ans = min(ans, sum - sub * dp[n]);
      }
    }
  }
  cout << ans << endl;
}