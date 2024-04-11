#include<bits/stdc++.h>
using std::cin;
using std::cout;
int t;
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> t;
	for(int i = 0;i < t;++i) {
		int n; cin >> n;
		std::vector<int> a(n + 1);
		std::vector<int> dp(n + 1);
		std::map<int, int> last;
		last[0] = 0;
		for(int i = 1;i <= n;++i) {
			cin >> a[i];
			a[i] ^= a[i - 1];
			dp[i] = std::min(dp[i - 1] + 1, last.count(a[i]) ? last[a[i]] + i - 1 : (int) 1e9);
			if(!last.count(a[i])) {
				last[a[i]] = dp[i] - i;
			} else {
				last[a[i]] = std::min(last[a[i]], dp[i] - i);
			}
		}
		cout << dp[n] << '\n';
	}
}