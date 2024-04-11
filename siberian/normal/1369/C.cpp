#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &i : a) {
		cin >> i;
	}
	sort(all(a));
	vector<int> w(k);
	for (auto &i : w) {
		cin >> i;
	}
	sort(all(w));
	reverse(all(w));
	int ans = 0;
	while (!w.empty() && !a.empty() && w.back() == 1) {
		k--;
		n--;
		w.pop_back();
		ans += a.back() * 2;
		a.pop_back();
	}
	int pos = 0;
	for (int i = 0; i < k; i++) {
		ans += a[n - 1 - i];
		ans += a[pos];
		pos += w[i] - 1;
	}
	cout << ans << endl;
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