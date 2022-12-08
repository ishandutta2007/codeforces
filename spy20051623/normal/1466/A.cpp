#include <bits/stdc++.h>
using namespace std;

main() {
	int t, n, x[55], l[55], i, j, cnt;
	scanf("%d", &t);
	while (t--) {
		memset(l, 0, sizeof(l));
		cnt = 0;
		scanf("%d", &n);
		for (i = 0; i < n; ++i)
			scanf("%d", &x[i]);
		for (i = 0; i < n; ++i)
			for (j = i + 1; j < n; ++j)
				if (l[x[j] - x[i]] == 0) {
					++cnt;
					l[x[j] - x[i]] = 1;
				}
		printf("%d\n", cnt);
	}
}