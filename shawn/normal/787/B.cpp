#include <cstdio>
#include <algorithm>

using namespace std;

int read() {
	int x = 0, f = 1; char c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1, c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

int n, m, f[20100];
bool fg, _fg;

int main() {
	n = read(), m = read();
	fg = 1;
	for (int i = 1; i <= m; i ++) {
		int t = read();
		_fg = 0; int j;
		for (j = 1; j <= t; j ++) {
			int a = read();
			if (f[-a + n]) _fg = 1;
			f[a + n] = 1;
		}
		fg &= _fg;
		if (!fg) break;
		for (int j = 0; j <= n * 2; j ++) f[j] = 0;
	}
	puts(fg ? "NO" : "YES");
	return 0;
}