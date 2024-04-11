#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int h = 0; h < t; ++h) {
		int n, k, c, x, mx, l, u, ans;
		cin >> n >> k;
		set<int> pos[k];
		for (int i = 0; i < k; ++i) {
			cin >> c;
			for (int j = 0; j < c; ++j) {
				cin >> x;
				pos[i].insert(x);
			}
		}
		cout << "? " << n;
		for (int i = 1; i <= n; ++i) cout << " " << i;
		cout << "\n";
		cout.flush();
		cin >> mx;
		l = 0, u = k - 1;
		while (l != u) {
			int m = (l + u) / 2;
			set<int> query;
			for (int i = l; i <= m; ++i) {
				for (int j: pos[i]) query.insert(j);
			}
			cout << "? " << query.size();
			for (int i: query) cout << " " << i;
			cout << "\n";
			cout.flush();
			cin >> ans;
			if (ans == mx) u = m;
			else l = m + 1;
		}
		set<int> query;
		for (int i = 1; i <= n; ++i) {
			if (pos[l].find(i) == pos[l].end()) query.insert(i);
		}
		cout << "? " << query.size();
		for (int i: query) cout << " " << i;
		cout << "\n";
		cout.flush();
		cin >> ans;
		cout << "!";
		for (int i = 0; i < k; ++i) {
			if (i == l) cout << " " << ans;
			else cout << " " << mx;
		}
		cout << "\n";
		cout.flush();
		string verdict;
		cin >> verdict;
	}
	return 0;
}