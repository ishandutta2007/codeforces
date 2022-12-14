#include <bits/stdc++.h>

using namespace std;

const int N = 600;
int f[N][N], a[N], n;

int rd() {
	int x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;
}

int F(int l, int r) {
	if (~f[l][r]) return f[l][r];
	if (l == r) return 1;
	if (l > r) return 0;
	int re = 1 + F(l + 1, r);
	for (int i = l + 2; i <= r; i ++) if (a[l] == a[i]) re = min(re, F(l + 1, i - 1) + F(i + 1, r));
	if (a[l] == a[l + 1]) re = min(re, 1 + F(l + 2, r));
	return f[l][r] = re;
}

int main() {
	n = rd();
	for (int i = 1; i <= n; i ++) a[i] = rd();
	memset(f, -1, sizeof f);
	printf("%d\n", F(1, n));
	return 0;
}