#include <bits/stdc++.h>
using namespace std;
map<int, int> m;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, i, j, k, maxm;
	cin >> t;
	while (t--) {
		cin >> n;
		m.clear();
		for (i = 0; i < n; ++i) {
			cin >> j;
			++m[j];//map
		}
		maxm = 0;
		for (auto it : m) {
			if (it.second > maxm)
				maxm = it.second;//
		}
		if (maxm <= n - maxm)
			cout << n % 2 << endl;
		else
			cout << 2 * maxm - n << endl;
	}
	return 0;
}