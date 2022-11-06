#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> x(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	vector<string> s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	
	long long bestval = 0;
	vector<int> bestp(m);
	iota(bestp.begin(), bestp.end(), 1);
	for (int mask = 0; mask < (1 << n); ++mask) {
		vector<int> coef(m, 0);
		
		long long val = 0;
		for (int i = 0; i < n; ++i) {
			int t = ((mask >> i) & 1) ? 1 : -1;
			val -= t * x[i];
			for (int j = 0; j < m; ++j) {
				if (s[i][j] == '1') {
					coef[j] += t;
				}
			}
		}

		vector<pair<int, int>> sortcoef;
		for (int i = 0; i < m; ++i) {
			sortcoef.emplace_back(coef[i], i);
		}
		sort(sortcoef.begin(), sortcoef.end());
		
		vector<int> p(m);
		for (int i = 0; i < m; ++i) {
			val += 1ll * sortcoef[i].first * (i + 1);
			p[sortcoef[i].second] = i + 1;
		}
		
		if (val > bestval) {
			bestval = val;
			bestp = p;
		}
	}

	for (int i = 0; i < m; ++i) {
		cout << bestp[i] << " ";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}