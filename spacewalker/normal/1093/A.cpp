#include <cstdio>

int solveCase(int x) {
	if (2 <= x && x <= 7) {
		return 1;
	} else {
		return solveCase(x-2) + 1;
	}
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		printf("%d\n", solveCase(n));
	}
}