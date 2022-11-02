#include <bits/stdc++.h>

#define NN 3000111
using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int mod = 1e9 + 7;

int power(int a, int n, int mod, int ans = 1) {
	for(; n; n >>= 1, a = (INT)a * a % mod) if(n & 1) ans = (INT)ans * a % mod;
	return ans;	
}

int fac[NN], rev[NN];
int dp[NN];

int C(int n, int k) {
	if(k < 0 or k > n) return 0;
	return (INT)fac[n] * rev[k] % mod * rev[n - k] % mod;
}

void pre() {
	for(int i = fac[0] = rev[0] = 1; i < NN; i ++) {
		fac[i] = (INT)fac[i-1] * i % mod;
	}
	rev[NN - 1] = power(fac[NN-1], mod-2, mod);
	for(int i = NN - 2; i >= 0; i --) rev[i] = (INT)rev[i + 1] * (i+1) % mod;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in ","r ",stdin);
//	freopen("out.out ","w ",stdout);
#endif
	pre();
	int n, q;
	cin >> n >> q;
	
	dp[0] = n;
	for(int i = 1; i <= n; i ++) {
		dp[1] = (dp[1] + 3 * i) % mod;
		dp[2] = (C(i * 3, 2) + dp[2]) % mod;
	}
	
	int r3 = power(3, mod-2, mod);
	
	for(int i = 3; i <= 3 * n; i ++) {
		dp[i] = (C(3 * n, i - 2) + 3LL * C(3 * n, i - 1) + 3LL * C(3 * n, i) + 
			C(3 * n, i + 1) - 3LL * dp[i - 1] - dp[i - 2]) % mod;
		dp[i] = (INT)dp[i] * r3 % mod;
		if(dp[i] < 0) dp[i] += mod;
	}
	
	while(q --) {
		int x;
		scanf("%d", &x);
		printf("%d\n", dp[x]);
	}
	return 0;
}