#include <bits/stdc++.h>
using namespace std;

void solve() {
	int i, j, n, m;
	long long sum = 0;
	cin >> n >> m;
	vector<int> a(m + 5);
	for (i = 0; i < n; ++i) {
		cin >> j;
		++a[j % m];
	}
	if (a[0])
		sum = 1;
	for (i = 1; i < (m + 1) / 2; ++i) {
		if (a[i] && a[m - i]) {
			if (a[i] == a[m - i])
				++sum;
			else
				sum += abs(a[i] - a[m - i]);
		} else if (a[i] && !a[m - i])
			sum += a[i];
		else if (!a[i] && a[m - i])
			sum += a[m - i];
	}
	if (m % 2 == 0 && a[m / 2])
		++sum;
	cout << sum << endl;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}