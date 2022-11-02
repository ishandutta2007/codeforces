#include <cstdio>
int a, b;
int main() {
	scanf("%d%d", &a, &b);
	puts(-1 <= a - b && a - b <= 1 && a + b != 0 ? "YES" : "NO");
	return 0;
}