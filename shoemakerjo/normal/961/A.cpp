#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int ct[n+1];
	fill(ct, ct+n+1, 0);
	int cur;
	while (m--) {
		cin >> cur;
		ct[cur]++;
	}
	int ans = 10000000;
	for (int i = 1; i <= n; i++) {
		ans = min(ans, ct[i]);
	}
	cout << ans << endl;
	cin >> n;
}