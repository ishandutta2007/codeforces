#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1000005;

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

int n, m, g, a[MAXN];
LL dp[MAXN][2];

void solve() {
    read(n); read(m);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    g = 0;
    for (int i = 1, b; i <= m; ++i) {
        read(b);
        g = __gcd(g, b);
    }
    for (int i = 1; i <= n; ++i) {
        if (i <= g) {
            dp[i][0] = a[i];
            dp[i][1] = -a[i];
        } else {
            dp[i][0] = max(dp[i - g][0] + a[i], dp[i - g][1] - a[i]);
            dp[i][1] = max(dp[i - g][0] - a[i], dp[i - g][1] + a[i]);
        }
    }
    LL ans1 = 0, ans2 = 0;
    for (int i = 0; i < g; ++i) {
        ans1 += dp[n - i][0];
        ans2 += dp[n - i][1];
    }
    printf("%lld\n", max(ans1, ans2));
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}