#include <bits/stdc++.h>

using namespace std;

map<int, vector<int>> m;

void solve() {
	int n, k;
	m.clear();
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &k);
		m[k].push_back(i);
	}
	int l = 0, r = 0, s = 0;
	auto it = m.end();
	--it;
	if (it->second.size() >= 3) {
		l = it->second[1];
		printf("YES\n");
		printf("%d %d %d\n", l - 1, 1, n - l);
		return;
	}
	l = it->second[0];
	r = it->second[it->second.size() - 1];
	s = it->second.size();
	do {
		--it;
		int cnt = 0;
		if (it->second.size() >= 3 && it->second[0] < l && it->second[it->second.size() - 1] > r) {
			bool ok = false;
			for (int i = 1; i < it->second.size() - 1; ++i) {
				int p = it->second[i];
				if (p == l - 1) {
					--l;
					++cnt;
					ok = true;
				}
				if (p == r + 1) {
					++r;
					++cnt;
					ok = true;
				}
				if (p > l && p < r) {
					++cnt;
					ok = true;
				}
			}
			if (ok && cnt + s == r - l + 1) {
				printf("YES\n");
				printf("%d %d %d\n", l - 1, r - l + 1, n - r);
				return;
			}
		}
		l = min(l, it->second[0]);
		r = max(r, it->second[it->second.size() - 1]);
		s += it->second.size();
	} while (it != m.begin());
	printf("NO\n");
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}