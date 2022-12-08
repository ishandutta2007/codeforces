#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::string s, t;
	std::cin >> s >> t;
	std::reverse(s.begin(), s.end());
	std::reverse(t.begin(), t.end());
	if (s == t) std::cout << "=\n";
	else if (s[0] < t[0]) std::cout << ">\n";
	else if (s[0] > t[0]) std::cout << "<\n";
	else if ((s[0] != 'S') ^ (s.length() > t.length())) std::cout << "<\n";
	else std::cout << ">\n";
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