#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int n, a[109], sum[109][109], dp[109]; bool ok[109];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int s = 0;
			for (int k = i; k < j; k++) s += a[k];
			sum[i][j] = s;
		}
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = -1;
		for (int j = 0; j < i; j++) {
			if (dp[j] != -1 && sum[j][i]) dp[i] = j;
		}
	}
	dp[0] = -1;
	if (dp[n] == -1) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		int pos = n;
		vector<int> ret;
		while (pos != -1) ret.push_back(pos), pos = dp[pos];
		reverse(ret.begin(), ret.end());
		cout << ret.size() - 1 << endl;
		for (int i = 1; i < ret.size(); i++) {
			cout << ret[i - 1] + 1 << ' ' << ret[i] << endl;
		}
	}
	return 0;
}