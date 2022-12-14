#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
	scanf("%d %d", &n, &k);
	if (k == 1 || n <= 3) puts("-1");
	else if (k == 2 && n == 4) puts("-1");
	else if (k == 2 || (k == 3 && n == 4)) {
		printf("%d\n", n - 1);
		for (int i = 1; i <= n - 1; i ++) {
			printf("%d %d\n", i, i + 1);
		}
	}
	else if (k == 3) {
		printf("%d\n1 3\n1 2\n2 4\n", 2 * n - 5);
		for (int i = 5; i <= n; i ++) printf("%d 1\n%d 3\n", i, i);
	}
	else {
		puts("-1");
	}
	return 0;
}