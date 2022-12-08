#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define pii pair<int, int>

int n, k;
int h[105];

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			if (j == n) {
				cout << -1 << endl;
				return;
			}
			if (h[j] >= h[j+1]) continue;
			h[j]++;

			if (i == k) cout << j << endl;
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) solve();
}