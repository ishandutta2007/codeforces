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
const int N = 300 * 1000 + 5;
li w[N];
li a[N];

inline bool read() {
	scanf("%d", &n);
	
	forn (i, n)
		scanf("%I64d%I64d", &a[i], &w[i]);		
	
	return true;
}
   
li l = 0;
li cur = 0;
set<pair<li, int> > fly;
set<pair<li, int> > candidates;

void relax() {
	bool t = true;
	while(t) {
		t = false;
		if (sz(candidates) && l >= candidates.begin()->x) {
			fly.insert(*candidates.begin());
			l -= candidates.begin()->x;
			candidates.erase(candidates.begin());
			t = true;
		}
		if (sz(fly) && sz(candidates) && fly.rbegin()->x > candidates.begin()->x) {
			pair<li, int> ff = *fly.rbegin();
			pair<li, int> cc = *candidates.begin();
			l += ff.x - cc.x;
			fly.erase(ff);
			candidates.erase(cc);
			fly.insert(cc);
			candidates.insert(ff);
			t = true;
		}	
	}
}

inline void solve() {

	vector<li> leq;
	
	forn (i, n)
		if (a[i] <= a[0])
			leq.pb(a[i]);
	
			leq.pb(0);
	
			
	sort(all(leq));
	leq.resize(unique(all(leq)) - leq.begin());
	
	
	reverse(all(leq));
	
	vector<pair<li, int> > b;
	forn (i, n - 1)
		b.pb(mp(a[i + 1], i + 1));
	sort(all(b));
	reverse(all(b));
	int f = 0;
	
	int curans = 0;
	forn (i, n)
		curans += a[i] > a[0];
		
	int ans = curans;
	cur = a[0];
	
	forn (i, sz(leq)) {
		l += cur - leq[i];
		cur = leq[i];
		while(f < sz(b) && b[f].x > cur) {
			int id = b[f++].y;
			candidates.insert(mp(w[id] - a[id] + 1, id));
		}
		relax();	
		ans = min(ans, sz(candidates));
	}
	cout << ans + 1 << endl;
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