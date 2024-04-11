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

int n, q, s;

const int N = 100 * 1000 + 5;
vector<pt> g[N];
vector<pair<pt, int> > lr[N];

pt target[N];
int l3[N], r3[N];

set<int> ids[4 * N];

void addq3(int id, int l, int r, int lq, int rq, int qnum) {
	if (l == lq && r == rq) {
		ids[id].insert(qnum);
		return;
	}
	int mid = (l + r) >> 1;
	if (lq < mid)
		addq3(2 * id + 1, l, mid, lq, min(mid, rq), qnum);
	if (rq > mid) 
		addq3(2 * id + 2, mid, r, max(mid, lq), rq, qnum);
}

void remq3(int id, int l, int r, int lq, int rq, int qnum) {
	if (l == lq && r == rq) {
		ids[id].erase(qnum);
		return;
	}
	int mid = (l + r) / 2;
	if (lq < mid)
		remq3(2 * id + 1, l, mid, lq, min(mid, rq), qnum);
	if (rq > mid) 
		remq3(2 * id + 2, mid, r, max(mid, lq), rq, qnum);
}

void gen() {
	n = 100 * 1000;
	s = 0;
	forn (i, n) {
		l3[i] = rand() % 100, r3[i] = n - rand() % 100 - 1;
		target[i] = mp(rand(), rand());
		addq3(0, 0, n, l3[i], r3[i] + 1, i);	
	}
}

inline bool read() {
	scanf("%d%d%d", &n, &q, &s);
	s--;
	forn (i, q) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int a, b, w;
			scanf("%d%d%d", &a, &b, &w);
			a--, b--;
			g[a].pb(mp(b, w));
		} else {
			int v, l, r, w;
			scanf("%d%d%d%d", &v, &l, &r, &w);
			v--;
			l--, r--;
			if (t == 2) 
				lr[v].pb(mp(mp(l, r), w));
			else {
				target[i] = mp(v, w);
				addq3(0, 0, n, l, r + 1, i);
				l3[i] = l, r3[i] = r;
			}
		}
	}
	return true;
}
   
li f[4 * N];
li ans[N];
li z[4 * N];

void build(int id, int l, int r, int s) {
	if (l + 1 == r)  {
		f[id] = l == s ? 0 : INF64;
		return;
	}
	int mid = (l + r) / 2;
	build(2 * id + 1, l, mid, s);
	build(2 * id + 2, mid, r, s);
	f[id] = min(f[2 * id + 1], f[2 * id + 2]);
}

void push(int id) {
	if (f[id] == INF64 + 1)
		return;
	f[id] = min(f[id], z[id]);
	if (2 * id + 1 < 4 * N) {
		z[2 * id + 1] = min(z[2 * id + 1], z[id]);
		z[2 * id + 2] = min(z[2 * id + 2], z[id]);
	}
	z[id] = INF64;
}

pair<li, int> getmin(int id, int l, int r) {
	push(id);
	if (l + 1 == r) {
		pair<li, int> res = mp(f[id], l); 
		f[id] = INF64 + 1;
		return res;
	}
	int mid = (l + r) / 2;
	pair<li, int> res;
	push(2 * id + 1);
	push(2 * id + 2);
	if (f[2 * id + 1] == f[id])
		res = getmin(2 * id + 1, l, mid);
	else
		res = getmin(2 * id + 2, mid, r);
	f[id] = min(f[2 * id + 1], f[2 * id + 2]);
	return res;
}

void upd(int id, int l, int r, int lq, int rq, li val) {
	if (l == lq && r == rq) {
		z[id] = min(z[id], val);
		push(id);
		return;
	}
	push(id);
	int mid = (l + r) / 2;
	push(2 * id + 1);
	push(2 * id + 2);
	if (lq < mid)
		upd(2 * id + 1, l, mid, lq, min(rq, mid), val);
	if (rq > mid)
		upd(2 * id + 2, mid, r, max(lq, mid), rq, val);
	f[id] = min(f[2 * id + 1], f[2 * id + 2]);
}

void getq3(int id, int l, int r, int v, set<int> &q3) {
	if (sz(q3) < sz(ids[id]))
		swap(q3, ids[id]);
	for (int qid : ids[id])
		q3.insert(qid); 
	ids[id].clear();
	if (l + 1 == r)
		return;
	int mid = (l + r) / 2;
	if (v < mid)
		getq3(2 * id + 1, l, mid, v, q3);
	else
		getq3(2 * id + 2, mid, r, v, q3);
}

set<int> q3;

inline void solve() {   
	build(0, 0, n, s);
	forn (i, 4 * N)
		z[i] = INF64;
	
	memset(ans, -1, sizeof ans);
	
	int sum = 0;
	
	while(true) {
		pair<li, int> cur = getmin(0, 0, n);
		if (cur.x >= INF64)
			break;
		int v = cur.y;
		ans[v] = cur.x;
		for (pt to : g[v]) {
			upd(0, 0, n, to.x, to.x + 1, cur.x + to.y);
		}
		for (auto to : lr[v]) {
			upd(0, 0, n, to.x.x, to.x.y + 1, cur.x + to.y);
		}
		
		q3.clear();
		
		getq3(0, 0, n, v, q3);
		
		for (int i : q3) {
			upd(0, 0, n, target[i].x, target[i].x + 1, cur.x + target[i].y);
			remq3(0, 0, n, l3[i], r3[i] + 1, i);
		}
	}
	forn (i, n)
		cout << ans[i] << ' ';
}

int main()
{
#ifdef SU2
	assert(freopen("input.txt", "r", stdin));
	assert(freopen("output.txt", "w", stdout));
#endif

	cout << setprecision(25) << fixed;
	cerr << setprecision(10) << fixed;

	srand(int(time(NULL)));

	assert(read());
	solve();

#ifdef SU2
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}