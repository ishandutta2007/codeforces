#include <bits/stdc++.h>

using namespace std;

using llint = long long;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int Tc;
	for (cin >> Tc; Tc--; ) {
		llint n;
		cin >> n;
		if (n % 2050) {
			cout << -1 << endl;
			continue;
		}
		n /= 2050;
		int ans = 0;
		while (n) {
			ans += n % 10;
			n /= 10;
		}
		cout << ans << endl;
	}
	
	return 0;
}