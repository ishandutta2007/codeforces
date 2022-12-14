#include <bits/stdc++.h>

using namespace std;

long long rd() {
	long long x = 0, f = 1; char c = getchar() ;
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1, c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

void wt(long long x) {
	if (x < 0) { putchar('-'), wt(-x); return;}
	if (!x) return;
	wt(x / 10), putchar(x % 10 + 48);
}

int main() {
	for (int q = rd(); q; q --) {
		long long a = rd(), b = rd(), c = rd();
		wt((a + b + c) / 2); puts("");
	}
	return 0;
}