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
int main(){
  int n;
  cin >> n;
  vector<int> k(n);
  vector<vector<int>> a(n);
  for (int i = 0; i < n; i++){
    cin >> k[i];
    a[i] = vector<int>(k[i]);
    for (int j = 0; j < k[i]; j++){
      cin >> a[i][j];
      a[i][j]--;
    }
  }
  vector<long long> yp(1000000, 0);
  vector<int> zc(1000000, 0);
  int p = modinv(n);
  for (int i = 0; i < n; i++){
    int q = modinv(k[i]) * p % MOD;
    for (int j = 0; j < k[i]; j++){
      yp[a[i][j]] += q;
      yp[a[i][j]] %= MOD;
      zc[a[i][j]]++;
    }
  }
  long long ans = 0;
  for (int i = 0; i < 1000000; i++){
    ans += yp[i] * p % MOD * zc[i] % MOD;
  }
  ans %= MOD;
  cout << ans << endl;
}