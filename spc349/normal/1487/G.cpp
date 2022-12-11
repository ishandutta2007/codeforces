#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

long long f[210];
int dp[210][210][210][2];
int sum[410][410], p1[410][410], p2[410][410];
int a[410];

void add(int &x, long long y) {
	x = (x + y) % mod;
}

int main () {
	f[0] = 1, f[1] = 24;
	for (int i = 2; i <= 200; i++) {
		f[i] = f[i - 1] * 23 % mod;
	}
	for (int i = 1; i <= 200; i++) {
		add(dp[i][1][0][0], f[i - 1]), add(dp[i][0][1][1], f[i - 1]);
		for (int j = 0; j <= i; j++) {
			for (int k = 0; j + k <= i; k++) {
				for (int pd = 0; pd < 2; pd++) {
					if (!dp[i][j][k][pd]) continue;
					int val = dp[i][j][k][pd];
					for (int nxt = i + 1; nxt <= 200; nxt++) {
						if (pd || nxt - i - 1) add(dp[nxt][j + 1][k][0], val * f[nxt - i - 1]);
						if (!pd || nxt - i - 1) add(dp[nxt][j][k + 1][1], val * f[nxt - i - 1]);
					}
				}
			}
		}
	}
	int n; cin >> n;
	for (int i = 0; i < 26; i++) {
		cin >> a[i];
	}
	int n1 = n >> 1, n2 = n + 1 >> 1;
	add(p1[0][0], f[n1]);
	for (int a = 0; a <= n1; a++) {
		for (int b = 0; a + b <= n1; b++) {
			for (int lst = 1; lst <= n1; lst++) {
				add(p1[a][b], dp[lst][a][b][0] * f[n1 - lst]);
				add(p1[a][b], dp[lst][a][b][1] * f[n1 - lst]);
			}
		}
	}
	add(p2[0][0], f[n2]);
	for (int a = 0; a <= n2; a++) {
		for (int b = 0; a + b <= n2; b++) {
			for (int lst = 1; lst <= n2; lst++) {
				add(p2[a][b], dp[lst][a][b][0] * f[n2 - lst]);
				add(p2[a][b], dp[lst][a][b][1] * f[n2 - lst]);
			}
		}
	}
	for (int a1 = 0; a1 <= n1; a1++) {
		for (int b1 = 0; a1 + b1 <= n1; b1++) {
			for (int a2 = 0; a2 <= n2; a2++) {
				for (int b2 = 0; a2 + b2 <= n2; b2++) {
					add(sum[a1 + a2][b1 + b2], 1ll * p1[a1][b1] * p2[a2][b2]);
				}
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < 26; i++) {
		for (int j = i + 1; j < 26; j++) {
			ans = (ans + sum[a[i]][a[j]]) % mod;
		}
	}
	for (int i = 0; i < 26; i++) {
		long long tot = 0;
		for (int j = 0; j <= n; j++) {
			tot = (tot + sum[a[i]][j]) % mod;
		}
		for (int j = 0; j < 26; j++) {
			if (i == j) continue;
			for (int k = a[j]; k <= n; k++) {
				tot = (tot - sum[a[i]][k] + mod) % mod;
			}
		}
		ans = (ans + tot) % mod;
	}
	long long tot = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			tot = (tot + sum[i][j]) % mod;
		}
	}
	for (int i = 0; i < 26; i++) {
		for (int j = a[i]; j <= n; j++) {
			for (int k = 0; k <= n; k++) {
				tot = (tot - sum[j][k] + mod) % mod;
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		for (int j = i + 1; j < 26; j++) {
			for (int k1 = a[i]; k1 <= n; k1++) {
				for (int k2 = a[j]; k2 <= n; k2++) {
					tot = (tot + sum[k1][k2] + mod) % mod;
				}
			}
		}
	}
	ans = (ans + tot) % mod;
	cout << ans << endl;
	return 0;
}