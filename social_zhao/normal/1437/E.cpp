#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 5e5 + 5;
int n, k, a[N], b[N], ans = 0;
int bin[N], tot, shit, c[N], f[N];
int val[N];

int lowbit(int x) { return x & -x; }
void upd(int x, int v) { while(x <= shit) val[x] = max(val[x], v), x += lowbit(x); }
int ask(int x) { int y = 0; while(x) y = max(y, val[x]), x -= lowbit(x); return y; }

int calc(int l, int r, int up, int dwn) {
	if(l > r) return 0;
	for(int i = l; i <= r; i++) if(a[i] >= up && a[i] <= dwn) bin[++tot] = c[tot] = a[i];
	sort(bin + 1, bin + 1 + tot);
	shit = unique(bin + 1, bin + 1 + tot) - bin - 1;
	int res = 0;
	for(int i = 1; i <= tot; i++) {
		c[i] = lower_bound(bin + 1, bin + 1 + shit, c[i]) - bin;
		int now = ask(c[i]);
		res = max(res, now + 1);
		upd(c[i], now + 1);
	}
	for(int i = 0; i <= shit; i++) val[i] = 0;
	tot = 0;
	return r - l + 1 - res;
}

int main() {
	n = get(), k = get();
	for(int i = 1; i <= n; i++) a[i] = get() - i;
	for(int i = 1; i <= k; i++) b[i] = get();
	b[0] = 0, b[k + 1] = n + 1, a[0] = -0x3f3f3f3f, a[n + 1] = 0x3f3f3f3f;
	for(int i = 0; i <= k; i++) {
		if(a[b[i]] > a[b[i + 1]]) return 0 * printf("-1\n");
		ans += calc(b[i] + 1, b[i + 1] - 1, a[b[i]], a[b[i + 1]]);
	}
	printf("%d\n", ans);
	return 0;
}