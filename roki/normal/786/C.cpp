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

const int N = 100 * 1000 + 5;

int a[N];
vector<int> pos[N];

int n;

void gen() {
	n = 3000;
	forn (i, n)
		a[i] = rand() + 1;	
}

inline bool read() {

	cin >> n;
	forn (i, n)
		cin >> a[i];

	return true;
}

int cur[N];

struct node {
	node *l, *r;
	int val;
	node (int x) {
		val = x;
	}
};

node* build(int l, int r) {
	if (l + 1 == r) {
		return new node(cur[l]);	
	}
	int mid = (l + r) / 2;
	node *vl = build(l, mid);
	node *vr = build(mid, r);
	node *res = new node(vl->val + vr->val);
	res->l = vl, res->r = vr;
	return res;	
}

node *root[N];

node *setval(node *v, int l, int r, int pos, int val) {
	if (l + 1 == r) {
		return new node(val);
	}
	int mid = (l + r) / 2;
	node *res = new node(v->val);
	res->l = v->l, res->r = v->r;
	if (pos < mid)
		res->l = setval(v->l, l, mid, pos, val);
	else
		res->r = setval(v->r, mid, r, pos, val);
	res->val = res->l->val + res->r->val;
	return res;		
}

int getnext(node *v, int l, int r, int cnt) {
	if (l + 1 == r) {
		if (cnt >= v->val)
			return r;
		else
			return l;			
	}
	int mid = (l + r) / 2;
	if (v->l->val > cnt)
		return getnext(v->l, l, mid, cnt);
	else
		return getnext(v->r, mid, r, cnt - v->l->val);
}

int solve(int k) {
	int l = 0;
	int ans = 0;
	while(l < n) {
		l = getnext(root[l], 0, n, k);
		ans++;
	}
	return ans;		
}

void print(int ar[N]) {
	forn (i, n)
		cerr << ar[i] << ' ';
	cerr << endl;
}

inline void solve() {

	forn (i, n)
		pos[a[i]].pb(i);
	
	forn (i, N)
		reverse(all(pos[i]));
	
	forn (i, N)
		if (sz(pos[i]))
			cur[pos[i].back()] = 1;
	
	//print(cur);

	root[0] = build(0, n);

	for (int i = 1; i < n; ++i) {
		root[i] = setval(root[i - 1], 0, n, i - 1, 0);
		cur[i - 1] = 0;
		pos[a[i - 1]].pop_back();
		if (sz(pos[a[i - 1]])) {
			root[i] = setval(root[i], 0, n, pos[a[i - 1]].back(), 1);								
			cur[pos[a[i - 1]].back()] = 1;
		}
		//print(cur);
	}



	for (int k = 1; k <= n; ++k)
		cout << solve(k) << ' ';
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

	read();
	solve();

#ifdef SU2
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}