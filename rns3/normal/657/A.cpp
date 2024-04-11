#include <bits/stdc++.h>

using namespace std;

main() {
	int n, h, d;
	scanf("%d %d %d", &n, &d, &h);
	if (d > 2 * h) return puts("-1");
	if (n < d + 1) return puts("-1");
	if (h == 1 && d == 1 && n > 2) return puts("-1");
    for (int i = 1; i <= h; i ++) printf("%d %d\n", i, i + 1);
    if (h == d) {
        for (int i = h + 2; i <= n; i ++) printf("%d %d\n", h, i);
    } else {
		printf("1 %d\n", h + 2);
    	for (int i = h + 2; i <= d; i ++) printf("%d %d\n", i, i + 1);
    	for (int i = d + 2; i <= n; i ++) printf("%d %d\n", h, i);
    }
}