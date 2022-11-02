#include <cstdio>
#pragma warning(disable : 4996)
int n, a[100009];
int main() {
	scanf("%d", &n);
	int s = 0;
	for (int i = 0; i <= n; i++) scanf("%d", &a[i]), s += a[i];
	int r = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] >= 2 && a[i + 1] >= 2) r = i + 1;
	}
	if (r == -1) printf("perfect\n");
	else {
		printf("ambiguous\n");
		for (int tp = 0; tp < 2; tp++) {
			printf("0");
			int cur = 1;
			for (int i = 1; i <= n; i++) {
				for (int j = 0; j < a[i]; j++) {
					if (j >= 1 || i != r || tp == 0) printf(" %d", cur);
					else printf(" %d", cur - 1);
				}
				cur += a[i];
			}
			printf("\n");
		}
	}
	return 0;
}