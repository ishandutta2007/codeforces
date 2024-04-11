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
  vector<long long> p(n);
  for (int i = 0; i < n; i++){
    cin >> p[i];
    p[i] *= modinv(100);
    p[i] %= MOD;
  }
  long long A = 0, B = 0;
  long long P = 1;
  for (int i = 0; i < n; i++){
    long long tmp = P * (MOD + 1 - p[i]) % MOD;
    A += tmp;
    A %= MOD;
    B += tmp * (i + 1);
    B %= MOD;
    P *= p[i];
    P %= MOD;
  }
  B += P * n;
  B %= MOD;
  cout << B * modinv(MOD + 1 - A) % MOD << endl;
}