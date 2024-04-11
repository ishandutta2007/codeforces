#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int N = 405;

template <typename T> inline void read(T &WOW) {
	T x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	WOW = flag * x;
}

char s[N];
int n, m, a[N][N];
int sum[N][N], rowsum[N][N], colsum[N][N], mn[N];

void solve() {
	read(n); read(m);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s + 1);
		for (int j = 1; j <= m; ++j) {
			a[i][j] = (s[j] - '0');
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			sum[i][j] = (a[i][j] == 1) + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			rowsum[i][j] = (a[i][j] == 0) + rowsum[i][j - 1];
		}
	}
	for (int j = 1; j <= m; ++j) {
		for (int i = 1; i <= n; ++i) {
			colsum[i][j] = (a[i][j] == 0) + colsum[i - 1][j];
		}
	}
	int ans = n * m;
	for (int u = 1; u <= n - 4; ++u) {
		for (int d = u + 4; d <= n; ++d) {
			mn[m + 1] = n * m;
			for (int i = m; i >= 4; --i) {
				mn[i] = min(mn[i + 1], colsum[d - 1][i] - colsum[u][i] + rowsum[u][i - 1] + rowsum[d][i - 1] + sum[d - 1][i - 1] - sum[u][i - 1]);
			//printf("%d %d %d %d\n", u, d, i, mn[i]);
			}
			for (int i = 1; i <= m - 3; ++i) {
				ans = min(ans, mn[i + 3] + colsum[d - 1][i] - colsum[u][i] - rowsum[u][i] - rowsum[d][i] - sum[d - 1][i] + sum[u][i]);
			}
		}
	}
	printf("%d\n", ans);
}

int main() {
	int T; read(T);
	while (T--) {
		solve();
	}
	return 0;
}