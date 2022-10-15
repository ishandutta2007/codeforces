#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

inline int read() {
	char c = getchar(); int n = 0, f = 0;
	while (c < '0' || c > '9') { if (c == '-') { f = 1; } c = getchar(); }
	while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
	return f ? -n : n;
}

const int maxN = 500005;

int n, m, max, a[maxN], num[maxN], f[maxN >> 1][8], cnt[maxN];
int pn, pri[maxN], mu[maxN], tot[maxN], lg2[maxN];
bool vis[maxN], used[maxN];
long long ans;

void init(int x) {
	for (int i = 2; i <= x; i++) {
		if (!vis[i]) { pri[++pn] = i; }
		for (int j = 1; j <= pn; j++) {
			int k = i * pri[j];
			if (k > x) { break; }
			vis[k] = true;
			if (i % pri[j] == 0) { break; }
		}
	}
}

void ins(int u) {
	tot[0] = 1, mu[1] = 1, ans += cnt[1], cnt[1]++;
	for (int i = 1, j = 0; i < (1 << num[u]); i++, j = i ^ (i & -i)) {
		tot[i] = tot[j] * f[u][lg2[i & -i]], mu[tot[i]] = -mu[tot[j]];
		ans += cnt[tot[i]], cnt[tot[i]] += mu[tot[i]];
	}
}
void del(int u) {
	tot[0] = 1, mu[1] = 1, cnt[1]--, ans -= cnt[1];
	for (int i = 1, j = 0; i < (1 << num[u]); i++, j = i ^ (i & -i)) {
		tot[i] = tot[j] * f[u][lg2[i & -i]], mu[tot[i]] = -mu[tot[j]];
		cnt[tot[i]] -= mu[tot[i]], ans -= cnt[tot[i]];
	}
}

int main() {
	n = read(), m = read();
	for (int i = 0; i <= 8; i++) { lg2[1 << i] = i; }
	for (int i = 1; i <= n; i++) { a[i] = read(); max = std::max(max, a[i]); }
	init(sqrt(max));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= pn && a[i] != 1; j++)  {
			if (a[i] % pri[j] == 0) {
				f[i][num[i]++] = pri[j];
				while (a[i] % pri[j] == 0) { a[i] /= pri[j]; }
			}
		}
		if (a[i] != 1) { f[i][num[i]++] = a[i]; }
	}
	for (; m; m--) {
		int u = read();
		if (used[u]) { used[u] = false, del(u); }
		else { used[u] = true, ins(u); }
		printf("%lld\n", ans);
	}
	return 0;
}

////////////////////////////////
//////////////