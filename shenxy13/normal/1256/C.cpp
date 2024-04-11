#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n, m, d;
	scanf("%d %d %d", &n, &m, &d);
	int len[m], rem[m];
	for (int i = 0; i < m; ++i) scanf("%d", &len[i]);
	rem[m - 1] = len[m - 1];
	for (int i = m - 2; i >= 0; --i) rem[i] = rem[i + 1] + len[i];
	int ans[n], pos = -1;
	fill_n(ans, n, 0);
	for (int i = 0; i < m; ++i) {
		pos += d;
		if (rem[i] >= n - pos) {
			pos = n - 1;
			for (int j = m - 1; j >= i; --j) {
				int temp = pos;
				for (; pos > temp - len[j]; --pos) ans[pos] = j + 1;
			}
			pos = n;
			break;
		} else {
			int temp = pos;
			for (; pos < temp + len[i]; ++pos) ans[pos] = i + 1;
			--pos;
		}
	}
	pos += d;
	if (pos < n) printf("NO");
	else {
		printf("YES\n");
		for (int i = 0; i < n; ++i) printf("%d ", ans[i]);
	}
	return 0;
}