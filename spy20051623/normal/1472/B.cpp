#include <bits/stdc++.h>
using namespace std;

main() {
	int i, t, n, a[3], x;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		a[1] = a[2] = 0;
		for (i = 0; i < n; ++i) {
			scanf("%d", &x);
			++a[x];
		}
		a[2] %= 2;
		if (a[1] < a[2] * 2 || a[1] % 2)
			puts("NO");
		else
			puts("YES");
	}
}