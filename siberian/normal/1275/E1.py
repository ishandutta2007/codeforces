#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

bool check(string s) {
	int sum = 0;
	for (auto i : s) {
		sum += i - '0';
	}
	return sum % 3 == 0;
}

bool check2(string s) {
	int cnt = 0;
	for (auto i : s) {
		cnt += i == '0';
	}
	int cnt2 = 0;
	for (auto i : s)
		cnt2 += (i - '0') % 2 == 0;
	return cnt > 0 && cnt2 > 1;
}

void solve() {
	string s;
	cin >> s;
	if (check(s) && check2(s)) {
		cout << "red" << "\n";
	}
	else {
		cout << "cyan" << "\n";
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