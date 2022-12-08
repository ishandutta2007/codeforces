#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	ll cur = 0LL;
	ll ans = 0LL;

	int nums[n+1];
	ll t[n+1];
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
		
	}

	for (int i = n; i >= 1; i--) {
		cur-=1LL;
		cur = max(cur, nums[i]+1LL);
		t[i] = cur;
	}

	cur = 0LL;
	for (int i = 1; i <= n; i++) {
		cur = max(cur, t[i]);
		ans += cur;
	}

	for (int i = 1; i <= n; i++) {
		ans -= nums[i]+0LL;

	}
	ans -= n+0LL;
	cout << ans << endl;
	cin >> ans;

}