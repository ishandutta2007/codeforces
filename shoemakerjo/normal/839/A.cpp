#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int nums[n];
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	int ans = 0;
	int giv = 0;
	int cur = 0;
	for (int i = 0; i < n; i++) {
		ans++;
		cur += nums[i];
		giv += min(8, cur);
		cur -= min(8, cur);
		if (giv >= k) break;
	}
	if (giv < k) cout << -1 << endl;
	else cout << ans << endl;
	// cin >> n;
}