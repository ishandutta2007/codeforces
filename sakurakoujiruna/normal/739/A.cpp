#include <bits/stdc++.h>
using namespace std;

int main() {
	ios :: sync_with_stdio(false);

	int n, m; cin >> n >> m;
	int ans = n;
	for(int i = 1; i <= m; i ++) {
		int l, r; cin >> l >> r;
		ans = min(ans, r - l + 1);
	}
	cout << ans << '\n';
	for(int i = 0; i < n; i ++)
		cout << i % ans << ' ';
	cout << '\n';

	return 0;
}