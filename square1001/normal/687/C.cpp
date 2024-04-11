#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a[509]; bool dp[509][509];
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	dp[0][0] = true;
	for (int i = 0; i < n; i++) {
		for (int j = m; j >= a[i]; j--) {
			for (int k = 0; k <= j; k++) {
				dp[j][k] = dp[j][k] || dp[j - a[i]][k];
				if (k >= a[i]) dp[j][k] = dp[j][k] || dp[j - a[i]][k - a[i]];
			}
		}
	}
	vector<int> ret;
	for (int i = 0; i <= m; i++) {
		if (dp[m][i]) ret.push_back(i);
	}
	cout << ret.size() << endl;
	for (int i = 0; i < ret.size(); i++) {
		if (i) cout << ' ';
		cout << ret[i];
	}
	cout << endl;
	return 0;
}