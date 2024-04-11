#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 55
int n, h, m;
int f[N][N][N];
int pl[N], pr[N], ph[N], pc[N];
int s[N];

int main() {
	cin >> n >> h >> m;
	for (int i = 0; i < m; i ++) {
		cin >> pl[i] >> pr[i] >> ph[i] >> pc[i];
		pl[i] --;
	}
	for (int x = 1; x <= n; x ++)
		for (int l = 0; l <= n-x; l++) {
			int r = l+x;
			for (int c = l; c < r; c++) {
				memset(s, 0, sizeof s);
				for (int i = 0; i < m; i ++)
					if (l <= pl[i] && pr[i] <= r && pl[i] <= c && c < pr[i])
						s[ph[i]+1] += pc[i];
				for (int i = 0; i < h; i ++) s[i+1] += s[i];

				for (int p = 0; p <= h; p ++)
					for (int u = 0; u <= p; u ++) {
						f[l][r][p] = max(f[l][r][p], f[l][c][u] + f[c+1][r][u] + u*u - s[u]);
					}
			}
		}
	printf("%d\n", f[0][n][h]);
	return 0;
}