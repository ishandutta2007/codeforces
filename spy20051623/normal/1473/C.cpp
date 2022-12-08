#include <bits/stdc++.h>
using namespace std;
int a[100005];

main() {
	int t, k, n, i, cnt;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		cnt = 0;
		for (i = 1; i < 2 * k - n; ++i) {
			a[cnt] = i;
			++cnt;
		}
		for (i = k; i >= 2 * k - n; --i) {
			a[cnt] = i;
			++cnt;
		}
		cout << a[0];
		for (i = 1; i < cnt; ++i) {
			cout << " " << a[i];
		}
		cout << endl;
	}
}