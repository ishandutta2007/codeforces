#include <bits/stdc++.h>

using i64 = long long;

int n;

int qry(std::string &s) {
	std::cout << s << std::endl;
	int x;
	std::cin >> x;
	if (x == n) exit(0);
	return x;
}

void solve() {
	std::cin >> n;
	std::string s(n, 'T'), t(n, 'T'), ans(n, 'T');
	for (int i = 1; i < n; i += 3) {
		t[i] = 'F';
	}
	int ss = qry(s), tt = qry(t);
	for (int i = 0; i + 2 < n; i += 3) {
		std::string x = s, y = t;
		x[i] = x[i + 1] = y[i] = y[i + 2] = 'F';
		y[i + 1] = 'T';
		int a = qry(x) - ss, b = qry(y) - tt;
		if (a == -2) {
			if (b == 1) ans[i + 2] = 'F';
		} else if (a == 2) {
			ans[i] = ans[i + 1] = 'F';
			if (b == 1) ans[i + 2] = 'F';
		} else if (b == 3) ans[i] = ans[i + 2] = 'F';
		else if (b == 1) ans[i] = 'F';
		else if (b == -1) ans[i + 1] = ans[i + 2] = 'F';
		else ans[i + 1] = 'F';
	}
	for (int i = n / 3 * 3; i < n; ++i) {
		std::string x = s;
		x[i] = 'F';
		int a = qry(x) - ss;
		if (a == 1) ans[i] = 'F';
	}
	qry(ans);
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
#else
	//	std::ios::sync_with_stdio(false);
	//	std::cin.tie(nullptr);
	//	std::cout.tie(nullptr);
#endif
	int t = 1;
//	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}