#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int N = 505;
const int INF = 0x3f3f3f3f;

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

int n, l, k;
int d[N], lim[N];
int dp[2][N][N];

void solve() {
    read(n); read(l); read(k);
    for (int i = 1; i <= n; ++i) {
        read(d[i]);
    }
    d[n + 1] = l;
    for (int i = 1; i <= n; ++i) {
        read(lim[i]);
    }
    mset(dp, 0x3f);
    dp[0][0][1] = d[2] * lim[1];
    int pre = 0, cur = 1;
    for (int i = 2; i <= n; ++i) {
        mset(dp[cur], 0x3f);
        int dis = d[i + 1] - d[i];
        for (int j = 0; j <= k; ++j) {
            int mn = INF;
            for (int t = 1; t < i; ++t) {
                dp[cur][j + 1][t] = min(INF, dp[pre][j][t] + lim[t] * dis);
                mn = min(mn, dp[pre][j][t]);
            }
            dp[cur][j][i] = min(INF, mn + lim[i] * dis);
        }
        swap(pre, cur);
    }
    int ans = INF;
    for (int j = 0; j <= k; ++j) {
        for (int t = 1; t <= n; ++t) {
            ans = min(ans, dp[pre][j][t]);
        }
    }
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}