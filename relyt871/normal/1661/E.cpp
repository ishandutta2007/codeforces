#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define lc (rt << 1)
#define rc (rt << 1) | 1
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

char s[MAXN];
int n, q, g[3][MAXN], id[3][MAXN], ID;
int ufs[MAXN * 3];

int getf(int x) {
    return (ufs[x] == x)? x : ufs[x] = getf(ufs[x]);
}

struct Node {
    int ans, f[6];
    Node() {}
    Node(int i, int a, int b, int c) {
        ans = a + b + c - (a & b) - (b & c);
        f[0] = f[3] = id[0][i];
        f[1] = f[4] = ((a & b)? f[0] : id[1][i]);
        f[2] = f[5] = ((b & c)? f[1] : id[2][i]);
    }
} seg[MAXN << 2];

Node Merge(int m, const Node &a, const Node &b) {
    Node ret;
    ret.ans = a.ans + b.ans;
    for (int i = 0; i < 6; ++i) {
        ufs[a.f[i]] = a.f[i];
        ufs[b.f[i]] = b.f[i];
    }
    for (int i = 0; i < 3; ++i) {
        if (g[i][m] && g[i][m + 1]) {
            int u = getf(a.f[3 + i]), v = getf(b.f[i]);
            if (u != v) {
                --ret.ans;
                ufs[u] = v;
            }
        }
    }
    for (int i = 0; i < 3; ++i) {
        ret.f[i] = getf(a.f[i]);
        ret.f[3 + i] = getf(b.f[3 + i]);
    }
    return ret;
}

void Build(int rt, int b, int e) {
    if (b == e) {
        seg[rt] = Node(b, g[0][b], g[1][b], g[2][b]);
        return;
    }
    int mid = (b + e) >> 1;
    Build(lc, b, mid);
    Build(rc, mid + 1, e);
    seg[rt] = Merge(mid, seg[lc], seg[rc]);
}

Node Query(int rt, int b, int e, int l, int r) {
    if (l <= b && e <= r) return seg[rt];
    int mid = (b + e) >> 1;
    if (r <= mid) return Query(lc, b, mid, l, r);
    if (l > mid) return Query(rc, mid + 1, e, l, r);
    return Merge(mid, Query(lc, b, mid, l, r), Query(rc, mid + 1, e, l, r));
}

void solve() {
    read(n);
    for (int i = 0; i < 3; ++i) {
        scanf("%s", s + 1);
        for (int j = 1; j <= n; ++j) {
            g[i][j] = s[j] - '0';
            id[i][j] = ++ID;
        }
    }
    Build(1, 1, n);
    read(q);
    while (q--) {
        int l, r;
        read(l); read(r);
        printf("%d\n", Query(1, 1, n, l, r).ans);
    }
}

int main() {
    solve();
    return 0;
}