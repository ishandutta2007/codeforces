#include <bits/stdc++.h>
using namespace std;

int n, m, t, x, a[105], b[105], c[105], dis[55][55];
double f[55][20005], p[105][20005], suf[105][20005], cost[105][20005];
vector<int> g[55];

const double PI = acos(-1);
struct Complex {
	double r, i;
	Complex(double a = 0, double b = 0): r(a), i(b) {}
	Complex conj() { return Complex(r, -i); }
} w[1 << 15];
Complex operator+(const Complex &a, const Complex &b) { return Complex(a.r + b.r, a.i + b.i); }
Complex operator-(const Complex &a, const Complex &b) { return Complex(a.r - b.r, a.i - b.i); }
Complex operator*(const Complex &a, const Complex &b) { return Complex(a.r * b.r - a.i * b.i, a.r * b.i + a.i * b.r); }
Complex operator/(const Complex &a, double b) { return Complex(a.r / b, a.i / b); }

void init(int n) {
	for (int i = 0; i < n / 2; ++i)
		w[n / 2 + i] = Complex(cos(2 * PI * i / n), sin(2 * PI * i / n));
	for (int i = n / 2 - 1; i >= 1; --i)
		w[i] = w[i << 1];
}
void dft(Complex *a, int n) {
	for (int i = 0, j = 0; i < n; ++i) {
		if (i > j) swap(a[i], a[j]);
		for (int k = n >> 1; (j ^= k) < k; k >>= 1);
	}
	for (int d = 1; d < n; d <<= 1)
		for (int i = 0; i < n; i += d << 1)
			for (int j = 0; j < d; ++j) {
				Complex tmp = a[i + d + j] * w[d + j];
				a[i + d + j] = a[i + j] - tmp;
				a[i + j] = a[i + j] + tmp;
			}
}
void idft(Complex *a, int n) {
	reverse(a + 1, a + n);
	dft(a, n);
	for (int i = 0; i < n; ++i)
		a[i].r /= n;
}

void solve(int l, int r) {
	if (l == r) {
		for (int e = 1; e <= m; ++e)
			f[a[e]][l] = min(f[a[e]][l], cost[e][l] + c[e] + f[b[e]][t + 1] * suf[e][t - l + 1]);
		return;
	}
	int mid = l + r >> 1;
	solve(mid + 1, r);
	for (int e = 1; e <= m; ++e) {
		static Complex x[1 << 15], y[1 << 15];
		int len = 1;
		while (len <= r - l) len <<= 1;
		init(len);
		for (int j = 0; j <= r - l; ++j) x[j] = {p[e][r - l - j], 0};
		for (int j = r - l + 1; j < len; ++j) x[j] = {0, 0};
		for (int j = mid + 1; j <= r; ++j) y[j - mid - 1] = {f[b[e]][j], 0};
		for (int j = r - mid; j < len; ++j) y[j] = {0, 0};
		dft(x, len), dft(y, len);
		for (int j = 0; j < len; ++j) x[j] = x[j] * y[j];
		idft(x, len);
		for (int j = l; j <= mid; ++j)
			cost[e][j] += x[r - l + j - mid - 1].r;
	}
	solve(l, mid);
}

int main() {
	scanf("%d%d%d%d", &n, &m, &t, &x);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			dis[i][j] = i == j ? 0 : 0x3f3f3f3f;
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%d", a + i, b + i, c + i);
		dis[a[i]][b[i]] = c[i];
		for (int j = 1, x; j <= t; ++j)
			scanf("%d", &x), p[i][j] = x * 1e-5;
		for (int j = t; j; --j)
			suf[i][j] = suf[i][j + 1] + p[i][j];
		g[a[i]].push_back(i);
	}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for (int i = 1; i <= n; ++i) {
		f[i][t + 1] = dis[i][n] + x;
		for (int j = 0; j <= t; ++j)
			f[i][j] = (i == n ? 0 : 1e100);
	}
	solve(0, t);
	printf("%.10f\n", f[1][0]);
	return 0;
}