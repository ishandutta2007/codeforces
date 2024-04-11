#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
using namespace std;
typedef long long LL;
const int N = 3005;

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

int n, a[N], pre[N], lst[N], dp[N][N];

int DP(int l, int r) {
    if (l >= r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    int ret = min(DP(l, r - 1), DP(l + 1, r)) + 1;
    if (a[l] == a[r]) {
        ret = min(ret, DP(l + 1, r - 1) + 1);
    }
    for (int i = pre[r]; i > l; i = pre[i]) {
        if (a[l] == a[r]) {
            ret = min(ret, DP(l, i - 1) + DP(i + 1, r));
        } else {
            ret = min(ret, DP(l, i - 1) + DP(i, r) + 1);
        }
    }
    return dp[l][r] = ret;
}

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        lst[i] = 0;
    }
    int m = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] != a[m]) {
            a[++m] = a[i];
        }
    }
    n = m;
    for (int i = 1; i <= n; ++i) {
        pre[i] = lst[a[i]];
        lst[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = -1;
        }
    }
    printf("%d\n", DP(1, n));
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}