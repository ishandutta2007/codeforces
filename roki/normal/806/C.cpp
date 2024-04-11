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
li a[N];

inline bool read() {
	cin >> n;
	forn (i, n)
		cin >> a[i];
	return true;
}

int b[N];
   
inline void solve() {
	
	set<li> d2;
	forn (i, 60)
		d2.insert(1LL << i);
	
	forn (i, n) {
		if (d2.count(a[i]))
			continue;
		int j = 0;
		while((1LL << j) < a[i])
			j++;
		b[j]++;
	}
		
	map<li, int> cnt;
	forn (i, n)
		cnt[a[i]]++;
	bool any = false;
	for (int ans = 1; ans <= n; ++ans) {
		int bal = ans;
		int prev = ans;
		int need = 0;
		if (cnt[1] < ans)
			continue;
		forn (i, 60) {
			int cur = cnt[1LL << i];
			need += b[i]; 
			need += max(0, cur - prev);
			if (cur < prev) {
				int c = prev - cur;
				bal -= min(c, need);
				need -= min(c, need);
			}
			prev = min(prev, cur);
		}
		if (need == 0 && bal >= 0) {
			cout << ans << ' ';
			any = true;
		}
	}
	if (!any)
		cout << -1 << endl;
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