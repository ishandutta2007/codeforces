#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a)
		cin >> i;
	vector<int> b(n);
	for (auto &i : b)
		cin >> i;
	reverse(all(a));
	int cnt1 = 0, cnt2 = 0;
	for (auto i : a)
		if (i == 1) cnt1++;
		else cnt2++;
	map<int, int> fans;
	fans[cnt1 - cnt2] = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) cnt1--;
		else cnt2--;
		if (fans.count(cnt1 - cnt2)) continue;
		fans[cnt1 - cnt2] = i + 1;
	}
	int ans = 2 * n;
	cnt1 = 0, cnt2 = 0;
	for (auto i : b)
		if (i == 1) cnt1++;
		else cnt2++;
	if (fans.count(cnt2 - cnt1)) chkmin(ans, fans[cnt2 - cnt1]);
	for (int i = 0; i < n; i++) {
		if (b[i] == 1) cnt1--;
		else cnt2--;
		if (!fans.count(cnt2 - cnt1)) continue;
		chkmin(ans, fans[cnt2 - cnt1] + i + 1);
	}
	cout << ans << "\n";
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