// In the name of God

/*
	........
	Gonna be happy
	........
*/


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline int read() { int32_t x; scanf("%d", &x); return x; }

const int N = 26, mod = 1051131;

map<int, int> id;

int adj[N][N], c[N][N], self[N + 1], to[N], a[1 << N - 1], dp[1 << N - 1], res[1 << N - 1], inv[N];

int pw(int a, int b) {
	return b? 1LL * pw(a * 1LL * a % mod, b >> 1) * (b & 1? a: 1) % mod: 1;
}

void mul(int a[N][N], int b[N][N]) {
	memset(c, 0, sizeof c);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			for (int k = 0; k < N; ++k)
				c[i][j] = (c[i][j] + a[i][k] * 1LL * b[k][j]) % mod;
}

void getpow(int a[N][N], ll b) {
	if (b == 1)
		return;
	int cur[N][N];
	memcpy(cur, a, sizeof adj);
//	for (int i = 0; i < 4; ++i)
//		for (int j = 0; j < 4; ++j) {
//			cur[i][j] = a[i][j];
//			cout << i << ' ' << j << ' ' << cur[i][j] << endl;
//		}
	getpow(a, b >> 1);
	mul(a, a);
	memcpy(a, c, sizeof adj);
	if (b & 1) {
		mul(a, cur);
		memcpy(a, c, sizeof adj);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	ll t;
	int m, s; 
	cin >> m >> t >> s;
	for (int i = 0; i < N; ++i)
		id[1 << i] = i;
	for (int i = 0; i < s; ++i)
		cin >> a[i];
	for (int i = s; i < 1 << m; ++i) {
		a[i] = (101 * 1LL * a[i - s] + 10007) % mod;
	}
	for (int j = 0; j < m; ++j) {
		for (int i = 0; i < 1 << m - j - 1; ++i) {
			if (!i) {
				self[j]++;
			} else {
				self[j] += 1LL << id[i & -i] + j + 1;
			}
		}
	}
	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (i == j) {
				adj[i][j] = self[i];
//				cout << i << ' ' << self[i] << endl;
				if (i == m)
					adj[i][j] = 1;
			} else {
				int unite = 1 << min(i, j), sz = (i != m? 1 << m - i - 1: 1);
				adj[i][j] = 1LL * unite * sz % mod;
			}
//			cout << i << ' ' << j << ' ' << adj[i][j] << endl;
		}
	}
//	return 0;
	getpow(adj, t);
//	return 0;
	for (int i = 0; i <= m; ++i) {
		to[i] = adj[m][i];
//		cout << i << ' ' << to[i] << endl;		
	}
//	return 0;
	for (int i = 0; i < 1 << m; ++i) {
		dp[i] = a[i];
		res[i] = 1LL * a[i] * to[m] % mod;
		a[i] = dp[i] * 1LL * to[m - 1] % mod;
	}
	for (int bit = m - 1; bit >= 0; --bit) {
		for (int mask = 0; mask < (1 << m); ++mask) {
			int cur = a[(mask ^ (1 << bit)) & ((1 << bit + 1) - 1)];				
//			cout << bit << ' ' << mask << ' ' << cur << ' ' << cur/to[bit] << endl;
			res[mask] = (res[mask] + cur);
//			if (res[mask] >= mod)
//				res[mask] -= mod;
		}
		for (int mask = 0; mask < (1 << bit); ++mask) {
			dp[mask] = (dp[mask] + dp[mask ^ (1 << bit)]);
			if (dp[mask] >= mod)
				dp[mask] -= mod;
			a[mask] = 1LL * dp[mask] * to[bit - 1] % mod;
		}
	}
	int ans = 0;
	for (int i = 0; i < 1 << m; ++i) {
		ans ^= res[i] % mod;
//		cout << res[i] << ' ' << i << endl;	
	}
	cout << ans;
}