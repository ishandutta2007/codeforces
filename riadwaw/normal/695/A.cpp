#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <cmath>
#include <ctime>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using vi = vector<int>;
void solve();


int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	auto start = clock();
#endif
	cout.sync_with_stdio(0);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	int t;
	//cin >> t;
	t = 1;
	while (t--) {
		solve();
	}
#ifdef LOCAL
	cerr << endl << endl << (clock() - start) / double(CLOCKS_PER_SEC) << endl;
#endif
	return 0;
}

//#define int li

auto& in = std::cin;
auto& out = std::cout;

void solve() {
	int n, k;
	in >> n >> k;
	vector<double> allp(n);

	for (int i = 0; i < n; ++i) {
		in >> allp[i];
	}

	for (int i = 0; i < n; ++i) {
		if (fabs(allp[i]) < 1e-6) {
			out << "0 ";
			continue;
		}
		vector<double> dp(1 << (n - 1));
		vector<double> p(n - 1);
		int c = 0;
		for (int j = 0; j < n; ++j) {
			if (i != j) {
				p[c++] = allp[j];
			}
		}
		dp[0] = allp[i];
		double ans = dp[0];
		for (int mask = 1; mask < (1 << (n - 1)); ++mask) {
			double sumP = 0;
			double sum = 0;
			int cnt = 0;
			for (int t = 0; t < (n - 1); ++t) {
				if (mask & (1 << t)) {
					sumP += p[t];
					sum += p[t] * dp[mask ^ (1 << t)];
					++cnt;
				}
			}
			dp[mask] = sum / (1 - sumP);
			if (cnt < k) {
				ans += dp[mask];
			}
		}
		out << ans << " ";

	}
}