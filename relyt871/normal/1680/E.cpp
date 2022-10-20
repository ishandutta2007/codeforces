#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int MAXN = 200005;

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

char s[2][MAXN];
int n, f[MAXN][2], g[MAXN][2];

void solve() {
    read(n);
    int l = n + 1, r = -1;
    for (int i = 0; i < 2; ++i) {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= n; ++j) {
            if (s[i][j] == '*') {
                l = min(l, j);
                r = max(r, j);
            }
        }
    }
    f[l - 1][0] = f[l - 1][1] = 0;
    for (int i = l; i <= r; ++i) {
        f[i][0] = min(f[i - 1][1] + 2, f[i - 1][0] + 1 + (s[1][i] == '*'));
        f[i][1] = min(f[i - 1][0] + 2, f[i - 1][1] + 1 + (s[0][i] == '*'));
    }
    g[r + 1][0] = g[r + 1][1] = 0;
    for (int i = r; i >= l; --i) {
        g[i][0] = min(g[i + 1][1] + 2, g[i + 1][0] + 1 + (s[1][i] == '*'));
        g[i][1] = min(g[i + 1][0] + 2, g[i + 1][1] + 1 + (s[0][i] == '*'));
    }
    int ans = 1e9;
    for (int t = 0; t < 2; ++t) {
        for (int i = l; i <= r; ++i) {
            ans = min(ans, f[i - 1][t] + g[i + 1][t] + (s[t ^ 1][i] == '*'));
            ans = min(ans, f[i - 1][t] + g[i + 1][t ^ 1] + 1);
            ans = min(ans, f[i - 1][t ^ 1] + g[i + 1][t] + 1);
            ans = min(ans, f[i - 1][t ^ 1] + g[i + 1][t ^ 1] + 1);
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