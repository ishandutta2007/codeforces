#include <bits/stdc++.h>
using namespace std;
int a[200005];

int cmp(int a, int b) {
	return a > b;
}

main() {
	int t, n, i;
	long long sa, sb;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		sa = sb = 0;
		memset(a, 0, sizeof(a));
		for (i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		sort(a, a + n, cmp);
		for (i = 0; i < n; ++i)
			if (i % 2 == 0) {
				if (a[i] % 2 == 0)
					sa += a[i];
			} else {
				if (a[i] % 2)
					sb += a[i];
			}
		if (sa > sb)
			puts("Alice");
		else if (sa == sb)
			puts("Tie");
		else
			puts("Bob");
	}
}