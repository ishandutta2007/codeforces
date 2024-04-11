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
	vector<int> b(n);
	for (auto &i : a) cin >> i;
	for (auto &i : b) cin >> i;
	auto fa = a, fb = b;
	sort(all(fa));
	sort(all(fb));
	if (fa != fb) {
		cout << "NO\n";
		return;
	}
	vector<pair<int, int>> haveA, haveB;
	for (int i = 0; i < n; i++) {
		haveA.push_back({a[i], a[n - 1 - i]});
		haveB.push_back({b[i], b[n - 1 - i]});
	}
	for (auto &i : haveA) {
		if (i.first > i.second) swap(i.first, i.second);
	}
	for (auto &i : haveB) {
		if (i.first > i.second) swap(i.first, i.second);
	}
	sort(all(haveA));
	sort(all(haveB));
	if (haveA == haveB) {
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