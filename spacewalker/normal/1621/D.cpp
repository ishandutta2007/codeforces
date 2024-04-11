#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		vector<vector<int>> grid(2*n, vector<int>(2*n, 0));
		for (int i = 0; i < 2*n; ++i) {
			for (int j = 0; j < 2 * n; ++j) {
				scanf("%d", &grid[i][j]);
			}
		}
		ll ans = 0;
		for (int i = n; i < 2 * n; ++i) {
			for (int j = n; j < 2 * n; ++j) {
				ans += grid[i][j];	
			}
		}
		vector<ll> ifthisworksfuckmylife{
			grid[n][0], grid[n][n-1], grid[2*n-1][0], grid[2*n-1][n-1],
			grid[0][n], grid[n-1][n], grid[0][2*n-1], grid[n-1][2*n-1]
		};
		printf("%lld\n", ans + *min_element(begin(ifthisworksfuckmylife), end(ifthisworksfuckmylife)));
	}
}