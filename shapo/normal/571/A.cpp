#include <bits/stdc++.h>
using namespace std;

#ifdef SG
	#include <debug.h>
#else
	#define show(...)
	#define debug(...)
	#define deepen(...)
	#define timer(...)
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
#define pb push_back
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

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

struct Input {
	
    int a, b, c, l;
	bool read () {
        return (cin >> a >> b >> c >> l);
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
    ll ans;	
	void write () {
		cout << ans << '\n';
	}
};

struct Solution: Data {
    ve< ll > psum;	
    ll calc_sum(int r, int from, int to)
    {
        to = r - to, from = r - from;
        return psum[from] - (to == 0 ? 0 : psum[to - 1]);
    }
    ll find_rec(int r, int alpha, int beta) {
        if (r < 0) return 0ll;
        if (alpha > r || beta < -r) {
            return 0ll;
        }
        ll ans = 0ll;
        alpha = max(alpha, -r), beta = min(beta, r);
        if (1ll * alpha * beta < 0ll) {
            ans += calc_sum(r, 0ll, beta) + calc_sum(r, 1ll, -alpha);
        } else {
            if (alpha < 0) {
                swap(alpha, beta);
                alpha *= -1, beta *= -1;
            }
            ans += calc_sum(r, alpha, beta);
        }
        return ans;
    }
	void solve () {
        psum.assign(l + 1, 0ll);
        forn(i, l + 1) {
            psum[i] = i / 2 + 1;
        }
        partial_sum(all(psum), psum.begin());
	    ans = 0ll;	
        forn(z, l + 1) {
            int alpha = z + (b + c - a), beta = z + (a + c - b);
            int t = z - (a + b - c) + 1, r = l - z;
            if (t > r) continue;
            beta--;
            alpha = 1 - alpha;
            ans += find_rec(r, alpha, beta) - find_rec(t - 1, alpha, beta);
        } 
	}
	
	void clear () {
		*this = Solution();
	}
};

Solution sol;

int main () {
	cout.setf(ios::showpoint | ios::fixed);
	cout.precision(20);
#ifdef SG
	while (sol.read()) {
		sol.solve();
		sol.write();
		sol.clear();
	}
#else
	sol.read();
	sol.solve();
	sol.write();
#endif
	return 0;
}