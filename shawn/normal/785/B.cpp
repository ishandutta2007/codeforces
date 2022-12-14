#include <bits/stdc++.h>

using namespace std;

int read() {
	int x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;
}

const int inf = 0x7f7f7f7f;
int nr, nl, ml, mr, n, m;

int main() {
	n = read();
	nr = mr = inf;
	for (int i = 1; i <= n; i ++) {
		int l = read(), r = read();
		nl = max(nl, l);
		nr = min(nr, r);
	}
	m = read();
	for (int i = 1; i <= m; i ++) {
		int l = read(), r = read();
		ml = max(ml, l);
		mr = min(mr, r);
	}
	printf("%d", max(max(0, ml - nr), max(0, nl - mr)));
	return 0;
}