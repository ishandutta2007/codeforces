#include <bits/stdc++.h>

using namespace std;

int n, m;
map<vector<pair<int, int>>, int> mem;

int main() {
	scanf("%d%d", &n, &m);
	long long ans = 0;
	for (int i = 1, x; i <= n; ++i) {
		scanf("%d", &x);
		vector<pair<int, int>> tmp;
		for (int i = 2; i * i <= x; ++i)
			if (x % i == 0) {
				int k = 0;
				while (x % i == 0) ++k, x /= i;
				if (k % m)
					tmp.emplace_back(i, k % m);
			}
		if (x > 1)
			tmp.emplace_back(x, 1);
		vector<pair<int, int>> tt;
		for (const auto &p : tmp)
			tt.emplace_back(p.first, m - p.second);
		auto it = mem.find(tt);
		if (it != mem.end()) ans += it->second;
		++mem[tmp];
	}
	printf("%lld\n", ans);
	return 0;
}