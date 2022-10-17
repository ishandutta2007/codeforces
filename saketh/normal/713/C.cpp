#include <bits/stdc++.h>
using namespace std;

// template {{{
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define f first
#define s second
#define resz resize

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define sort_by(x, y) sort(all(x), [&](const auto& a, const auto& b) { return y; })

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;
using vpdd = vector<pdd>;
using vvpdd = vector<vpdd>;

template<typename T> void ckmin(T& a, const T& b) { a = min(a, b); }
template<typename T> void ckmax(T& a, const T& b) { a = max(a, b); }

template<typename T> using max_heap = priority_queue<T>;
template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace __input {
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);

    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) {
        re(first); re(rest...);
    }

    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}
using namespace __input;

namespace __output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const deque<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);

    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) {
        pr(first); pr(rest...);
    }

    template<class T1, class T2> void pr(const pair<T1,T2>& x) {
        pr("{",x.f,", ",x.s,"}");
    }
    template<class T, bool pretty = true> void prContain(const T& x) {
        if (pretty) pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?pretty?", ":" ":"",a), fst = 0;
        if (pretty) pr("}");
    }
    template<class T> void pc(const T& x) { prContain<T, false>(x); pr("\n"); }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const deque<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }

    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) {
        pr(first); ps();
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) {
        pr(first," "); ps(rest...);
    }
}
using namespace __output;

#define TRACE(x) x
#define __pn(x) pr(#x, " = ")
#define pd(...) __pn((__VA_ARGS__)), ps(__VA_ARGS__), cout << flush

namespace __numeric {
    template<typename T>
    typename enable_if<is_integral<T>::value, T>::type floor(T n, T d) {
        assert(d != 0);
        if (d < 0) tie(n, d) = mp(-n, -d);
        return n / d - ((n < 0) && (n % d));
    }
    template<typename T>
    typename enable_if<is_integral<T>::value, T>::type ceil(T n, T d) {
        assert(d != 0);
        if (d < 0) tie(n, d) = mp(-n, -d);
        return n / d + ((n > 0) && (n % d));
    }
};
using namespace __numeric;

namespace __algorithm {
    template<typename T> void dedup(vector<T>& v) {
        sort(all(v)); v.erase(unique(all(v)), v.end());
    }
    template<typename T> typename vector<T>::iterator find(vector<T>& v, const T& x) {
        auto it = lower_bound(all(v), x); return it != v.end() && *it == x ? it : v.end();
    }
    template<typename T> size_t index(vector<T>& v, const T& x) {
        auto it = find(v, x); assert(it != v.end() && *it == x); return it - v.begin();
    }
    template<typename C, typename T, typename OP> vector<T> prefixes(const C& v, T id, OP op) {
        vector<T> r(sz(v)+1, id); F0R (i, sz(v)) r[i+1] = op(r[i], v[i]); return r;
    }
    template<typename C, typename T, typename OP> vector<T> suffixes(const C& v, T id, OP op) {
        vector<T> r(sz(v)+1, id); F0Rd (i, sz(v)) r[i] = op(v[i], r[i+1]); return r;
    }
}
using namespace __algorithm;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
struct monostate {
    friend istream& operator>>(istream& is, const monostate& ms) { return is; }
    friend ostream& operator<<(ostream& os, const monostate& ms) { return os; }
    friend monostate operator+(const monostate& a, const monostate& b) { return a; }
} ms;
#pragma GCC diagnostic pop

namespace __io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        cout << fixed << setprecision(15);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}
using namespace __io;
// }}}

template<typename T> struct PWLC {
    T y0;
    max_heap<pair<T, T>> left;
    min_heap<pair<T, T>> right;
    T left_offset = 0, right_offset = 0;

    PWLC(T _y0 = 0) : y0(_y0) {}

    /* __ : y = alpha */
    static PWLC constant(T alpha) { return PWLC(alpha); }
    /* \_ : y = max(0, beta * (x - x0)) */
    static PWLC decreasing(T x0, T beta = -1) { assert(beta <= 0); PWLC f; f.left.push({ x0, -beta }); return f; }
    /* _/ : y = max(0, beta * (x - x0)) */
    static PWLC increasing(T x0, T beta =  1) { assert(beta >= 0); PWLC f; f.right.push({ x0, beta }); return f; }
    /* \/ : y = beta * abs(x - x0) */
    static PWLC abs(T x0, T beta = 1) { return decreasing(x0, -beta) + increasing(x0, beta); }

    /* f'(x) = f(x + c) */
    void shift(int c) { left_offset -= c; right_offset -= c; }
    /* \_/ => \__ : f'(x') = min_{x <= x'} f(x) */
    void prefix_min() { while (!right.empty()) right.pop(); }
    /* \_/ => __/ : f'(x') = min_{x >= x'} f(x) */
    void suffix_min() { while (!left.empty()) left.pop(); }
	/* \_/ => \__/ : f'(x') = min_{dx in [xl, xr]} f(x' + dx) */
	void range_min(T xl, T xr) {
		assert(xl <= xr);
		if (xl > 0) shift(xl), tie(xl, xr) = make_pair(0, xr - xl);
		if (xr < 0) shift(xr), tie(xl, xr) = make_pair(xl - xr, 0);
		left_offset -= xr;
		right_offset -= xl;
	}

    T minimum() const { return y0; }
	T left_arg_min() const { return left.empty() ? numeric_limits<T>::min() : (left.top().first + left_offset); }
	T right_arg_min() const { return right.empty() ? numeric_limits<T>::max() : (right.top().first + right_offset); }

    void operator+=(PWLC o) {
        y0 += o.y0;
		for (; !o.left.empty(); o.left.pop()) {
			T x = o.left.top().first + o.left_offset;
			T beta_change = o.left.top().second;

			if (x <= right_arg_min()) {
				left.push({ x - left_offset, beta_change });
			} else {
				T x0 = right_arg_min();
				y0 += (x - x0) * beta_change;
				right.push({ x - right_offset, beta_change });
				for (T beta = beta_change; beta > 0; ) {
					T next_change = right.top().second;
					right.pop();
					if (next_change >= beta) {
						left.push({ x0 - left_offset, beta });
						if (next_change > beta) right.push({ x0 - right_offset, next_change - beta });
						beta = 0;
					} else {
						beta -= next_change;
						y0 -= beta * (right_arg_min() - x0);
						x0 = right_arg_min();
					}
				}
			}
		}
		for (; !o.right.empty(); o.right.pop()) {
			T x = o.right.top().first + o.right_offset;
			T beta_change = o.right.top().second;

			if (x >= left_arg_min()) {
				right.push({ x - right_offset, beta_change });
			} else {
				T x0 = left_arg_min();
				y0 += (x0 - x) * beta_change;
				left.push({ x - left_offset, beta_change });
				for (T beta = beta_change; beta > 0; ) {
					T next_change = left.top().second;
					left.pop();
					if (next_change >= beta) {
						right.push({ x0 - right_offset, beta });
						if (next_change > beta) left.push({ x0 - left_offset, next_change - beta });
						beta = 0;
					} else {
						beta -= next_change;
						y0 -= beta * (x0 - left_arg_min());
						x0 = left_arg_min();
					}
				}
			}
		}
    }
	friend PWLC operator+(const PWLC &a, const PWLC &b) { PWLC f(a); f += b; return f; }
};

int main() {
    setIO();

	int N; re(N); vi a(N); re(a);

	PWLC<ll> f;

	F0R (i, N) {
		f.prefix_min();
		f.shift(-1);
		f += PWLC<ll>::abs(a[i]);
	}

	ps(f.minimum());

    // did you check N=1? did you mix up N,M?
    // check your "infinity" and "null" values against the bounds
    return 0;
}