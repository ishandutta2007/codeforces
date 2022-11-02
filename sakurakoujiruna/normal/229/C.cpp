#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 11;
using ll = long long;

int deg[N];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i ++) {
		int u, v;
		scanf("%d%d", &u, &v);
		deg[u] ++;
		deg[v] ++;
	}
	ll ans = ll(n) * (n - 1) * (n - 2) / 3;
	for(int i = 1; i <= n; i ++)
		ans -= ll(deg[i]) * (n - deg[i] - 1);
	cout << ans / 2 << '\n';
	return 0;
}