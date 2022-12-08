#include <bits/stdc++.h>
using namespace std;

struct pt {
	int a[2];
} p[200005];

int cmp(pt x, pt y) {
	return x.a[0] < y.a[0];
}

main() {
	int t, n, m, r, c, i, j, k, flag;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		memset(p, 0, sizeof(p));
		for (k = 0; k < m; ++k) {
			scanf("%d%d", &i, &j);
			p[k].a[0] = j - 1;
			p[k].a[1] = i - 1;
		}
		sort(p, p + m, cmp);
		flag = 0;
		k = 0;
		if (m % 2)
			puts("NO");
		else
			for (k = 0; k < m; ++k) {
				if (flag == 0) {
					i = p[k].a[0];
					j = p[k].a[1];
					flag = 1;
				} else {
					if ((p[k].a[0] + p[k].a[1] - i - j) % 2) {
						if (k < m - 1 && p[k + 1].a[0] == p[k].a[0]) {
							puts("NO");
							break;
						} else
							flag = 0;
					} else {
						puts("NO");
						break;
					}
				}
			}
		if (k == m)
			puts("YES");
	}
}