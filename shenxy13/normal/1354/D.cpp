#include <cstdio>
#include <algorithm>
using namespace std;
int ft[1000001];
int main() {
	int n, q, a, l, u;
	scanf("%d %d", &n, &q);
	fill_n(ft, n + 1, 0);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		for (; a <= n; a += a & -a) ++ft[a];
	}
	for (int i = 0; i < q; ++i) {
		scanf("%d", &a);
		if (a > 0) {
			for (; a <= n; a += a & -a) ++ft[a];
		}
		else {
			a = -a;
			l = 0, u = 1 << 19;
			while (u != 0) {
				if (l + u <= n && ft[l + u] < a) a -= ft[l + u], l += u;
				u >>= 1;
			}
			++l;
			for (; l <= n; l += l & -l) --ft[l];
		}
	}
	for (int i = 1; i <= n; ++i) {
		int ans = 0;
		for (int j = i; j > 0; j -= j & -j) ans += ft[j];
		if (ans != 0) {
			printf("%d", i);
			return 0;
		}
	}
	printf("0");
	return 0;
}