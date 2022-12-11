#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

string a[300010];
char buf[300010];
long long pw[300010], f[300010];

int main() {
	pw[0] = 1; for (int i = 1; i <= 300005; i++) pw[i] = pw[i - 1] * 2 % mod;
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%s", buf), a[i] = buf;
	int tot = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) tot += a[i][j] == 'o';
	f[0] = pw[tot - 2];
	for (int i = 1; i <= tot - 2; i++) {
		if (i & 1) f[i] = (f[i - 1] - pw[tot - i - 2] + mod) % mod;
		else f[i] = (f[i - 1] + pw[tot - i - 2] + mod) % mod;
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != 'o') continue;
			int nj = j; while (nj < m && a[i][nj] == 'o') nj++;
			for (int k = j; k + 1 < nj; k++) {
				ans = (ans + f[k - j]) % mod;
			}
			j = nj - 1;
		}
	}
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (a[i][j] != 'o') continue;
			int ni = i; while (ni < n && a[ni][j] == 'o') ni++;
			for (int k = i; k + 1 < ni; k++) {
				ans = (ans + f[k - i]) % mod;
			}
			i = ni - 1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}