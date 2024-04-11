#include <stdio.h>
int inp[1000010], ans[1000010];
int main() {
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &inp[i]);
	for (int i=1; i<n; i++) {
		for (int j=1; j<n;) {
			int p = (i-1)/j;

			int nj = p ? (i+p-1) / p : n;
			if (inp[i] < inp[p]) {
				ans[j]++;
				ans[nj]--;
			}
			j=nj;
		}
	}
	printf("%d", ans[1]);
	for (int i=2; i<n; i++) {
		ans[i] += ans[i-1];
		printf(" %d", ans[i]);
	}
	puts("");
	return 0;
}