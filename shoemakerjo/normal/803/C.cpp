#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	ll n, k;
	cin >> n >> k;
	ll ans = -1;
	for (ll div = 1; div <= sqrt(n); div+=1LL) {
		if (n%div != 0LL) continue;
		ll od = n/div;
		if ((k)*(k+1LL) <= 2LL*n/od) {
			ans = max(ans, od);
		}
		if (k*(k+1LL) <= 2ll*n/div) {
			ans = max(ans, div);
		}
	}
	// cout << "ans   " << ans << endl;
	if (k >= sqrt(2*n)) ans = -1;
	if (ans == -1) {
		cout << -1 << endl;
	}
	else {
		ll sum = 0LL;
		for (ll i = 1LL; i <= k-1; i+=1LL) {
			sum += i*ans;
			cout << i*ans << " ";
		}
		cout << n-sum << endl;
	}
	cin >> n;
}