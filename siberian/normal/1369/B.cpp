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
	string s;
	cin >> s;
	reverse(all(s));
	while (!s.empty() && s.back() == '0') {
		cout << "0";
		s.pop_back();
	}
	reverse(all(s));
	int cnt = 0;
	while (!s.empty() && s.back() == '1') {
		cnt++;
		s.pop_back();
	}
	if (!s.empty() && s[0] == '1' && s.back() == '0') {
		s = "0";
	} 
	cout << s;
	while (cnt--) {
		cout << "1";
	}
	cout << endl;
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