#include <bits/stdc++.h>
using namespace std;
#define N 100100

typedef long long LL;

int n, m, a[N][55], w[N];
LL k, ex[55], f[N][55], g[N][55];

LL Sum(int x, LL k) {
	LL rlt = 0;
	for (int i = m; i >= 0; i --) {
		if (k & ex[i]) {
			rlt += f[x][i];
			x = a[x][i];
		}
	}
	return rlt;
}

LL Min(int x, LL k) {
	LL rlt = ex[50];
	for (int i = m; i >= 0; i --) {
		if (k & ex[i]) {
			rlt = min(rlt, g[x][i]);
			x = a[x][i];
		}
	}
	return rlt;
}

int main() {
//	freopen("e.in", "r", stdin);
	ex[0] = 1;
	for (int i = 1; i <= 50; i ++) ex[i] = ex[i-1] << 1;
	cin >> n >> k;
	for (int i = 0; i < n; i ++) scanf("%d", &a[i][0]);
	for (int i = 0; i < n; i ++) scanf("%d", &w[i]);
	for (int i = 0; i < n; i ++) f[i][0] = w[i], g[i][0] = w[i];
	m = log2(k) + 1;
	for (int j = 1; j <= m; j ++) {
		for (int i = 0; i < n; i ++) {
			a[i][j] = a[a[i][j-1]][j-1];
			f[i][j] = f[i][j-1] + f[a[i][j-1]][j-1];
			g[i][j] = min(g[i][j-1], g[a[i][j-1]][j-1]);
		}
	}
	for (int i = 0; i < n; i ++) {
		cout << Sum(i, k) << ' ' << Min(i, k) << endl;
	}
	return 0;
}