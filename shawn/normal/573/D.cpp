#pragma GCC optimize("O2")
#include <cstdio>
#include <algorithm>

using namespace std;

int rd() {
	int x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;
}

void wt(long long x) {
	if (x >= 10) wt(x / 10);
	putchar(x % 10 + 48);
}

const long long inf = 1ll << 60;
const int N = 30010;
struct pt{
	long long v, id;
	bool operator < (const pt &t) const {
		return v < t.v;
	}
} a[N], b[N];
int n, m, pa[N], pb[N], l[N]; 
long long f[N], g[N][4];

void turnto(int i) {
	g[i][1] = g[i][2] = g[i][3] = -inf;
	if (i >= 1 && l[i] != i) g[i][1] = 1ll * a[i].v * b[i].v;
	if (i >= 2 && l[i] != i - 1 && l[i - 1] != i) g[i][2] = 1ll * a[i].v * b[i - 1].v + 1ll * a[i - 1].v * b[i].v;
	if (i >= 3) {
		if (l[i] != i - 2 && l[i - 1] != i && l[i - 2] != i - 1)
			g[i][3] = 1ll * a[i].v * b[i - 2].v + a[i - 1].v * b[i].v + a[i - 2].v * b[i - 1].v;
		if (l[i] != i - 1 && l[i - 1] != i - 2 && l[i - 2] != i)
			g[i][3] = max(g[i][3], 1ll * a[i].v * b[i - 1].v + 1ll * a[i - 1].v * b[i - 2].v + 1ll * a[i - 2].v * b[i].v);
	}
}

int main() {
	n = rd(), m = rd();
	for (int i = 1; i <= n; i ++) a[a[i].id = i].v = rd();
	for (int i = 1; i <= n; i ++) b[b[i].id = i].v = rd();
	sort(a + 1, a + n + 1), sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i ++) pa[a[i].id] = i, pb[b[i].id] = i;
	for (int i = 1; i <= n; i ++) l[i] = pb[a[i].id];
	for (int i = 1; i <= n; i ++) turnto(i);
	for (int j = 1; j <= m; j ++) {
		int x = pa[rd()], y = pa[rd()];
		swap(l[x], l[y]), f[0] = 0;
		for (int i = max(1, x - 5); i <= min(n, x + 5); i++) turnto(i);
		for (int i = max(1, y - 5); i <= min(n, y + 5); i++) turnto(i);
		for (int i = 1; i <= n; i ++) {
			if (i >= 1) f[i] = f[i - 1] + g[i][1];
			if (i >= 2) f[i] = max(f[i], f[i - 2] + g[i][2]);
			if (i >= 3) f[i] = max(f[i], f[i - 3] + g[i][3]);
		}
		wt(f[n]), putchar(10);
	}
	return 0;
}