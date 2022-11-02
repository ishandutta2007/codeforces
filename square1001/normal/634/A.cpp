#include <cstdio>
typedef unsigned long long ull;
const ull bs = 11111111111;
int n, x, a[200009], b[200009];
int main() {
	scanf("%d", &n);
	for (int i = 0, j = 0; i < n; i++) {
		scanf("%d", &x);
		if (x != 0) a[j++] = x;
	}
	for (int i = 0, j = 0; i < n; i++) {
		scanf("%d", &x);
		if (x != 0) b[j++] = x;
	}
	ull h = 0, h2 = 0, pw = 1;
	for (int i = 0; i < n - 1; i++) {
		h = h * bs + a[i];
		h2 = h2 * bs + b[i];
		pw *= bs;
	}
	bool f = false;
	for (int i = 0; i < n - 1; i++) {
		if (h == h2) f = true;
		h2 = h2 * bs - b[i] * pw + b[i];
	}
	printf(f ? "YES\n" : "NO\n");
	return 0;
}