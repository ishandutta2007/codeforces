#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll
int n;
vector<int> a;

bool check(int mid) {
	int last = 1e18 + 228 + 1337;
	for (int i = n - 1; i >= 0; i--) {
		int have = a[i];
		for (int bit = mid - 1; bit >= 0; bit--) {
			if (have + (1LL << bit) <= last) {
				have += (1LL << bit);
			}
		}
		if (last < have) return false;
		last = have;
	}
	return true;
}

void solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a)
		cin >> i;
	int l = -1, r = 35;
	while (l < r - 1) {
		int mid = (l + r) / 2;
		if (check(mid))
			r = mid;
		else
			l = mid;
	}
	cout << r << "\n";
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