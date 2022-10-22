#include <bits/stdc++.h>

#define LL long long
#define pii pair<int,int>
using namespace std;
const int inf = 2147483647;
const int N = 200001;

int _max(int x, int y) {return x > y ? x : y;}
int _min(int x, int y) {return x < y ? x : y;}
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x * f;
}
void put(LL x) {
	if(x < 0) putchar('-'), x = -x;
	if(x >= 10) put(x / 10);
	putchar(x % 10 + '0');
}

struct node {int x, y;} a[N];
struct LCT {
	int fa[N], son[N][2], rev[N];
	int tp, sta[N];
	
	bool Son(int x) {return son[fa[x]][1] == x;}
	bool isroot(int x) {return son[fa[x]][0] != x && son[fa[x]][1] != x;}
	void reve(int x) {rev[x] ^= 1, swap(son[x][0], son[x][1]);}
	void pushdown(int x) {if(!rev[x]) return ; reve(son[x][0]), reve(son[x][1]), rev[x] = 0;}
	
	void rot(int x) {
		int y = fa[x], z = fa[y], c = Son(x);
		if(!isroot(y)) son[z][Son(y)] = x; fa[x] = z;
		son[y][c] = son[x][!c]; if(son[y][c]) fa[son[y][c]] = y;
		son[x][!c] = y, fa[y] = x;
	}
	void splay(int x) {
		int i = x;
		while(!isroot(i)) sta[++tp] = i, i = fa[i]; sta[++tp] = i;
		while(tp) pushdown(sta[tp--]);
		for(int y = fa[x]; !isroot(x); rot(x), y = fa[x]) {
			if(!isroot(y)) Son(x) ^ Son(y) ? rot(x) : rot(y);
		}
	}
	
	void access(int x) {
	for(int y = 0; x; y = x, x = fa[x]) splay(x), son[x][1] = y;}
	void makeroot(int x) {access(x), splay(x), reve(x);}
	int findroot(int x) {
		access(x), splay(x);
		while(1) {
			pushdown(x);
			if(!son[x][0]) break;
			x = son[x][0];
		} return x;
	} bool check(int x, int y) {
		int fx = findroot(x), fy = findroot(y);
		return fx == fy;
	} bool Link(int x, int y) {if(check(x, y)) return 1; makeroot(x), fa[x] = y; return 0;}
	void Cut(int x, int y) {if(!check(x, y)) return ; makeroot(x), access(y), splay(y); son[y][0] = fa[x] = 0;}
} t; int S[N];
struct tnode {
	int cnt, lc[N << 1], rc[N << 1], c[N << 1], s[N << 1], lazy[N << 1];
	
	void pushup(int now) {
		c[now] = _min(c[lc[now]], c[rc[now]]);
		if(c[lc[now]] == c[rc[now]]) s[now] = s[lc[now]] + s[rc[now]];
		else if(c[lc[now]] < c[rc[now]]) s[now] = s[lc[now]];
		else s[now] = s[rc[now]];
	}
	
	void bt(int l, int r) {
		int now = ++cnt;
		lc[now] = rc[now] = -1;
		if(l == r) c[now] = l - S[l], s[now] = 1;
		else {
			int mid = (l + r) / 2;
			lc[now] = cnt + 1; bt(l, mid);
			rc[now] = cnt + 1; bt(mid + 1, r);
			pushup(now);
		}
	}
	void pushdown(int now) {
		if(lazy[now]) {
			c[lc[now]] += lazy[now];
			c[rc[now]] += lazy[now];
			lazy[lc[now]] += lazy[now];
			lazy[rc[now]] += lazy[now];
			lazy[now] = 0;
		}
	}
	
	void change(int now, int l, int r, int ll, int rr) {
		if(l == ll && r == rr) {c[now]++, lazy[now]++; return ;}
		pushdown(now);
		int mid = (l + r) / 2;
		if(rr <= mid) change(lc[now], l, mid, ll, rr);
		else if(ll > mid) change(rc[now], mid + 1, r, ll, rr);
		else change(lc[now], l, mid, ll, mid), change(rc[now], mid + 1, r, mid + 1, rr);
		pushup(now);
	}
	
	int query(int now, int l, int r, int ll, int rr) {
		if(l == ll && r == rr) return c[now] == 1 ? s[now] : 0;
		pushdown(now);
		int mid = (l + r) / 2;
		if(rr <= mid) return query(lc[now], l, mid, ll, rr);
		else if(ll > mid) return query(rc[now], mid + 1, r, ll, rr);
		else return query(lc[now], l, mid, ll, mid) + query(rc[now], mid + 1, r, mid + 1, rr);
	}
} tt;
int n, m, p[N];
int zz, te[N];

int getid(int x, int y) {return (x - 1) * m + y;}

bool gao(int l, int r, int x, int y, int c) {
	int o = -1; bool ch = 0; zz = 0;
	if(x > 1) o = p[getid(x - 1, y)];
	if(o >= l && o <= r) ch |= t.Link(o, c), te[++zz] = o; o = -1;
	if(y > 1) o = p[getid(x, y - 1)];
	if(o >= l && o <= r) ch |= t.Link(o, c), te[++zz] = o; o = -1;
	if(x < n) o = p[getid(x + 1, y)];
	if(o >= l && o <= r) ch |= t.Link(o, c), te[++zz] = o; o = -1;
	if(y < m) o = p[getid(x, y + 1)];
	if(o >= l && o <= r) ch |= t.Link(o, c), te[++zz] = o; o = -1;
	if(ch) for(int i = 1; i <= zz; i++) t.Cut(c, te[i]);
	return ch;
}

void del(int l, int r, int x, int y, int c) {
	int o = -1;
	if(x > 1) o = p[getid(x - 1, y)];
	if(o >= l && o <= r) t.Cut(c, o);
	if(o > c) tt.change(1, 1, n * m, o, n *m); o = -1;
	if(y > 1) o = p[getid(x, y - 1)];
	if(o >= l && o <= r) t.Cut(c, o);
	if(o > c) tt.change(1, 1, n * m, o, n * m); o = -1;
	if(x < n) o = p[getid(x + 1, y)];
	if(o >= l && o <= r) t.Cut(c, o);
	if(o > c) tt.change(1, 1, n * m, o, n * m); o = -1;
	if(y < m) o = p[getid(x, y + 1)];
	if(o >= l && o <= r) t.Cut(c, o);
	if(o > c) tt.change(1, 1, n * m, o, n * m); o = -1;
}

int gg(int x, int y, int c) {
	int o = -1, ans = 0;
	if(x > 1) o = p[getid(x - 1, y)];
	if(o != -1 && o <= c) ans++; o = -1;
	if(y > 1) o = p[getid(x, y - 1)];
	if(o != -1 && o <= c) ans++; o = -1;
	if(x < n) o = p[getid(x + 1, y)];
	if(o != -1 && o <= c) ans++; o = -1;
	if(y < m) o = p[getid(x, y + 1)];
	if(o != -1 && o <= c) ans++; o = -1;
	return ans;
}

int main() {
	n = read(), m = read();
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) {
		int x = read();
		p[getid(i, j)] = x, a[x] = node{i, j};
	} int tp = 1; LL ans = 0;
	for(int i = 1; i <= n * m; i++) S[i] = S[i - 1] + gg(a[i].x, a[i].y, i);
	tt.bt(1, n * m);
	for(int i = 1; i <= n * m; i++) {
		tp = _max(tp, i);
		while(tp < n * m && !gao(i, tp + 1, a[tp + 1].x, a[tp + 1].y, tp + 1)) 
		tp++;
		ans += tt.query(1, 1, n * m, i, tp);
		del(i, tp, a[i].x, a[i].y, i);
		tt.lazy[1]--, tt.c[1]--;
	} put(ans), puts("");
	return 0;
}