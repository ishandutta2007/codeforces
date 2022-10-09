#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

#define forab(i, a, b) for (int i = a; i < int(b); ++i)
#define fordab(i, a, b) for (int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab (i, 0, n)
#define ford(i, n) fordab (i, 0, n)
#define forv(i, a) forn (i, a.size())
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long int64;
typedef long double ld;

int a[100100], nxt[200100], prev[200100], fs[100100], cnt[100100], l[100100], ans[100100];
vector<pair<int, int> > q[100100];

struct tree {
	tree *l, *r;
	int sum;
} *rt;

void build(tree *&v, int l, int r) {
	v = new(tree);
	v->l = v->r = NULL;
	v->sum = 0;
	if (l == r - 1) {
		return;
	}
	int m = (l + r) >> 1;
	build(v->l, l, m);
	build(v->r, m, r);
}

void give(tree *v) {
	if (!v) {
		return;
	}
	if (v->l) {
		v->l->sum += v->sum;
	}
	if (v->r) {
		v->r->sum += v->sum;
	}
	v->sum = 0;
}

int get(tree *v, int l, int r, int i) {
	if (l == r - 1) {
		return v->sum;
	}
	give(v);
	int m = (l + r) >> 1;
	if (i < m) {
		return get(v->l, l, m, i);
	} else {
		return get(v->r, m, r, i);
	}
}

void add(tree *v, int L, int R, int l, int r, int x) {
	if (l <= L && R <= r) {
		v->sum += x;
		return;
	}
	if (r <= L || R <= l) {
		return;
	}
	give(v);
	int M = (L + R) >> 1;
	add(v->l, L, M, l, r, x);
	add(v->r, M, R, l, r, x);
}

int main() {
	int n, m;
	cin >> n >> m;
	forn (i, n) {
		cin >> a[i];
		--a[i];
		cnt[i] = 0;
		fs[i] = n + i;
		nxt[n + i] = n << 1;
	}
	forn (i, m) {
		int x, y;
		cin >> x >> y;
		--x;
		--y;
		q[x].pb(mp(y, i));
	}
	ford (i, n) {
		if (a[i] >= n) {
			continue;
		}
		nxt[i] = fs[a[i]];
		prev[i] = -1;
		prev[fs[a[i]]] = i;
		fs[a[i]] = i;
		++cnt[a[i]];
		if (cnt[a[i]] == a[i] + 1) {
			l[a[i]] = prev[n + a[i]];
		} else if (cnt[a[i]] > a[i] + 1) {
			l[a[i]] = prev[l[a[i]]];
		}
	}
	build(rt, 0, n);
	forn (i, n) {
		if (cnt[i] < i + 1) {
			continue;
		}
//		cerr << l[i] << " " << nxt[l[i]] << endl;
		add(rt, 0, n, l[i], nxt[l[i]], 1);
	}
	forn (i, n) {
//		cerr << get(rt, 0, n, i) << " ";
	}
//	cerr << endl;
	forn (i, n) {
		forv (j, q[i]) {
			ans[q[i][j].sc] = get(rt, 0, n, q[i][j].fs);
		}
		if (a[i] >= n || cnt[a[i]] < a[i] + 1) {
			continue;
		}
		add(rt, 0, n, l[a[i]], nxt[l[a[i]]], -1);
		--cnt[a[i]];
		l[a[i]] = nxt[l[a[i]]];
		if (cnt[a[i]] < a[i] + 1) {
			continue;
		}
		add(rt, 0, n, l[a[i]], nxt[l[a[i]]], 1);
	}
	forn (i, m) {
		cout << ans[i] << endl;
	}
}