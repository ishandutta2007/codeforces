#include <cstdio>

#define forn(i, n) for (int i = 0; i < n; i++)

int n, k, a[100010];

int main() {
	scanf("%d %d", &n, &k);
	forn(i, n) a[i] = 1;
	a[n-1] = 0;
	forn(j, k) {
		int lim = 1 << j;
		forn(i, n) {
			if (i) printf(" ");
			int q = n - 1 - i - a[i];
			if (q > lim) q = lim;
			a[i] += a[n - 1 - q];
			printf("%d", n - q);
		}
		printf("\n");
	}
	return 0;
}