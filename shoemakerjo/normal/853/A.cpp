#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	ll nums[n+1];
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	ll ans = 0;
	ll cursum = 0LL;
	priority_queue<pair<ll, int>> ins;
	for (int i = 1; i <= k; i++) {
		ins.push(pair<ll, int>(nums[i], i));
		cursum += nums[i];
		ans += cursum;
	}
	int mins[n+1];
	for (int i = k+1; i <= k+n; i++) {
		if (i <= n) {
			ins.push(pair<ll, int>(nums[i], i));
			cursum+=nums[i];
		}
		cursum -= ins.top().first;
		mins[ins.top().second] = i;
		ins.pop();
		ans += cursum;
	}
	cout << ans << endl;
	for (int i = 1; i <= n; i++)  {
		if (i > 1) cout << " ";
		cout << mins[i];
	}
	cout << endl;
	// cin >> ans;
}