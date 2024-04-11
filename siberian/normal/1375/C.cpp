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
	vector<int> a(n);
	for (auto &i : a) {
		cin >> i;
	}
	vector<int> st;
	for (int i = 0; i < n; i++) {
		int x = a[i];
		while (st.size() > 1 && st.back() < x) {
			st.pop_back();
		}	
		if (!st.empty() && st.back() < x) {

		} else {
			st.push_back(x);
		}
		/*cout << "st = " << endl;
		for (auto i : st) {
			cout << i << " ";
		}
		cout << endl;*/
	}
	auto have = st;
	sort(all(have));
	if (have == st) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
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