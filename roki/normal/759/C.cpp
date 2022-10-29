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

int n;

const int N = 100 * 1000 + 5;
int x[N];
int type[N], pos[N];

inline bool read() {
	cin >> n;
	forn (i, n) {
		cin >> pos[i] >> type[i];
		pos[i]--;
		if (type[i])
			cin >> x[i];
		else
			type[i] = -1;
	}
	return true;
}

int t[4 * N];
int add[4 * N];

int ans[N];

void push(int id) {
	if (id > 4 * N)
		return;
	t[id] += add[id];
	if (2 * id + 1 < 4 * N) {
		add[2 * id + 1] += add[id];
		add[2 * id + 2] += add[id];
	}
	add[id] = 0; 
}

void inc(int id, int l, int r, int lq, int rq, int val) {
	if (l == lq && r == rq) {
		add[id] += val;
		push(id);
		return;	
	}
	push(id);
	int mid = (l + r) / 2;
	if (lq < mid)
		inc(2 * id + 1, l, mid, lq, min(mid, rq), val);
	if (mid < rq)
		inc(2 * id + 2, mid, r, max(mid, lq), rq, val);
	push(2 * id + 1);
	push(2 * id + 2);
	t[id] = max(t[2 * id + 1], t[2 * id + 2]);
}

int getans(int id, int l, int r) {
	push(id);
	if (t[id] <= 0)
		return -1;
	if (l + 1 == r) {
		//cerr << l << endl;
		return ans[l];
	}
	push(2 * id + 2);
	int mid = (l + r) / 2;
	if (t[2 * id + 2] > 0)
		return getans(2 * id + 2, mid, r);
	return getans(2 * id + 1, l, mid);
}

inline void solve() {   
	forn (i, n) {
		ans[pos[i]] = x[i];
		inc(0, 0, n, 0, pos[i] + 1, type[i]);
		//cerr << pos[i] << ' ' << type[i] << endl;
		cout << getans(0, 0, n) << endl;
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

	assert(read());
	solve();

#ifdef _DEBUG
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}