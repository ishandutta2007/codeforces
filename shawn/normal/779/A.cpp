#include <stdio.h>
#include <algorithm>

using namespace std;

int read() {
	char c = getchar(); int x = 0;
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;
}

void write(int x) {
	if (x >= 10) write(x / 10);
	putchar(x % 10 + 48);
}

int a[110], b[110], c[10], app[10], n, ans;

int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	n = read();
	for (int i = 1; i <= n; i ++) a[i] = read(), app[a[i]]++, c[a[i]]++;
	for (int i = 1; i <= n; i ++) b[i] = read(), app[b[i]]++;
	//for (int i = 1; i <= 5; i ++) printf("%d ", c[i]); puts("");	
	for (int i = 1; i <= 5; i ++) if (app[i] & 1) return puts("-1"), 0;
	for (int i = 1; i <= 5; i ++) ans += abs(app[i] / 2 - c[i]);
	write(ans / 2);	
	return 0;
}