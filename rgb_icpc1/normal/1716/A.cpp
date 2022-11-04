#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long LL;

const int MX = 200005;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int Tc;
	for (cin >> Tc; Tc--; ) {
		int n; cin >> n;
		if (n % 3 == 0) cout << abs(n / 3) << endl;
		else if (n % 3 == 1) {
			int ans = abs((n + 2) / 3) + 1;
			ans = min(ans, abs((n - 4) / 3) + 2);
			cout << ans << endl;
		}
		else cout << abs(n / 3) + 1 << endl;
	}

	return 0;
}