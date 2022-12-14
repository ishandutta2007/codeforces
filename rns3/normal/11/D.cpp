#include <bits/stdc++.h>
using namespace std;
#define M 20

int n, m, a, b;
bool con[M][M];
long long f[M][1<<M], gas[M], ans;
int v[M][M], size[M];

int bit(int m) {
	int res = 0;
	while (m) res += m & 1, m >>= 1;
	return res;
}

int main() {
///	freopen("d.in", "r", stdin);
	scanf("%d %d", &n, &m);
	while (m --) {
		scanf("%d %d", &a, &b), a --, b --;
		con[a][b] = con[b][a] = 1;
		v[a][size[a]++] = b;
		v[b][size[b]++] = a;
	}
	while (n > 2) {
		int N = 1 << (n - 1);
		memset(gas, 0, sizeof gas);
		for (int j = 0; j < n; j ++) for (int k = 0; k < N; k ++) f[j][k] = 0;
		f[n-1][0] = 1;
		for (int k = 1; k < N; k ++) {
			for (int j = 0; j < n - 1; j ++) if (k & (1 << j)) {
				for (int r = 0; r < size[j]; r ++) if (v[j][r] < n) f[j][k] += f[v[j][r]][k-(1<<j)];
				if (con[j][n-1]) gas[bit(k)+1] += f[j][k];
			}
		}
		for (int node = 3; node <= n; node ++) ans += gas[node] / 2;
		n --;
	}
	printf("%I64d\n", ans);
	return 0;
}