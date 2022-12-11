#include <bits/stdc++.h>
using namespace std;
int main () {
	int T; cin >> T;
	while (T--) {
		int n, m; cin >> n >> m;
		long long ans = 0;
		for (int l = 1, r; l <= n; l = r + 1) {
			r = n / (n / l);
			if (l == 1) continue;
			if (r > m + 1) r = m + 1;
			int val = n / l;
			if (r - 2 <= val) ans += (long long)(l - 2 + r - 2) * (r - l + 1) / 2;
			else if (l - 2 <= val) ans += (long long)(l - 2 + val) * (val - l + 3) / 2 + (long long)(r - 2 - val) * val;
			else ans += (long long)(r - l + 1) * val;
			if (r == m + 1) break;
		}
		cout << ans << endl;
	}
	return 0;
}