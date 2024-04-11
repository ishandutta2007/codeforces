#include<cstdio>
#include<cstring>
#include<algorithm>

#define N 100010
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

template <class T> inline void chkmin(T &a, T b) { if (a > b) a = b; }
template <class T> inline void chkmax(T &a, T b) { if (a < b) a = b; }

const int SZ = N << 1;
int arr[SZ], n;

#define V(x) (nil + x)

struct Node {
	Node *son[2], *pa;

	int size;
	int val;	//dt ? 1 : -1, ft ? -1 : 1;
	int sum, min, max;

	void push_up() {
		size = son[0]->size + 1 + son[1]->size;
		sum = son[0]->sum + val + son[1]->sum;
		min = min(son[0]->min, son[0]->sum + min(0, val + son[1]->min));
		max = max(son[0]->max, son[0]->sum + max(0, val + son[1]->max));
	}

	inline bool isroot();
	inline bool dir() { return pa->son[1] == this; }
	inline void Set(Node *x, int d) { (son[d] = x)->pa = this; }

} nil[SZ], *root;

inline bool Node::isroot() { return pa == nil; }

void rot(Node *x) {
	int d = x->dir();
	Node *p = x->pa;
	p->Set(x->son[!d], d);
	p->push_up();
	if (p->isroot()) x->pa = p->pa, root = x;
	else p->pa->Set(x, p->dir());
	x->Set(p, !d);
//	x->push_up();
}

void print(Node *rt, int dp = 0) {
	if (rt == nil) return;
	print(rt->son[0], dp + 1);
	printf("%d(%d) ", rt - nil, dp);
	print(rt->son[1], dp + 1);
	if (rt == root) puts("");
}

void splay(Node *x, Node *p = nil) {
	for (Node *y; x->pa != p; ) {
		y = x->pa;
		if (y->pa != p) x->dir() == y->dir() ? rot(y) : rot(x);
		rot(x);
	}
	x->push_up();
}

inline int depth(int x) { return splay(V(x)), V(x)->son[0]->sum; }
inline int dfn(int x){ return splay(V(x)), V(x)->son[0]->size; }

int LCAdp(int x, int y) {
	if (dfn(x) > dfn(y)) swap(x, y);
	splay(V(x));
	splay(V(y), root);
	return depth(x) + min(0, V(x)->val + min(V(y)->son[0]->min, V(y)->son[0]->sum));
}

int Last(Node *x, int d) {
	for (int cnt = 0; ; ) {
		if (cnt + x->son[0]->sum + x->val + x->son[1]->min <= d &&
			d <= cnt + x->son[0]->sum + x->val + x->son[1]->max) cnt += x->son[0]->sum + x->val, x = x->son[1];
		else if (x->son[0]-> sum + cnt == d) return x - nil;
		else x = x->son[0];
	}
}

Node* pred(Node *x) {
	splay(x);
	Node *y = x->son[0];
	for (; y->son[1] != nil; y = y->son[1]);
	return y;
}

Node* succ(Node *x) {
	splay(x);
	Node *y = x->son[1];
	for (; y->son[0] != nil; y = y->son[0]);
	return y;
}

int Ancestor(int x, int d) {
	int dep = depth(x) - d, v;
	splay(V(x));
	v = Last(V(x)->son[0], dep);

	// CUT edge from p[x] to x
	Node *pre = pred(V(x));
	Node *nxt = succ(V(x + n));
	splay(pre);
	splay(nxt, root);
	Node *cur = nxt->son[0];
	nxt->Set(nil, 0), nxt->push_up();
	pre->push_up();

	// LINK edge from v to x (x will become the last child of v)
	pre = pred(nxt = V(v + n));
	splay(pre);
	splay(nxt, root);
	nxt->Set(cur, 0), nxt->push_up();
	pre->push_up();

	return v;
}

void init() {
	V(0)->min = SZ;
	V(0)->max = -SZ;
}

Node* build(int l, int r) {
	if (l > r) return nil;
	int m = (l + r) >> 1, x = arr[m];
	V(x)->val = (x <= n) ? 1 : -1;
	V(x)->sum = V(x)->min = V(x)->max = V(x)->val;
	V(x)->pa = nil;
	V(x)->Set(build(l, m - 1), 0);
	V(x)->Set(build(m + 1, r), 1);
	V(x)->push_up();
	return V(x);
}

int head[N], next[N], to[N];
int cur[N];
int p[N], cnt;

void DFT(int rt) {
	for (int i = 1; i <= n; i ++) cur[i] = head[i];
	arr[cnt = 1] = rt;
	for (int x = rt, v, i; x; ) {
		i = cur[x], cur[x] = next[i];
		if (!i) arr[++ cnt] = x + n, x = p[x];			//finish time
		else p[v = to[i]] = x, arr[++ cnt] = x = v;		//discover time
	}
}

int chd[N];

inline void AddEdge(int s, int e, int m) {
	to[m] = e;
	next[m] = head[s];
	head[s] = m;
}

int main() {
	int q;
//	freopen ("E.in", "r", stdin);
//	freopen ("E_.out", "w", stdout);
	scanf("%d %d", &n, &q);
	for (int i = 1, sz, m = 0; i <= n; i ++) {
		scanf("%d", &sz);
		for (int j = 1; j <= sz; j ++) scanf("%d", chd + j);
		for (int j = sz; j; j --) AddEdge(i, chd[j], ++ m);
	}

	init();
	DFT(1);

	root = build(1, cnt);

	while (q --) {
		int bf;
		scanf("%d", &bf);
		if (bf == 1) {
			int u, v;
			scanf("%d %d", &u, &v);
			if (u == v) puts("0");
			else printf("%d\n", depth(u + n) + depth(v + n) - LCAdp(u + n, v + n) * 2);
		} else if (bf == 2) {
			int u, h;
			scanf("%d %d", &u, &h);
			Ancestor(u, h);
		} else {
			int k;
			scanf("%d", &k);
			printf("%d\n", Last(root, k + 1) - n);
		}
	}

	return 0;
}