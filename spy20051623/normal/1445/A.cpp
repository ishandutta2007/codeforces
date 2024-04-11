#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, x, a[100], b[100], i;
	cin >> t;
	while (t--) {
		cin >> n >> x;
		for (i = 0; i < n; ++i)
			cin >> a[i];
		for (i = 0; i < n; ++i)
			cin >> b[i];
		sort(a, a + n);
		sort(b, b + n, greater<int>());
		for (i = 0; i < n; ++i)
			if (a[i] + b[i] > x)
				break;
		cout << (i < n ? "no" : "yes") << endl;
	}
	return 0;
}