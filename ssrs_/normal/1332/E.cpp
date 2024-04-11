#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;
long long modpow(long long a, long long b){
	a %= MOD;
	long long res = 1;
	while (b > 0){
		if (b % 2 == 1) res = res * a % MOD;
		a = a * a % MOD;
		b = b / 2;
	}
	return res;
}
long long modinv(long long a){
	return modpow(a, MOD - 2);
}
int main(){
  long long n, m, L, R;
  cin >> n >> m >> L >> R;
  if (n * m % 2 == 1){
    cout << modpow(R - L + 1, n * m) << endl;
  } else {
    int A = R / 2 - (L - 1) / 2;
    int B = (R - L + 1) - A;
    long long ans;
    ans = modpow(A + B, n * m);
    if ((A - B) % 2 != 0){
      ans++;
    }
    ans = ans * modinv(2) % MOD;
    cout << ans << endl;
  }
}