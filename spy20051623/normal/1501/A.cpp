#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	long long T, n, a[1000], b[1000], t[1000], i, sum;
	cin >> T;
	while (T--) {
		cin >> n;
		for (i = 1; i <= n; ++i) {
			cin >> a[i] >> b[i];
		}
		for (i = 1; i <= n; ++i) {
			cin >> t[i];
		}
		sum = 0;
		for (i = 1; i < n; ++i) {
			sum += a[i] - b[i - 1] + t[i];
			sum = max(sum + (b[i] - a[i] + 1) / 2, b[i]);
		}
		sum += a[i] - b[i - 1] + t[i];
		cout << sum << endl;
	}
	return 0;
}