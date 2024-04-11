#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

int lg(int x) {
	int ans = 0;
	while (x > 1) {
		x /= 2;
		ans++;
	}
	return ans;
}

void solve() {
	int sum, n;
	cin >> sum >> n;
	vector<int> cnt(62);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[lg(x)]++;
	}
	int ans = 0;
	for (int i = 0; i < 60; i++) {
		if ((sum >> i) & 1) {
			if (!cnt[i]) {
				int pos = -1;
				for (int j = i + 1; j < 60; j++) {
					if (cnt[j]) {
						pos = j;
						break;
					}
				}
				if (pos == -1) {
					cout << "-1\n";
					return;
				}
				//cout << "pos = " << pos << endl;
				while (pos > i) {
					cnt[pos - 1] += 2;
					cnt[pos]--;
					pos--;
					ans++;
				}
				//cout << "i = " << i << endl;
			}
			assert(cnt[i]);
			cnt[i]--;
		}
		cnt[i + 1] += cnt[i] / 2;
	}
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