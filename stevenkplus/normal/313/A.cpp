#include <cstdio>

int go(int x) {
	if (x >= 0) return x;
	else {
		x *= -1;
		int a, b;
		a = x % 10;
		x /= 10;
		b = x % 10;
		x /= 10;
		if (a > b) a = b;
		return -(10 * x + a);
	}
}

int main() {
	int x;
	scanf("%d", &x);
	printf("%d\n", go(x));
	return 0;
}