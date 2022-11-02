#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

int n, m;
vector<int> a, b;

bool check(ld have) {
	ld now = m + have;
	for (int i = 0; i < n; i++) {
		ld need = now / a[i];
		now -= need;
		have -= need;
		if (have < 0) return false;
		need = now / (b[(i + 1) % n]);
		now -= need;
		have -= need;
		if (have < 0) return false;	
	}
	return true;
}

void solve() {
	cin >> n >> m;
	a.resize(n);
	for (auto &i : a) cin >> i;
	b.resize(n);
	for (auto &i : b) cin >> i;
	ld l = 0, r = 1e9 + 10;
	for (int i = 0; i < 50; i++) {
		ld mid = (l + r) / 2;
		if (check(mid))
			r = mid;
		else
			l = mid;
	}
	if (r == 1e9 + 10) {
		cout << -1 << endl;
		return;
	}
	cout.precision(20);
	cout << r << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}