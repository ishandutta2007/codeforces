#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int n, x;
	cin >> n >> x;
	multiset <pair <int, int> > x2;
	multiset <pair <int, pair <int, int> > >a;
	for (int i = 0; i < n; i++) {
		int d, h;
		cin >> d >> h;
		x2.insert({d, h});
		a.insert({d - h, {d, h}});
	}

	auto x1 = *(--x2.end());
	int can = x1.first;

	auto a1 = *(--a.end());	
	int diff = a1.first;

	if (diff <= 0 && can < x) {
		cout << -1 << endl;
		return;
	}
	int ans = 0;
	ans++;
	x -= can;
	if (x <= 0) {
		cout << ans << endl;
		return;
	}

	ans += (x + diff - 1) / diff;
	cout << ans << endl;
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