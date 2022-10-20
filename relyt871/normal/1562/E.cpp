#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define check(a) cout << a << endl;
#define CHECK cout << "wow" << endl;
using namespace std;
typedef long long LL;
const int N = 5005;

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

int n, lcp[N][N], dp[N][N], pre[N][N], suf[N][N], tmp[N];
char s[N];

void solve() {
	read(n);
	scanf("%s", s + 1);
	for (int i = 1; i <= n + 1; ++i) {
		for (int j = 1; j <= n + 1; ++j) {
			lcp[i][j] = 0;
		}
	}
	for (int i = n; i >= 1; --i) {
		for (int j = n; j >= 1; --j) {
			if (i == j) {
				lcp[i][j] = (n - i + 1);
				continue;
			}
			if (s[i] == s[j]) {
				lcp[i][j] = lcp[i + 1][j + 1] + 1;
			} else {
				lcp[i][j] = 0;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			dp[i][j] = 1;
			tmp[j] = 0;
		}
		int mxlcp = 0;
		for (int j = i - 1; j >= 1; --j) {
			int l = lcp[i][j];
			for (int k = mxlcp + 1; k <= l; ++k) {
				cmax(dp[i][i + k - 1], pre[j][j + k - 2] + 1);
			}
			cmax(mxlcp, l);
			if (i + l <= n && s[j + l] < s[i + l]) {
				cmax(tmp[i + l], suf[j][j + l]);
			}
		}
		tmp[i - 1] = 0;
		for (int j = i; j <= n; ++j) {
			cmax(tmp[j], tmp[j - 1]);
			cmax(dp[i][j], tmp[j] + 1);
		}
		for (int j = i + 1; j <= n; ++j) {
			cmax(dp[i][j], dp[i][j - 1] + 1);
		}
		pre[i][i - 1] = suf[i][n + 1] = 0;
		for (int j = i; j <= n; ++j) {
			pre[i][j] = max(pre[i][j - 1], dp[i][j]);
		}
		for (int j = n; j >= i; --j) {
			suf[i][j] = max(suf[i][j + 1], dp[i][j]);
		}
		ans = max(ans, pre[i][n]);
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