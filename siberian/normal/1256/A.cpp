#include <bits/stdc++.h>

using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int get(string s) {
	map <char, int> cnt;
	int ans = 0;
	for (auto i : s) {
		for (int j = i + 1; j < 'z'; j++) {
			ans += cnt[j];
		}
		cnt[i]++;
	}
	return ans % 2;
}

void solve() {
	int a, b, n, s;
	cin >> a>> b >> n >> s;
	int x = min(s / n, a);
	s -= x * n;
	if (s > b) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
	}
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