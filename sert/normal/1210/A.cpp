#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> e;
	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		e.emplace_back(v1 - 1, v2 - 1);
	}

	int mx_msk = 1;
	for (int i = 0; i < n; i++) mx_msk *= 6;

	int ans = 0;
	for (int msk = 0; msk < mx_msk; msk++) {
		vector<int> c(n);
		int x = msk;
		for (int i = 0; i < n; i++) {
			c[i] = x % 6;
			x /= 6;
		}
		set<pair<int, int>> s;
		for (const auto &[v1, v2] : e) {
			s.insert(make_pair(min(c[v1], c[v2]), max(c[v1], c[v2])));
		}
		ans = max(ans, (int)s.size());
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
#ifdef MADE_BY_SERT
	int T = 4;
	for (int i = 1; i < T; i++) solve();	
#endif
}