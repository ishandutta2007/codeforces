#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

void make(string & s, int pos) {
	for (int i = 0; i <= pos; i++) {
		s[i] = ((s[i] - '0') ^ 1) + '0';
	}
	reverse(s.begin(), s.begin() + pos + 1);
}

void solve() {
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	vector<int> ans;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] == b[i]) continue;
		if (a[i] == a[0]) {
			make(a, i);
			ans.push_back(i);
		} else {
			make(a, 0);
			ans.push_back(0);
			make(a, i);
			ans.push_back(i);
		}
	}
	cout << ans.size() << "\n";
	for (auto i : ans) {
		cout << i + 1 << " ";
	}
	cout << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}