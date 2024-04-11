#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
	scanf("%d%d", &n, &k);
	int q = (n - 1) / k, r = (n - 1) % k;
	if (r == 0) {
		printf("%d\n", 2 * q);
	}
	else if (r == 1) {
		printf("%d\n", 2 * q + 1);
	}
	else {
		printf("%d\n", 2 * q + 2);
	}
	int tot = 0;
	for (int i = 1; i <= k - r; i ++) {
		printf("%d %d\n", n, ++tot);
		for (int j = 1; j < q; j ++) printf("%d %d\n", tot, tot + 1), tot ++;
	}
	for (int i = 1; i <= r; i ++) {
		printf("%d %d\n", n, ++tot);
		for (int j = 1; j <= q; j ++) printf("%d %d\n", tot, tot + 1), tot ++;
	}
}