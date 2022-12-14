#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n;
		scanf("%d", &n);
		int x[n], cnt[2 * n + 1], ans = 0;
		for (int i = 0; i < n; ++i) scanf("%d", &x[i]), --x[i];
		fill_n(cnt, 2 * n + 1, 0);
		for (int i = 0; i < n; ++i) {
			if (cnt[x[i]]) ++cnt[x[i] + 1];
			else ++cnt[x[i]];
		}
		for (int i = 0; i <= 2 * n; ++i) ans += (cnt[i] != 0);
		printf("%d\n", ans);
	}
	return 0;
}