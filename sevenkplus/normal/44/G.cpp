#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;
const int N = 100005;
template<class T> inline void checkmin(T &a, const T &b)
{if (b < a) a = b;}
struct Tnode;
struct Trect;
typedef Tnode *Tlink;
struct Tnode {
	Tlink lch, rch;
	int key, val, minval, rp;
	bool del;
} nodebuf[N * 30];
Tlink null, root[N << 2];
int X[N], ans[N];
int cnodebuf;
int n, m;
struct Trect {
	int x1, x2, y1, y2, z, pid;
	void read()
	{scanf("%d%d%d%d%d", &x1, &x2, &y1, &y2, &z);}
} rect[N];
struct Tpoint {
	int x, y;
} pt[N];
struct cmp_rect {
	bool operator()(const Trect &a, const Trect &b)
	{return a.z < b.z;}
};

inline int lch(int n)
{return (n << 1) + 1;}
inline int rch(int n)
{return (n << 1) + 2;}

void init(int n, int lb, int rb)
{
	root[n] = null;
	if (lb == rb) return;
	int mid = lb + rb >> 1;
	init(lch(n), lb, mid);
	init(rch(n), mid + 1, rb);
}

inline Tlink newnode()
{return nodebuf + cnodebuf++;}

int bsearch(int x)
{
	int l = 0, r = m + 1;
	while (l + 1 < r) {
		int mid = l + r >> 1;
		if (X[mid] < x) l = mid; else r = mid;
	}
	return r;
}

void update(Tlink t)
{
	t->minval = min(t->lch->minval, t->rch->minval);
	if (!t->del) checkmin(t->minval, t->val);
}

void treap_zig(Tlink &x)
{
	Tlink y = x->rch; x->rch = y->lch; y->lch = x;
	if (!x->del) update(x);
	if (!y->del) update(y);
	x = y;
}

void treap_zag(Tlink &x)
{
	Tlink y = x->lch; x->lch = y->rch; y->rch = x;
	if (!x->del) update(x);
	if (!y->del) update(y);
	x = y;
}

void treap_insert(Tlink &t, int key, int val)
{
	if (t == null) {
		t = newnode();
		t->lch = t->rch = null;
		t->key = key;
		t->val = t->minval = val;
		t->rp = rand() * 32768 + rand();
		t->del = false;
		return;
	}
	if (key < t->key || key == t->key && val < t->val) {
		treap_insert(t->lch, key, val);
		if (t->lch->rp < t->rp) treap_zag(t);
	} else {
		treap_insert(t->rch, key, val);
		if (t->rch->rp < t->rp) treap_zig(t);
	}
	update(t);
}

void treap_delete(Tlink &t, int key, int val)
{
	assert(t != null);
	if (key == t->key && val == t->val) {
		t->del = true;
		update(t);
		return;
	}
	if (key < t->key || key == t->key && val < t->val) 
		treap_delete(t->lch, key, val);
	else
		treap_delete(t->rch, key, val);
	update(t);
}

int treap_query(Tlink t, int key1, int key2, bool canl, bool canr)
{
	if (t == null) return 0x3f3f3f3f;
	if (canl && canr) return t->minval;
	if (key2 < t->key) return treap_query(t->lch, key1, key2, canl, canr);
	if (key1 > t->key) return treap_query(t->rch, key1, key2, canl, canr);
	int ret = 0x3f3f3f3f;
	if (!t->del) ret = t->val;
	checkmin(ret, treap_query(t->lch, key1, key2, canl, true));
	checkmin(ret, treap_query(t->rch, key1, key2, true, canr));
	return ret;
}

void insert(int n, int lb, int rb, int x, int y, int val)
{
	treap_insert(root[n], y, val);
	if (lb == rb) return;
	int mid = lb + rb >> 1;
	if (x <= mid)
		insert(lch(n), lb, mid, x, y, val);
	else
		insert(rch(n), mid + 1, rb, x, y, val);
}

void del(int n, int lb, int rb, int x, int y, int val)
{
	treap_delete(root[n], y, val);
	if (lb == rb) return;
	int mid = lb + rb >> 1;
	if (x <= mid)
		del(lch(n), lb, mid, x, y, val);
	else
		del(rch(n), mid + 1, rb, x, y, val);
}

int query(int n, int lb, int rb, int x1, int x2, int y1, int y2)
{
	if (x1 <= lb && rb <= x2) return treap_query(root[n], y1, y2, false, false);
	int ret = 0x3f3f3f3f;
	int mid = lb + rb >> 1;
	if (x1 <= mid) checkmin(ret, query(lch(n), lb, mid, x1, x2, y1, y2));
	if (mid < x2) checkmin(ret, query(rch(n), mid + 1, rb, x1, x2, y1, y2));
	return ret;
}

int main()
{
	//freopen("G.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		rect[i].read();
		rect[i].pid = i;
	}
	sort(rect + 1, rect + n + 1, cmp_rect());
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &pt[i].x, &pt[i].y);
		X[i] = pt[i].x;
	}
	sort(X + 1, X + m + 1);
	null = newnode();
	null->lch = null->rch = null;
	null->val = null->minval = 0x3f3f3f3f;
	null->del = false;
	init(0, 1, m);
	for (int i = 1; i <= m; ++i) {
		pt[i].x = bsearch(pt[i].x);
		insert(0, 1, m, pt[i].x, pt[i].y, i);
	}
	for (int i = 1; i <= n; ++i) {
		int lb = bsearch(rect[i].x1);
		int rb = bsearch(rect[i].x2);
		if (rb > m || X[rb] > rect[i].x2) --rb;
		if (lb > rb) continue;
		int t = query(0, 1, m, lb, rb, rect[i].y1, rect[i].y2);
		if (t <= m) {
			ans[t] = rect[i].pid;
			del(0, 1, m, pt[t].x, pt[t].y, t);
		}
	}
	for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
}