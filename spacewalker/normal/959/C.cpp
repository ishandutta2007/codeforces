#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>

void printWACase(int n) {
	if (n <= 5) {
		printf("-1\n");
	} else {
		printf("1 2\n1 3\n1 4\n");
		for (int i = 5; i <= n; ++i) {
			printf("4 %d\n", i);
		}
	}
}

void printACCase(int n) {
	for (int i = 2; i <= n; ++i) {
		printf("1 %d\n", i);
	}
}

int main() {
	int n; scanf("%d", &n);
	printWACase(n);
	printACCase(n);
	return 0;
}