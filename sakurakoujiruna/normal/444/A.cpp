#include <bits/stdc++.h>
using namespace std;

const int N = 511;
int x[N];

int main() {
	ios :: sync_with_stdio(false);
	int n, m; cin >> n >> m;
	double ans = 0;
	for(int i = 1; i <= n; i ++)
		cin >> x[i];
	for(int i = 0; i < m; i ++) {
		int u, v; double w;
		cin >> u >> v >> w;
		ans = max(ans, (x[u] + x[v]) / w);
	}
	cout << fixed << setprecision(12) << ans << '\n';
	return 0;
}