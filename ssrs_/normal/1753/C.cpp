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
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    int p = 0;
    for (int j = 0; j < n; j++){
      if (a[j] == 0){
        p++;
      }
    }
    int cnt = 0;
    for (int j = 0; j < p; j++){
      if (a[j] == 0){
        cnt++;
      }
    }
    long long ans = 0;
    for (int j = cnt; j < p; j++){
      ans += (long long) n * (n - 1) / 2 % MOD * modinv((long long) (p - j) * (p - j) % MOD);
      ans %= MOD;
    }
    cout << ans << endl;
  }
}