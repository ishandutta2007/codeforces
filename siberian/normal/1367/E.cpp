#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	map<char, int> cnt;
	for (auto i : s) {
		cnt[i]++;
	}
	vector<int> have;
	for (auto i : cnt) {
		have.push_back(i.second);
	}
	sort(all(have));
	int ans = 0;
	for (int len = 1; len <= n; len++) {
		vector<bool> used(len);
		int val = -1;
		int bloks = 0;
		for (int i = 0; i < len; i++) {
			if (used[i]) continue;
			int fcnt = 0;
			for (int now = i; !used[now]; now = (now + k) % len) {
				fcnt++;
				used[now] = true;
			}
			if (val == -1) {
				val = fcnt;
			} else {
				assert(val == fcnt);
			}
			bloks++;
		}
		for (auto i : have) {
			bloks -= i / val;
		}
		if (bloks <= 0) {
			chkmax(ans, len);
		}
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