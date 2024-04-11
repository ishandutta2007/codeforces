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
	multiset<int> a;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.insert(x);
	}

	int ans = 0;
	auto b = a;
	for (int i = 0; i < n - 1; i++) {
		int x;
		cin >> x;
		b.erase(b.find(x));
	}
	ans = *b.begin();
	int ans2 = 0;
	b = a;
	b.erase(b.find(ans));
	for (int i = 0; i < n - 2; i++) {
		int x;
		cin >> x;
		b.erase(b.find(x));
	}
	cout << ans << " " << *b.begin();
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	//cin >> t;	
	t = 1;
	while (t--)
		solve();
	return 0;
}