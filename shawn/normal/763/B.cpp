#include <bits/stdc++.h>

using namespace std;

int rd() {
	int x = 0, f = 1; char c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1, c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}
int a, b, c, d, n;
int main() {
	n = rd();
	puts("YES");
	for (int i = 1; i <= n; i ++) {
		a = rd(), b = rd(), c = rd(), d = rd();
		a = (a % 2 + 2) % 2, b = (b % 2 + 2) % 2;
		printf("%d\n", a + b * 2 + 1);
	}
	return 0;
}