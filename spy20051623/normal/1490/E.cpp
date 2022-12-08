#include <bits/stdc++.h>
using namespace std;
int a[200005], b[200005];

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, i, j, s;
	long long sum;
	cin >> t;
	while (t--) {
		cin >> n;
		for (i = 0; i < n; ++i) {
			cin >> a[i];
			b[i] = a[i];
		}
		sort(b, b + n);
		sum = 0;
		s = 0;
		for (i = 0; i < n; ++i) {
			if (sum < b[i])
				s = i;
			sum += b[i];
		}
		cout << n - s << endl;
		for (i = 0; i < n; ++i) {
			if (a[i] >= b[s])
				cout << i + 1 << ' ';
		}
		cout << endl;
	}
	return 0;
}