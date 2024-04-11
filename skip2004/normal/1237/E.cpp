#include<bits/stdc++.h>
const int maxn = 1000100;
int dp[maxn][20][2];
using std::cin;
using std::cout;
inline int lg(int x) {
	return x < 1 ? -1 : std::__lg(x + 1);
}
inline int dfs(int len, int d, int o) {
	if(len == 0 && d <= 1) return 1;
	int & ans = dp[len][d][o];
	if(~ans) return ans;
	ans = 0;
	int mid = len + 1 >> 1;
	for(int l = std::max(mid - 10, 0);l < mid + 10 && l < len;++l) if(l + o & 1) {
		const int left = l, right = len - l - 1;
		if(lg(left) < d && lg(right) < d) {
			ans = ans || dfs(left, d - 1, o ^ 1) && dfs(right, d - 1, 0);
		}
	}
	return ans;
}
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	memset(dp, -1, sizeof dp);
	int n;
	std::cin >> n;
	std::cout << (dfs(n, std::__lg(n) + 1, 0) || dfs(n, std::__lg(n) + 1, 1)) << '\n';
}