#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	long long t, n, a[1005], b[1005], i, j;
	cin >> t;
	while (t--) {
		cin >> n;
		for (i = 0; i < n; ++i) {
			cin >> a[i] >> b[i];
		}
		if (n % 2)
			cout << 1 << endl;
		else {
			sort(a, a + n);
			sort(b, b + n);
			cout << (a[n / 2] - a[n / 2 - 1] + 1)*(b[n / 2] - b[n / 2 - 1] + 1) << endl;
		}
	}
	return 0;
}