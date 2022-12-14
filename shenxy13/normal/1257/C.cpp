#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int T, n;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {	
		scanf("%d", &n);
		int A[n], nxt[n], occ[n], hi[n];
		fill_n(nxt, n, n);
		fill_n(occ, n, -1);
		for (int j = 0; j < n; ++j) scanf("%d", &A[j]);
		for (int j = 0; j < n; ++j) {
			if (occ[A[j] - 1] != -1) nxt[occ[A[j] - 1]] = j;
			occ[A[j] - 1] = j;
		}
		hi[n - 1] = nxt[n - 1];
		for (int j = n - 2; j >= 0; --j) hi[j] = min(hi[j + 1], nxt[j]);
		int ans = 1000000000;
		for (int j = 0; j < n; ++j) {
			if (hi[j] != n) ans = min(ans, hi[j] - j + 1);
		}
		if (ans != 1000000000) printf("%d\n", ans);
		else printf("-1\n");
	}
	return 0;
}