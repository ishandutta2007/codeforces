#include <bits/stdc++.h>

using namespace std;

int read(){
	int x = 0, f = 1, c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1, c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

void write(int x) {
	if (x < 0) puts("-"), write(-x);
	if (x >= 10) write(x / 10);
	putchar(x % 10 + 48);
}

long long n, a, b, c, ans;

int main() {
	n = read();
	a = read(), b = read(), c = read();
	if (n % 4 == 0) return puts("0"), 0;
	if ((n + 1) % 4 == 0) {
		ans = min(a, min(c * 3ll, b + c));
		return printf("%I64d\n", ans), 0;
	}
	if ((n + 2) % 4 == 0) {
		ans = min(b, min(a + a, c + c));
		return printf("%I64d\n", ans), 0;
	}
	if ((n + 3) % 4 == 0) {
		ans = min(c, min(a + a + a, b + a));
		return printf("%I64d\n", ans), 0;
	}
}