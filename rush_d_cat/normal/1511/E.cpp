#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 300000 + 10;
const int mod = 998244353;

LL f[N][2], g[N][2], pw[N];
int main() {
	pw[0] = 1;
	for (int i = 1; i < N; i ++) pw[i] = pw[i-1] * 2 % mod;

	g[1][0] = g[1][1] = 1;
	for (int i = 2; i < N; i ++) {
		f[i][0] = ((f[i-1][0] + f[i-1][1]) % mod + (f[i-1][1] + g[i-1][1]) % mod) % mod;
		f[i][1] = f[i-1][0];

		g[i][0] = (g[i-1][0] + g[i-1][1] + g[i-1][1]) % mod;
		g[i][1] = g[i-1][0];
	}

	int n, m;
	scanf("%d%d", &n, &m);
	char s[n+1][m+1];
	
	for (int i = 1; i <= n; i ++) {
		scanf("%s", s[i] + 1);
	}

	int c = 0;
	for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++)
		if (s[i][j] == 'o') c ++;

	LL ans = 0;
	for (int i = 1; i <= n; i ++) {
		for (int x = 1, y = 1; x <= m; x = y) {
			if (s[i][y] == '*') {
				y ++;
			} else {
				while (y <= m && s[i][y] == 'o') y ++;
				int cnt = y - x;
				ans += pw[c - cnt] * (f[cnt][0] + f[cnt][1]) % mod;
			}
		}
	}

	for (int j = 1; j <= m; j ++) {
		for (int x = 1, y = 1; x <= n; x = y) {
			if (s[y][j] == '*') {
				y ++;
			} else {
				while (y <= n && s[y][j] == 'o') y ++;
				int cnt = y - x;
				ans += pw[c - cnt] * (f[cnt][0] + f[cnt][1]) % mod;
			}
		}
	}
	ans %= mod;
	cout << ans << endl;
}