#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int deg[N+1];
	fill(deg, deg+N+1, 0);
	int u, v;
	int ans = 0;
	for (int i = 0; i < N-1; i++) {
		cin >> u >> v;
		deg[u]++;
		deg[v]++;
	}
	for (int i = 1; i <= N; i++) {
		if (deg[i] == 1) ans ++;
	}
	cout << ans << endl;
	cin >> ans;
}