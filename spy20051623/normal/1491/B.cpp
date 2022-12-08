#include <bits/stdc++.h>
using namespace std;
int r[200005];

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, u, v, i, j, maxm;
	cin >> t;
	while (t--) {
		cin >> n >> u >> v;
		maxm = 0;
		for (i = 1; i <= n; ++i) {
			cin >> r[i];
			if (i >= 2 && abs(r[i] - r[i - 1]) > maxm)
				maxm = abs(r[i] - r[i - 1]);
		}
		if (maxm >= 2)
			cout << 0 << endl;
		else if (maxm == 1)
			cout << min(u, v) << endl;
		else
			cout << v + min(u, v) << endl;
	}
	return 0;
}