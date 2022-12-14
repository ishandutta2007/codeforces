#include <bits/stdc++.h>

using namespace std;

int rd() {
	char c = getchar(); int x = 0, f = 1;
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1, c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

int R, D, n, ans;

int main() {
	R = rd(), D = rd();
	n = rd();
	for (int i = 1; i <= n; i ++) {
		double x = rd(), y = rd(), r = rd();
		double t = sqrt(x * x + y * y);
		if (R >= t + r && t - r >= R - D) ans ++;
	}
	printf("%d\n", ans);
	return 0;
}