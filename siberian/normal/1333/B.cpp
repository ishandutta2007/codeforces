#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto &i : a)
		cin >> i;
	for (auto &i : b)
		cin >> i;
	int posA = -1, posB = -1;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] == 1) posA = i;
		if (a[i] == -1) posB = i;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) continue;
		if (b[i] - a[i] > 0 && posA != -1 && posA < i) continue;
		if (b[i] - a[i] < 0 && posB != -1 && posB < i) continue;
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
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