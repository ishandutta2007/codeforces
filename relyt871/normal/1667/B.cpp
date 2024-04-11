#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define lc (rt << 1)
#define rc (rt << 1) | 1
using namespace std;
typedef long long LL;
const int MAXN = 500005;
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

int n, m;
LL a[MAXN], b[MAXN];

struct SegmentTree {
    int mx0[MAXN << 2], mx1[MAXN << 2], mx2[MAXN << 2];

    void Build(int rt, int b, int e) {
        mx0[rt] = mx1[rt] = mx2[rt] = -INF;
        if (b == e) return;
        int mid = (b + e) >> 1;
        Build(lc, b, mid);
        Build(rc, mid + 1, e);
    }

    void Update(int rt, int b, int e, int pos, int v0, int v1, int v2) {
        if (b == e) {
            mx0[rt] = max(mx0[rt], v0);
            mx1[rt] = max(mx1[rt], v1);
            mx2[rt] = max(mx2[rt], v2);
            return;
        }
        int mid = (b + e) >> 1;
        if (pos <= mid) Update(lc, b, mid, pos, v0, v1, v2);
        else Update(rc, mid + 1, e, pos, v0, v1, v2);
        mx0[rt] = max(mx0[lc], mx0[rc]);
        mx1[rt] = max(mx1[lc], mx1[rc]);
        mx2[rt] = max(mx2[lc], mx2[rc]);
    }

    int Query(int rt, int b, int e, int l, int r, int type) {
        if (l <= b && e <= r) {
            if (type == 0) return mx0[rt];
            if (type == 1) return mx1[rt];
            if (type == 2) return mx2[rt];
        }
        int mid = (b + e) >> 1;
        if (r <= mid) return Query(lc, b, mid, l, r, type);
        if (l > mid) return Query(rc, mid + 1, e, l, r, type);
        return max(Query(lc, b, mid, l, r, type), Query(rc, mid + 1, e, l, r, type));
    }
} SEG;

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        a[i] += a[i - 1];
        b[i] = a[i];
    }
    b[m = n + 1] = 0;
    sort(b + 1, b + m + 1);
    m = unique(b + 1, b + m + 1) - (b + 1);
    SEG.Build(1, 1, m);

    int p = lower_bound(b + 1, b + m + 1, 0) - b;
    SEG.Update(1, 1, m, p, 0, 0, 0);
    for (int i = 1; i <= n; ++i) {
        p = lower_bound(b + 1, b + m + 1, a[i]) - b;
        int cur = SEG.Query(1, 1, m, p, p, 0);
        if (p > 1) {
            cur = max(cur, SEG.Query(1, 1, m, 1, p - 1, 1) + i);
        }
        if (p < m) {
            cur = max(cur, SEG.Query(1, 1, m, p + 1, m, 2) - i);
        }
        if (i == n) {
            printf("%d\n", cur);
            return;
        } else {
            SEG.Update(1, 1, m, p, cur, cur - i, cur + i);
        }
    }
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}