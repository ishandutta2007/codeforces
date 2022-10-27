#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);

	int t;
	cin >> t;
	while (t --) {
		int n, b, x, y;
		cin >> n >> b >> x >> y;
		ll ans = 0;
		int cur = 0;
		for (int i = 1; i <= n; i ++) {
			if (cur + x <= b) cur += x; else cur -= y;
			ans += cur;
		}
		cout << ans << "\n";
	}
}