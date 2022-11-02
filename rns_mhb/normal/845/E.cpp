#include <bits/stdc++.h>
using namespace std;
#define f1(i, a, b) for (int i = a; i <= b; i ++)

const int inf = 0x3f3f3f3f;

#define N 505

struct pnt {
    int x, y;
    pnt (int x = 0, int y = 0) : x(x), y(y) {}
    void input() {
		scanf("%d %d", &x, &y);
    }
} p[N];

int n, m, k, qs;

struct data {
    int h, l, r, d;
    data (int h = 0, int l = 0, int r = 0, int d = 0) : h(h), l(l), r(r), d(d) {}
    bool operator < (const data &a) {return h < a.h;}
} q[N<<2];

#define M 50000
int tot;
int son[M][2], a[M], b[M];

int make_node(int v) {
    ++ tot;
    a[tot] = 0; b[tot] = v;
    son[tot][0] = son[tot][1] = 0;
    return tot;
}

void update(int l, int r, int d, int L, int R, int seg) {
    if (l <= L && R <= r) {
        a[seg] += d;
        if (a[seg]) b[seg] = 0;
        else {
            if (!son[seg][0]) b[seg] = R - L + 1;
            else b[seg] = b[son[seg][0]] + b[son[seg][1]];
        }
        return;
    }
    int mid = L + R >> 1;
    if (!son[seg][0]) son[seg][0] = make_node(mid - L + 1);
    if (!son[seg][1]) son[seg][1] = make_node(R - mid);
    if (l <= mid) update(l, r, d, L, mid, son[seg][0]);
    if (mid < r) update(l, r, d, mid + 1, R, son[seg][1]);
    b[seg] = a[seg] ? 0 : b[son[seg][0]] + b[son[seg][1]];
    return;
}

void init() {
    tot = 0;
    make_node(n);
    return;
}

int func(int d, int t) {
    if (d) {f1(i, 1, k) swap(p[i].x, p[i].y); swap(m, n);}
    qs = 0;
    f1(i, 1, k) {
    	q[qs ++] = data(max(1, p[i].x - t), max(1, p[i].y - t), min(p[i].y + t, m), 1);
        q[qs ++] = data(min(n + 1, p[i].x + t + 1), max(1, p[i].y - t), min(p[i].y + t, m), -1);
    }
    init();
    sort(q, q + qs);
    int res = 0;
    if (q[0].h != 1) res = 1;
    else for (int i = 0, j; i < qs && !res; ) {
        for (j = i; j < qs && q[j].h == q[i].h; j ++) update(q[j].l, q[j].r, q[j].d, 1, m, 1);
        if (q[i].h <= n && b[1]) {
			res = q[i].h;
        }
        i = j;
    }
    if (d) {f1(i, 1, k) swap(p[i].x, p[i].y); swap(m, n);}
    return res;
}

bool check(int t) {
    int x = func(0, t);
    int y = func(1, t);
    p[++ k] = pnt(x + t, y + t);
    int f = func(0, t);
    -- k;
    if (f) return 0;
    return 1;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    f1(i, 1, k) p[i].input();
    int st = -1, en = inf;
    while (en - st > 1) {
		int mid = en + st >> 1;
		if (check(mid)) en = mid;
		else st = mid;
    }
    printf("%d\n", en);
	return 0;
}