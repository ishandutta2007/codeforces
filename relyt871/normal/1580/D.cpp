#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int N = 4005;
const LL INF = 0x3f3f3f3f3f3f3f3f;

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

template <typename T> inline void cmax(T &x, T y) {
	if (x < y) x = y;
}

int n, m, siz[N];
LL a[N], dp[N][N];

int DP(int l, int r) {
	if (l > r) return 0;
	if (l == r) {
		siz[l] = 1;
		dp[l][0] = 0;
		dp[l][1] = a[l] * (m - 1);
		return l;
	}
	int u = l;
	for (int i = l + 1; i <= r; ++i) {
		if (a[i] < a[u]) u = i;
	}
	int v1 = DP(l, u - 1), v2 = DP(u + 1, r);
	siz[u] = min(m, r - l + 1);
	for (int i = 0; i <= siz[u]; ++i) {
		dp[u][i] = -INF;
	}
	for (int i = 0; i <= siz[v1]; ++i) {
		for (int j = 0; j <= siz[v2] && i + j <= siz[u]; ++j) {
			cmax(dp[u][i + j], dp[v1][i] + dp[v2][j] - a[u] * 2 * i * j);
			if (i + j + 1 <= siz[u]) {
				cmax(dp[u][i + j + 1], dp[v1][i] + dp[v2][j] - a[u] * (2 * (i * j + i + j) - (m - 1)));
			}
		}
	}
	return u;
}

void solve() {
	read(n); read(m);
	for (int i = 1; i <= n; ++i) {
		read(a[i]);
	}
	int rt = DP(1, n);
	printf("%lld\n", dp[rt][m]);
}

int main() {
	solve();
	return 0;
}