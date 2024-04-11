#include <bits/stdc++.h>
using namespace std;
#define M 110
int a[M], b[M], f[M];
int n, m, T;

typedef vector <vector <int> > matrix;

matrix A, ans, tmp;

void multi(matrix A, matrix B, matrix &C) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			tmp[i][j] = 0;
			for (int k = i; k <= j; k++) {
				tmp[i][j] = max(tmp[i][j], A[i][k] + B[k][j]);
			}
		}
	}
	C = tmp;
}

int main() {
//	freopen("B.in", "r", stdin);
	scanf("%d %d", &n, &T);
	for (int i = 0; i < n; i++) scanf("%d", a + i), b[i] = a[i];
	sort(b, b + n); m = unique(b, b + n) - b;
	for (int i = 0; i < n; i++) a[i] = lower_bound(b, b + m, a[i]) - b;
	A.resize(m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) f[j] = 0;
		bool bf = 0;
		for (int k = 0; k < n; k++) {
			if (bf && a[k] >= i) {
				int mx = 0;
				for (int j = i; j <= a[k]; j++) mx = max(mx, f[j] + 1);
                f[a[k]] = mx;
			}
			else if (a[k] == i) {bf = 1; f[i] = 1;}
		}
		A[i].resize(m);
		for (int j = i; j < m; j++) {
			A[i][j] = f[j]; f[j+1] = max(f[j], f[j+1]);
		}
	}
	ans.resize(m); tmp.resize(m);
	for (int i = 0; i < m; i++) {
		ans[i].resize(m); tmp[i].resize(m);
	}
	for ( ; T; T >>= 1) {
		if (T & 1) multi(ans, A, ans); multi(A, A, A);
	}
	int res = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) if (res < ans[i][j]) res = ans[i][j];
	}
	printf("%d\n", res);
	return 0;
}