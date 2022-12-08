#include <bits/stdc++.h>

using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	long long c = 0, d = 0, ans = 0;
	map<long long, int> m;
	m[0];
	for (int i = 0; i < n; ++i) {
		int p;
		scanf("%d", &p);
		if (i & 1) {
			ans += min(c, 1ll * p);
			ans += m[d] * (m[d] - 1) / 2;
			m.erase(d);
			c -= p, d -= p;
			if (c < 0) c = 0;
			else ++m[d];
			while (!m.empty() && (--m.end())->first > d) {
				int k = (--m.end())->second;
				ans += k * (k + 1) / 2;
				m.erase(--m.end());
			}
		} else {
			c += p, d += p;
			++m[d];
		}
	}
	for (auto i : m) ans += i.second * (i.second - 1) / 2;
	printf("%lld\n", ans);
	return 0;
}