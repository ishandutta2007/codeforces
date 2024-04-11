#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const int U = 200;
const int M = U + 5;

int n;
ld p, q;
ld f[M][M], F[M][M];
ld a[M][M];
ld C[M][M];

void input() {
	int pp;
	scanf("%d %d", &n, &pp);
	p = pp/1000000000.;
	q = p * (1-p);
}

void prepare() {
	f[1][1] = p, F[1][1] = p, f[1][2] = 1-p, F[1][2] = 2-2*p;
	for (int k = 2; k <= U; k++) {
		f[k][1] = q;
		for (int i = 2; i <= k; i++) F[k][1] += F[k-1][i];
		if (k > 2) F[k][1] = F[k][1] * q / (1 - q) + q;
		else F[k][1] = 3 * q;

		f[k][2] = 1 - q;
		for (int i = 3; i <= k + 1; i++) f[k][i] = f[k][i-1] * f[k-1][i-1];
		for (int i = 2; i <= k + 1; i++) {
			for (int j = i - 1; j >= 1; j--) {
				F[k][i] += F[k-1][j];
			}
			F[k][i] = F[k][i] * f[k][i] + i * (f[k][i] - f[k][i+1]);
		}
	}
	a[1][U] = q;
	for (int j = 2; j < U; j++) a[1][j] = q / (1 - q);
	for (int i = 2; i < U; i++) {
		a[i][U] = i * (f[U][i] - f[U][i+1]);
		for (int j = i - 1; j >= 1; j--) a[i][j] = f[U][i];
	}
	a[U][U] = 1;
}

ld t[M][M];
void multi(ld C[][M], ld a[][M]) {
	memset(t, 0, sizeof t);
	for (int i = 1; i <= U; i++) for (int j = 1; j <= U; j++) for (int k = 1; k <= U; k++)
		t[i][k] += C[i][j] * a[j][k];
	for (int i = 1; i <= U; i++) for (int j = 1; j <= U; j++)
		C[i][j] = t[i][j];
}

double solve() {
	ld rlt = 0;
	if (n <= U) {
		for (int i = 1; i <= n + 1; i++) rlt += F[n][i];
		return rlt;
	}
	n -= U;
	for (int i = 1; i <= U; i++) C[i][i] = 1;
	while (n) {
		if (n & 1) multi(C, a);
		n >>= 1;
		multi(a, a);
	}

	F[U][U] = 1;
	for (int i = 1; i < U; i++) {
		for (int j = 1; j <= U; j++)
			rlt += C[i][j] * F[U][j];
	}
	return rlt;
}

int main() {
	//freopen("500_G3.in", "r", stdin);
	input();
int nn = n;
n = min(1000000, n);
	prepare();
double rlt = solve();
if (nn > 1000000) rlt = rlt / 1000000 * nn;
	printf("%.15lf\n", rlt);
	return 0;
}