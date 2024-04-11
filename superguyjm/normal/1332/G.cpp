#include <bits/stdc++.h>

#define I inline
#define fi first
#define se second
#define LL long long
#define mp make_pair
#define reg register int
#define pii pair<int,int>
#define fo(i, a, b) for(reg i = a; i <= b; i++)
#define fd(i, a, b) for(reg i = a; i >= b; i--)
#define cr const reg&
using namespace std;
const int N = 2e5 + 1;

I int _max(cr x, cr y) {return x > y ? x : y;}
I int _min(cr x, cr y) {return x < y ? x : y;}
I int read() {
	reg x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
	return x * f;
}
I void ptt(LL x) {if(x >= 10) ptt(x / 10); putchar(x % 10 + '0');}
I void put(LL x) {x < 0 ? putchar('-'), ptt(-x) : ptt(x);}
I void pr1(LL x) {put(x), putchar(' ');}
I void pr2(LL x) {put(x), puts("");}

struct tnode {
	int cnt, lc[N << 1], rc[N << 1], c[N << 1];
	
	void bt(cr l, cr r) {
		reg u = ++cnt;
		lc[u] = rc[u] = -1;
		if(l < r) {
			reg mid = l + r >> 1;
			lc[u] = cnt + 1, bt(l, mid);
			rc[u] = cnt + 1, bt(mid + 1, r);
		} c[u] = 999999999;
	}
	
	void cg(cr u, cr l, cr r, cr p, cr s) {
		if(l == r) {c[u] = s; return ;}
		reg mid = l + r >> 1;
		if(p <= mid) cg(lc[u], l, mid, p, s);
		else cg(rc[u], mid + 1, r, p, s);
		c[u] = _min(c[lc[u]], c[rc[u]]);
	}
	
	I int findl(cr u, cr l, cr r, cr p, cr s) {
		if(l > p) return 0;
		if(c[u] > s) return 0;
		if(l == r) return l;
		reg mid = l + r >> 1;
		reg c = findl(rc[u], mid + 1, r, p, s);
		if(c) return c;
		return findl(lc[u], l, mid, p, s);
	}
} t;
struct g1 {int a, b, c;};
vector<g1> z[N];
vector<pii> g[N], qq[N];
vector<int> ans[N];
struct node {int c, id;} a[N];
int tp, L[N], R[N], fa[N], sta[N];
int d[4], h[3];

I int findfa(cr x) {return fa[x] == x ? x : fa[x] = findfa(fa[x]);}

I bool cmp1(const node &a, const node &b) {return a.c == b.c ? a.id < b.id : a.c < b.c;}
I bool cmp2(const node &a, const node &b) {return a.c == b.c ? a.id < b.id : a.c > b.c;}

int main() {
	reg n = read(), q = read();
	fo(i, 1, n) a[i].c = read(), a[i].id = i;
	fo(i, 1, q) {
		reg l = read(), r = read();
		qq[r].push_back(pii{l, i});
	} sta[0] = n + 1; fd(i, n, 1) {
		while(tp && a[i].c >= a[sta[tp]].c) tp--;
		L[i] = sta[tp], sta[++tp] = i;
	} tp = 0; fd(i, n, 1) {
		while(tp && a[i].c <= a[sta[tp]].c) tp--;
		R[i] = sta[tp], sta[++tp] = i;
	} sta[tp = 0] = 0; fo(i, 1, n) {
		while(tp && a[i].c >= a[sta[tp]].c) tp--;
		if(sta[tp] && L[i] <= n) g[L[i]].push_back(pii{sta[tp], i});
		sta[++tp] = i;
	} sta[tp = 0] = 0; fo(i, 1, n) {
		while(tp && a[i].c <= a[sta[tp]].c) tp--;
		if(sta[tp] && R[i] <= n) g[R[i]].push_back(pii{sta[tp], i});
		sta[++tp] = i;
	} sort(a + 1, a + n + 1, cmp1);
	fo(i, 1, n) fa[i] = i;
	t.cnt = 0, t.bt(1, n);
	fo(i, 1, n) {
		reg x = a[i].id;
		reg fx = findfa(x - 1); fa[x] = fx;
		t.cg(1, 1, n, x, R[x]);
		if(!fx) continue;
		reg p = t.findl(1, 1, n, fx, x);
		reg u = R[p], v = fx;
		if(u > v) swap(u, v);
		if(p) z[x].push_back(g1{p, u, v});
	} sort(a + 1, a + n + 1, cmp2);
	fo(i, 1, n) fa[i] = i;
	t.cnt = 0, t.bt(1, n);
	fo(i, 1, n) {
		reg x = a[i].id;
		reg fx = findfa(x - 1); fa[x] = fx;
		t.cg(1, 1, n, x, L[x]);
		if(!fx) continue;
		reg p = t.findl(1, 1, n, fx, x);
		reg u = L[p], v = fx;
		if(u > v) swap(u, v);
		if(p) z[x].push_back(g1{p, u, v});
	} fo(i, 1, n) {
		fo(j, 0, (int)z[i].size() - 1) {
			if(z[i][j].a > d[0]) d[0] = z[i][j].a, d[1] = z[i][j].b, d[2] = z[i][j].c, d[3] = i;
		} fo(j, 0, (int)g[i].size() - 1) {
			if(g[i][j].fi > h[0]) h[0] = g[i][j].fi, h[1] = g[i][j].se, h[2] = i;
		} fo(j, 0, (int)qq[i].size() - 1) {
			reg id = qq[i][j].se;
			if(qq[i][j].fi <= d[0]) {
				fo(k, 0, 3) ans[id].push_back(d[k]);
			} else if(qq[i][j].fi <= h[0]) {
				fo(k, 0, 2) ans[id].push_back(h[k]);
			}
		}
	} fo(i, 1, q) {
		reg len = (int)ans[i].size();
		pr2(len);
		fo(j, 0, len - 1) pr1(ans[i][j]); puts("");
	} return 0;
}