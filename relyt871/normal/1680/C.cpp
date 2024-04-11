#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
#define lc (rt << 1)
#define rc (rt << 1) | 1
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

char s[MAXN];
int n, pre[2][MAXN], suf[2][MAXN];

struct SegmentTree {
    int val[2][MAXN << 2];

    void Build(int rt, int b, int e) {
        if (b == e) {
            val[0][rt] = pre[0][b];
            val[1][rt] = pre[1][b];
            return;
        }
        int mid = (b + e) >> 1;
        Build(lc, b, mid);
        Build(rc, mid + 1, e);
        val[0][rt] = max(val[0][lc], val[0][rc]);
        val[1][rt] = min(val[1][lc], val[1][rc]);
    }

    int Query0(int rt, int b, int e, int l, int r) {
        if (l <= b && e <= r) return val[0][rt];
        int mid = (b + e) >> 1;
        if (r <= mid) return Query0(lc, b, mid, l, r);
        if (l > mid) return Query0(rc, mid + 1, e, l, r);
        return max(Query0(lc, b, mid, l, r), Query0(rc, mid + 1, e, l, r));
    }

    int Query1(int rt, int b, int e, int l, int r) {
        if (l <= b && e <= r) return val[1][rt];
        int mid = (b + e) >> 1;
        if (r <= mid) return Query1(lc, b, mid, l, r);
        if (l > mid) return Query1(rc, mid + 1, e, l, r);
        return min(Query1(lc, b, mid, l, r), Query1(rc, mid + 1, e, l, r));
    }
} seg;

void solve() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; ++i) {
        pre[0][i] = pre[0][i - 1] + (s[i] == '0');
        pre[1][i] = pre[1][i - 1] + (s[i] == '1');
    }
    suf[0][n + 1] = suf[1][n + 1] = 0;
    for (int i = n; i >= 1; --i) {
        suf[0][i] = suf[0][i + 1] + (s[i] == '0');
        suf[1][i] = suf[1][i + 1] + (s[i] == '1');
    }
    seg.Build(1, 1, n);

    int lim = n + 1 - pre[0][n];
    int ans = min(pre[0][n], pre[1][n]);
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, max(pre[1][i], suf[0][i + 1]));
        ans = min(ans, max(suf[1][i], pre[0][i - 1]));
    }
    for (int i = 3; i <= n; ++i) {
        if (i - 1 <= lim) {
            ans = min(ans, suf[1][i] + seg.Query1(1, 1, n, 1, i - 1));
        } else {
            ans = min(ans, suf[1][i] + seg.Query1(1, 1, n, i - lim, i - 1));
            ans = min(ans, pre[0][n] - suf[0][i] - seg.Query0(1, 1, n, 1, i - lim - 1));
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