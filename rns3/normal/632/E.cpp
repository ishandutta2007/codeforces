#include <bits/stdc++.h>
using namespace std;
#define M 1001001

int n, k;
int a[M];
int f[M];


int main() {
	scanf("%d", &n);
	scanf("%d", &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	sort(a, a + n);
	n = unique(a, a + n) - a;

	int init = k * a[0];
	for (int j = 1; j < n; j++) {
		a[j] -= a[0];
	}

	f[0] = 0;
	printf("%d", init);
	for (int i = 1; i < M; i++) {
		f[i] = k + 1;
		for (int j = 1; j < n && i >= a[j]; j++) {
			f[i] = min(f[i], f[i - a[j]] + 1);
		}
		if (f[i] <= k) {
			printf(" %d", i + init);
		}
	}
	puts("");
	return 0;
}