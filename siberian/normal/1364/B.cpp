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
	vector<int> p;
	p.resize(n);
	for (auto &i : p) {
		cin >> i;
		i--;
	}

	vector<int> ans;
	for (auto i : p) {
		if (ans.size() <= 1) {
			ans.push_back(i);
		} else {
			int L = min(ans[ans.size() - 2], i);
			int R = max(ans[ans.size() - 2], i);
			if (L < ans.back() && R > ans.back()) {
				ans.pop_back();
			}
			ans.push_back(i);
		}
	}

	cout << ans.size() << "\n";
	for (auto i : ans) {
		cout << i + 1 << " ";
	}
	cout << "\n";
}


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}