#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
#define int ll

int n;
string s;

void solve() {
	cin >> n >> s;
	vector<pair<int, int>> a;
	int x = 0, y = 0;
	a.push_back({x, y});
	for (auto i : s) {
		if (i == 'U') x--;
		else if (i == 'D') x++;
		else if (i == 'L') y--;
		else if (i == 'R') y++;
		a.push_back({x, y});
	}
	int l = -1, r = -1;
	map<pair<int,int>, int> have;
	for (int i = 0; i < a.size(); i++) {
		if (have.count(a[i])) {
			int L = have[a[i]];
			int R = i;
			if (r == -1 || r - l > R - L) {
				l = L, r = R;
			} 
		}
		have[a[i]] = i;
	}
	if (r == -1) {
		cout << -1 << endl;
	}
	else {
		cout << l + 1 << " " << r << endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}