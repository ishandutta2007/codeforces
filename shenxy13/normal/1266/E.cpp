#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int main() {
	int n, q, s, t, u;
	scanf("%d", &n);
	long long a[n], ans = 0;
	for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
	for (int i = 0; i < n; ++i) ans += a[i];
	map<int, int> ok[n];
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		scanf("%d %d %d", &s, &t, &u);
		if (ok[s - 1][t] != 0) {
			++a[ok[s - 1][t] - 1];
			if (a[ok[s - 1][t] - 1] > 0) ++ans;
		}
		ok[s - 1][t] = u;
		if (u != 0) {
			if (a[u - 1] > 0) --ans;
			--a[u - 1];
		}
		printf("%lld\n", ans);
	}
	return 0;
}