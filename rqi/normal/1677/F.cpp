#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
// #include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
// #include <cuchar>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
// #include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#if __cplusplus >= 201402L
#include <shared_mutex>
#endif

#if __cplusplus >= 201703L
#include <any>
#include <charconv>
// #include <execution>
#include <filesystem>
#include <optional>
// #include <memory_resource>
#include <string_view>
#include <variant>
#endif

#if __cplusplus > 201703L
#include <barrier>
#include <bit>
#include <compare>
#include <concepts>
#if __cpp_impl_coroutine
# include <coroutine>
#endif
#include <latch>
#include <numbers>
#include <ranges>
#include <span>
#include <stop_token>
#include <semaphore>
#include <source_location>
#include <syncstream>
#include <version>
#endif

using namespace std;
 
using ll = long long;
using db = long double; // or double, if TL is tight
using str = string; // yay python! 

// pairs
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;
#define mp make_pair
#define f first
#define s second

#define tcT template<class T
#define tcTU tcT, class U
// ^ lol this makes everything look weird but I'll try it
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;

// vectors
// oops size(x), rbegin(x), rend(x) need C++17
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()

#define lb lower_bound
#define ub upper_bound
tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }
tcT> int upb(V<T>& a, const T& b) { return int(ub(all(a),b)-bg(a)); }

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

const int MOD = 998244353;
const int MX = 2e5+5;
const ll BIG = 1e18; // not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4]{1,0,-1,0}, dy[4]{0,1,0,-1}; // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

// bitwise ops
// also see https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
constexpr int pct(int x) { return __builtin_popcount(x); } // # of bits set
constexpr int bits(int x) { // assert(x >= 0); // make C++11 compatible until USACO updates ...
	return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x)) 
constexpr int p2(int x) { return 1<<x; }
constexpr int msk2(int x) { return p2(x)-1; }

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down

tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; } // set a = max(a,b)

tcTU> T fstTrue(T lo, T hi, U f) {
	++hi; assert(lo <= hi); // assuming f is increasing
	while (lo < hi) { // find first index such that f is true 
		T mid = lo+(hi-lo)/2;
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
	--lo; assert(lo <= hi); // assuming f is decreasing
	while (lo < hi) { // find first index such that f is true 
		T mid = lo+(hi-lo+1)/2;
		f(mid) ? lo = mid : hi = mid-1;
	} 
	return lo;
}
tcT> void remDup(vector<T>& v) { // sort and remove duplicates
	sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcTU> void erase(T& t, const U& u) { // don't erase
	auto it = t.find(u); assert(it != end(t));
	t.erase(it); } // element that doesn't exist from (multi)set

#define tcTUU tcT, class ...U

inline namespace Helpers {
	//////////// is_iterable
	// https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable
	// this gets used only when we can call begin() and end() on that type
	tcT, class = void> struct is_iterable : false_type {};
	tcT> struct is_iterable<T, void_t<decltype(begin(declval<T>())),
	                                  decltype(end(declval<T>()))
	                                 >
	                       > : true_type {};
	tcT> constexpr bool is_iterable_v = is_iterable<T>::value;

	//////////// is_readable
	tcT, class = void> struct is_readable : false_type {};
	tcT> struct is_readable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cin >> declval<T&>()), istream&>
	        >
	    > : true_type {};
	tcT> constexpr bool is_readable_v = is_readable<T>::value;

	//////////// is_printable
	// // https://nafe.es/posts/2020-02-29-is-printable/
	tcT, class = void> struct is_printable : false_type {};
	tcT> struct is_printable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cout << declval<T>()), ostream&>
	        >
	    > : true_type {};
	tcT> constexpr bool is_printable_v = is_printable<T>::value;
}

inline namespace Input {
	tcT> constexpr bool needs_input_v = !is_readable_v<T> && is_iterable_v<T>;
	tcTUU> void re(T& t, U&... u);
	tcTU> void re(pair<T,U>& p); // pairs

	// re: read
	tcT> typename enable_if<is_readable_v<T>,void>::type re(T& x) { cin >> x; } // default
	tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } // complex
	tcT> typename enable_if<needs_input_v<T>,void>::type re(T& i); // ex. vectors, arrays
	tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
	tcT> typename enable_if<needs_input_v<T>,void>::type re(T& i) {
		each(x,i) re(x); }
	tcTUU> void re(T& t, U&... u) { re(t); re(u...); } // read multiple

	// rv: resize and read vectors
	void rv(size_t) {}
	tcTUU> void rv(size_t N, V<T>& t, U&... u);
	template<class...U> void rv(size_t, size_t N2, U&... u);
	tcTUU> void rv(size_t N, V<T>& t, U&... u) {
		t.rsz(N); re(t);
		rv(N,u...); }
	template<class...U> void rv(size_t, size_t N2, U&... u) {
		rv(N2,u...); }

	// dumb shortcuts to read in ints
	void decrement() {} // subtract one from each
	tcTUU> void decrement(T& t, U&... u) { --t; decrement(u...); }
	#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);
	#define int1(...) ints(__VA_ARGS__); decrement(__VA_ARGS__);
}

inline namespace ToString {
	tcT> constexpr bool needs_output_v = !is_printable_v<T> && is_iterable_v<T>;

	// ts: string representation to print
	tcT> typename enable_if<is_printable_v<T>,str>::type ts(T v) {
		stringstream ss; ss << fixed << setprecision(15) << v;
		return ss.str(); } // default
	tcT> str bit_vec(T t) { // bit vector to string
		str res = "{"; F0R(i,sz(t)) res += ts(t[i]);
		res += "}"; return res; }
	str ts(V<bool> v) { return bit_vec(v); }
	template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } // bit vector
	tcTU> str ts(pair<T,U> p); // pairs
	tcT> typename enable_if<needs_output_v<T>,str>::type ts(T v); // vectors, arrays
	tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
	tcT> typename enable_if<is_iterable_v<T>,str>::type ts_sep(T v, str sep) {
		// convert container to string w/ separator sep
		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += sep;
			fst = 0; res += ts(x);
		}
		return res;
	}
	tcT> typename enable_if<needs_output_v<T>,str>::type ts(T v) {
		return "{"+ts_sep(v,", ")+"}"; }

	// for nested DS
	template<int, class T> typename enable_if<!needs_output_v<T>,vs>::type 
	  ts_lev(const T& v) { return {ts(v)}; }
	template<int lev, class T> typename enable_if<needs_output_v<T>,vs>::type 
	  ts_lev(const T& v) {
		if (lev == 0 || !sz(v)) return {ts(v)};
		vs res;
		for (const auto& t: v) {
			if (sz(res)) res.bk += ",";
			vs tmp = ts_lev<lev-1>(t);
			res.ins(end(res),all(tmp));
		}
		F0R(i,sz(res)) {
			str bef = " "; if (i == 0) bef = "{";
			res[i] = bef+res[i];
		}
		res.bk += "}";
		return res;
	}
}

inline namespace Output {
	template<class T> void pr_sep(ostream& os, str, const T& t) { os << ts(t); }
	template<class T, class... U> void pr_sep(ostream& os, str sep, const T& t, const U&... u) {
		pr_sep(os,sep,t); os << sep; pr_sep(os,sep,u...); }
	// print w/ no spaces
	template<class ...T> void pr(const T&... t) { pr_sep(cout,"",t...); } 
	// print w/ spaces, end with newline
	void ps() { cout << "\n"; }
	template<class ...T> void ps(const T&... t) { pr_sep(cout," ",t...); ps(); } 
	// debug to cerr
	template<class ...T> void dbg_out(const T&... t) {
		pr_sep(cerr," | ",t...); cerr << endl; }
	void loc_info(int line, str names) {
		cerr << "Line(" << line << ") -> [" << names << "]: "; }
	template<int lev, class T> void dbgl_out(const T& t) {
		cerr << "\n\n" << ts_sep(ts_lev<lev>(t),"\n") << "\n" << endl; }
	#ifdef LOCAL
		#define dbg(...) loc_info(__LINE__,#__VA_ARGS__), dbg_out(__VA_ARGS__)
		#define dbgl(lev,x) loc_info(__LINE__,#x), dbgl_out<lev>(x)
	#else // don't actually submit with this
		#define dbg(...) 0
		#define dbgl(lev,x) 0
	#endif

	const clock_t beg = clock();
	#define dbg_time() dbg((db)(clock()-beg)/CLOCKS_PER_SEC)
}

inline namespace FileIO {
	void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
	void setOut(str s) { freopen(s.c_str(),"w",stdout); }
	void setIO(str s = "") {
		cin.tie(0)->sync_with_stdio(0); // unsync C / C++ I/O streams
		// cin.exceptions(cin.failbit);
		// throws exception when do smth illegal
		// ex. try to read letter into int
		if (sz(s)) setIn(s+".in"), setOut(s+".out"); // for old USACO
	}
}

/**
 * Description: modular arithmetic operations 
 * Source: 
	* KACTL
	* https://codeforces.com/blog/entry/63903
	* https://codeforces.com/contest/1261/submission/65632855 (tourist)
	* https://codeforces.com/contest/1264/submission/66344993 (ksun)
	* also see https://github.com/ecnerwala/cp-book/blob/master/src/modnum.hpp (ecnerwal)
 * Verification: 
	* https://open.kattis.com/problems/modulararithmetic
 */

template<int MOD, int RT> struct mint {
	static const int mod = MOD;
	static constexpr mint rt() { return RT; } // primitive root for FFT
	int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
	mint():v(0) {}
	mint(ll _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
		if (v < 0) v += MOD; }
	bool operator==(const mint& o) const {
		return v == o.v; }
	friend bool operator!=(const mint& a, const mint& b) { 
		return !(a == b); }
	friend bool operator<(const mint& a, const mint& b) { 
		return a.v < b.v; }
	friend void re(mint& a) { ll x; re(x); a = mint(x); }
	friend str ts(mint a) { return ts(a.v); }
   
	mint& operator+=(const mint& o) { 
		if ((v += o.v) >= MOD) v -= MOD; 
		return *this; }
	mint& operator-=(const mint& o) { 
		if ((v -= o.v) < 0) v += MOD; 
		return *this; }
	mint& operator*=(const mint& o) { 
		v = int((ll)v*o.v%MOD); return *this; }
	mint& operator/=(const mint& o) { return (*this) *= inv(o); }
	friend mint pow(mint a, ll p) {
		mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans; }
	friend mint inv(const mint& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	mint operator-() const { return mint(-v); }
	mint& operator++() { return *this += 1; }
	mint& operator--() { return *this -= 1; }
	friend mint operator+(mint a, const mint& b) { return a += b; }
	friend mint operator-(mint a, const mint& b) { return a -= b; }
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	friend mint operator/(mint a, const mint& b) { return a /= b; }
};

using mi = mint<MOD,5>; // 5 is primitive root for both common mods
using vmi = V<mi>;
using pmi = pair<mi,mi>;
using vpmi = V<pmi>;

V<vmi> scmb; // small combinations
void genComb(int SZ) {
	scmb.assign(SZ,vmi(SZ)); scmb[0][0] = 1;
	FOR(i,1,SZ) F0R(j,i+1) 
		scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}


/**
 * Description: 2D matrix operations.
 * Source: KACTL
 * Verification: https://dmoj.ca/problem/si17c1p5, SPOJ MIFF
 */

using T = mi;
using Mat = V<V<T>>; // use array instead if tight TL

Mat makeMat(int r, int c) { return Mat(r,V<T>(c)); }
Mat makeId(int n) { 
	Mat m = makeMat(n,n);
	F0R(i,n) m[i][i] = 1;
	return m;
}
Mat& operator+=(Mat& a, const Mat& b) {
	assert(sz(a) == sz(b) && sz(a[0]) == sz(b[0]));
	F0R(i,sz(a)) F0R(j,sz(a[0])) a[i][j] += b[i][j];
	return a;
}
Mat& operator-=(Mat& a, const Mat& b) {
	assert(sz(a) == sz(b) && sz(a[0]) == sz(b[0]));
	F0R(i,sz(a)) F0R(j,sz(a[0])) a[i][j] -= b[i][j];
	return a;
}
Mat operator*(const Mat& a, const Mat& b) {
	int x = sz(a), y = sz(a[0]), z = sz(b[0]); 
	assert(y == sz(b)); Mat c = makeMat(x,z);
	F0R(i,x) F0R(j,y) F0R(k,z) c[i][k] += a[i][j]*b[j][k];
	return c;
}
Mat operator+(Mat a, const Mat& b) { return a += b; }
Mat operator-(Mat a, const Mat& b) { return a -= b; }
Mat& operator*=(Mat& a, const Mat& b) { return a = a*b; }
Mat pow(Mat m, ll p) {
	int n = sz(m); assert(n == sz(m[0]) && p >= 0);
	Mat res = makeId(n);
	for (; p; p /= 2, m *= m) if (p&1) res *= m;
	return res;
}

/**
 * Description: Basic poly ops including division. Can replace \texttt{T} with double, complex.
 * Source: Own. Also see
	* https://github.com/kth-competitive-programming/kactl/blob/master/content/numerical/PolyInterpolate.h
	* https://github.com/ecnerwala/icpc-book/blob/master/content/numerical/fft.cpp
 * Verification: see FFT
 */


using T = mi; using poly = V<T>;
void remz(poly& p) { while (sz(p)&&p.bk==T(0)) p.pop_back(); }
poly REMZ(poly p) { remz(p); return p; }
poly rev(poly p) { reverse(all(p)); return p; }
poly shift(poly p, int x) { 
	if (x >= 0) p.insert(begin(p),x,0); 
	else assert(sz(p)+x >= 0), p.erase(begin(p),begin(p)-x);
	return p; 
}
poly RSZ(const poly& p, int x) { 
	if (x <= sz(p)) return poly(begin(p),begin(p)+x);
	poly q = p; q.rsz(x); return q;  }
T eval(const poly& p, T x) { // evaluate at point x
	T res = 0; R0F(i,sz(p)) res = x*res+p[i]; 
	return res; }
poly dif(const poly& p) { // differentiate
	poly res; FOR(i,1,sz(p)) res.pb(T(i)*p[i]); 
	return res; }
poly integ(const poly& p) { // integrate
	static poly invs{0,1};
	for (int i = sz(invs); i <= sz(p); ++i) 
		invs.pb(-MOD/i*invs[MOD%i]);
	poly res(sz(p)+1); F0R(i,sz(p)) res[i+1] = p[i]*invs[i+1];
	return res; 
}

poly& operator+=(poly& l, const poly& r) {
	l.rsz(max(sz(l),sz(r))); F0R(i,sz(r)) l[i] += r[i]; 
	return l; }
poly& operator-=(poly& l, const poly& r) {
	l.rsz(max(sz(l),sz(r))); F0R(i,sz(r)) l[i] -= r[i]; 
	return l; }
poly& operator*=(poly& l, const T& r) { each(t,l) t *= r; 
	return l;	 }
poly& operator/=(poly& l, const T& r) { each(t,l) t /= r; 
	return l; }
poly operator+(poly l, const poly& r) { return l += r; }
poly operator-(poly l, const poly& r) { return l -= r; }
poly operator-(poly l) { each(t,l) t *= -1; return l; }
poly operator*(poly l, const T& r) { return l *= r; }
poly operator*(const T& r, const poly& l) { return l*r; }
poly operator/(poly l, const T& r) { return l /= r;	 }
poly operator*(const poly& l, const poly& r) {
	if (!min(sz(l),sz(r))) return {};
	poly x(sz(l)+sz(r)-1); 
	F0R(i,sz(l)) F0R(j,sz(r)) x[i+j] += l[i]*r[j];
	return x;
}
poly& operator*=(poly& l, const poly& r) { return l = l*r; }

pair<poly,poly> quoRem(poly a, poly b) { 
	remz(a); remz(b); assert(sz(b));
	T lst = b.bk, B = T(1)/lst; each(t,a) t *= B; 
	each(t,b) t *= B;
	poly q(max(sz(a)-sz(b)+1,0));
	for (int dif; (dif=sz(a)-sz(b)) >= 0; remz(a)) {
		q[dif] = a.bk; F0R(i,sz(b)) a[i+dif] -= q[dif]*b[i]; }
	each(t,a) t *= lst;
	return {q,a}; // quotient, remainder
}
poly operator%(const poly& a, const poly& b) { 
	return quoRem(a,b).s; }
/**poly operator/(const poly& a, const poly& b) { 
	return quoRem(a,b).f; }
poly a = {1,3,5,8,6,0,0,0,0}, b = {1,5,1};
ps(quoRem(a,b)); a = 2*a, b = 2*b; ps(quoRem(a,b));
poly gcd(poly a, poly b) { return b == poly{} ? a : gcd(b,a%b); }*/
T resultant(poly a, poly b) { // R(A,B)
	// =b_m^n*prod_{j=1}^mA(mu_j)
	// =b_m^na_n^m*prod_{i=1}^nprod_{j=1}^m(mu_j-lambda_i)
	// =(-1)^{mn}a_n^m*prod_{i=1}^nB(lambda_i)
	// =(-1)^{nm}R(B,A)
	// Also, R(A,B)=b_m^{deg(A)-deg(A-CB)}R(A-CB,B)
	int ad = sz(a)-1, bd = sz(b)-1; 
	if (bd <= 0) return bd < 0 ? 0 : pow(b.bk,ad);
	int pw = ad; a = a%b; pw -= (ad = sz(a)-1);
	return resultant(b,a)*pow(b.bk,pw)*T((bd&ad&1)?-1:1);
}
/**
 * Description: Multiply polynomials of ints for any modulus $<2^{31}$. 
 	* For XOR convolution ignore \texttt{m} within \texttt{fft}. 
 * Time: O(N\log N)
 * Source: 
 	* KACTL (https://github.com/kth-competitive-programming/kactl/blob/master/content/numerical/NumberTheoreticTransform.h)
 	* https://cp-algorithms.com/algebra/fft.html
 	* https://csacademy.com/blog/fast-fourier-transform-and-variations-of-it
 	* maroonrk
 	* https://github.com/atcoder/ac-library/blob/master/atcoder/convolution.hpp
 * Verification: 
	* https://judge.yosupo.jp/problem/convolution_mod
	* SPOJ polymul, CSA manhattan, CF Perfect Encoding
	* http://codeforces.com/contest/632/problem/E
 */

// const int MOD = 998244353;
tcT> void fft(V<T>& A, bool inv = 0) { // NTT
	int n = sz(A); assert((T::mod-1)%n == 0); V<T> B(n);
	for(int b = n/2; b; b /= 2, swap(A,B)) { // w = n/b'th root
		T w = pow(T::rt(),(T::mod-1)/n*b), m = 1; 
		for(int i = 0; i < n; i += b*2, m *= w) F0R(j,b) {
			T u = A[i+j], v = A[i+j+b]*m;
			B[i/2+j] = u+v; B[i/2+j+n/2] = u-v;
		}
	}
	if (inv) { reverse(1+all(A)); 
		T z = T(1)/T(n); each(t,A) t *= z; }
} // for NTT-able moduli
tcT> V<T> mul(V<T> A, V<T> B) {
	if (!min(sz(A),sz(B))) return {};
	int s = sz(A)+sz(B)-1, n = 1; for (; n < s; n *= 2);
	bool eq = A == B; A.rsz(n), fft(A);
	if (eq) B = A; // squaring A, reuse result
	else B.rsz(n), fft(B);
	F0R(i,n) A[i] *= B[i];
	fft(A,1); A.rsz(s); return A;
}
template<class M, class T> V<M> mulMod(V<T> x, V<T> y) {
	auto con = [](const V<T>& v) {
		V<M> w(sz(v)); F0R(i,sz(v)) w[i] = (int)v[i];
		return w; };
	return mul(con(x),con(y));
} // arbitrary moduli
tcT> V<T> MUL(const V<T>& A, const V<T>& B) {
	using m0 = mint<(119<<23)+1,62>; auto c0 = mulMod<m0>(A,B);
	using m1 = mint<(5<<25)+1,  62>; auto c1 = mulMod<m1>(A,B);
	using m2 = mint<(7<<26)+1,  62>; auto c2 = mulMod<m2>(A,B);
	int n = sz(c0); V<T> res(n); m1 r01 = 1/m1(m0::mod); 
	m2 r02 = 1/m2(m0::mod), r12 = 1/m2(m1::mod);
	F0R(i,n) { // a=remainder mod m0::mod, b fixes it mod m1::mod
		int a = c0[i].v, b = ((c1[i]-a)*r01).v, 
			c = (((c2[i]-a)*r02-b)*r12).v;
		res[i] = (T(c)*m1::mod+b)*m0::mod+a; // c fixes m2::mod
	}
	return res;
}

/**
 * Description: Multiply small polys directly, otherwise use FFT.
 * Source: KACTL, https://cp-algorithms.com/algebra/fft.html
 */

bool small(const poly& a, const poly& b) { // multiply directly
	return min(sz(a),sz(b)) <= 60; }
// vmi smart(const vmi& a, const vmi& b) { return mul(a,b); }
// vl smart(const vl& a, const vl& b) {
// 	auto X = mul(vcd(all(a)),vcd(all(b)));
// 	vl x(sz(X)); F0R(i,sz(X)) x[i] = round(X[i].real());
// 	return x; }
poly conv(const poly& a, const poly& b) {
	return small(a,b) ? a*b : mul(a,b); } 
/**
 * Description: computes $A^{-1}$ such that $AA^{-1}\equiv 1\pmod{x^n}$.
 	* Newton's method: If you want $F(x)=0$ and $F(Q_k)\equiv 0\pmod{x^a}$
 	* then $Q_{k+1}=Q_k-\frac{F(Q_k)}{F'(Q_k)}\pmod{x^{2a}}$ satisfies
 	* $F(Q_{k+1})\equiv 0 \pmod{x^{2a}}$. Application: if $f(n),g(n)$ are the
 	* \#s of forests and trees on $n$ nodes then 
 	* $\sum_{n=0}^{\infty}f(n)x^n=\exp\left(\sum_{n=1}^{\infty}\frac{g(n)}{n!}\right)$.
 * Time: O(N\log N)
 * Source: CF
 	* http://people.csail.mit.edu/madhu/ST12/scribe/lect06.pdf
 	* https://cp-algorithms.com/algebra/polynomial.html
 	* maroonrk's submissions ^_^
 	* if you need faster exp for some reason, see https://old.yosupo.jp/submission/36732 ...
 * Usage: vmi v={1,5,2,3,4}; ps(exp(2*log(v,9),9)); // squares v
 * Verification: https://codeforces.com/contest/438/problem/E
 	* https://codeforces.com/gym/102028/submission/77687049
 	* https://loj.ac/problem/6703 (MultipointEval)
 */

/// WARNING: lots of sketchy optimizations to improve constant factors of calls to FFT ...
/// there are much simpler versions of functions below, but they are slower ...

void double_inverse_given(poly& A_inv, poly a, 
		const poly& a_inv) {
	int N = sz(A_inv);
	F0R(i,2*N) a[i] *= a_inv[i];
	fft(a,1); F0R(i,N) a[i] = 0; 
	/// now a represents 1+stuff_{N..3*N-2}, we only care about stuff_{N..2*N-1} 
	/// so we zero out the rest
	fft(a); F0R(i,2*N) a[i] *= a_inv[i];
	fft(a,1); FOR(i,N,2*N) A_inv.pb(-a[i]);
}

void double_inverse(const poly& A, poly& A_inv) { 
	/// given first 2*N terms of A and N terms of A_inv, extend A_inv
	/// add terms N...2*N-1 of -A_inv^2A to A_inv
	int N = sz(A_inv);
	poly f = RSZ(A,2*N); fft(f); // first 2N terms of A
	poly g = RSZ(A_inv,2*N); fft(g);
	double_inverse_given(A_inv,f,g);
}

// A_inv such that A*A_inv = 1
poly inv(const poly& A, int NEED_N) { assert(A[0] != 0);
	// F(Q)=1/Q
	// Q-F(Q)/F'(Q)=Q-(1/Q-A)/(-Q^{-2})
	// =2Q-Q^2A=Q+Q(1-QA)
	poly A_inv{1/A[0]};
	while (sz(A_inv) < NEED_N) double_inverse(A,A_inv);
	return RSZ(A_inv,NEED_N);
}

// e^{result}=A
poly log(poly A, int N) { assert(A[0] == 1); 
	// ln A = integral(A'/A)
	return integ(RSZ(mul(dif(A),inv(A,N-1)),N-1)); }

// A_sqrt^2=A
poly sqrt(const poly& A, int NEED_N) { assert(A[0] == 1); 
	// F(Q)=Q^2-A
	// Q-F(Q)/F'(Q)=Q-(Q^2-A)/(2Q)
	// =1/2(Q+A/Q)
	const T i2 = T(1)/T(2);
	poly A_sqrt{1}, A_sqrt_inv{1},a_sqrt{1};
	auto value_at = [&](int i) -> T { return i<sz(A)?A[i]:0; };
	for (int N = 1; N < NEED_N; N *= 2) {
		F0R(i,N) a_sqrt[i] *= a_sqrt[i]; // z is transform of Q^2
		fft(a_sqrt,1); poly delta(2*N); // set delta = Q^2-A
		F0R(i,N) delta[N+i] = a_sqrt[i]-value_at(i)-value_at(N+i);
		fft(delta); 
		poly a_sqrt_inv = RSZ(A_sqrt_inv,2*N);
		fft(a_sqrt_inv); F0R(i,2*N) delta[i] *= a_sqrt_inv[i];
		fft(delta,1); FOR(i,N,2*N) A_sqrt.pb(-i2*delta[i]);
		// get terms of (Q^2-A)/2Q
		if (2*N >= NEED_N) break;
		a_sqrt = A_sqrt; fft(a_sqrt);
		double_inverse_given(A_sqrt_inv,a_sqrt,a_sqrt_inv);
	}
	return RSZ(A_sqrt,NEED_N);
}

// e^A
poly exp(const poly& A, int NEED_N) { assert(A[0] == 0);
	// F(Q)=ln(Q)-A
	// Q-F(Q)/F'(Q)=Q-(ln(Q)-A)/(1/Q)
	// =Q*(1+A-ln(Q))=Q+Q*(A-ln(Q))
	auto value_at = [&](int i) -> T { return i<sz(A)?A[i]:0; };
	auto conv_given = [&](const poly& a, poly b) {
		b.rsz(sz(a)); fft(b); // fft already applied to a
		F0R(i,sz(b)) b[i] *= a[i];
		fft(b,1); return b; };
	poly A_exp{1}, A_inv{1};
	for (int N = 1; N < NEED_N; N *= 2) { // sz(A_exp) = N
		poly a_exp = RSZ(A_exp,2*N); fft(a_exp);
		if (N > 1) {
			poly a_inv_small = RSZ(A_inv,2*N); fft(a_inv_small);
			F0R(i,2*N) a_inv_small[i] *= a_inv_small[i]*a_exp[i];
			fft(a_inv_small,1);
			FOR(i,N/2,N) A_inv.pb(-a_inv_small[i]);
		}
		poly a_inv = RSZ(A_inv,2*N); fft(a_inv);
		poly ln = conv_given(a_inv,dif(A_exp));
		poly a_inv_exp(2*N); 
		F0R(i,2*N) a_inv_exp[i] = a_inv[i]*a_exp[i];

		poly a_dif = RSZ(dif(RSZ(A,N)),2*N); fft(a_dif);
		F0R(i,2*N) a_inv_exp[i] *= a_dif[i];
		fft(a_inv_exp,1); FOR(i,N,2*N) ln[i] -= a_inv_exp[i];
		ln.pop_back(); ln = integ(ln);

		poly A_minus_ln(N); 
		F0R(i,N) A_minus_ln[i] = value_at(i+N)-ln[i+N];
		poly prod = conv_given(a_exp,A_minus_ln); // conv(N,N)
		FOR(i,N,2*N) A_exp.pb(prod[i-N]);
	} 
	return RSZ(A_exp,NEED_N);
}


pair<poly,poly> divi(const poly& f, const poly& g) {
	if (sz(f) < sz(g)) return {{},f};
	poly q = conv(inv(rev(g),sz(f)-sz(g)+1),rev(f));
	q = rev(RSZ(q,sz(f)-sz(g)+1));
	poly r = RSZ(f-conv(q,g),sz(g)-1); return {q,r};
}

poly pow(poly a, int expo){
	assert(expo <= 100);
	poly res = {1};
	for(int i = 0; i < expo; i++){
		res*=a;
	}
	return res;
}



/**
 * Description: Multipoint evaluation and interpolation
 * Time: O(N\log^2 N)
 */

void segProd(V<poly>& stor, poly& v, int ind, int l, int r) { // v -> places to evaluate at
	if (l == r) { stor[ind] = {-v[l],1}; return; }
	int m = (l+r)/2; segProd(stor,v,2*ind,l,m); segProd(stor,v,2*ind+1,m+1,r);
	stor[ind] = conv(stor[2*ind],stor[2*ind+1]);
}
void evalAll(V<poly>& stor, poly& res, poly v, int ind = 1) {
	v = divi(v,stor[ind]).s;
	if (sz(stor[ind]) == 2) { res.pb(sz(v)?v[0]:0); return; }
	evalAll(stor,res,v,2*ind); evalAll(stor,res,v,2*ind+1);
}
poly multiEval(poly v, poly p) {
	V<poly> stor(4*sz(p)); segProd(stor,p,1,0,sz(p)-1);
	poly res; evalAll(stor,res,v); return res; }

poly combAll(V<poly>& stor, poly& dems, int ind, int l, int r) {
	if (l == r) return {dems[l]};
	int m = (l+r)/2;
	poly a = combAll(stor,dems,2*ind,l,m), b = combAll(stor,dems,2*ind+1,m+1,r);
	return conv(a,stor[2*ind+1])+conv(b,stor[2*ind]);
}
poly interpolate(V<pair<T,T>> v) {
	int n = sz(v); poly x; each(t,v) x.pb(t.f);
	V<poly> stor(4*n); segProd(stor,x,1,0,n-1);
	poly dems; evalAll(stor,dems,dif(stor[1]));
	F0R(i,n) dems[i] = v[i].s/dems[i];
	return combAll(stor,dems,1,0,n-1);
}


/**
 * Description: pre-compute factorial mod inverses,
 	* assumes $MOD$ is prime and $SZ < MOD$.
 * Time: O(SZ)
 * Source: KACTL
 * Verification: https://dmoj.ca/problem/tle17c4p5
 */

vmi invs, fac, ifac;
void genFac(int SZ) {
	invs.rsz(SZ), fac.rsz(SZ), ifac.rsz(SZ); 
	invs[1] = fac[0] = ifac[0] = 1; 
	FOR(i,2,SZ) invs[i] = mi(-(ll)MOD/i*(int)invs[MOD%i]);
	FOR(i,1,SZ) fac[i] = fac[i-1]*i, ifac[i] = ifac[i-1]*invs[i];
}
mi comb(int a, int b) {
	if (a < b || b < 0) return 0;
	return fac[a]*ifac[b]*ifac[a-b]; }

const int mx = 100005;
int n, k;
mi p;
mi a[mx];

Mat dp[mx];
mi quant[mx];

pair<vmi, vmi> getFracSum(vmi& A, vmi& B, int L, int R){
	if(L == R){
		return mp(vmi{B[L]}, vmi{1, -A[L]});
	}
	int M = (L+R)/2;
	pair<vmi, vmi> frac1 = getFracSum(A, B, L, M);
	pair<vmi, vmi> frac2 = getFracSum(A, B, M+1, R);
	return mp(conv(frac1.f, frac2.s)+conv(frac1.s, frac2.f), conv(frac1.s, frac2.s));
}
vmi getKthPowers(vmi A, vmi B){
	// vmi res;
	// for(int i = 0; i <= k; i++){
	// 	mi sum = 0;
	// 	for(int j = 0; j <= k; j++){
	// 		sum+=B[j]*pow(A[j], i);
	// 	}
	// 	res.pb(sum);
	// }
	// return res;

	pair<vmi, vmi> frac_sum = getFracSum(A, B, 0, k);

	vmi denom_inv = inv(frac_sum.s, k+5);
	vmi frac_sum_prod = conv(frac_sum.f, denom_inv);
	frac_sum_prod.rsz(k+1);
	return frac_sum_prod;
}

//compute sum from i = 0 to k of B[i]*(x+A[i])^k
vmi solveNext(vmi A, vmi B){
	// vmi res;
	// for(int i = 0; i <= k; i++){
	// 	res+=B[i]*pow(poly{A[i], 1}, k);
	// }
	// return res;
	vmi kth_powers = getKthPowers(A, B);

	vmi res;
	for(int i = 0; i <= k; i++){
		res.pb(kth_powers[k-i]*comb(k, i));
	}
	return res;
}

vmi computePolyS(vmi g){
	// vmi res;
	// for(int i = 0; i <= k; i++){
	// 	res+=g[i]*pow(poly{mi(i), 1}, k);
	// }
	// dbg(g, res);
	vmi A, B;
	for(int i = 0; i <= k; i++){
		A.pb(i);
		B.pb(g[i]);
	}
	return solveNext(A, B);
}

void genQuant(){

	mi second_sum = mi(0);
	for(int i = 0; i <= k+1; i++){
		second_sum+=comb(k+1, i)*pow(mi(-1), i)*pow(p, i);
	}

	vmi second_csums(k+2, mi(0));
	for(int i = 0; i <= k+1; i++){
		second_csums[i]+=comb(k+1, i)*pow(mi(-1), i)*pow(p, i);
		if(i-1 >= 0){
			second_csums[i]+=second_csums[i-1];
		}
	}

	vmi g(k+1, 0);
	for(int i = 0; i <= k; i++){
		g[i] = second_csums[k-i]*pow(p, i);
	}

	
	vmi poly_S = computePolyS(g);
	

	vmi x_vals;
	x_vals.pb(0);
	for(int i = 1; i <= n; i++){
		x_vals.pb(a[i]+1);
	}

	// dbg(x_vals, poly_S);
	// remDup(s_vals);
	// while(sz(poly_S) < sz(x_vals)){
	// 	poly_S.pb(0);
	// }
	// while(sz(x_vals) < sz(poly_S)){
	// 	x_vals.pb(0);
	// }
	dbg("HI1");
	dbg(sz(poly_S), sz(x_vals));
	clock_t BEG = clock();
	vmi y_vals = multiEval(poly_S, x_vals);
	dbg(db(clock()-BEG)/db(CLOCKS_PER_SEC));
	dbg("HI2");
	// dbg(x_vals, y_vals);

	map<int, mi> pre_evalS;

	for(int i = 0; i < sz(x_vals); i++){
		pre_evalS[x_vals[i].v] = y_vals[i];
	}


	auto evalS = [&](int s){
		assert(pre_evalS.count(s));
		return pre_evalS[s];
		// mi res = 0;
		// for(int i = 0; i <= k; i++){
		// 	res+=g[i]*pow(mi(i+s), k);
		// }
		// return res;
	};


	auto evalINF = [&](int s){
		return evalS(s)/second_sum;
	};

	// auto evalINF = [&](int s){
	// 	mi res = 0;
	// 	for(int i = 0; i <= 1000-s; i++){
	// 		res+=pow(p, i)*pow(mi(i+s), k);
	// 	}
	// 	return res;
	// };

	// for(int i = 1; i <= n; i++){
	// 	quant[i] = evalINF(0)-pow(p, a[i].v+1)*evalINF(a[i].v+1);
	// }

	for(int i = 1; i <= n; i++){
		quant[i] = evalINF(0)-pow(p, a[i].v+1)*evalINF(a[i].v+1);
		// quant[i] = (mi(1)/second_sum*evalS(0)-pow(p, a[i].v+1)*mi(1)/second_sum*evalS(a[i].v+1));
	}


	// for(int i = 1; i <= n; i++){
	// 	quant[i] = mi(0);
	// 	for(int j = 0; j <= a[i].v; j++){
	// 		quant[i]+=pow(p, j)*pow(mi(j), k);
	// 	}
	// }
}

int main() {
	setIO();
	genFac(1000005);

	// n = 100000;
	// k = 100000;
	// p = rng() % MOD;
	re(n, k, p);
	for(int i = 1; i <= n; i++){
		re(a[i]);
		// a[i] = rng() % MOD;
	}

	genQuant();

	for(int i = 1; i <= n; i++){
		dp[i] = makeMat(4, 4);
		dp[i][0][0] = a[i]+1;
		dp[i][0][1] = a[i];
		dp[i][0][2] = quant[i];
		dp[i][0][3] = quant[i];
		dp[i][1][1] = a[i]+1;
		dp[i][1][3] = quant[i];
		dp[i][2][2] = a[i]+1;
		dp[i][2][3] = a[i];
		dp[i][3][3] = a[i]+1;
	}

	Mat cur_pref_sum = makeMat(4, 4);
	Mat cur_sum = makeMat(4, 4);
	// dbg(cur_sum);
	for(int l = n; l >= 1; l--){
		cur_pref_sum = dp[l]*cur_pref_sum+dp[l]; //all nonempty prefixes starting at l
		cur_sum+=cur_pref_sum;
	}

	mi ans = cur_sum[0][3];
	ps(ans);


	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/