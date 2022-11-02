#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int get(int a, int b, int c) {
	if (a < b)
		swap(a, b);
	int d = a - b;
	if (c > d)
		return a + (c - d) / 2;
	return b + c;
}

void solve() {
	vector<int> a(3);
	for (auto &i : a)
		cin >> i;
	sort(a.begin(), a.end());
	int ans = 0;
	do {
		chkmax(ans, get(a[0], a[1], a[2]));
	} while (next_permutation(a.begin(), a.end()));
	cout << ans << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}