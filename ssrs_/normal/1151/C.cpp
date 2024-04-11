#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
string bit(long long n){
  string ans = "";
  while (n > 0){
    ans += n % 2 + '0';
    n /= 2;
  }
  return ans;
}
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
long long modsub(long long a, long long b){
	a %= MOD;
	b %= MOD;
	if (a >= b){
		return (a - b) % MOD;
	} else {
		return MOD - (b - a) % MOD;
	}
}
long long modinv(long long a){
	return modpow(a, MOD - 2);
}
long long modapsum(long long l, long long r){
  long long ans = 1;
  ans += modinv(2) * modsub(r, l);
  ans %= MOD;
  ans = ans * ((l + r) % MOD) % MOD;
  ans *= modinv(2);
  ans %= MOD;
  return ans;
}
long long solve(long long l, long long r, int n){
  if (n % 2 == 1){
    //
    long long B = 1;
    for (int i = 0; i < n / 2; i++){
      B = B * 4 - 1;
      B %= MOD;
    }
    long long P = ((long long) 1 << (n - 1)) % MOD;
    long long S = (modsub(l, P) * 2 + B) % MOD;
    long long E = (modsub(r, P) * 2 + B) % MOD;
    return modapsum(S, E);
  } else {
    long long B = 1;
    for (int i = 0; i < n / 2; i++){
      B = B * 4 - 2;
      B %= MOD;
    }
    long long P = ((long long) 1 << (n - 1)) % MOD;
    long long S = (modsub(l, P) * 2 + B) % MOD;
    long long E = (modsub(r, P) * 2 + B) % MOD;
    return modapsum(S, E);
  }
}
int main(){
  long long l, r;
  cin >> l >> r;
  string S = bit(l);
  string T = bit(r);
  int n = S.size();
  int m = T.size();
  if (n == m){
    cout << solve(l, r, n) << endl;
  } else {
    long long ans = 0;
    ans += solve(l, ((long long) 1 << n) - 1, n);
    for (int i = n + 1; i < m; i++){
      ans += solve((long long) 1 << (i - 1), ((long long) 1 << i) - 1, i);
    }
    ans += solve((long long) 1 << (m - 1), r, m);
    cout << ans % MOD << endl;
  }
}