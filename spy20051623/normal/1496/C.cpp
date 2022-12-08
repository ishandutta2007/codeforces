#include <bits/stdc++.h>
using namespace std;
vector<int> a, b;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, i, j, x, y;
	double res;
	cin >> t;
	while (t--) {
		cin >> n;
		a.clear();
		b.clear();
		for (i = 0; i < 2 * n; ++i) {
			cin >> x >> y;
			if (x == 0)
				b.push_back(abs(y));
			if (y == 0)
				a.push_back(abs(x));
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		res = 0;
		for (i = 0; i < n; ++i) {
			res += sqrt(1LL * a[i] * a[i] + 1LL * b[i] * b[i]);
		}
		cout << fixed << setprecision(12) << res << endl;
	}
	return 0;
}