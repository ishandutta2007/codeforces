#include <cstdio>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	printf("%d\n", (n & 1) ? (n - 1) + (n - 1) * ((n - 3) / 2) / 2: (n - 2) * (n - 2) / 4 + (n - 2));
	if (n & 1) {
		for (int i = 2; i <= n; i += 2) {
			printf("%d %d %d %d\n", 3, 1, i, i + 1);
			printf("%d %d %d %d\n", 3, 1, i, i + 1);
			for (int j = 2; j < i; j += 2) {
				printf("%d %d %d %d %d\n", 4, i, j, i + 1, j + 1);
				printf("%d %d %d %d %d\n", 4, i, j, i + 1, j + 1);
			}
		}
	}
	else {
		puts("4 1 2 3 4"), puts("4 1 3 4 2"), puts("4 1 4 2 3");
		for (int i = 5; i <= n; i += 2) {
			printf("%d %d %d %d \n", 3, 1, i, i + 1);
			printf("%d %d %d %d \n", 3, 2, i, i + 1);
			printf("%d %d %d %d %d\n", 4, 1, i, 2, i + 1);
			for (int j = 3; j < i; j += 2) {
				printf("%d %d %d %d %d\n", 4, i, j, i + 1, j + 1);
				printf("%d %d %d %d %d\n", 4, i, j, i + 1, j + 1);
			}
		}
	}
	return 0;
}