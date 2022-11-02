#include <cstdio>
#pragma warning(disable : 4996)
int n, c, a[100009];
int main() {
	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	int ptr = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] - a[i - 1] > c) ptr = i;
	}
	printf("%d\n", n - ptr);
	return 0;
}