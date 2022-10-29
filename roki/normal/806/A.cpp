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

li x, y;
li p, q;

li ans = -1;

li gcd(li a, li b) {
	return b == 0 ? a : gcd(b, a % b);
}


void gen() {
	y = rand() % 1000 + 1;
	x = rand() % y;
	q = rand() % 1000 + 1;
	p = rand() % q;
	li g = gcd(p, q);
	p /= g, q /= g;
	if (p == 0)
		gen();
}

li naive() {
	forn (i, 1e9) {
		forn (win, i + 1) {
			int lose = i - win;
			if((x + win) * q == (y + win + lose) * p) {
				cerr << win << ' ' << lose << ' ' << i << endl;
				return i;
			}
		}
	}
	return -1;
}

inline bool read() {
	/*#ifdef SU2
		cerr << "TEST: " << endl;
		gen();
		cerr << x << ' ' << y << ' ' << p << ' ' << q << endl;
		ans = naive();
		return true;
	#endif
	*/cin >> x >> y;
	cin >> p >> q;
	return true;
}
   
bool ok(li lose) {
	li mod = (q - p);
	li k = (y + lose - x) / mod;
	k = min(k, li(2e9));
	li win = k * p - x;
	return win >= 0;
}

inline void solve() {   
	if (x * q == p * y) {
		cout << 0 << endl;
		return;
	}
	li mod = (q - p);
	if (mod <= 0) {
		cout << -1 << endl;
		return;
	}
	li a = (y - x) % mod;
	li l = (mod - a) % mod;
	li lf = 0, rg = 2e18 / mod;
	while(rg - lf > 1) {
		li mid = (lf + rg) / 2;
		if (ok(l + mid * mod))
			rg = mid;
		else
			lf = mid;	
	}
	if (ok(l + lf * mod))
		rg = lf;
	if (ok(l + rg * mod)) {
		li lose = l + rg * mod;
		li k = (y + lose - x) / mod;
		li win = k * p - x;
		cout << lose + win << endl;
	/*	#ifdef SU2
			cerr << win << ' ' << lose << ' ' << win + lose << endl;
			assert(win + lose == ans);
			assert((x + win) * q == (y + win + lose) * p);
		#endif
	*/} else {
		cout << -1 << endl;
	}
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

	int t;
	cin >> t;
	forn (i, t) {
		assert(read());
		solve();
	}

#ifdef SU2
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}