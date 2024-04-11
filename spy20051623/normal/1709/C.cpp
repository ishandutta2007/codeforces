#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::string s;
	std::cin >> s;
	int n = s.length();
	int c = n / 2;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') --c;
	}
	for (int i = 0; i < n; ++i) {
		if (s[i] == '?') {
			if (c) s[i] = '[', --c;
			else s[i] = ']';
		}
	}
	int p = 0, f = 0, ok = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(' || s[i] == '[') ++p;
		else --p;
		if (s[i] == '[' && p >= 2) f = 1;
		if (s[i] == ']' && f) ok = 1;
		if (p < 2) f = 0;
	}
	if (ok) std::cout << "NO\n";
	else std::cout << "YES\n";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#else
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
#endif
	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}