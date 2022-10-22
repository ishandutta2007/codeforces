#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, h;
vector <int> a;

 main() {
	//freopen("B.in", "r", stdin);
	//freopen("B.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin >> n >> h;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int l = 0, r = n + 1;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		vector <int> b;
		for (int i = 0; i < mid; i++) {
			b.push_back(a[i]);
		}
		sort(b.rbegin(), b.rend());
		int now = 0;
		for (int i = 0; i < mid; i += 2) {
			now += b[i];
		}
		if (now > h) {
			r = mid;
		} else {
			l = mid;
		}
	}
	cout << l << "\n";
}