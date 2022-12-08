#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	long long t, a, b, x, y, n, i, j, ii, jj, k;
	cin >> t;
	while (t--) {
		cin >> a >> b >> x >> y >> n;
		i = min(a - x, n);
		ii = min(n - i, b - y);
		j = min(b - y, n);
		jj = min(n - j, a - x);
		k = min((a - i) * (b - ii), (a - jj) * (b - j));
		cout << k << endl;
	}
	return 0;
}