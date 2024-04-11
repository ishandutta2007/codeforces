#include <bits/stdc++.h>

using namespace std;

int rd() {
	int x = 0, f = 1; char c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1, c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

void wt(int x) {
	if (x < 0) {
		putchar('-');
		wt(-x);
		return;
	}
	if (x >= 10) wt(x / 10);
	putchar(x % 10 + 48);
}

const int N = 1e5 + 10;
int a[N], b[N], c[N], n, k, m, d, cnt, tot;
long long ans;

int main() {
	n = rd(), k = rd(), m = rd();
	for (int i = 1; i <= n; i ++) a[i] = rd();
	for (int i = 1; i <= n; ++i) {
		if (a[i] != b[cnt]) b[++cnt] = a[i], c[cnt] = 1; 
		else c[cnt]++, cnt = c[cnt] == k ? cnt - 1 : cnt;
	}
	if (!cnt) return puts("0"), 0;
	for (int i = 1; i <= cnt; i ++) tot += c[i];
	int i;
	for (i = 1; i < cnt + 1 - i; i ++) {
		if (b[i] == b[cnt + 1 - i] && c[i] + c[cnt + 1 - i] == k) d += k;
		else break;
	}
	if (i < cnt + 1 - i) {
		if (b[i] == b[cnt + 1 - i] && c[i] + c[cnt + 1 - i] > k) d += k;
		ans = 1ll * tot * m - 1ll * d * (m - 1);
	}
	else {
		ans = 1ll * c[i] * m % k;
		if (ans) ans += tot - c[i];
	}
	printf("%lld\n", ans);
	return 0;
}