#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b; scanf("%d %d", &a, &b);
	for (int i = 1;; ++i) {
		if (i % 2 == 1) {
			// printf("%d vladik\n", i);
			if (a < i) {
				printf("Vladik\n");
				return 0;
			}
			a -= i;
		} else {
			// printf("%d valera\n", i);
			if (b < i) {
				printf("Valera\n");
				return 0;
			}
			b -= i;
		}
	}
	return 0;
}