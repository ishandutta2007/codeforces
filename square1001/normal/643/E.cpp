#include <vector>
#include <iostream>
using namespace std;
const int lim = 70;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int Q;
	cin >> Q;
	cout.precision(15);
	vector<vector<double> > dp(1, vector<double>(lim, 1.0));
	vector<int> par(1, -1);
	for (int i = 0; i < Q; ++i) {
		int tp, x;
		cin >> tp >> x; --x;
		if (tp == 1) {
			int cur = par.size();
			par.push_back(x);
			dp.push_back(vector<double>(lim, 1.0));
			double mul = 0.5;
			for (int j = 0; j < lim; ++j) {
				cur = par[cur];
				if (cur == -1) break;
				double ndp = dp[cur][j] * mul;
				mul = (ndp + 1) / (dp[cur][j] + 1);
				dp[cur][j] = ndp;
			}
		}
		else {
			double ans = 0.0;
			for (int j = 1; j < lim; ++j) {
				ans += (dp[x][j] - dp[x][j - 1])* j;
			}
			cout << ans << '\n';
		}
	}
	return 0;
}