#include <bits/stdc++.h>
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

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5;
const ll BIG = 1e18; // not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4]{1,0,-1,0}, dy[4]{0,1,0,-1}; // for every grid problem!!
mt19937 rng(0); 
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

using Fib = AR<mi,2>;

int N,Q;

Fib operator*(const Fib& x, const Fib& y) { // F_i+F_j -> F_{i+j}
	return {x[0]*(y[1]-y[0])+x[1]*y[0],
			x[0]*y[0]+x[1]*y[1]};
}

const int big = 1e6;
V<Fib> inc_1, inc_big;
V<Fib> neg_inc_1, neg_inc_big;

Fib _get_time(ll t) {
	if (t == -1) return {1,0};
	if (t == 0) return {0,1};
	if (t == 1) return {1,1};
	if (t%2 == 0) {
		Fib f = _get_time(t/2);
		return f*f;
	}
	return _get_time(t-1)*_get_time(1);
}

V<Fib> generate(Fib f) {
	V<Fib> res; res.pb(_get_time(0));
	rep(big) res.pb(res.bk*f);
	return res;
}

Fib get_time_cached(ll t) {
	assert(t/big/big == 0);
	if (t >= 0) return inc_1.at(t%big)*inc_big.at(t/big);
	else {
		t *= -1;
		return neg_inc_1.at(t%big)*neg_inc_big.at(t/big);
	}
}

void adv(Fib& f, ll t) {
	f = f*get_time_cached(t);
}

Fib& operator+=(Fib& a, const Fib& b) {
	F0R(i,2) a[i] += b[i];
	return a;
}

Fib operator+(Fib a, const Fib& b) {
	return a += b;
}


struct Node {
	AR<ll,2> mx; // max, second max
	AR<ll,2> mn; // min, second min
	// AR<Info,3> info; // sum of each, # of each
	AR<ll,3> lazy; // lazy increments for min, middle, max
	Node() {}
	Node(ll x) { // OK
		mx = {x,-BIG};
		mn = {x,BIG};
		// info = {}; info[1] = {x,1};
		lazy = {};
	}
	bool all_equal() const { return mx[0] == mn[0]; } // true if min of range = max of range
	// Info get_sum() const { return info[0]+info[1]+info[2]; }
	ll get_min() {
		if (all_equal()) return mn[0]+lazy[1];
		return mn[0]+lazy[0];
	}
	ll get_max() {
		if (all_equal()) return mn[0]+lazy[1];
		return mx[0]+lazy[2];
	}
};

struct SuperNode {
	Node node[2];
	AR<AR<Fib,3>,3> info;
	SuperNode() {}
	SuperNode(ll x, ll y) {
		node[0] = Node(x);
		node[1] = Node(y);
		info = {};
		info[1][1] = get_time_cached(x+y);
	}
	Fib get_sum() {
		Fib res{};
		F0R(i,3) F0R(j,3) res += info[i][j];
		return res;
	}
};

SuperNode seg[1<<17];

AR<ll,2> comb_mx(const AR<ll,2>& a, const AR<ll,2>& b) {
	ll mx = max(a[0],b[0]);
	ll second_mx = max(a[0] == mx ? a[1] : a[0],b[0] == mx ? b[1] : b[0]);
	return {mx,second_mx};
}

AR<ll,2> comb_mn(const AR<ll,2>& a, const AR<ll,2>& b) {
	ll mn = min(a[0],b[0]);
	ll second_mn = min(a[0] == mn ? a[1] : a[0],b[0] == mn ? b[1] : b[0]);
	return {mn,second_mn};
}

void comb(SuperNode& res, const SuperNode& l, const SuperNode& r) {
	F0R(i,2) {
		res.node[i].mx = comb_mx(l.node[i].mx,r.node[i].mx);
		res.node[i].mn = comb_mn(l.node[i].mn,r.node[i].mn);
		assert(res.node[i].mn[0] <= res.node[i].mx[0]);
	}
	res.info = {};
	vi stk_res, stk_x;
	auto deal = [&](auto self, const SuperNode& x) {
		int ind = sz(stk_res); //which array we are looking at
		if (ind == 2) {
			assert(sz(stk_res) == sz(stk_x));
			res.info[stk_res[0]][stk_res[1]] += x.info[stk_x[0]][stk_x[1]];
			return;
		}
		if (x.node[ind].all_equal()) { // case 1: same value
			ll v = x.node[ind].mn[0];
			stk_x.pb(1);
			assert(res.node[ind].mn[0] <= v && v <= res.node[ind].mx[0]);
			if (res.node[ind].all_equal()) {
				stk_res.pb(1); // if min = max, we store in second min/max
			} else {
				if (res.node[ind].mn[0] == v) {
					stk_res.pb(0);
				} else if (res.node[ind].mx[0] == v) {
					stk_res.pb(2); 
				} else { 
					stk_res.pb(1); //second min/max
				}
			}
			self(self,x); stk_x.pop_back(), stk_res.pop_back();
		} else {
			stk_res.pb(x.node[ind].mn[0] == res.node[ind].mn[0] ? 0 : 1); stk_x.pb(0);
			self(self,x); stk_x.pop_back(), stk_res.pop_back();
			stk_res.pb(1), stk_x.pb(1);
			self(self,x); stk_x.pop_back(), stk_res.pop_back();
			stk_res.pb(x.node[ind].mx[0] == res.node[ind].mx[0] ? 2 : 1); stk_x.pb(2);
			self(self,x); stk_x.pop_back(), stk_res.pop_back();
		}
	};
	deal(deal,l); 
	deal(deal,r);
}

void push(int ind, int L, int R) {
	F0R(p,2) {
		if (seg[ind].node[p].all_equal()) {
			assert(seg[ind].node[p].lazy[0] == 0 && seg[ind].node[p].lazy[2] == 0);
			seg[ind].node[p].lazy[0] = seg[ind].node[p].lazy[2] = seg[ind].node[p].lazy[1];
		}
		if (L != R) {
			auto pushdown = [&](SuperNode& node) {
				if (node.node[p].all_equal()) {
					if (seg[ind].node[p].mn[0] == node.node[p].get_min()) {
						node.node[p].lazy[1] += seg[ind].node[p].lazy[0];
					} else if (seg[ind].node[p].mx[0] == node.node[p].get_max()) {
						node.node[p].lazy[1] += seg[ind].node[p].lazy[2];
					} else {
						node.node[p].lazy[1] += seg[ind].node[p].lazy[1];
					}
				} else {
					node.node[p].lazy[0] += seg[ind].node[p].lazy[seg[ind].node[p].mn[0] == node.node[p].get_min() ? 0 : 1];
					node.node[p].lazy[1] += seg[ind].node[p].lazy[1];
					node.node[p].lazy[2] += seg[ind].node[p].lazy[seg[ind].node[p].mx[0] == node.node[p].get_max() ? 2 : 1];
				}
			};
			pushdown(seg[2*ind]);
			pushdown(seg[2*ind+1]);
		}
	}
	F0R(i,3) F0R(j,3) adv(seg[ind].info[i][j],seg[ind].node[0].lazy[i]+seg[ind].node[1].lazy[j]);
	F0R(p,2) {
		bool two_valued = (seg[ind].node[p].mn[1] == seg[ind].node[p].mx[0]);
		seg[ind].node[p].mn[0] += seg[ind].node[p].lazy[0];
		seg[ind].node[p].mx[0] += seg[ind].node[p].lazy[2];
		if (two_valued) {
			seg[ind].node[p].mn[1] = seg[ind].node[p].mx[0];
			seg[ind].node[p].mx[1] = seg[ind].node[p].mn[0];
		} else {
			if (seg[ind].node[p].mn[1] != BIG) //not single
				seg[ind].node[p].mn[1] += seg[ind].node[p].lazy[1];
			if (seg[ind].node[p].mx[1] != -BIG) 
				seg[ind].node[p].mx[1] += seg[ind].node[p].lazy[1];
		}
		seg[ind].node[p].lazy = {};
		assert(seg[ind].node[p].mn[0] <= seg[ind].node[p].mx[0]);
	}
}

void pull(int ind, int L, int R) {
	assert(L < R);
	comb(seg[ind],seg[2*ind],seg[2*ind+1]);
}

void build(int ind, int L, int R, const vl& A, const vl& B) {
	if (L == R) {
		seg[ind] = SuperNode(A[L],B[L]);
		return;
	}
	int M = (L+R)/2;
	build(2*ind,L,M,A,B); build(2*ind+1,M+1,R,A,B);
	pull(ind,L,R);
}

Fib query_sum(int lo, int hi, int ind, int L, int R) {
	if (R < lo || hi < L) return {};
	push(ind,L,R);
	if (lo <= L && R <= hi) return seg[ind].get_sum();
	int M = (L+R)/2;
	return query_sum(lo,hi,2*ind,L,M)+query_sum(lo,hi,2*ind+1,M+1,R);
}

void upd_min(int p, int lo, int hi, ll B, int ind, int L, int R) {
	push(ind,L,R);
	ll dif = B-seg[ind].node[p].mx[0];
	if (R < lo || hi < L || dif >= 0) return;
	if (lo <= L && R <= hi) {
		if (seg[ind].node[p].all_equal()) {
			seg[ind].node[p].lazy[1] = dif;
			push(ind,L,R);
			return;
		} else if (B > seg[ind].node[p].mx[1]) {
			seg[ind].node[p].lazy[2] = dif;
			push(ind,L,R);
			return;
		}
	}
	int M = (L+R)/2;
	upd_min(p,lo,hi,B,2*ind,L,M);
	upd_min(p,lo,hi,B,2*ind+1,M+1,R);
	pull(ind,L,R);
}

void upd_max(int p, int lo, int hi, ll B, int ind, int L, int R) {
	push(ind,L,R);
	ll dif = B-seg[ind].node[p].mn[0];
	if (R < lo || hi < L || dif <= 0) return;
	if (lo <= L && R <= hi) {
		if (seg[ind].node[p].all_equal()) {
			// all equal
			seg[ind].node[p].lazy[1] = dif;
			push(ind,L,R);
			return;
		} else if (B < seg[ind].node[p].mn[1]) {
			seg[ind].node[p].lazy[0] = dif;
			push(ind,L,R);
			return;
		}
	}
	int M = (L+R)/2;
	upd_max(p,lo,hi,B,2*ind,L,M);
	upd_max(p,lo,hi,B,2*ind+1,M+1,R);
	pull(ind,L,R);
}

void upd_ad(int p, int lo, int hi, ll B, int ind, int L, int R) {
	push(ind,L,R);
	if (R < lo || hi < L) return;
	if (lo <= L && R <= hi) {
		if (seg[ind].node[p].all_equal()) {
			seg[ind].node[p].lazy[1] = B;
		} else {
			F0R(i,3) seg[ind].node[p].lazy[i] = B;
		}
		push(ind,L,R);
		return;
	}
	int M = (L+R)/2;
	upd_ad(p,lo,hi,B,2*ind,L,M);
	upd_ad(p,lo,hi,B,2*ind+1,M+1,R);
	pull(ind,L,R);
}

int main() {
	setIO(); re(N,Q);
	vl A(N); re(A);
	vl A2(N); re(A2);
	inc_1 = generate(_get_time(1));
	inc_big = generate(_get_time(big));
	neg_inc_1 = generate(_get_time(-1));
	neg_inc_big = generate(_get_time(-big));
	build(1,0,N-1,A,A2);
	rep(Q) {
		ints(T);
		if (T == 4) {
			ints(L,R); --L, --R;
			ps(query_sum(L,R,1,0,N-1)[0]);
		} else {
			ints(P,L,R,X); --P, --L, --R;
			if (T == 1) upd_min(P,L,R,X,1,0,N-1);
			else if (T == 2) upd_max(P,L,R,X,1,0,N-1);
			else if (T == 3) upd_ad(P,L,R,X,1,0,N-1);
			else assert(0);
		}
	}
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/