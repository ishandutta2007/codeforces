#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, i, a[100], cnt;
	double p;
	cin >> t;
	while (t--) {
		cin >> n;
		for (i = 0; i < n; ++i) {
			cin >> a[i];
		}
		cnt = 0;
		for (i = 0; i < n - 1; ++i) {
			p = (a[i] < a[i + 1] ? 1.0 * a[i + 1] / a[i] : 1.0 * a[i] / a[i + 1]);
			while (p > 2) {
				++cnt;
				p /= 2;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}