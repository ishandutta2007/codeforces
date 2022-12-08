#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, nn, i, j, maxm;
	cin >> n;
	nn = n;
	vector<int> a(n + 1);
	vector<int> cnt(200005);
	vector<int> dp(200005);
	for (i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a.begin(), a.begin() + n);
	for (i = 0; i < n; ++i)
		++cnt[a[i]];
	n = unique(a.begin(), a.begin() + n) - a.begin();
	for (i = 1; i <= 200000; ++i) {
		dp[i] += cnt[i];
		for (j = 2 * i; j <= 200000; j += i) {
			if (cnt[j])
				dp[j] = max(dp[i], dp[j]);
		}
	}
	maxm = 0;
	for (i = 1; i <= 200000; ++i)
		maxm = max(maxm, dp[i]);
	cout << nn - maxm << endl;
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