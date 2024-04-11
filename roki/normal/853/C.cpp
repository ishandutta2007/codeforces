#include <bits/stdc++.h>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i,l,r) for (int i = int(l); i <= int(r); i++)
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define x first
#define y second

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

int n, q;
const int N = 200 * 1000 + 5;
int p[N];

inline bool read() {
	scanf("%d%d", &n, &q);
	forn (i, n) {
		scanf("%d", &p[i]);	
		p[i]--;
	}
	return true;
}
   
struct node {
	node * l, * r;
	int sum;
	node(node * t) {
		if (!t) {
			node();
			return;
		}
		this->sum = t->sum;
		this->l = t->l;
		this->r = t->r;
	}
	node(int s = 0) {
		l = r = NULL;
		sum = s;
	}
};

node * inc(node * t, int l, int r, int pos) {
	if (l + 1 == r) {
		return new node(1);
	}
	int mid = (l + r) / 2;
	node * p = new node(t);
	if (pos < mid) {
		if (!p->l)
			p->l = new node();
		p->l = inc(p->l, l, mid, pos);
	} else {
		if (!p->r)
			p->r = new node();
		p->r = inc(p->r, mid, r, pos);
	}
	p->sum++;
	return p;
}

int sum(node * t, int l, int r, int lq, int rq) {
	if (!t)
		return 0;
	if (l == lq && r == rq)
		return t->sum;
	int mid = (l + r) / 2;
	int res = 0;
	if (lq < mid)
		res += sum(t->l, l, mid, lq, min(rq, mid));
	if (mid < rq)
		res += sum(t->r, mid, r, max(lq, mid), rq);
	return res; 	
}

li f(int n) {
	return li(n) * (n - 1) / 2;
}

vector<node *> roots;

int rect(int l, int r, int d, int u) {
	if (l == r || d == u)
		return 0;
	return sum(roots[r], 0, n, d, u) - sum(roots[l], 0, n, d, u);
}

li req(int l, int r, int d, int u) {
	li res = f(n);
	res -= f(rect(0, l, 0, n));
	res -= f(rect(r, n, 0, n));
	res -= f(rect(0, n, 0, d));
	res -= f(rect(0, n,	u, n));
	res += f(rect(0, l, 0, d));
	res += f(rect(0, l, u, n));
	res += f(rect(r, n, 0, d));
	res += f(rect(r, n, u, n));		
	return res;
}

inline void solve() {
	cerr << "!" << endl;
	roots.pb(new node());
	forn (i, n) {
		roots.pb(inc(roots.back(), 0, n, p[i]));
	}
	forn (i, q) {
		int l, d, r, u;
		scanf("%d%d%d%d", &l, &d, &r, &u);
		l--, d--;
		printf("%I64d\n", req(l, r, d, u));
	}   
}

int main()
{
#ifdef _DEBUG
	assert(freopen("input.txt", "r", stdin));
	assert(freopen("output.txt", "w", stdout));
#endif

	cout << setprecision(25) << fixed;
	cerr << setprecision(10) << fixed;

	srand(int(time(NULL)));

	read();
	solve();

#ifdef _DEBUG
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}