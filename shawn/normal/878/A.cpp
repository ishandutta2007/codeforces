#include <bits/stdc++.h>

using namespace std;

int rd() {
	int x = 0, f = 1; char c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1, c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

void wt(int x) {
	if (x < 0) {
		putchar('-');
		wt(-x);
		return;
	}
	if (x >= 10) wt(x / 10);
	putchar(x % 10 + 48);
}

int n, X, Y, AND, XOR, OR;
char op[2];

int main() {
//	freopen("A.in", "r", stdin);
//	freopen("A.out", "w", stdout);
	n = rd(), X = 0, Y = 1023;
	for (int i = 1, x; i <= n; i ++) {
		scanf("%s", op), x = rd();
		if (op[0] == '&') X &= x, Y &= x;
		if (op[0] == '|') X |= x, Y |= x;
		if (op[0] == '^') X ^= x, Y ^= x;
	}
	for (int i = 0, B = 1; i < 11; i ++, B <<= 1, X >>= 1, Y >>= 1) {
		int x = X & 1, y = Y & 1;
		if (!x && y) AND += B;
		if (x) {
			if (!y) AND += B, XOR += B;
			else AND += B, OR += B;
		}
	}
	printf("3\n^ %d\n& %d\n| %d\n", XOR, AND, OR);
	return 0;
}