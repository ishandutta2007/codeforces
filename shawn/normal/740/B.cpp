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

int a[200], n, m, ans;

int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i ++) a[i] = read();
	for (int i = 1; i <= m; i ++) {
		int l = read(), r = read();
		int sum = 0;
		for (int j = l; j <= r; j ++) sum += a[j];
		if (sum < 0) continue;
		ans += sum;
	} 
	printf("%d\n", ans);
	return 0;
}