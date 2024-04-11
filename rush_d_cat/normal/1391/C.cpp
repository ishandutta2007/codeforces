#include <bits/stdc++.h>
using namespace std;
const int N = 1000000 + 10;
const int MOD = 1e9 + 7;
typedef long long LL;
int n;
LL f[N], s[N], fac[N];
int main() {
	f[0] = 1; s[0] = 1; 
	fac[0] = 1;
	for (int i = 1; i < N; i ++) {
		fac[i] = fac[i-1] * i % MOD;
	}

	for (int i = 1; i < N; i ++) {
		f[i] = s[i-1];
		s[i] = (s[i-1] + f[i]) % MOD;
	}
	scanf("%d", &n);
	LL ans = (fac[n] - f[n] + MOD) % MOD;
	cout << ans << endl;

}