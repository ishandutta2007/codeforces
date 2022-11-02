#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ppb pop_back
#define x first
#define y second
#define bitclz __builtin_clz
#define f1(i, a, b) for (int i = a; i <= b; i ++)
#define f3(i, a, b) for (int i = a; i >= b; i --)
template <class T> void chkmin(T &a, T b) {if (a > b) a = b;}

typedef pair <int, int> pii;
typedef vector <int> vi;

#define N 200005

int n, m, tot;

struct edge {
    int x, y, d, t;
    edge() {}
    edge(int x, int y, int d, int t) : x(x), y(y), d(d), t(t) {}
} ed[N<<2];

map <pii, int> h;
map <pii, int> :: iterator it;
vector <pii> A;
vi v[N<<2];
int rt[N], d[N], st[N], fs[N], val[N], a[N], b[30];

void add_edge(int x, int y, int d, int t) {
    ++ tot;
    h[pii(x, y)] = tot;
    ed[tot] = edge(x, y, d, t);
    return;
}

pii find_rt(int x) {
    if (rt[x] == x) return pii(x, 0);
    pii res = find_rt(rt[x]);
    return pii(res.x, res.y ^ a[x]);
}

int func3(int k) {
    f3(i, 29, 0) chkmin(k, k ^ b[i]);
    return k;
}

void func2(int k) {
    int x, y, d, rx, ry, dx, dy;
    pii sbg;
    for (auto rpt : v[k]) {
        x = ed[rpt].x, y = ed[rpt].y, d = ed[rpt].d;
        sbg = find_rt(x);
        rx = sbg.x, dx = sbg.y;
        sbg = find_rt(y);
        ry = sbg.x, dy = sbg.y;
        if (rx == ry) {
            d ^= dx ^ dy;
            d = func3(d);
            if (d) {
                x = 31 - bitclz(d);
                A.pb(pii(0, x));
                b[x] = d;
            }
        }
        else {
            if (val[rx] > val[ry]) swap(rx, ry), swap(x, y);
            if (val[rx] == val[ry]) {
				A.pb(pii(1, rx));
                val[ry] ++;
            }
            else A.pb(pii(2, rx));
            rt[rx] = ry;
            a[rx] = dx ^ d ^ dy;
        }
    }
}

void func(int L, int R, int seg) {
    int x = A.size();
    func2(seg);
    pii rpt;
    if (L == R) {
        if (st[L]) printf("%d\n", func3(find_rt(st[L]).y ^ find_rt(fs[L]).y));
    }
    else {
        int mid = L + R >> 1;
        func(L, mid, seg << 1);
        func(mid + 1, R, seg << 1 | 1);
    }
    while (A.size() > x) {
        rpt = A.back();
        if (!rpt.x) b[rpt.y] = 0;
        else {
			if (rpt.x & 1) val[rt[rpt.y]] --;
			rt[rpt.y] = rpt.y;
			a[rpt.y] = 0;
        }
        A.ppb();
    }
	return;
}

void update(int l, int r, int id, int L, int R, int seg) {
    if (l <= L && R <= r) {
        v[seg].pb(id);
        return;
    }
    int mid = L + R >> 1;
    if (l <= mid) update(l, r, id, L, mid, seg << 1);
	if (mid < r) update(l, r, id, mid + 1, R, seg << 1 | 1);
	return;
}

int main() {
    scanf("%d %d", &n, &m);
    f1(i, 1, n) rt[i] = i;
    int x, y, d;
    f1(i, 1, m) {
        scanf("%d %d %d", &x, &y, &d);
        add_edge(x, y, d, 1);
    }
    scanf("%d", &n);
    int type;
    f1(i, 1, n) {
        scanf("%d", &type);
        if (type == 1) {
			scanf("%d %d %d", &x, &y, &d);
			add_edge(x, y, d, i);
        }
        else if (type == 2) {
            scanf("%d %d", &x, &y);
            it = h.find(pii(x, y));
            h.erase(it);
            if (ed[it->y].t >= i) continue;
            update(ed[it->y].t, i-1, it->y, 1, n, 1);
        }
        else {
            scanf("%d %d", &x, &y);
            st[i] = x, fs[i] = y;
        }
    }
    for (auto x : h) {
		update(ed[x.y].t, n, x.y, 1, n, 1);
    }
    func(1, n, 1);
	return 0;
}