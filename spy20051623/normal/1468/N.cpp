#include <bits/stdc++.h>
using namespace std;

main() {
	int t;
	long c1, c2, c3, a1, a2, a3, a4, a5;
	scanf("%d", &t);
	while (t--) {
		scanf("%ld%ld%ld", &c1, &c2, &c3);
		scanf("%ld%ld%ld%ld%ld", &a1, &a2, &a3, &a4, &a5);
		c1 -= a1;
		c2 -= a2;
		c3 -= a3;
		if (c1 < 0 || c2 < 0 || c3 < 0)
			puts("NO");
		else {
			if (a4 > c1)
				a4 -= c1;
			else
				a4 = 0;
			if (a5 > c2)
				a5 -= c2;
			else
				a5 = 0;
			if (c3 < a4 + a5)
				puts("NO");
			else
				puts("YES");
		}
	}
}