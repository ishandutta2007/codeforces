#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);

	int t;
	cin >> t;
	while (t --) {
		int l, r;
		cin >> l >> r;
		int ans = r % l;
		int x = r / 2 + 1;
		if (x >= l) ans = max(ans, r % x);
		cout << ans << "\n";
		// [5, 8]
		// [3, 8] 
	}
}