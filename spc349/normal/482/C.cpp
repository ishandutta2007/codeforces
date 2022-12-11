#include <bits/stdc++.h>
using namespace std;

long double dp[1 << 20];
int sum[1 << 20];
string a[60];
long long f[1 << 20];
int id[1 << 20];
int cnt[1 << 20];
long long mmm[60];

int count(long long x) {
	return cnt[x & 1048575] + cnt[x >> 20 & 1048575] + cnt[x >> 40];
}

int main () {
	for (int i = 0; i < 20; i++) {
		id[1 << i] = i;
	}
	for (int i = 1; i < (1 << 20); i++) {
		cnt[i] = cnt[i >> 1] + (i & 1);
	}
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int m = a[0].size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mmm[j] = 0;
			for (int k = 0; k < n; k++) {
				if (a[i][j] == a[k][j]) mmm[j] |= 1ll << k;
			}
		}
		for (int mask = 0; mask < (1 << m); mask++) {
			if (mask) {
				int x = id[mask & -mask];
				f[mask] = f[mask ^ 1 << x] & mmm[x];
			} else f[0] = (1ll << n) - 1;
			if (count(f[mask]) > 1) sum[mask]++;
		}
	}
	long double ans = 0;
	dp[0] = 1;
	for (int mask = 0; mask < (1 << m); mask++) {
		int inv = m - cnt[mask];
		for (int i = 0; i < m; i++) {
			if (mask >> i & 1) continue;
			dp[mask | 1 << i] += dp[mask] / inv;
		}
		ans += dp[mask] * sum[mask] / n;
	}
	cout << fixed << setprecision(15) << ans << endl;
	return 0;
}