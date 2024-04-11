#include <bits/stdc++.h>
using namespace std;
#define M 300300
const int mod = 1000000007;

int n;
vector<int> v[M];
int fac[M] = {1}, fac_[M] = {1};
int C[M];
long long dp[M];

int POW(int a, int n) {
	int s = 1;
	while (n) {
		if (n & 1) {
			s = 1ll * s * a % mod;
		}
		a = 1ll * a * a % mod;
		n >>= 1;
	}
	return s;
}

int CC(int a, int b) {
	return (1ll * fac[a] * fac_[b] % mod) * fac_[a-b] % mod;
}

void init() {
    for (int i = 1; i < M; i++) {
		fac[i] = 1ll * fac[i-1] * i % mod;
    }
    fac_[M-1] = POW(fac[M-1], mod-2);
    for (int i = M - 2; i >= 1; i--) {
		fac_[i] = 1ll * fac_[i+1] * (i + 1) % mod;
    }
	n--;
	for (int i = 0; i <= n; i++) {
		C[i] = CC(n, i);
	}
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
		dp[0] = dp[0] * 2 % mod;
    }
    dp[0] --;
    for (int i = 1; i <= n; i++) {
		dp[i] = (dp[i-1] + mod - C[i] + mod - C[i-1]) % mod;
    }
}

int main() {
	scanf("%d", &n);

	for (int x, i = 1; i <= n; i++) {
		scanf("%d", &x);
		for (int p = 2; p * p <= x; p++) {
			if (x % p != 0) {
				continue;
			}
			int r = 0;
			while (x % p == 0) {
				x /= p;
				r ++;
			}
			v[p].push_back(-r);
		}
		if (x > 1) {
			v[x].push_back(-1);
		}
	}

	init();
	long long answer = 0;
	for (int p = 2; p < M; p++) {
		int m = v[p].size();
		if (m == 0) {
			continue;
		}
		sort(v[p].begin(), v[p].end());
		for (int x, i = 0; i < m; i++) {
			x = -v[p][i];
			answer = (answer + 1ll * x * dp[i]) % mod;
		}
	}
	printf("%I64d\n", answer);
	return 0;
}