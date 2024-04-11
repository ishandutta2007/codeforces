#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int n;
	cin >> n;
	set<pair<int, int>> a;
	a.insert({-n, 0});
	vector<int> ans(n);
	int it = 1;
	while (!a.empty()) {
		auto x = *a.begin();
		a.erase(a.begin());
		int pos = x.second;
		int len = -x.first;
		//cout << pos << " " << len << endl;

		if (len == 0) continue;
		if (len == 1) {
			ans[pos] = it++;
		} else {
			if (len % 2 == 0) {
				ans[pos + (len - 1) / 2] = it++;
				a.insert({-(len / 2) + 1, pos});
				a.insert({-(len / 2), pos + (len - 1) / 2 + 1});
			} else {
				ans[pos + len / 2] = it++;
				a.insert({-(len / 2), pos});
				a.insert({-(len / 2), pos + len / 2 + 1});
			}
		}
	}
	for (auto i : ans) {
		cout << i << " ";
	}
	cout << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}