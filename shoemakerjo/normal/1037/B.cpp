#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	ll s;
	cin >> n >> s;
	vector<ll> nums;
	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		nums.push_back(cur);
	}
	sort(nums.begin(), nums.end());
	int bel = 0;
	int abo = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] < s) bel++;
		if (nums[i] > s) abo++;
	}
	ll ans = 0LL;
	if (bel > n/2) {
		for (int i = bel-1; i >= n/2; i--) {
			ans += (s-nums[i]);
		}
	}
	if (abo > n/2) {
		for (int i = n-abo; i < n-n/2; i++) {
			ans += (nums[i]-s);
		}
	}
	cout << ans << endl;

}