// i < j: d[i] + a[j]
// i > j: c[i] + b[j]
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, s, e, x[5005], a[5005], b[5005], c[5005], d[5005];
ll dp[2][5005];

void read(int *x) {
	for (int i = 1; i <= n; ++i) cin >> x[i];
}
void upd(ll &x, const ll &y) {
	if (x > y) x = y;
}

int main() {
	cin >> n >> s >> e; read(x), read(a), read(b), read(c), read(d);
	for (int i = 1; i <= n; ++i)
		a[i] += x[i], b[i] -= x[i], c[i] += x[i], d[i] -= x[i];
	bool _s = false, _e = false;
	memset(dp[0], 0x3f, sizeof dp[0]);
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		memset(dp[i & 1], 0x3f, sizeof dp[i & 1]);
		for (int j = 0; j < i; ++j)
			if (dp[i - 1 & 1][j] <= (ll)1e18) {
				if (i == s) {
					if (i != n) upd(dp[i & 1][j], dp[i - 1 & 1][j] + d[i]);
					if (j || i == n) upd(dp[i & 1][j - (i != n)], dp[i - 1 & 1][j] + c[i]);
					_s = true;
				} else if (i == e) {
					if (i != n) upd(dp[i & 1][j], dp[i - 1 & 1][j] + b[i]);
					if (j || i == n) upd(dp[i & 1][j - (i != n)], dp[i - 1 & 1][j] + a[i]);
					_e = true;
				} else {
					upd(dp[i & 1][j + 1], dp[i - 1 & 1][j] + b[i] + d[i]);
					if (j - 1 + _s + _e >= 1 || i == n) upd(dp[i & 1][j - (i != n)], dp[i - 1 & 1][j] + a[i] + c[i]);
					if (i != n) {
						if (j || _e) upd(dp[i & 1][j], dp[i - 1 & 1][j] + b[i] + c[i]);
						if (j || _s) upd(dp[i & 1][j], dp[i - 1 & 1][j] + a[i] + d[i]);
					}
				}
			}
	}
	printf("%lld\n", dp[n & 1][0]);
	return 0;
}