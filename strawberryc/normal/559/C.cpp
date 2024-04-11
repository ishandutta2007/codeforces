#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)
using namespace std;
inline int read() {
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}
const int N = 2005, M = 2e5 + 5, ZZQ = 1e9 + 7;
int h, w, n, fac[M], inv[M], f[N];
struct cyx {
	int x, y;
} a[N];
bool comp(cyx a, cyx b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}
int C(int n, int m) {
	return 1ll * fac[n] * inv[m] % ZZQ * inv[n - m] % ZZQ;
}
int main() {
	int i, j;
	h = read(); w = read(); n = read();
	fac[0] = inv[0] = inv[1] = 1;
	For (i, 1, 200000) fac[i] = 1ll * fac[i - 1] * i % ZZQ;
	For (i, 2, 200000) inv[i] = 1ll * (ZZQ - ZZQ / i) * inv[ZZQ % i] % ZZQ;
	For (i, 1, 200000) inv[i] = 1ll * inv[i] * inv[i - 1] % ZZQ;
	For (i, 1, n) a[i].x = read(), a[i].y = read();
	a[++n] = (cyx) {h, w};
	sort(a + 1, a + n + 1, comp);
	For (i, 1, n) {
		f[i] = C(a[i].x + a[i].y - 2, a[i].x - 1);
		For (j, 1, i - 1) if (a[j].y <= a[i].y)
			f[i] = (f[i] - 1ll * f[j] * C(a[i].x - a[j].x + a[i].y - a[j].y,
				a[i].x - a[j].x) % ZZQ + ZZQ) % ZZQ;
	}
	cout << f[n] << endl;
	return 0;
}