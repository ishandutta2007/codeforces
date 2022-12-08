#include <bits/stdc++.h>

using namespace std;

long long a[300005], b[300005];

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	long long sum = 0, cnt = 0, ans = 0;
	for (int i = n; i >= k; --i) {
		sum -= cnt;
		cnt -= b[i + 1];
		if (sum < a[i]) {
			long long d = a[i] - sum, cur = (d - 1) / k + 1;
			b[i - k + 1] = cur;
			ans += cur;
			cnt += cur;
			sum += cur * k;
		}
	}
	for (int i = k - 1; i; --i) {
		sum -= cnt;
		cnt -= b[i + 1];
		if (sum < a[i]) {
			long long d = a[i] - sum, cur = (d - 1) / i + 1;
			b[1] += cur;
			ans += cur;
			cnt += cur;
			sum += cur * i;
		}
	}
	cout << ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}