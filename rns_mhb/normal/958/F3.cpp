#include <bits/stdc++.h>
using namespace std;

const int mod = 1009;

#define N 202020

typedef long long ll;
typedef long double ldb;
typedef double db;

namespace fft{ /// multiply two polynomial nlog(n) time modulo p
	const int L = 18, FN = (1<<L);
	int rev[FN];
	const db pi = 3.1415926535897932384626433832795028841971l;
	const db two_pi = pi * 2;
	struct cp{
		db x, y;
		cp() {}
		cp(db _x) : x(_x), y(0) {}
		cp(db _x, db _y) : x(_x), y(_y) {}
		inline cp operator + (const cp &p) const { return cp(x+p.x, y+p.y); }
		inline cp operator - (const cp &p) const { return cp(x-p.x, y-p.y); }
		inline cp operator * (const cp &p) const { return cp(x*p.x-y*p.y, x*p.y+y*p.x); }
		inline cp operator !() const { return cp(x, -y); }
	} nw[FN+1], f[FN], g[FN], h[FN], hh[FN];

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

	void multiply(vector <int> &a, vector <int> &b, vector <int> &c) {
		int n1 = a.size(), n2 = b.size(), n = 1;
		while (n <= n1 + n2) n <<= 1;
		for (int i = 0; i < n; i ++) {
			f[i] = cp((db)(i < n1 ? a[i] : 0));
			g[i] = cp((db)(i < n2 ? b[i] : 0));
		}
		dft(f, n, 0);
		dft(g, n, 0);
		for (int i = 0; i < n; i ++) {
			h[i] = f[i] * g[i];
		}
		dft(h, n, 1);
		c.resize(n1 + n2 - 1);
		for (int i = 0; i < c.size(); i ++) c[i] = ((long long)(h[i].x + 0.5)) % mod;
	}
}

int n, m, k;
int a[N];

void solve(int st, int en, vector <int> &z) {
	z.clear();
	if (a[st] == a[en]) {
		z.resize(en - st + 2, 1);
		return ;
	}

	int mid = (st + en) >> 1;
	if (a[mid] != a[en]) {
		while (a[mid] == a[mid+1]) mid ++;
	}
	else {
		while (a[mid] == a[mid+1]) mid --;
	}

	vector <int> x, y;
	solve(st, mid, x);
	solve(mid + 1, en, y);

	fft::multiply(x, y, z);
}

vector <int> answer;

int main() {
	fft::init();
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	solve(1, n, answer);
	printf("%d\n", answer[k]);


	return 0;
}