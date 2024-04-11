#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int b, w;
	cin >> b >> w;
	//cout << "b = " << b << " w = " << w << endl;
	if (max(b, w) > min(b, w) * 3 + 1) {
		cout << "NO\n";
		return;
	}

	vector<pair <int, int> > ans;
	int pos_x = 1e6, pos_y = 1e6;
	if (b > w)
		pos_x++;
	for (int i = 0; i < 2 * min(b, w); i++)
		ans.push_back({pos_x, pos_y + i});

	int x = min(b, w);
	b -= x;
	w -= x;
	int need = max(b, w);
	if (need > 0) {
		ans.push_back({pos_x, ans.size() + pos_y});
		need--;
	}
	int i = 1;
	while (need) {
		ans.push_back({pos_x + 1, pos_y + i});
		need--;
		if (need > 0) {
			ans.push_back({pos_x - 1, pos_y + i});
			need--;
		}
		pos_y += 2;
	}

	cout << "YES\n";
	for (auto i : ans) {
		cout << i.first << " " << i.second << "\n";
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin >> q;
	while (q--) {
		solve();
	}
	return 0;
}