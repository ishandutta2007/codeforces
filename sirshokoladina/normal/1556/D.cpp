#include <bits/stdc++.h>
using namespace std;

#ifdef SG
	#include <debug.h>
#else
	template<typename T> struct outputer;
	struct outputable {};
	#define PRINT(...)
	#define OUTPUT(...)
	#define show(...)
	#define debug(...)
	#define deepen(...)
	#define timer(...)
	#define fbegin(...)
	#define fend
	#define pbegin(...)
	#define pend
#endif

#define ARG4(_1,_2,_3,_4,...) _4

#define forn3(i,l,r) for (int i = int(l); i < int(r); ++i)
#define forn2(i,n) forn3 (i, 0, n)
#define forn(...) ARG4(__VA_ARGS__, forn3, forn2) (__VA_ARGS__)

#define ford3(i,l,r) for (int i = int(r) - 1; i >= int(l); --i)
#define ford2(i,n) ford3 (i, 0, n)
#define ford(...) ARG4(__VA_ARGS__, ford3, ford2) (__VA_ARGS__)

#define ve vector
#define pa pair
#define tu tuple
#define mp make_pair
#define mt make_tuple
#define pb emplace_back
#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

typedef long double ld;
typedef int64_t ll;
typedef uint64_t ull;
typedef uint32_t ui;
typedef uint16_t us;
typedef uint8_t uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 10000;

int n, k;
ll a[N];

ll get_sum(int i, int j) {
	ll x, y;
	cout << "and " << i + 1 << " " << j + 1 << endl;
	cin >> x;
	cout << "or " << i + 1 << " " << j + 1 << endl;
	cin >> y;
	return x + y;
}

int main() {
	cin >> n >> k;
	--k;

	ll s01 = get_sum(0, 1);
	ll s02 = get_sum(0, 2);
	ll s12 = get_sum(1, 2);
	a[0] = (s01 + s02 - s12) / 2;
	a[1] = s01 - a[0];
	a[2] = s02 - a[0];
	forn (i, 3, n) {
		a[i] = get_sum(0, i) - a[0];
	}
	debug(a, a + n);
	sort(a, a + n);
	cout << "finish " << a[k] << endl;
	return 0;
}