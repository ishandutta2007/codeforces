#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	int par[n+1];
	for (int i = 1; i <= n; i++) {
		cin >> par[i];
	}
	int dp[n+1];
	for (int i = 1; i <= n; i++) {
		if (par[i] == 0) {
			int maxspot = min(i+k, n);
			int minspot = max(1, i-k);
			dp[i] = maxspot-minspot+1;
		}
		else {
			int u = par[i];
			int maxspot = min(i+k, n);
			int minspot = max(1, i-k);
			dp[i] = dp[u];
			if (u + k >= maxspot) continue;
			minspot = max(minspot, u+k+1);
			dp[i] += maxspot-minspot+1;
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << dp[i] << " ";
	}
	cout << endl;
	cin >>  n;
}