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

string s, t;

inline bool read() {
	cin >> s >> t;
	return true;
}
   
inline void solve() {   
	sort(all(s));
	sort(all(t));
	reverse(all(t));
	string ans = s;
	int n = sz(s);
	s.resize((n + 1) / 2);
	t.resize(n / 2);
	
	int ls = 0, rs = sz(s) - 1;
	int lt = 0, rt = sz(t) - 1;
	
	int lans = 0, rans = n - 1;
	
	for (int i = 0; i < n; ++i) {
		if (i & 1) {
			if (t[lt] > s[ls])
				ans[lans++] = t[lt++];
			else
				ans[rans--] = t[rt--];
		} else {
			if (s[ls] < t[lt])
				ans[lans++] = s[ls++];
			else
				ans[rans--] = s[rs--];
		}
	}
	cout << ans << endl;
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