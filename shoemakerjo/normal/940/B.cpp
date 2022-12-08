#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, k, A, B;
	cin >> n >> k >> A >> B;
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	if (k == 1) {
		cout << A*(n-1) << endl;
		return 0;
	}
	ll ans = 0LL;
	while (n > 1) {
		if (n%k == 0) {
			ll nx = n/k;
			if (B < A*(n-nx)) {
				ans += B;
				n = nx;
			}
			else {
				ans += A*(n-1);
				break;
			}
		}
		else {
			if (n < k) {
				ans += A*(n-1);
				n = 1;
			}
			else {
				ans += A*(n%k);
				n -= n%k;
			}
		}
	}
	cout << ans << endl;
	cin >> n;

}