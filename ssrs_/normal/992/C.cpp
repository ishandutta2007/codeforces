#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
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
int main(){
  long long x, k;
  cin >> x >> k;
  if (x == 0){
    cout << 0 << endl;
  } else {
    x %= MOD;
    k %= (MOD - 1);
    long long p = modpow(2, k);
    x = (x * 2 + MOD - 1) % MOD;
    cout << (p * x + 1) % MOD << endl;
  }
}