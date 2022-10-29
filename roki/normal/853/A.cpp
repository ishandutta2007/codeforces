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

int n, k;
const int N = 300 * 1000 + 5;
int a[N];

inline bool read() {
	cin >> n >> k;
	forn (i, n)
		cin >> a[i];
	return true;
}
   
inline void solve() {
	set<pt> s;
	forn (i, k)
		s.insert(mp(a[i], i));
	li ans = 0;
	vector<int> t(n);
	int curt = k + 1;
	for (int i = k; i < n; ++i) {
		s.insert(mp(a[i], i));
		pt cur = *(--s.end());
		s.erase(cur);
		t[cur.y] = curt++;	
	}
	while(sz(s)) {
		pt cur = *(--s.end());
		s.erase(cur);
		t[cur.y] = curt++;	
	}
	forn (i, n)
		ans += li(t[i] - i - 1) * a[i];
	cout << ans << endl;
	forn (i, n)
		cout << t[i] << ' ';
	cout << endl;
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