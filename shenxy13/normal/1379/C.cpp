#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<long long, long long> ii;
int main() {
	int T;
	scanf("%d", &T);
	for (int h = 0; h < T; ++h) {
		int n, m;
		scanf("%d %d", &n, &m);
		long long a[m], b[m], fsuf[m + 1], ans;
		for (int i = 0; i < m; ++i) scanf("%lld %lld", &a[i], &b[i]);
		ii flowers[m];
		for (int i = 0; i < m; ++i) flowers[i] = ii(a[i], b[i]);
		sort(a, a + m);
		fsuf[m] = 0;
		for (int i = m - 1; i >= 0; --i) fsuf[i] = fsuf[i + 1] + a[i];
		ans = fsuf[max(0, m - n)];
		for (int i = 0; i < m; ++i) {
			int nurch = upper_bound(a, a + m, flowers[i].second) - a;
			if (n <= m - nurch) continue;
			if (flowers[i].first > flowers[i].second) ans = max(ans, fsuf[nurch] + flowers[i].second * (n - m + nurch));
			else ans = max(ans, fsuf[nurch] + flowers[i].first + flowers[i].second * (n - m + nurch - 1));
		}
		printf("%lld\n", ans);
	}
	return 0;
}