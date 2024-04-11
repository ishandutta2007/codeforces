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

const int N = 66;
int cnt[N];
int n;

inline bool read() {
	scanf("%d", &n);
	forn (i, n) {
		int a;
		scanf("%d", &a);
		cnt[a]++;
	}
	return true;
}
map<pair<int, li>, int> dp;

li norm(int n, li mask) {
	for (int i = n + 1; i <= 60; ++i)
		if (mask & (1LL << i))
			mask ^= 1LL << i;
	return mask;
}

int sg(int n, li mask) {
	mask = norm(n, mask);
	if (dp.count(mp(n, mask)))
		return dp[mp(n, mask)];
	set<int> x;
	for (int i = 1; i <= n; ++i) {
		if (mask & (1LL << i))
			continue;
		int nn = n - i, nmask = mask | (1LL << i);
		x.insert(sg(nn, nmask));
	}
	forn (i, INF)
		if (!x.count(i))
			return dp[mp(n, mask)] = i;
}

inline void solve() {   
	vector<int> v;
	forn (i, N)
		if (cnt[i] & 1)
			v.pb(i);
	int cur = 0;
	
	for (int x : v)
		cur ^= sg(x, 0);
	
	if (cur == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
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