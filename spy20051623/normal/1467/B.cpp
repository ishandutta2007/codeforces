#include <bits/stdc++.h>
using namespace std;
int a[300005], n;

int check(int i) {
	if (i == 0 || i == n - 1)
		return 0;
	if (a[i] > a[i - 1] && a[i] > a[i + 1])
		return 1;
	if (a[i] < a[i - 1] && a[i] < a[i + 1])
		return 1;
	return 0;
}

main() {
	int t, i, count, maxd, temp, s, x, y;
	cin >> t;
	while (t--) {
		cin >> n;
		for (i = 0; i < n; ++i) {
			cin >> a[i];
		}
		count = 0;
		for (i = 1; i < n - 1; ++i) {
			if (check(i))
				++count;
		}
		maxd = 0;
		for (i = 1; i < n - 1; ++i) {
			temp = a[i];
			s = check(i - 1) + check(i) + check(i + 1);
			a[i] = a[i - 1];
			x = check(i - 1) + check(i) + check(i + 1);
			a[i] = a[i + 1];
			y = check(i - 1) + check(i) + check(i + 1);
			if (maxd < s - min(x, y))
				maxd = s - min(x, y);
			a[i] = temp;
		}
		cout << count - maxd << endl;
	}
}