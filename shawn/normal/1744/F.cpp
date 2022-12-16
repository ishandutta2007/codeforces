#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

ll a[N];

int main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	int _;
	cin >> _;
	while (_--) {
		int n;
		cin >> n;
		for (int x, i = 1; i <= n; i++) {
			cin >> x;
			a[x] = i;
		}
		ll l = n, r = 1, ans = 0;
		for (int i = 1; i <= n; i++) {
			l = min(l, a[i - 1]);
			r = max(r, a[i - 1]);
			ll len = 2 * i;
			if (r - l + 1 > len) continue;
			ll x = max(1ll, r - len + 1);
			ll y = min(l, n - len + 1);
			ans += max(0ll, y - x + 1);
			len--;
			if (r - l + 1 > len) continue;
			x = max(1ll, r - len + 1);
			y = min(l, n - len + 1);
			ans += max(0ll, y - x + 1);
		}
		cout << ans << '\n';
	}
	return 0;	
}