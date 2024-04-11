#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &i : a)
		cin >> i;
	vector<bool> used(100, false);
	bool ans = true;
	for (auto i : a) {
		int it = 0;
		while (i) {
			if (i % k == 0) {
				i /= k;
				it++;
				continue;
			}
			if (i % k > 1) {
				ans = false;
			}
			if (used[it]) {
				ans = false;
			}
			used[it] = true;
			it++;
			i /= k;
		}
	}
	/*cout << "used = " << endl;
	for (auto i : used)
		cout << i << " ";
	cout << endl;*/
	if (ans) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}