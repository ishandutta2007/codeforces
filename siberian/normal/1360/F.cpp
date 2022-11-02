#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

bool check(string & a, string & b) {
	int cnt = 0;
	for (int i = 0; i < (int)a.size(); i++) {
		cnt += a[i] != b[i];
	}
	return cnt <= 1;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for (auto &i : a) {
		cin >> i;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int na = 0; na < 26; na++) {
				string have = a[i];
				have[j] = na + 'a';
				bool ok = true;
				for (int ind = 0; ind < n; ind++) {
					ok &= check(have, a[ind]);
				}
				if (ok) {
					cout << have << "\n";
					return;
				}
			}
		}
	}
	cout << "-1\n";
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