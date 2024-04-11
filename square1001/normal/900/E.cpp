#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
int main() {
	int n, m; string s;
	cin >> n >> s >> m;
	vector<pair<int, int> > dp(n + 1);
	for (int i = 1; i <= n; ++i) {
		dp[i] = dp[i - 1];
		if (i >= m) {
			bool f = true; int ques = 0;
			for (int j = 0; j < m; ++j) {
				if (s[i - m + j] == (j % 2 == 0 ? 'b' : 'a')) {
					f = false;
					break;
				}
				if (s[i - m + j] == '?') ++ques;
			}
			if (f) {
				dp[i] = max(dp[i], make_pair(dp[i - m].first + 1, dp[i - m].second - ques));
			}
		}
	}
	cout << -dp[n].second << '\n';
	return 0;
}