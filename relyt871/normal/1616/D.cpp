#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 500005;

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

int n, dp[MAXN], q[MAXN], head, tail;
LL a[MAXN], x;

set<LL> S;

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    read(x);
    dp[0] = 0;
    q[head = tail = 1] = 0;
    int lim = -1;
    for (int i = 1; i <= n; ++i) {
        if (i > 2 && a[i] + a[i - 1] + a[i - 2] < x * 3) {
            lim = max(lim, i - 3);
        }
        if (i > 1 && a[i] + a[i - 1] < x * 2) {
            lim = max(lim, i - 2);
        }
        dp[i] = dp[i - 1];
        if (lim == -1) {
            dp[i] = max(dp[i], i);
        }
        while (head <= tail && q[head] < lim) {
            ++head;
        }
        if (q[head] <= i - 2) {
            int j = q[head];
            dp[i] = max(dp[i], dp[j] + i - j - 1);
        }
        while (head <= tail && dp[i] - i >= dp[q[tail]] - q[tail]) {
            --tail;
        }
        q[++tail] = i;
    }
    printf("%d\n", dp[n]);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}