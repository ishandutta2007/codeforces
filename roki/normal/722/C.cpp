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
int p[N];
int n;

inline bool read() {
	cin >> n;
	forn (i, n)
		cin >> a[i];
	forn (i, n)
		cin >> p[i];
	return true;
}
   
li sum[N];

inline void solve() {   
	
	forn (i, n)
		sum[i + 1] = sum[i] + a[i];
	
	set<int> rem;
	rem.insert(-1);
	rem.insert(n);
	
	multiset<li> sums;
	sums.insert(sum[n]);	
		
	
	forn (i, n) {
		p[i]--;
		auto it = rem.lower_bound(p[i]);
		int r = *it;
		it--;
		int l = *it;
		rem.insert(p[i]);
		li psum = sum[r] - sum[l + 1];
		assert(sums.count(psum));
		sums.erase(sums.find(psum));
		sums.insert(sum[r] - sum[p[i] + 1]);
		sums.insert(sum[p[i]] - sum[l + 1]);
		cout << *sums.rbegin() << endl;
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