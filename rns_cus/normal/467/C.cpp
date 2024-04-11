#include <bits/stdc++.h>
using namespace std;
#define N 5050

int n, m, k, p[N];
long long s[N], f[N][N];
const long long inf = 1ll << 60;

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i ++) scanf("%d", &p[i]), s[i] = s[i-1] + p[i];
	for (int i = 1; i <= n; i ++) for (int j = 1; j <= k; j ++) f[i][j] = -inf;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= k; j ++) {
			f[i][j] = f[i-1][j];
			if (i - m >= 0) {
				f[i][j] = max(f[i][j], f[i-m][j-1] + s[i] - s[i-m]);
			}
		}
	}
	cout << f[n][k] << endl;
	return 0;
}