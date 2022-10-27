#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin >> n >> k;
	vector<vector<int> > a(n, vector<int>(n, 0));
	set<int> s;
	vector<int> cnt(n*n + 1, 0);
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			cin >> a[i][j];
			s.insert(a[i][j]);
			cnt[a[i][j]] ++;
		}
	}

	if (s.size() <= k) {
		cout << k - s.size() << "\n";
	} else {

		vector<int> tmp(n*n + 1, 0);
		vector<pair<int,int> > vec;
		for (int i = 0; i < n; i ++) {
			vec.push_back({0, i});
		}
		for (int i = 1; i < n; i ++) {
			vec.push_back({i, 0});
		}
		int ans = 0;
		auto add = [&](int x, int y) {
			tmp[a[x][y]] ++;
			if (tmp[a[x][y]] == cnt[a[x][y]]) ans ++;
		};
		auto del = [&](int x, int y) {
			tmp[a[x][y]] --;
			if (tmp[a[x][y]] == cnt[a[x][y]] - 1) ans --;
		};
		bool ok = false;
		for (auto p: vec) {
			for (int i = 1; i <= n * n; i ++) tmp[i] = 0;
			int x_1 = p.first, y_1 = p.second;
			int x_2 = p.first, y_2 = p.second;
			ans = 0;
			int need = s.size() - k;
			while (x_1 < n and y_1 < n) {
				// cout << x_1 << " " << y_1 << " " << x_2 << " " << y_2 << "\n";
				while (x_2 < n and y_2 < n and ans < need) {
					// add (x2, y2)
					for (int i = x_1; i <= x_2; i ++) add(i, y_2);
					for (int j = y_1; j < y_2; j ++) add(x_2, j);
					x_2 ++, y_2 ++;
					// cout << x_2 << " " << y_2 << " " << ans << "\n";
				}	
				if (ans == need or ans == need + 1) {	
					ok = true; break;
				}
				// del(x1, y1)
				for (int i = x_1; i < x_2; i ++) del(i, y_1);
				for (int j = y_1 + 1; j < y_2; j ++) del(x_1, j);
				x_1 ++, y_1 ++;
				// cout << "del " << x_1 << " " << y_1 << " " << ans << "\n";
			}
		}
		if (ok) cout << 1 << "\n"; else cout << 2 << "\n";
	}
}