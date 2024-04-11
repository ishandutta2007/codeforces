//In the name of God
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 18;
int mat[N][N], sum[1 << N], dp[1 << N][N], a[N];
int32_t main() {
	int n, m, k; cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int mask = 0; mask < (1 << n); ++mask)
		for (int i = 0; i < n; ++i)
			if (mask >> i & 1)
				sum[mask] += a[i];
	for (int i = 0; i < k; ++i) {
		int u, v, c; cin >> u >> v >> c; --u, --v;
		mat[u][v] += c;	
	}
	for (int mask = 1; mask < (1 << n); ++mask)
		for (int last = 0; last < n; ++last) if (mask >> last & 1)
			for (int i = 0; i < n; ++i) if (i != last && mask >> i & 1)
				dp[mask][i] = max(dp[mask][i], dp[mask ^ (1 << i)][last] + mat[last][i]);
	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int mask = 0; mask < (1 << n); ++mask)
			if (__builtin_popcount(mask) == m)
				ans = max(ans, dp[mask][i] + sum[mask]);
	cout << ans << endl;
	return 0;
}