#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int l[m], ans[m];
	for (int i = 0; i < m; ++i) scanf("%d", &l[i]);
	for (int i = 0; i < m; ++i) ans[i] = i;
	for (int i = 0; i < m; ++i) {
		if (ans[i] + l[i] > n) {
			printf("-1");
			return 0;
		}
	}
	ans[m - 1] = n - l[m - 1];
	for (int i = m - 2; i >= 0; --i) ans[i] = max(ans[i], ans[i + 1] - l[i]);
	if (ans[0] == 0) {
		for (int i = 0; i < m; ++i) printf("%d ", ans[i] + 1);
	} else printf("-1");
	return 0;
}