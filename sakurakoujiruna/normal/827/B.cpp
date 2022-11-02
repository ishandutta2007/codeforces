#include <bits/stdc++.h>
using namespace std;

int main() {
	ios :: sync_with_stdio(0);
	int n, k; cin >> n >> k;

	int ans = 0, m = n;
	while(m > k) {
		m -= k;
		ans += 2;
	}
	if(m == 2)
		ans ++;
	else if(m > 2)
		ans += 2;

	cout << ans << '\n';

	if(m == 1) {
		for(int i = 2; i <= k + 1; i ++)
			cout << 1 << ' ' << i << '\n';
	} else if(m == 2) {
		cout << 1 << ' ' << 2 << '\n';
		cout << 1 << ' ' << 3 << '\n';
		for(int i = 4; i <= k + 2; i ++)
			cout << 2 << ' ' << i << '\n';
	} else {
		for(int i = 2; i <= m; i ++) {
			cout << 1 << ' ' << i << '\n';
			cout << i << ' ' << i + m - 1 << '\n';
		}
		for(int i = m + m; i <= m + k; i ++)
			cout << 1 << ' ' << i << '\n';
	}
	for(int i = m + 1; i + k <= n; i ++)
		cout << i << ' ' << i + k << '\n';
}