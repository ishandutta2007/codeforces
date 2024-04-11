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

const int MOD = 1e9+7; // 998244353;
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

//returns arbitrary order
vpi removeBads(vpi v){
	sort(all(v), [&](pi l, pi r){
		if(l.f != r.f) return l > r;
		return l < r;
	});

	vpi new_v;
	int cur_r = MOD;
	for(auto u: v){
		if(u.s >= cur_r){
			continue;
		}
		ckmin(cur_r, u.s);
		new_v.pb(u);
	}
	sor(new_v);
	return new_v;
}

/**
 * Description: 1D range increment and sum query.
 * Source: USACO Counting Haybales
 * Verification: SPOJ Horrible
 */

tcT, int SZ> struct LazySeg { 
	static_assert(pct(SZ) == 1); // SZ must be power of 2
	ll seg1[2*SZ];
	ll seg2[2*SZ];
	ll lazy1[2*SZ];
	pl lazy2[2*SZ];

	LazySeg() { 
		F0R(i,2*SZ){
			seg1[i] = seg2[i] = 0;
			lazy1[i] = 0;
			lazy2[i] = mp(0, 0);
		}
	}
	void push(int ind, int L, int R) { /// modify values for current node
		seg2[ind]+=seg1[ind]*lazy2[ind].f+lazy2[ind].s*(R-L+1);
		seg1[ind]+=lazy1[ind]*(R-L+1);

		if(L != R){
			F0R(i, 2){
				lazy2[2*ind+i].f+=lazy2[ind].f;
				lazy2[2*ind+i].s+=lazy2[ind].s+lazy2[ind].f*lazy1[2*ind+i];
				lazy1[2*ind+i]+=lazy1[ind];
			}
		}

		lazy1[ind] = 0;
		lazy2[ind] = mp(0, 0);

		// seg[ind] += (R-L+1)*lazy[ind]; // dependent on operation
		// if (L != R) F0R(i,2) lazy[2*ind+i] += lazy[ind]; /// prop to children
		// lazy[ind] = 0; 
	} // recalc values for current node
	void pull(int ind){
		seg1[ind] = seg1[2*ind]+seg1[2*ind+1];
		seg2[ind] = seg2[2*ind]+seg2[2*ind+1];
	}
	void build() { ROF(i,1,SZ) pull(i); }
	void upd(int lo,int hi, bool typ, ll inc, int ind=1,int L=0, int R=SZ-1) {
		push(ind,L,R); if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) { 
			if(typ == 0){
				lazy1[ind] = inc;
			}
			else{
				lazy2[ind] = mp(1, 0);
			}
			push(ind,L,R); return; }
		int M = (L+R)/2; upd(lo,hi,typ, inc,2*ind,L,M); 
		upd(lo,hi,typ, inc,2*ind+1,M+1,R); pull(ind);
	}
	ll query(int lo, int hi, int ind=1, int L=0, int R=SZ-1) {
		push(ind,L,R); if (lo > R || L > hi) return 0;
		if (lo <= L && R <= hi) return seg2[ind];
		int M = (L+R)/2; return query(lo,hi,2*ind,L,M)+
			query(lo,hi,2*ind+1,M+1,R);
	}
};

const int SZ = 262144;
LazySeg<ll, SZ> seg = LazySeg<ll, SZ>();

void addUpd(int l, int r, int amt){
	dbg(l, r, amt);
	seg.upd(l, r, 0, amt);
}

void convUpd(){
	dbg("conv");
	seg.upd(0, SZ-1, 1, 0);
}

ll queryRect(int l, int r){
	dbg("q", l, r);
	return seg.query(l, r);
}

// const int SZ = 1005;
// int a1[SZ];
// int a2[SZ];

// void addUpd(int l, int r, int amt){
// 	for(int i = l; i <= r; i++){
// 		a1[i]+=amt;
// 	}
// }

// void convUpd(){
// 	for(int i = 0; i < SZ; i++){
// 		a2[i]+=a1[i];
// 	}
// }

// ll queryRect(int l, int r){
// 	ll res = 0;
// 	for(int i = l; i <= r; i++){
// 		res+=a2[i];
// 	}
// 	return res;
// }

const int mx = 200005;
const int mx2 = 1000005;

int n, q;
int p[mx];
int ip[mx];
int l[mx2];
int r[mx2];
ll ans[mx2];

int main() {
	setIO();
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> p[i];
		ip[p[i]] = i;
	}
	for(int i = 1; i <= q; i++){
		cin >> l[i] >> r[i];
	}

	set<pi> rangs; rangs.insert(mp(1, n));

	vector<pair<pi, pi>> rects;

	for(int i = n; i >= 1; i--){
		int pos = ip[i];
		pi rang = mp(-1, -1);
		{
			auto it = prev(rangs.lb(mp(pos+1, 0)));
			rang = *it;
		}

		rangs.erase(rang);
		if(rang.f <= pos-1){
			rangs.insert(mp(rang.f, pos-1));
		}
		if(pos+1 <= rang.s){
			rangs.insert(mp(pos+1, rang.s));
		}

		vpi adds;
		for(int fac1 = 1; fac1*fac1 < i; fac1++){
			if(i % fac1 == 0){
				int fac2 = i/fac1;
				int ifac1 = ip[fac1];
				int ifac2 = ip[fac2];
				if(rang.f <= ifac1 && ifac1 <= rang.s && rang.f <= ifac2 && ifac2 <= rang.s){
					adds.pb(mp(min(pos, min(ifac1, ifac2)), max(pos, max(ifac1, ifac2))));
				}
			}
		}

		adds = removeBads(adds);
		sor(adds);

		dbg(adds);

		int last_x = rang.f-1;
		for(auto u: adds){
			rects.pb(mp(mp(last_x+1, u.f), mp(u.s, rang.s)));
			last_x = u.f;
		}
	}

	dbg(rects);

	//updates take in effect before queries
	vector<pair<int, pair<pi, int>>> upds; //(y coordinate, ((l, r), amount add))
	vector<pair<int, pair<pi, int>>> queries; //(y coordiante, ((l, r), corresponding ans  index))

	for(auto u: rects){
		upds.pb(mp(u.s.f, mp(u.f, +1)));
		upds.pb(mp(u.s.s+1, mp(u.f, -1)));
	}

	for(int i = 1; i <= q; i++){
		queries.pb(mp(r[i], mp(mp(l[i], n), i)));
	}
	sor(upds);
	sor(queries);

	int upds_ind = 0;
	int queries_ind = 0;

	for(int y = 1; y <= n; y++){
		while(upds_ind < sz(upds) && upds[upds_ind].f <= y){
			assert(upds[upds_ind].f == y);
			addUpd(upds[upds_ind].s.f.f, upds[upds_ind].s.f.s, upds[upds_ind].s.s);
			upds_ind++;
		}
		convUpd();
		while(queries_ind < sz(queries) && queries[queries_ind].f <= y){
			assert(queries[queries_ind].f == y);
			ans[queries[queries_ind].s.s] = queryRect(queries[queries_ind].s.f.f, queries[queries_ind].s.f.s);
			queries_ind++;
		}
	}

	for(int i = 1; i <= q; i++){
		cout << ans[i] << "\n";
	}

	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/