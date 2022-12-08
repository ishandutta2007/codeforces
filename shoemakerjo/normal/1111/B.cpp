#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
int n, k;
ll m;
vector<ll> nums;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k >> m;
	ll cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		nums.push_back(cur);
	}
	sort(nums.begin(), nums.end());

	ll numin = n+1;
	ld ans = 0.0;
	ll csum = 0;
	for (ll val : nums) csum += val;
	for (int i = 0; i < nums.size(); i++) {
		numin--;
		ll cv = nums[i];
		if (i) csum -= nums[i-1];

		if (n - numin > m) break;

		ll inc = min(m - (n - numin), k * numin);

		// cout << numin << " : " << csum << " : " << inc << endl;

		ans = max(ans, (ld) (inc + csum)*1.0 / numin);
	}

	cout << fixed << setprecision(10) <<  ans << endl;
}