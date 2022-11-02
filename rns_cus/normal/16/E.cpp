#include <bits/stdc++.h>
using namespace std;
#define M 20

int n, x[M];
double a[M][M], f[1<<M];
vector <int> v[M];

int main() {
//	freopen("e.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) for (int j = 0; j < n; j ++) scanf("%lf", &a[i][j]);
	int N = 1 << n;
	for (int i = 1; i < N; i ++) {
		int bit = 0;
		for (int j = 0; j < n; j ++) if (i & (1 << j)) bit ++;
		v[bit].push_back(i);
	}
	f[N-1] = 1;
	for (int d = n; d > 1; d --) {
		for (int i = 0; i < v[d].size(); i ++) {
			int I = v[d][i], J, K, cnt = 0;
			for (int j = 0; j < n; j ++) if (I & (1 << j)) x[++cnt] = j;
			for (int j = 1; j < cnt; j ++) {
				for (int k = j + 1; k <= cnt; k ++) {
					J = x[j], K = x[k];
					f[I-(1<<K)] += f[I] * a[J][K] * 2 / cnt / (cnt - 1);
					f[I-(1<<J)] += f[I] * a[K][J] * 2 / cnt / (cnt - 1);
				}
			}
		}
	}
	for (int i = 0; i < n; i ++) printf("%.6lf ", f[1<<i]); puts("");
	return 0;
}