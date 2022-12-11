#include <bits/stdc++.h>
using namespace std;

int a[110];

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		if (n & 1) {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					if (j - i <= n / 2) a[i] += 3, printf("1 ");
					else a[j] += 3, printf("-1 ");
				}
			}
			printf("\n");
			continue;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (i + n / 2 == j) printf("0 ");
				else if (i + n / 2 > j) printf("1 ");
				else printf("-1 ");
			}
		}
		printf("\n");
	}
	return 0;
}