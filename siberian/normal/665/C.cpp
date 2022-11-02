#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

void solve() {
	string s;
	cin >> s;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == s[i - 1]) {
			for (int j = 0; j < 26; j++) {
				if (s[i - 1] != 'a' + j && (i == s.size() - 1 || s[i + 1] != 'a' + j)) {
					s[i] = 'a' + j;
					break;
				}
			}
		}
	}
	cout << s;
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