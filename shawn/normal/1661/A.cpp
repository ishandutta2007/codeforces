#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, a[30], b[30], _;

int main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> _;
	while (_ --) {
		cin >> n;
		ll ans = 0;
		for (int i = 1; i <= n; i ++) cin >> a[i];
		for (int i = 1; i <= n; i ++) cin >> b[i];
		for (int i = 1; i < n; i ++) {
			ans += min((abs(a[i] - a[i + 1]) + abs(b[i] - b[i + 1])), abs(b[i] - a[i + 1]) + abs(a[i] - b[i + 1]));
		}
		cout << ans << "\n";
	}
	return 0;	
}