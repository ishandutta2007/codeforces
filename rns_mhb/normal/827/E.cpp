#include <bits/stdc++.h>
using namespace std;
#define N 505050

int t, n;
char s[N];
int a[1<<20], b[1<<20];

typedef long long ll;
typedef long double ldb;
typedef double db;

const int L = 20, FN = (1<<L);
int rev[FN];
const ldb pi = 3.1415926535897932384626433832795028841971l;
const ldb two_pi = pi * 2;

struct cp{
	ldb x, y;
	cp() {}
	cp(ldb _x) : x(_x), y(0) {}
	cp(ldb _x, ldb _y) : x(_x), y(_y) {}
	inline cp operator + (const cp &p) const { return cp(x+p.x, y+p.y); }
	inline cp operator - (const cp &p) const { return cp(x-p.x, y-p.y); }
	inline cp operator * (const cp &p) const { return cp(x*p.x-y*p.y, x*p.y+y*p.x); }
	inline cp operator !() const { return cp(x, -y); }
} nw[FN+1], f[FN], g[FN], h[FN];

void init() {
	rev[0] = 0; for (int i = 1; i < FN; i ++) rev[i] = (rev[i>>1]>>1)|((i&1)<<(L-1));
	nw[0] = nw[FN] = cp(1,0);
	for (int i = 1; i <= (FN>>1); i ++) nw[i] = cp(cos(i*two_pi/FN), sin(i*two_pi/FN));
	for (int i = (FN>>1)+1; i < FN; i ++) nw[i] = !nw[FN-i];
}

void dft(cp *a, int n, int fg) {
	int d = __builtin_ctz(FN / n);
	for (int i = 0; i < n; i ++) if (i < (rev[i]>>d)) swap(a[i], a[rev[i]>>d]);
	for (int size = 2; size <= n; size <<= 1) {
		int step = FN / size; if (fg) step = -step;
		for (int i = 0; i < n; i += size) {
			cp *u = a + i, *v = a + (i+(size>>1)), *w = fg ? nw + FN : nw;
			for (int k = (size>>1); k --; ) {
				cp tmp = (*v) * (*w);
				*v = *u - tmp, *u = *u + tmp;
				u ++, v ++, w += step;
			}
		}
	}
	if (fg) for (int i = 0; i < n; i ++) a[i].x /= n, a[i].y /= n;
}

void func(int *a, int *b, int *c, int n) {
	for (int i = 0; i < n; i ++) {
		f[i] = cp((ldb)a[i]);
		g[i] = cp((ldb)b[i]);
	}
	dft(f, n, 0);
	dft(g, n, 0);
	for (int i = 0; i < n; i ++) h[i] = f[i] * g[i];
	dft(h, n, 1);
	for (int i = 0; i < n; i ++) c[i] = int(h[i].x + 0.5);
}

bool chk(int d) {
	for (int i = d; i < n; i += d) if (a[n+i] || a[n-i]) return false;
	return true;
}

int ans[N];

int main() {
	init();
	scanf("%d", &t);
	while (t --) {
		scanf("%d%s", &n, s);
		int m = 1 << (33 - __builtin_clz(n - 1));
		assert(m >= 2 * n);
		for (int i = 0; i < m; i ++) a[i] = b[i] = 0;
		for (int i = 0; i < n; i ++) {
			if (s[i] == 'V') a[i] = 1;
			else if (s[i] == 'K') b[n-i] = 1;
		}
		func(a, b, a, m);
		int cnt = 0;
		for (int i = 1; i <= n; i ++) ans[i] = chk(i), cnt += ans[i];
		cout<<cnt<<endl;
		for (int i = 1; i <= n; i ++) if (ans[i]) printf("%d ", i);
		puts("");
	}
}