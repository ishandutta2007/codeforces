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

int ans, a[200], n, m;
char s[200];

int main() {
	m = read(), n = read();
	for (int i = 1; i <= n; i ++) {
		scanf("%s", s + 1);
		for (int j = 1; j <= m; j ++) {
			if (s[j] == '0') {
				a[i] = 1;
				break;
			}
		}
	}
	ans = 0;
	for (int i = 1; i <= n; i ++) {
		int res = 0;
		if (a[i] == 1) {
			while (a[i] == 1) res ++, i ++;
		}
		ans = max(ans, res);
	}
	write(ans);
	return 0;
}