#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 105, T = 1e5 + 5;
const double Pi = acos(-1), inf = 0x3f3f3f3f;
struct Complex {
    double x, y;
    Complex(double a = 0, double b = 0) { x = a, y = b; }
    Complex operator +(Complex b) { return Complex(x + b.x, y + b.y); }
    Complex operator -(Complex b) { return Complex(x - b.x, y - b.y); }
    Complex operator *(Complex b) { return Complex(x * b.x - y * b.y, x * b.y + y*b.x); }
};
int n, m, t, x, r[T], dis[N][N], a[N], b[N], c[N];
double p[N][T], f[N][T], g[N][T];

void FFT(Complex* A, int lim, int type) {
	for(int i = 0; i < lim; i++) if(i > r[i]) swap(A[i], A[r[i]]);
	for(int mid = 1; mid < lim; mid <<= 1) {
		Complex Wn(cos(Pi / mid), type * sin(Pi / mid));
		for(int i = 0; i < lim; i += mid << 1) {
			Complex w = Complex(1, 0);
			for(int j = 0; j < mid; j++, w = w * Wn) {
				Complex x = A[i + j], y = w * A[i + mid + j];
				A[i + j] = x + y, A[i + mid + j] = x - y;
			}
		}
	}
	if(type == -1) for(int i = 0; i < lim; i++) A[i].x /= lim;
}

void Floyd() {
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}

Complex F[1000005], G[1000005];
void solve(int L, int R) {
	if(L >= t) return;
	if(L == R) {
		for(int i = 1; i < n; i++) f[i][L] = inf;
		for(int i = 1; i <= m; i++) if(a[i] != n) f[a[i]][L] = min(f[a[i]][L], g[i][L] + c[i]);
		return;
	}
	int mid = (L + R) >> 1; 
	solve(mid + 1, R);
	int len = R - L - 1, lenr = R - mid - 1;
	int lim = 1, l = 0;
	while(lim <= len + lenr) lim <<= 1, ++l;
	for(int i = 0; i < lim; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
	for(int i = 1; i <= m; i++) {
		if(a[i] == n) continue;
		for(int j = 0; j <= len; j++) F[j] = Complex(p[i][j + 1]);
		for(int j = 0; j <= lenr; j++) G[j] = Complex(f[b[i]][R - j]);
		for(int j = len + 1; j < lim; j++) F[j] = Complex(0, 0);
		for(int j = lenr + 1; j < lim; j++) G[j] = Complex(0, 0);
		FFT(F, lim, 1), FFT(G, lim, 1);
		for(int j = 0; j < lim; j++) F[j] = F[j] * G[j];
		FFT(F, lim, -1);
		for(int j = L; j <= mid; j++) 
			g[i][j] += F[R - j - 1].x;
	}
	solve(L, mid);
}

int main() {
	n = get(), m = get(), t = get(), x = get();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			dis[i][j] = (i != j) * inf;
	for(int i = 1; i <= m; i++) {
		a[i] = get(), b[i] = get(), c[i] = dis[a[i]][b[i]] = get();
		for(int j = 1; j <= t; j++) p[i][j] = 1.0 * get() / 1e5;
	}
	Floyd();
	for(int i = 0; i < 2 * t; i++) f[n][i] = (i > t) * x;
	for(int i = 1; i < n; i++)
		for(int j = t; j < 2 * t; j++)
			f[i][j] = dis[i][n] + x;
	solve(0, 2 * t - 1);
	printf("%.10lf", f[1][0]);
	return 0;
}