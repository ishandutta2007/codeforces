#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	std::string ans;
	for (int i = n - 1; i >= 0;) {
		if (s[i] == '0') {
			ans += 'a' + (s[i - 2] - '0') * 10 + s[i - 1] - '0' - 1;
			i -= 3;
		} else {
			ans += 'a' + s[i] - '0' - 1;
			--i;
		}
	}
	std::reverse(ans.begin(), ans.end());
	std::cout << ans << '\n';
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