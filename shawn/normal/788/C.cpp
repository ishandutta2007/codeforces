#include <bits/stdc++.h>

using namespace std;

int rd() {
	int x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;
}

bitset < 2010 > f[2];
bool a[2010], u;
int n, k;

int main() {
	n = rd(), k = rd();
	for (int i = 1; i <= k; i ++) a[rd()] = 1;
	f[u][1000] = 1;
	for (int i = 1; i <= 1000; i ++) {
		u ^= 1, f[u].reset();
		for (int j = 0; j <= 1000; j ++) {
			if (a[j]) f[u] |= (f[u ^ 1] >> j) << n;
		}
		if (f[u][1000]) return printf("%d\n", i), 0;
	}
	return puts("-1"), 0;
}