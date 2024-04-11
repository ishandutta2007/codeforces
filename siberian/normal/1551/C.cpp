#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define all(a) (a).begin(), (a).end()

template<typename T1, typename T2>
inline void chkmin(T1& x, const T2& y) {
	if (y < x) {
		x = y;
	}
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
	if (x < y) {
		x = y;
	}
}

int calc(string& a, char c) {
	int ans = 0;
	for (auto i : a) {
		if (i == c) {
			++ans;
		} else {
			--ans;
		}
	}
	return ans;
}

int calc(vector<string>& a, char c) {
	vector<int> have;
	for (auto i : a) {
		have.push_back(calc(i, c));
	}
	sort(all(have));
	reverse(all(have));
	int ans = 0;
	int cnt = 0;
	for (auto i : have) {
		if (ans + i > 0) {
			ans += i;
			++cnt;
		} else {
			break;
		}
	}
	return cnt;
}

void solve() {
	int n;
	cin >> n;
	vector<string> a(n);
	for (auto& i : a) {
		cin >> i;
	}
	int ans = 0;
	for (char c = 'a'; c <= 'e'; ++c) {
		chkmax(ans, calc(a, c));
	}
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20), cout.setf(ios::fixed);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}