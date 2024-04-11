#include <bits/stdc++.h>

using i64 = long long;
std::vector<std::vector<int>> dp;
std::string s;

int dfs(int, int);

int dec(int, int, char);

int dfs(int l, int r) {
	if (dp[l][r] != -2) return dp[l][r];
	if (l == r - 1) return dp[l][r] = s[l] != s[r] ? 1 : 0;
	return dp[l][r] = std::max(dec(l, r - 1, s[r]), dec(l + 1, r, s[l]));
}

int dec(int l, int r, char c) {
	int L = 1, R = 1;
	if (dfs(l + 1, r) == -1 || dfs(l + 1, r) == 0 && s[l] < c) L = -1;
	else if (dfs(l + 1, r) == 0 && s[l] == c) L = 0;
	if (dfs(l, r - 1) == -1 || dfs(l, r - 1) == 0 && s[r] < c) R = -1;
	else if (dfs(l, r - 1) == 0 && s[r] == c) R = 0;
	return std::min(L, R);
}

void solve() {
	std::cin >> s;
	int n = s.length();
	dp = std::vector<std::vector<int>>(n, std::vector<int>(n, -2));
	int ans = dfs(0, n - 1);
	if (ans == -1) std::cout << "Bob\n";
	else if (ans == 0) std::cout << "Draw\n";
	else std::cout << "Alice\n";
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