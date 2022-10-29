#include <bits/stdc++.h>
using namespace std;

#ifdef SG
	#include <debug.h>
    #include <sys/time.h>
    #include <sys/resource.h>
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
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int MAXN = 2050;

struct Input {
    int h, w, n;
    int x[MAXN], y[MAXN];
	bool read () {
        if (!(cin >> h >> w >> n)) {
            return 0;
        }
        forn(i, n) {
            cin >> x[i] >> y[i];
        }
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
    int ans;
	void write () {
        cout << ans << '\n';
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

const int MOD = 1000000007;
const int MAXL = 200500;

struct Solution: Data {
    int fact[MAXL], rfact[MAXL];
    int rev(int x)
    {
        int res = 1, st = MOD - 2;
        while (st) {
            if (st & 1) {
                res = 1ll * res * x % MOD;
            }
            st /= 2;
            x = 1ll * x * x % MOD;
        }
        return res;
    }
    void precalc()
    {
        fact[0] = rfact[0] = 1;
        forn(i, 1, MAXL) {
            fact[i] = 1ll * fact[i - 1] * i % MOD;
            rfact[i] = rev(fact[i]);
        }
    }
    int binom(int n, int k)
    {
        if (n < k || k < 0) return 0;
        int a = fact[n], b = rfact[k], c = rfact[n - k];
        return (1ll * a * b) % MOD * c % MOD;
    }
    int cnt[MAXN];
	void solve () {
        ve< pii > points;
        x[n] = h, y[n] = w;
        n++;
        forn(i, n) {
            points.pb({x[i], y[i]});
        }
        sort(all(points));
        forn(i, n) {
            int dx = points[i].fs - 1, dy = points[i].sc - 1;
            cnt[i] = binom(dx + dy, dx);
            forn(j, i) {
                if (points[i].fs >= points[j].fs && points[i].sc >= points[j].sc) {
                    int dx1 = points[i].fs - points[j].fs, dy1 = points[i].sc - points[j].sc;
                    int mult1 = cnt[j], mult2 = binom(dx1 + dy1, dx1);
                    cnt[i] = (cnt[i] - 1ll * mult1 * mult2 % MOD + MOD) % MOD;
                }
            }
        }
        debug(points);
        debug(cnt, cnt + n);
        ans = cnt[n - 1];
	}
	
	void clear () {
	}
};

Solution sol;

int main () {
    ios_base::sync_with_stdio(false);
	cout.setf(ios::showpoint | ios::fixed);
    cout.precision(20);
    sol.precalc();
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