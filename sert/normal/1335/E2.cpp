#include <bits/stdc++.h>
using namespace std;

const int N = 202;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	vector<int> pos[N];
	for (int i = 0; i < n; i++) pos[a[i]].push_back(i);

	vector<vector<int>> sum(n + 1, vector<int>(N, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < N; j++) sum[i + 1][j] = sum[i][j];
		sum[i + 1][a[i]]++;
	}

	int ans = 0;
	for (int j = 0; j < N; j++) ans = max(ans, sum[n][j]);

	for (int i = 0; i < n; i++) {
		const auto &v = pos[a[i]];
		int num = lower_bound(v.begin(), v.end(), i) - v.begin() + 1;
		int fn = v[(int)v.size() - num];
		if (fn <= i) continue;

		int mx = 0;
		for (int j = 0; j < N; j++) {
			mx = max(sum[fn][j] - sum[i + 1][j], mx);
		}
		ans = max(ans, mx + num * 2);
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}