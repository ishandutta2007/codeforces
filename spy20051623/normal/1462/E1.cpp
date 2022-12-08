#include <bits/stdc++.h>
using namespace std;
int a[200005];

int main() {
//	freopen("in.txt", "r", stdin);
	long long t, n, i, j, res;
	cin >> t;
	while (t--) {
		cin >> n;
		for (i = 0; i < n; ++i)
			cin >> a[i];
		sort(a, a + n);
		res = 0;
		for (i = 0; i < n; ++i) {
			j = upper_bound(a, a + n, a[i] + 2) - 1 - a - i;
			res += 1LL * (j - 1) * j / 2;
		}
		cout << res << endl;
	}
	return 0;
}