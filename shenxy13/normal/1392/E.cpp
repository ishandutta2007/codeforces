#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	long long a[n][n];
	for (int i = 0; i < n; ++i) fill_n(a[i], n, 0);
	for (int i = 1; i < 2 * n - 2; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i - j < 0 || i - j >= n) continue;
			if (j % 2 == 0) a[i - j][j] = 1LL << (i - 1);
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%lld", a[i][0]);
		for (int j = 1; j < n; ++j) printf(" %lld", a[i][j]);
		printf("\n");
	}
	fflush(stdout);
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		long long k;
		scanf("%lld", &k);
		printf("1 1\n");
		int x = 0, y = 0;
		while (x != n - 1 || y != n - 1) {
			if (x != n - 1 && y != n - 1) {
				if (a[x][y + 1] == 0) {
					if (k & a[x + 1][y]) ++x;
					else ++y;
				} else {
					if (k & a[x][y + 1]) ++y;
					else ++x;
				}
			} else if (x == n - 1) ++y;
			else ++x;
			printf("%d %d\n", x + 1, y + 1);
		}
		fflush(stdout);
	}
	return 0;
}