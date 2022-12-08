#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

long long quickpow(long long a, long long b) {
	long long res = 1;
	a %= mod;
	while (b) {
		if (b & 1)
			res = res * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	s = ' ' + s;
	vector<string> t(1 << n);
	vector<int> a(1 << n);
	function<void(int)> dfs = [&](int p) {
		if (p >= 1 << (n - 1)) {
			t[p] = s[p];
			a[p] = 0;
			return;
		}
		int ls = p + p, rs = p + p + 1;
		dfs(ls);
		dfs(rs);
		a[p] = a[ls] + a[rs];
		if (t[ls] != t[rs]) ++a[p];
		if (t[ls] < t[rs]) t[p] = s[p] + t[ls] + t[rs];
		else t[p] = s[p] + t[rs] + t[ls];
	};
	dfs(1);
	cout << quickpow(2, a[1]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}