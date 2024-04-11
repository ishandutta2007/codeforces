#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		ll h = 0, s = 0;
		for (int i=0; i<n; i++) {
			ll x;
			cin >> x;
			x += 321321321321ll;
			if (x < h) {
				s = max(s, h - x);
			}
			h = max(x, h);
		}

		cout << (s ? 64 - __builtin_clzll(s) : 0) << '\n';
	}
}