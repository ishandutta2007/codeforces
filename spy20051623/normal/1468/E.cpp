#include <bits/stdc++.h>
using namespace std;

main() {
	int t, a[4], i;
	scanf("%d", &t);
	while (t--) {
		for (i = 0; i < 4; i++)
			scanf("%d", &a[i]);
		sort(a, a + 4);
		printf("%ld\n", 1L * a[0]*a[2]);
	}
}