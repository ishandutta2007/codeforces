#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, d; cin >> n >> d;
	string thing; cin >> thing;
	vector<int> dp(n, 1000000000);
	dp[0] = 0;
	for (int i = 1; i < n; ++i) {
		for (int src = max(0, i - d); src < i; ++src) {
			if (thing[src] == '1' && thing[i] == '1' && dp[src] >= 0) {
				dp[i] = min(dp[i], dp[src] + 1);
			}
		}
		//cout << i << " = " << dp[i] << endl;
	}
	cout << (dp[n-1] == 1000000000 ? -1 : dp[n-1]);
	return 0;
}