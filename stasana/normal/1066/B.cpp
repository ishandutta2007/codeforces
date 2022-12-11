#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef int64_t ll;

int main() {
	int n, r;
	cin >> n >> r;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<int> dp(n, 1e9);
	for (int i = 0; i < n; ++i) {
		if (a[i] == 0) {
			continue;
		}
		for (int j = 0; j < i; ++j) {
			if (!a[j]) {
				continue;
			}
			if (i - r + 1 <= j + r) {
				dp[i] = min(dp[i], dp[j] + 1);
			}
		}
		if (i - r < 0) {
			dp[i] = 1;
		}
	}
	//for (int i = 0; i < n; ++i) {
	//	cout << dp[i] << " ";
	//}
	//cout << endl;
	int res = dp.back();
	for (int i = n - 1; i >= max(0, n - r); --i) {
		if (a[i]) {
			res = min(res, dp[i]);
		}
	}
	cout << (1e9 == res ? -1 : res);
	return 0;
}