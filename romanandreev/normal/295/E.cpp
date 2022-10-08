#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cassert>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define forit(it,v) for(typeof((v).begin()) it = v.begin() ; it != (v).end() ; ++it)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = (int)1e9;
const ld eps = 1e-9;


#define TASK "a"
ll rnd() {
	return (rand() + (ll)rand() * RAND_MAX);
}
struct node {
	int x, y;
	ll s;
	ll sum;
	ll sum1;
	int l, r;
	node() {
		x = 0;
		sum = 0;
		sum1 = 0;
		l = 0;
		r = 0;
		y = rnd();
	}
};
node a[1000000];

void upd(int v) {
	if (v == 0) return;
	a[v].sum = a[a[v].l].sum + a[a[v].r].sum + a[v].x;
	a[v].s = a[a[v].l].s + a[a[v].r].s + 1;
	a[v].sum1 = a[a[v].l].sum1 + a[a[v].r].sum1 + a[a[v].r].sum * (a[a[v].l].s + 1) + a[a[v].l].sum * (-a[a[v].r].s - 1) + a[v].x * (-a[a[v].r].s + a[a[v].l].s);
}
void split(int v, int k, int& l, int& r) {
	l = 0;
	r = 0;
	if (v == 0) {
		return;
	}
	if (a[v].x > k) {
		split(a[v].l, k, l, a[v].l);
		r = v;
	} else {
		split(a[v].r, k, a[v].r, r);
		l = v;
	}
	upd(l);
	upd(r);
}
int merge(int l, int r) {
	if (l == 0 || r == 0) return l + r;
	if (a[l].y < a[r].y) {
		a[l].r = merge(a[l].r, r);
		upd(l);
		return l;
	} else {
		a[r].l = merge(l, a[r].l);
		upd(r);
		return r;
	}
}
int root = 0;
int kv = 1;
int n, m;
pi p[1000000];
int tx[1000000];
int main()
{
	#ifdef home
		assert(freopen(TASK".in", "r", stdin));
		assert(freopen(TASK".out", "w", stdout));
	#endif
	srand(239);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i].x);
		p[i].y = i;
	}
	sort(p, p + n);
	for (int i = 0; i < n; i++) {
		a[i + 1].x = p[i].x;
		tx[p[i].y] = p[i].x;
		upd(i + 1);
		root = merge(root, i + 1);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
	    int x, y, t;
		scanf("%d %d %d", &t, &x, &y);
		int lf, rg, md;
		if (t == 1) {
			x--;
			int old = tx[x];
			int nw = old + y;
			tx[x] = nw;
			split(root, old - 1, lf, rg);
			split(rg, old, md, rg);
			assert(a[md].s == 1);
			assert(a[md].x == old);
			a[md].x = nw;
			upd(md);
			root = merge(lf, rg);
			split(root, nw, lf, rg);
			root = merge(lf, md);
			root = merge(root, rg);
		} else {
			split(root, x - 1, lf, rg);
			split(rg, y, md, rg);
			printf("%I64d\n", a[md].sum1);
			root = merge(lf, md);
			root = merge(root, rg);
		}
	}
	#ifdef home
		eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
	#endif
	return 0;
}