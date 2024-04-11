#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	int cnt_zeroes = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			cnt_zeroes++;
			continue;
		}

		int x = 0;
		for (int j = i; j < n && j < i + 20; j++) {
			x *= 2;
			x += s[j] - '0';
			if (j - i + 1 <= x && cnt_zeroes + j - i + 1 >= x)
				ans++;
		}
		cnt_zeroes = 0;
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