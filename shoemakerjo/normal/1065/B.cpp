#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;

	if (m*2 >= n) {
		cout << 0 << " ";
	}
	else cout << n - m*2 << " ";
	for (ll i = 0; i <= n; i++) {
		ll curedge = (i*(i-1))/2LL;
		if (curedge >= m) {
			cout << n-i << endl;
			return 0;
		}
	}
	cout << 0 << endl;

}