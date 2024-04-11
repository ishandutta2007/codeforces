#include <bits/stdc++.h>

using namespace std;

long long a[100005];
long long s[100005];
long long dp[460][460];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &a[i]);
	}
	memset(dp, 0, sizeof dp);
	s[0] = a[0];
	for (int i = 1; i < n; ++i) {
		s[i] = s[i - 1] + a[i];
	}
	for (int i = n - 1; i >= 0; --i) {
		memset(dp[i % 460], 0, sizeof dp[0]);
		dp[i % 460][1] = max(a[i], dp[(i + 1) % 460][1]);
		for (int j = 2; j * (j + 1) / 2 <= n && j <= n - i; ++j) {
			if (s[i + j - 1] - s[i - 1] < dp[(i + j) % 460][j - 1])
				dp[i % 460][j] = max(dp[(i + 1) % 460][j], s[i + j - 1] - s[i - 1]);
			else
				dp[i % 460][j] = dp[(i + 1) % 460][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < 460; ++i) {
		for (auto &j: dp) {
			if (j[i]) {
				++ans;
				break;
			}
		}
	}
	printf("%d\n", ans);
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}