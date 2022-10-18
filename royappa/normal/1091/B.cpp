#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int n;
	cin >> n;

	vector<int> x(n), y(n), a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	if (n == 1) {
		cout << x[0]+a[0] << " " << y[0]+b[0] << endl;
		exit(0);
	}
	set<vector<int>> ts;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (x[0]+a[i] == x[1]+a[j] && y[0]+b[i] == y[1]+b[j]) {
				ts.insert({x[0]+a[i], y[0]+b[i]});
			}
		}
	}
	vector<vector<int>> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = {a[i], b[i]};
	}
	sort(v.begin(), v.end());
	for (auto t : ts) {
		int tx = t[0], ty = t[1];
		// find if there is a unique assignment of (a,b) which will make this tx, ty work
		vector<vector<int>> w(n);
		for (int i = 0; i < n; i++) {
			w[i] = {tx-x[i], ty-y[i]};
		}
		sort(w.begin(), w.end());
		if (v == w) {
			cout << tx << " " << ty << endl;
		}
	}
	exit(0);
}