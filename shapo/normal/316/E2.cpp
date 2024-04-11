#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;
typedef vector < int > vi;
typedef vector < vi > vvi;

const int MD = 1000000000;

struct Matrix {
	int s[4];
	Matrix() {
		memset(s, 0, sizeof(s));
	}
	Matrix(const Matrix &a, const Matrix &b) {
		s[0] = ((ll)(a.s[0]) * b.s[0] + (ll)(a.s[1]) * b.s[2]) % MD;
		s[1] = ((ll)(a.s[0]) * b.s[1] + (ll)(a.s[1]) * b.s[3]) % MD;
		s[2] = ((ll)(a.s[2]) * b.s[0] + (ll)(a.s[3]) * b.s[2]) % MD;
		s[3] = ((ll)(a.s[2]) * b.s[1] + (ll)(a.s[3]) * b.s[3]) % MD;
	}
	Matrix(const int &a, const int &b, const int &c, const int &d) {
		s[0] = a, s[1] = b, s[2] = c, s[3] = d;
	}
};

struct Vector {
	int s[2];
	Vector() {
		memset(s, 0, sizeof(s));
	}
	Vector(const Matrix &a, const Vector &b) {
		s[0] = ((ll)(a.s[0]) * b.s[0] + (ll)(a.s[1]) * b.s[1]) % MD;
		s[1] = ((ll)(a.s[2]) * b.s[0] + (ll)(a.s[3]) * b.s[1]) % MD;
	}
	Vector(const int &a, const int &b) {
		s[0] = a, s[1] = b;
	}
	Vector sum(const Vector &a, const Vector &b) {
		return Vector((a.s[0] + b.s[0]) % MD, (a.s[1] + b.s[1]) % MD);
	}
};

#ifdef DEBUG
	#define maxn 10
	#define maxk 16
#else
	#define maxn 200500
	#define maxk 262144
#endif

Matrix fib[maxn];
Vector sum[maxn], num[maxn];

struct list {
	Vector sum;
	int add;
	int l, r;
	Vector getV(Vector *x) const {
		Vector cur = sum;
		Vector plus = x[r - l];
		for (int i = 0; i < 2; ++i)
			plus.s[i] = (ll)(plus.s[i]) * add % MD;
		return cur.sum(cur, plus);
	}
	void proc(const list &a, const list &b, Vector *x) {
		Vector sp = a.getV(x);
		sp = sp.sum(sp, Vector(fib[b.l - a.l], b.getV(x)));
		sum = sp;
	}
};

int n, m, curk;
list tree[2 * maxk];
int t, v, x, l, r, d;
int a[maxk];

int st[2 * maxk];

int init() {
	for (int i = curk, j = 1; i < 2 * curk; ++i, ++j) {
		tree[i].sum = Vector(a[j], 0); 
		tree[i].add = 0;
		tree[i].l = tree[i].r = j;
	}
	for (int i = curk - 1; i > 0; --i) {
		tree[i].proc(tree[i * 2], tree[i * 2 + 1], sum);
		tree[i].l = tree[i * 2].l, tree[i].r = tree[i * 2 + 1].r;
	}
	for (int i = curk, j = 1; i < 2 * curk; ++i, ++j)
		st[i] = a[j] - a[j - 1];
	for (int i = curk - 1; i > 0; --i)
		st[i] = (st[i * 2] + st[i * 2 + 1]) % MD;
	return 0;
}

inline void add(int &a, const int b) {
	a += b;
	while (a >= MD) a -= MD;
}

int add(const int &l, const int &r, const int &l1, const int &r1, const int &v, int x) {
	if (max(l, l1) <= min(r, r1)) {
		//fprintf(stderr, "add [%d, %d] in [%d, %d] to %d\n", l, r, l1, r1, x);
		if (l <= l1 && r >= r1) {
			add(tree[v].add, MD + x);
			return 0;
		} else {
			add(tree[v * 2].add, tree[v].add);
			add(tree[v * 2 + 1].add, tree[v].add);
			tree[v].add = 0;
			add(l, r, l1, (l1 + r1) / 2, v * 2, x);
			add(l, r, (l1 + r1) / 2 + 1, r1, v * 2 + 1, x);
			tree[v].proc(tree[v * 2], tree[v * 2 + 1], sum);
		}
	}
	return 0;
}

int getsum(const int &l, const int &r, const int &l1, const int &r1, const int &v) {
	int res = 0;
	if (max(l, l1) <= min(r, r1)) {
		//fprintf(stderr, "[%d; %d] in [%d; %d]\n", l, r, l1, r1);
		if (l <= l1 && r >= r1) {
			Vector addV = sum[r1 - l];
			for (int i = 0; i < 2; ++i) {
				add(addV.s[i], MD - ((l1 == l) ? 0 : sum[l1 - 1 - l].s[i]));
				addV.s[i] = (ll)(addV.s[i]) * tree[v].add % MD;
			}
			res = Vector(fib[l1 - l], tree[v].sum).s[0];
			add(res, addV.s[0]);
		} else {
			add(tree[v * 2].add, tree[v].add);
			add(tree[v * 2 + 1].add, tree[v].add);
			tree[v].add = 0;
			res = getsum(l, r, l1, (l1 + r1) / 2, v * 2);
			add(res, getsum(l, r, (l1 + r1) / 2 + 1, r1, v * 2 + 1));
			tree[v].proc(tree[v * 2], tree[v * 2 + 1], sum);
		}
	}
	return res;
}

int upd(int x, int val) {
	st[x + curk - 1] = (st[x + curk - 1] + val) % MD;
	int par = (x + curk - 1) / 2;
	while (par) {
		st[par] = (st[par * 2] + st[par * 2 + 1]) % MD;
		par /= 2;
	}
	return 0;
}

int get(int l, int r) {
	l = (l + curk - 1), r = (r + curk - 1);
	int res = 0;
	while (l < r) {
		if (l % 2 == 1) add(res, st[l]);
		if (r % 2 == 0) add(res, st[r]);
		l = (l + 1) / 2;
		r = (r - 1) / 2;
	}
	if (l == r) add(res, st[l]);
	return res;
}

int main() {
	//init
	fib[1] = Matrix(1, 1, 1, 0);
	fib[0] = Matrix(1, 0, 0, 1);
	for (int i = 2; i < maxn; ++i) {
		fib[i] = Matrix(fib[i - 1], fib[1]);
		/*for (int j = 0; j < 4; ++j) 
			fprintf(stderr, "%d ", fib[i].s[j]);
		fprintf(stderr, "\n");*/
	}
	num[0] = Vector(1, 0);
	num[1] = Vector(1, 1);
	for (int i = 2; i < maxn; ++i) {
		num[i] = num[i].sum(num[i - 2], num[i - 1]);
		/*for (int j = 0; j < 2; ++j)
			fprintf(stderr, "%d ", num[i].s[j]);
		fprintf(stderr, "\n");*/
	}
	sum[0] = Vector(1, 0);
	for (int i = 1; i < maxn; ++i)
		sum[i] = sum[i].sum(sum[i - 1], num[i]);
	//reading
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	curk = 2;
	while (curk < n) curk *= 2;
	init();
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &t);
		int ans = 0;
		switch (t) {
			case 1:
				scanf("%d%d", &x, &v);
				//fprintf(stderr, "old %d new %d\n", get(1, x), v);
				ans = v - get(1, x);
				upd(x, ans);
				upd(x + 1, -ans);
				add(x, x, 1, curk, 1, ans);
				break;
			case 2:
				scanf("%d%d", &l, &r);
				ans = getsum(l, r, 1, curk, 1);
				printf("%d\n", ans);
				break;
			case 3:
				scanf("%d%d%d", &l, &r, &d);
				upd(l, d);
				upd(r + 1, -d);
				add(l, r, 1, curk, 1, d);
			default: break;
		}
	}
	return 0;
}