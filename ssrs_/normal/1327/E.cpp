#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
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
  int n;
  cin >> n;
  for (int i = 1; i < n; i++){
    cout << (180 * modpow(10, n - i - 1) + 810 * (n - i - 1) * modpow(10, n - i - 2)) % MOD << ' ';
  }
  cout << 10;
}