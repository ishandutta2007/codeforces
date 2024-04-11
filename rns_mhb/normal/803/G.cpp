#include <bits/stdc++.h>
using namespace std;
#define f1(i, a, b) for (int i = a; i <= b; i ++)
template <class T> void chkmin(T &a, T b) {if (a > b) a = b;}

const int inf = 0x3f3f3f3f;

#define N 100005
#define M 6000005

int n, tot, k, b[N], q;
int mn[N][17];
int son[M][2], val[M], op[M];

int find_min(int l, int r) {
    int len = r - l + 1;
    int k = 31 - __builtin_clz(len);
    return min(mn[l][k], mn[r-(1<<k) + 1][k]);
}

int get(int l, int r) {
    if (r - l + 1 >= n) return find_min(1, n);
    int lx = (l - 1) / n, rx = (r - 1) / n;
    if (lx == rx) return find_min(l - lx * n, r - rx * n);
    return min(find_min(l - lx * n, n), find_min(1, r - rx * n));
}

int make_node(int l, int r) {
    ++ tot; op[tot] = 0;
    son[tot][0] = son[tot][1] = 0;
    val[tot] = get(l, r);
    return tot;
}

void func(int seg, int v) {
    val[seg] = v; op[seg] = v;
    return;
}

void push_down(int seg, int l, int r) {
    int mid = l + r >> 1;
    if (!son[seg][0]) son[seg][0] = make_node(l, mid);
    if (!son[seg][1]) son[seg][1] = make_node(mid + 1, r);
    if (op[seg]) {
        func(son[seg][0], op[seg]);
        func(son[seg][1], op[seg]);
        op[seg] = 0;
    }
    return;
}

void push_up(int seg) {
    val[seg] = min(val[son[seg][0]], val[son[seg][1]]);
    return;
}

void update(int l, int r, int v, int L, int R, int seg) {
    if (l <= L && R <= r) {
		func(seg, v);
		return;
    }
    push_down(seg, L, R);
    int mid = L + R >> 1;
    if (l <= mid) update(l, r, v, L, mid, son[seg][0]);
    if (mid < r) update(l, r, v, mid + 1, R, son[seg][1]);
    push_up(seg);
	return;
}

int query(int l, int r, int L, int R, int seg) {
	if (l <= L && R <= r) return val[seg];
    push_down(seg, L, R);
    int mid = L + R >> 1;
    int ans = inf;
    if (l <= mid) chkmin(ans, query(l, r, L, mid, son[seg][0]));
    if (mid < r) chkmin(ans, query(l, r, mid + 1, R, son[seg][1]));
    return ans;
}

int main() {
    scanf("%d %d", &n, &k);
    f1(i, 1, n) scanf("%d", &b[i]);
    f1(i, 1, n) mn[i][0] = b[i];
    int m = 31 - __builtin_clz(n);
    f1(i, 1, m) {
        int up = n - (1 << i) + 1;
        f1(j, 1, up) mn[j][i] = min(mn[j][i-1], mn[j+(1<<i-1)][i-1]);
    }
    scanf("%d", &q);
    int len = n * k;
    int type, l, r, x;
    make_node(1, len);
    while (q --) {
        scanf("%d %d %d", &type, &l, &r);
        if (type == 1) {
			scanf("%d", &x);
			update(l, r, x, 1, len, 1);
        }
        else {
			x = query(l, r, 1, len, 1);
			printf("%d\n", x);
        }
	}
	return 0;
}