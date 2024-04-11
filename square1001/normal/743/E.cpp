#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i]; --a[i];
	}
	int ans = 0;
	for (int i = 0; i < 8; ++i) {
		if (find(a.begin(), a.end(), i) != a.end()) {
			++ans;
		}
	}
	for (int i = 1; i <= n / 8; ++i) {
		vector<int> p1(n, n + 1), p2(n, n + 1);
		for (int j = 0; j < n; ++j) {
			int ptr = j, cnt = 0;
			while (ptr != n && cnt < i) {
				cnt += (a[ptr] == a[j]);
				++ptr;
			}
			if (cnt == i) p1[j] = ptr;
			while (ptr != n && cnt < i + 1) {
				cnt += (a[ptr] == a[j]);
				++ptr;
			}
			if (cnt == i + 1) p2[j] = ptr;
		}
		vector<vector<int> > dp(n + 1, vector<int>(1 << 8, -inf));
		dp[0][0] = 0;
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < 1 << 8; ++k) {
				dp[j + 1][k] = max(dp[j + 1][k], dp[j][k]);
				if (((k >> a[j]) & 1) || p1[j] == n + 1) continue;
				dp[p1[j]][k + (1 << a[j])] = max(dp[p1[j]][k + (1 << a[j])], dp[j][k] + i);
				if (p2[j] != n + 1) {
					dp[p2[j]][k + (1 << a[j])] = max(dp[p2[j]][k + (1 << a[j])], dp[j][k] + i + 1);
				}
			}
		}
		ans = max(ans, dp[n][(1 << 8) - 1]);
	}
	cout << ans << endl;
	return 0;
}