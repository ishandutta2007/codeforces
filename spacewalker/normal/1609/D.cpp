#include <bits/stdc++.h>

using namespace std;

int getMax(vector<pair<int, int>> &sz_surs) {
	int k = sz_surs.size();
	sort(begin(sz_surs), end(sz_surs));
	int extra = 1;
	for (auto [s, sur] : sz_surs) extra += sur;
	int ans = 0;
	for (int i = k - 1; i >= 0 && k - i <= extra; --i) ans += sz_surs[i].first;
	return ans - 1;
}

int main() {
	int n, d; scanf("%d %d", &n, &d);
	vector<int> ccid(n); iota(begin(ccid), end(ccid), 0);
	vector<int> sz(n, 1), surplus(n, 0);
	auto merge = [&] (int i, int j) {
		i = ccid[i]; j = ccid[j];
		if (i == j) ++surplus[i];
		else {
			sz[i] += sz[j];
			surplus[i] += surplus[j];
			sz[j] = surplus[j] = 0;
			for (int x = 0; x < n; ++x) if (ccid[x] == j) ccid[x] = i;
		}
	};
	for (int condition = 0; condition < d; ++condition) {
		int x, y; scanf("%d %d", &x, &y); --x; --y;
		merge(x, y);
		vector<pair<int, int>> comps;
		for (int i = 0; i < n; ++i) {
			if (ccid[i] == i) comps.emplace_back(sz[i], surplus[i]);
		}
		printf("%d\n", getMax(comps));
	}
}