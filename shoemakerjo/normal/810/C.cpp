#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
	ll mod = 1000000007;
	int n;
	cin >> n;
	vector<ll> nums;
	ll cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		nums.push_back(cur);
	}
	sort(nums.begin(), nums.end());
	ll is_min = 1;
	ll is_max = 1;
	for (int i = 1; i < nums.size(); i++) {
		is_min = (is_min*2l)%mod;
	}
	ll inv = (mod+1)/2l;
	ll ans = 0l;
	ans = (ans + is_max*(nums[0]))%mod;
	ans -= (is_min*(nums[0]))%mod;
	if (ans < 0) ans+=mod;
	for (int i = 1; i < nums.size(); i++) {
		is_min = (is_min*inv)%mod;
		is_max = (is_max*2l)%mod;

		ans = (ans + is_max*(nums[i]))%mod;
		ans -= (is_min*(nums[i]))%mod;
		if (ans < 0) ans+=mod;
	}
	ans = ans%mod;
	cout << ans << endl;
	cin >> n;
}