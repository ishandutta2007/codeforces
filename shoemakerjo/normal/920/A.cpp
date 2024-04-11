#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	int nums[k];
	for (int i = 0; i < k; i++) {
		cin >> nums[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int dist = 3*n;
		for (int j = 0; j < k; j++) {
			dist = min(dist, abs(i-nums[j]));
		}
		ans = max(ans, dist+1);
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) solve();
	cin >> t;
}