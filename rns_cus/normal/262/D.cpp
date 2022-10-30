#include <bits/stdc++.h>
using namespace std;
#define N 55

int n, a[N], p, b[N];
long long c[N][N], f[N][N][N];

void prepare() {
	c[0][0] = 1;
	for (int i = 1; i <= 50; i ++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j ++) c[i][j] = c[i-1][j] + c[i-1][j-1];
	}
}

double calc(int x) {
	int m = 0;
	for (int i = 1; i <= n; i ++) if (i != x) b[++m] = a[i];
	memset(f, 0, sizeof f);
    f[0][0][0] = 1;
    for (int i = 1; i <= m; i ++) {
		for (int j = 0; j <= i; j ++) {
			for (int k = 0; k <= p; k ++) {
                f[i][j][k] = f[i-1][j][k];
                if (j && k - b[i] >= 0) f[i][j][k] += f[i-1][j-1][k-b[i]];
			}
		}
    }
	double rlt = 0;
    for (int j = 0; j <= m; j ++) {
		for (int k = p - a[x] + 1; k <= p; k ++) {
            rlt += 1.0 * j * f[m][j][k] / c[m][j];
		}
    }
    return rlt;
}

int main() {
//	freopen("d.in", "r", stdin);
	prepare();
	scanf("%d", &n);
    int sum = 0;
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), sum += a[i];
	scanf("%d", &p);
	if (sum <= p) {
		printf("%d\n", n); return 0;
	}
	double ans = 0;
	for (int i = 1; i <= n; i ++) ans += calc(i);
	printf("%.12lf\n", ans / n);
	return 0;
}