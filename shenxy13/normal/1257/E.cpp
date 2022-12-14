#include <cstdio>
#include <algorithm>
#define n k1 + k2 + k3
using namespace std;
int main() {
	int k1, k2, k3, nint;
	scanf("%d %d %d", &k1, &k2, &k3);
	int f1[n + 1], f2[n + 1], f3[n + 1];
	fill_n(f1, n + 1, 0);
	for (int i = 0; i < k1; ++i) {
		scanf("%d", &nint);
		f1[nint] = 1;
	}
	fill_n(f2, n + 1, 0);
	for (int i = 0; i < k2; ++i) {
		scanf("%d", &nint);
		f2[nint] = 1;
	}
	fill_n(f3, n + 1, 0);
	for (int i = 0; i < k3; ++i) {
		scanf("%d", &nint);
		f3[nint] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		f1[i] += f1[i - 1];
		f2[i] += f2[i - 1];
		f3[i] += f3[i - 1];
	}
	int a[n + 1], b[n + 1];
	for (int i = 0; i <= n; ++i) {
		a[i] = f1[n] - f1[i] + f2[i];
		if (i != 0) b[i] = f3[i - 1] + f2[n] - f2[i - 1];
		else b[i] = f2[n];
	}
	for (int i = 1; i <= n; ++i) a[i] = min(a[i], a[i - 1]);
	for (int i = n - 1; i >= 0; --i) b[i] = min(b[i], b[i + 1]);
	int ans = 1000000000;
	for (int i = 0; i < n; ++i) ans = min(ans, a[i] + b[i + 1]);
	ans = min(ans, a[n] + k3);
	printf("%d", ans);
	return 0;
}