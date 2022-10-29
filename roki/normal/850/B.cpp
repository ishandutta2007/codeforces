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

int n, x, y;

const int N = 1000 * 1000 + 5;
int a[N];

li prefcnt[N];
li prefsum[N];

inline bool read() {
	scanf("%d%d%d", &n, &x, &y);
	forn (i, n) {
		scanf("%d", &a[i]);
		prefcnt[a[i]]++;
		prefsum[a[i]] += a[i];
	}
	forn (i, N - 1) {
		prefcnt[i + 1] += prefcnt[i];
		prefsum[i + 1] += prefsum[i];
	}
	return true;
}
   
bool dv[N];

li sum(li a[N], int l, int r) {
	li res = a[r];
	if (l - 1 >= 0)
		res -= a[l - 1];
	return res;
}

li solve(int p) {
	int w = x / y;
	li curans = 0;
	for (int i = 0; i + 1 < N; i += p) {
		int l = max(i + 1, min(N - 1, i + p - w));
		int r = min(N - 1, i + p - 1);
		li cnt = sum(prefcnt, l, r);
		li s = sum(prefsum, l, r);
		if (l <= r)
			curans += ((i + p) * cnt - s) * y;
		if (i + 1 < l)
			curans += sum(prefcnt, i + 1, l - 1) * x;
	}
	return curans;
}

inline void solve() {   
	li ans = n * li(x);
	
	for (int i = 2; i < N; ++i) {
		if (dv[i])
			continue;
		ans = min(ans, solve(i));
		for (int j = i; j < N; j += i)
			dv[j] = true;
	}
	cout << ans << endl;
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