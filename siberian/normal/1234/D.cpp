#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

const int MAXN = 1e6 + 10;
set<int> a[26];
void solve() {
	string s;
	cin >> s;
	for (int i = 0; i < (int)s.size(); i++) {
		a[s[i] - 'a'].insert(i);
	}
	int q;
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int pos;
			char x;
			cin >> pos >> x;
			pos--;
			a[s[pos] - 'a'].erase(pos);
			s[pos] = x;
			a[s[pos] - 'a'].insert(pos);
		}
		else {
			int ans = 0;
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			for (int i = 0; i < 26; i++) {
				auto it = a[i].lower_bound(l);
				if (it != a[i].end() && *it <= r)
					ans++;
			}
			cout << ans << endl;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}


/*
1
1
abc
bca
*/