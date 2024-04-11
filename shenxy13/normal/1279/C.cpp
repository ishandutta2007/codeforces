#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n, m, x;
		long long ans = 0;
		scanf("%d %d", &n, &m);
		int pos[n], b[m];
		for (int i = 0; i < n; ++i) {
			scanf("%d", &x);
			pos[x - 1] = i;
		}
		for (int i = 0; i < m; ++i) scanf("%d", &b[i]);
		set<int> ds;
		for (int i = 0; i < m; ++i) {
			if (ds.empty() || *--ds.end() < pos[b[i] - 1]) ans += 2 * (pos[b[i] - 1] - ds.size()) + 1;
			else ++ans;
			ds.insert(pos[b[i] - 1]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}