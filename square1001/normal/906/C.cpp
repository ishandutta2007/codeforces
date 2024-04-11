#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
int n, m, x[25], dp[4194333], p[4194333]; bool clique[4194333];
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) x[i] = (1 << i);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b; a--, b--;
		x[a] |= 1 << b;
		x[b] |= 1 << a;
	}
	for (int i = 1; i < 1 << n; i++) {
		clique[i] = true;
		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				if ((x[j] & i) != i) clique[i] = false;
			}
		}
	}
	for (int i = (1 << n) - 2; i >= 1; i--) {
		dp[i] = inf;
		for (int j = 0; j < n; j++) {
			if (((i >> j) & 1) && dp[i] > dp[i | x[j]] + 1) {
				p[i] = j;
				dp[i] = dp[i | x[j]] + 1;
			}
		}
	}
	int pos = -1;
	for (int i = 1; i < 1 << n; i++) {
		if (clique[i] && (pos == -1 || dp[pos] > dp[i])) {
			pos = i;
		}
	}
	cout << dp[pos] << endl;
	while (pos < (1 << n) - 1) {
		cout << p[pos] + 1 << ' ';
		pos = pos | x[p[pos]];
	}
	return 0;
}