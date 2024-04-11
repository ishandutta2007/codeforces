#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int n;
	ll p, q, r;
	cin >> n >> p >> q >> r;
	ll nums[n];
	ll maxk[n];
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		maxk[i] = r*nums[i];
	}
	ll best = maxk[n-1];
	ll maxj[n];
	for (int i = n-1; i>= 0; i--) {
		best = max(best, maxk[i]);
		maxj[i] = q*nums[i] + best;
	}
	best = maxj[n-1];
	ll ans = p*nums[n-1] + maxj[n-1];
	for (int i = n-1; i >= 0; i--) {
		best = max(best, maxj[i]);
		ll cur = best + p*nums[i];
		ans = max(ans, cur);
	}
	cout << ans << endl;
	// cin >> ans;
	
}