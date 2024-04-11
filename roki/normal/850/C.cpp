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
const int N = 105;
int a[N];

inline bool read() {
	cin >> n;
	forn (i, n)
		cin >> a[i];
	return true;
}
   
map<int, int> degs;

void add(int a) {
	for (int i = 2; i * i <= a; ++i) {
		if (a % i == 0) {
			int d = 0;
			while(a % i == 0)
				d++, a /= i;
			degs[i] |= 1 << d;
		}
	}
	if (a > 1)
		degs[a] |= 1 << 1;
}

map<int, int> sg;

int calc(int mask) {
	if (mask < 2)
		return 0;
	if (sg.count(mask))
		return sg[mask];
	set<int> s;
	for (int i = 1; (1 << i) <= mask; ++i) {
		int nmask = (mask & ((1 << i) - 1)) | (mask >> i);
		s.insert(calc(nmask));
	}
	for (int i = 0; ; ++i)
		if (!s.count(i))
			return sg[mask] = i;
}

inline void solve() {   
	forn (i, n)
		add(a[i]);

	int x = 0;
	for (auto p : degs)
		x ^= calc(p.y);
	if (x == 0)
		cout << "Arpa" << endl;
	else
		cout << "Mojtaba" << endl;
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