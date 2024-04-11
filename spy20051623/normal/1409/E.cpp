#include <bits/stdc++.h>
using namespace std;
int a[200005];
int l[200005];
int r[200005];

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, k, i, j, maxm;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (i = 0; i < n; ++i) {
			cin >> a[i];
		}
		for (i = 0; i < n; ++i) {
			cin >> j;
		}
		sort(a, a + n);
		j = 0;
		l[0] = 1;
		for (i = 1; i < n; ++i) {
			while (abs(a[i] - a[j]) > k)
				++j;
			l[i] = max(l[i - 1], i - j + 1);
		}
		j = n - 1;
		r[n - 1] = 1;
		for (i = n - 2; i >= 0; --i) {
			while (abs(a[i] - a[j]) > k)
				--j;
			r[i] = max(r[i + 1], j - i + 1);
		}
		maxm = 1;
		for (i = 0; i < n - 1; ++i) {
			maxm = max(maxm, l[i] + r[i + 1]);
		}
		cout << maxm << endl;
	}
	return 0;
}