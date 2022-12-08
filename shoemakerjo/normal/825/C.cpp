#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int n;
	ll k;
	cin >> n >> k;
	vector<ll> nums;
	ll cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		nums.push_back(cur);
	}
	sort(nums.begin(), nums.end());
	int ans = 0;
	for (int i = 0; i < nums.size(); i++) {
		while (k*2 < nums[i]) {
			k*=2l;
			ans++;
		}
		k = max(k, nums[i]);
	}
	cout << ans << endl;
	cin >> n;
}