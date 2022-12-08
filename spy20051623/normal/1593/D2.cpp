#include <bits/stdc++.h>

using namespace std;

int a[100];
set<int> dp[100];
map<int, int> mp;

void solve() {
	mp.clear();
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		++mp[a[i]];
	}
	for (auto &it: mp) {
		if (it.second >= n / 2) {
			puts("-1");
			return;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) dp[j].clear();
		int num = 0;
		for (int j = 0; j < n; ++j) if (a[j] == a[i]) ++num;
		for (int j = 0; j < n; ++j) {
			if (a[j] > a[i]) {
				for (int k = n - 1; k > 0; --k) {
					for (int l: dp[k]) {
						dp[k + 1].insert(__gcd(l, a[j] - a[i]));
					}
				}
				dp[1].insert(a[j] - a[i]);
			}
		}
		for (int j = n / 2 - num; j <= n; ++j) {
			if (!dp[j].empty()) ans = max(ans, *--dp[j].end());
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