#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	map<char, int> a;
	for (auto i : s)
		a[i]++;
	for (auto i : a) {
		if (i.second > k) {
			cout << "No";
		return;
		}
	}
	cout << "Yes";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	t = 1;
	while (t--)
		solve();
	return 0;
}