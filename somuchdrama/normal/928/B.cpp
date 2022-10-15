#include <iostream>
#include <vector>
#include <algorithm>

#define pii pair <int, int>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second

using namespace std;

int32_t main() {
	int n, k;
	cin >> n >> k;
	vector <int> a(n);
	for (auto & i : a) cin >> i;
	vector <int> dp(n, 0), last(n, 0);
	dp[0] = min(k + 1, n); last[0] = min(k + 1, n);

	for (int i = 1; i < n; ++i) {
		int first = max(0, i - k);
		last[i] = min(i + k + 1, n);
		if (a[i]) {
			dp[i] = last[i] - first + dp[a[i] - 1] - max(0, (last[a[i] - 1] - first));
		} else {
			dp[i] = last[i] - first;
		}
	}
	for (auto & i : dp) cout << i << ' ';
	cout << '\n';
}