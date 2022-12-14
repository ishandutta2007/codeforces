#include <bits/stdc++.h>

using namespace std;

int read() {
	int x = 0 , f = 1 , c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1 , c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48 , c = getchar();
	return x * f;
}

int n, m, ans;

int main() {
	n = read(), m = read();
	ans = 0x7f7f7f7f;
	for (int i = 1; i <= m; i ++) {
		int l = read(), r = read();
		ans = min(ans , r - l + 1);
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; i ++) {
		printf("%d ", (i - 1) % ans);
	}
	return 0;
}