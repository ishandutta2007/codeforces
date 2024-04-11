#include <bits/stdc++.h>

using namespace std;

int a[203][103];

int main() {
#ifdef FLOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m, k, ans = 0, mc = 0;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	for (int i = 0; i < m; i++) {
		int cs = 0, ms = 0, bc = 0, p = 0;
		for (int j = 0; j < k; j++)
			cs += a[j][i];
		for (int j = k; j <= n + k; j++) {
			if (a[j - k][i] && cs > ms) {
				ms = cs;
				bc = p;
			}
			else if (a[j - k][i] && cs == ms)
				bc = min(bc, p);
			cs += a[j][i] - a[j - k][i];
			p += a[j - k][i];
		}
		ans += ms;
		mc += bc;
	}
	cout << ans << ' ' << mc << '\n';
}