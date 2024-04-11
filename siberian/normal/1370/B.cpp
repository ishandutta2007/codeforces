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
	vector<int> odd, even;
	for (int i = 0; i < 2 * n; i++) {
		int x;
		cin >> x;
		if (x % 2 == 1) {
			odd.push_back(i + 1);
		} else {
			even.push_back(i + 1);
		}
	}
	if (odd.empty()) {
		even.pop_back();
		even.pop_back();
	} else if (odd.size() % 2 == 1) {
		odd.pop_back();
		even.pop_back();
	} else {
		odd.pop_back();
		odd.pop_back();
	}
	for (int i = 0; i < odd.size(); i += 2) {
		cout << odd[i] << " " << odd[i + 1] << "\n";
	}
	for (int i = 0; i < even.size(); i += 2) {
		cout << even[i] << " " << even[i + 1] << "\n";
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