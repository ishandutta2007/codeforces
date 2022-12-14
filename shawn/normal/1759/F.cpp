#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

set<int> s;
int a[110], p, n, _;

int main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> _;
	while (_ --) {
		s.clear();
		cin >> n >> p;
		for (int i = n; i; i--) {
			cin >> a[i];
			s.insert(a[i]);
		}
		// for (int i = 1; i <= n + 4; i ++) {
		// 	cout << a[i];
		// }
		// cout << "\n";
		if (s.size() == p) {
			cout << "0\n";
			continue;
		}
		int l = 0, r = p - 1;
		while (s.count(l)) l++;
		while (s.count(r)) r--;
		if (a[1] < l) {
			cout << r - a[1] << "\n";
			continue;	
		}
		int t = a[1], ans = p - a[1];
		a[1] = p, a[n + 1] = 0;
		for (int i = 1; i <= n; i ++) {
			if (a[i] >= p) {
				a[i + 1] += a[i] / p;
				a[i] %= p;
			}
			s.insert(a[i]);
		}
		if (a[n + 1]) s.insert(a[n + 1]);
		while (s.count(t)) t--;
		cout << ans + max(t, 0) << "\n";
	}
	return 0;	
}