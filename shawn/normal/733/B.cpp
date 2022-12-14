#include <bits/stdc++.h>

using namespace std;

int read() {
	int x = 0 , f = 1 , c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1 , c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48 , c = getchar();
	return x * f;
}

int n, a[100010], b[100010], ans, delat, sa, sb;

long long l, r;

int main() {
	n = read();
	for (int i = 1; i <= n; i ++) {
		a[i] = read(), b[i] = read();
		sa += a[i];
		sb += b[i];
	}
	delat = abs(sa - sb);
	for (int i = 1; i <= n; i ++) {
		l = sa - a[i] + b[i];
		r = sb - b[i] + a[i];
		if (delat < abs(l - r)) {
			ans = i;
			delat = abs(l - r);
		}
	}
	printf("%d\n", ans);
	return 0;
}