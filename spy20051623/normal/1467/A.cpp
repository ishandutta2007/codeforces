#include <bits/stdc++.h>
using namespace std;

main() {
	int t, n, i, k;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		if (n == 1)
			puts("9");
		else {
			printf("98");
			k = 9;
			for (i = 3; i <= n; ++i) {
				printf("%d", k);
				++k;
				if (k == 10)
					k = 0;
			}
			printf("\n");
		}
	}
}