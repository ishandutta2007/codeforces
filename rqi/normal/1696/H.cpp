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


const int mx = 605;
int n, k;
vi poses;
vi negs;
mi tpow[mx];


void genTpows(){
	tpow[0] = mi(1);
	for(int i = 1; i < mx; i++){
		tpow[i] = tpow[i-1]*mi(2);
	}
}


vector<vmi> genProds(vi nums){ //looking at suffix i, consider all size j subsets, evaluate product
	vector<vmi> res(sz(nums)+1);
	for(int i = sz(nums); i >= 0; i--){
		if(i == sz(nums)){
			res[sz(nums)] = vmi(k+1, mi(0));
			res[sz(nums)][0] = mi(1);
			continue;
		}
		res[i] = vmi(k+1, mi(0));
		for(int j = 0; j <= k; j++){
			//not using index i
			res[i][j]+=res[i+1][j];
			//using index i
			if(j-1 >= 0){
				res[i][j]+=res[i+1][j-1]*mi(nums[i]);
			}
		}
	}
	return res;
}

vi rev_pos_ind, rev_neg_ind;

void genRevs(){
	vector<pair<int, pair<int, int>>> sorted_abs; //(abs value, (value, index in their respective vector))
	for(int i = 0; i < sz(poses); i++){
		sorted_abs.pb(mp(abs(poses[i]), mp(poses[i], i)));
	}
	for(int i = 0; i < sz(negs); i++){
		sorted_abs.pb(mp(abs(negs[i]), mp(negs[i], i)));
	}
	sor(sorted_abs);
	assert(sz(sorted_abs) == n);
	rev_pos_ind = vi(sz(poses), 0);
	rev_neg_ind = vi(sz(negs), 0);
	for(int i = 0; i < n; i++){
		if(sorted_abs[i].s.f >= 0){
			rev_pos_ind[sorted_abs[i].s.s] = i;
		}
		else{
			rev_neg_ind[sorted_abs[i].s.s] = i;
		}
	}
}

mi getKAns(){ //subset size = k
	vi all_nums = poses;
	for(auto u: negs){
		all_nums.pb(u);
	}
	vector<vmi> prods = genProds(all_nums);
	return prods[0][k];
}


mi getPosAns(){
	vector<vmi> prods = genProds(poses);
	dbg(prods);
	mi res = 0;
	for(int i = 0; i < sz(poses); i++){
		res+=(tpow[rev_pos_ind[i]]-1)*mi(poses[i])*prods[i+1][k-1];
	}
	return res;
}

mi getNegAnsEasy(){
	vector<vmi> prods = genProds(negs);
	mi res = 0;
	for(int i = 0; i < sz(negs); i++){
		res+=(tpow[rev_neg_ind[i]]-1)*mi(negs[i])*prods[i+1][k-1];
	}
	return res;
}

mi getNegAnsHard(){
	vector<vmi> prods = genProds(negs);
	mi res = 0;
	for(int neg_ind = 0; neg_ind < sz(negs); neg_ind++){
		for(int pos_lo = 0; pos_lo < sz(poses); pos_lo++){
			dbg("HI", neg_ind, pos_lo);
			if(rev_pos_ind[pos_lo] >= rev_neg_ind[neg_ind]) continue;
			dbg("HI2", neg_ind, pos_lo);
			int how_many_smaller = pos_lo+neg_ind;
			res+=poses[pos_lo]*prods[neg_ind+1][k-1]*tpow[how_many_smaller];
		}
	}
	return res;
}

mi getNegAnsFlipped(){
	dbg("HI3");
	vi negs_rev = negs;
	if(k % 2 == 1){
		reverse(all(negs_rev));
	}

	vector<vmi> prods = genProds(negs_rev);
	mi res = 0;
	for(int i = 0; i < sz(negs_rev); i++){ //lowest number in the set of size K
		res+=(tpow[i]-1)*mi(negs_rev[i])*prods[i+1][k-1];
	}
	dbg(res);
	return res;
}

mi getNegAns(){
	if(k % 2 == 1){
		return getNegAnsHard()+getNegAnsFlipped();
	}
	return getNegAnsEasy();
}

bool get_pos_ind_to_neg_lo(int pos_ind, int neg_ind, int pos_lo, int neg_lo){
	bool pos_ind_to_neg_lo = false;
	if(pos_lo == -1){
		pos_ind_to_neg_lo = true;
	}
	else if(neg_lo == -1){
		pos_ind_to_neg_lo = false;
	}
	else{
		//pos_ind_to_neg_lo is -neg[neg_lo]/pos[pos_ind], other is -pos[pos_lo]/neg[neg_ind]
		if(ll(negs[neg_lo])*ll(negs[neg_ind]) > ll(poses[pos_lo])*ll(poses[pos_ind])){
			pos_ind_to_neg_lo = true;
		}
		else{
			pos_ind_to_neg_lo = false;
		}
	}
	return pos_ind_to_neg_lo;
}

int main() {
	setIO();
	genTpows();
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		int v;
		cin >> v;
		if(v >= 0){
			poses.pb(v);
		}
		else{
			negs.pb(v);
		}
	}
	sort(all(poses));
	sort(negs.rbegin(), negs.rend());
	genRevs();

	mi k_ans = getKAns();
	mi pos_ans = getPosAns();
	mi neg_ans = getNegAns();
	
	mi ans = 0;

	vector<vmi> pos_prod = genProds(poses);
	vector<vmi> neg_prod = genProds(negs);

	for(int take_pos = 1; take_pos <= min(k-1, sz(poses)); take_pos++){ //how many positives to take
		int take_neg = k-take_pos;
		assert(1 <= take_pos && 1 <= take_neg);
		for(int pos_ind = 0; pos_ind < sz(poses); pos_ind++){ //lowest (abs value) pos taken
			for(int neg_ind = 0; neg_ind < sz(negs); neg_ind++){ //lowest (abs value) neg taken
				if(take_neg % 2 == 0){
					//how many values with abs value < the smaller of pos_ind, neg_ind?
					int how_many_smaller = min(rev_pos_ind[pos_ind], rev_neg_ind[neg_ind]);
					ans+=mi(poses[pos_ind])*mi(negs[neg_ind])*pos_prod[pos_ind+1][take_pos-1]*neg_prod[neg_ind+1][take_neg-1]*(tpow[how_many_smaller]-1);
					continue;
				}
			}
		}
	}


	int BLOCK = 5;
	vector<vector<vmi>> csum(2, vector<vmi>(n+5+BLOCK, vmi(n+5+BLOCK, mi(0))));

	for(int pos_lo = -1; pos_lo < sz(poses); pos_lo++){
		for(int neg_lo = -1; neg_lo < sz(negs); neg_lo++){
			int how_many_smaller = ((pos_lo <= 0) ? 0 : pos_lo) + ((neg_lo <= 0) ? 0 : neg_lo);
			if(pos_lo == -1 && neg_lo == -1) continue;

			dbg(pos_lo, neg_lo);

			dbg(pos_lo+BLOCK, neg_lo+BLOCK);

			dbg(sz(csum));
			dbg(sz(csum[1][pos_lo+BLOCK]));
			if(neg_lo >= 0){
				dbg("HI2");
				csum[1][pos_lo+BLOCK][neg_lo+BLOCK]+=mi(negs[neg_lo])*tpow[how_many_smaller];
				dbg("HI36");
			}
			if(pos_lo >= 0){
				csum[0][pos_lo+BLOCK][neg_lo+BLOCK]+=mi(poses[pos_lo])*tpow[how_many_smaller];
			}
			dbg(pos_lo, neg_lo);
			csum[1][pos_lo+BLOCK][neg_lo+BLOCK]+=csum[1][pos_lo+BLOCK][neg_lo+BLOCK-1];
			csum[0][pos_lo+BLOCK][neg_lo+BLOCK]+=csum[0][pos_lo+BLOCK][neg_lo+BLOCK-1];
		}
	}
	dbg("HI");

	//now consider take_neg % 2 == 1
	for(int pos_ind = 0; pos_ind < sz(poses); pos_ind++){ //lowest (abs value) pos taken
		for(int neg_ind = 0; neg_ind < sz(negs); neg_ind++){ //lowest (abs value) neg taken
			mi first_sum = 0;
			mi second_sum = 0;

			int max_pos_lo = -2;
			int max_neg_lo = -2;
			for(int pos_lo = -1; pos_lo < pos_ind; pos_lo++){
				if(pos_lo != -1 && rev_pos_ind[pos_lo] >= rev_neg_ind[neg_ind]) break;
				max_pos_lo = pos_lo;
			}
			for(int neg_lo = -1; neg_lo < neg_ind; neg_lo++){
				if(neg_lo != -1 && rev_neg_ind[neg_lo] >= rev_pos_ind[pos_ind]) break;
				max_neg_lo = neg_lo;
			}


			// int prev_true = -2;
			// for(int pos_lo = -1; pos_lo <= max_pos_lo; pos_lo++){
			// 	int first_true = MOD;
			// 	for(int neg_lo = -1; neg_lo <= max_neg_lo; neg_lo++){
			// 		if(get_pos_ind_to_neg_lo(pos_ind, neg_ind, pos_lo, neg_lo)){
			// 			if(first_true == MOD){
			// 				first_true = neg_lo;
			// 			}
			// 		}
			// 		else{
			// 			assert(first_true == MOD);
			// 		}
			// 	}
			// 	assert(first_true >= prev_true);
			// 	ckmax(prev_true, first_true);
			// }

			int first_true = 0;
			for(int pos_lo = -1; pos_lo <= max_pos_lo; pos_lo++){
				while(first_true <= max_neg_lo){
					if(!get_pos_ind_to_neg_lo(pos_ind, neg_ind, pos_lo, first_true)){
						first_true++;
					}
					else{
						break;
					}
				}
				first_sum+=csum[1][pos_lo+BLOCK][max_neg_lo+BLOCK]-csum[1][pos_lo+BLOCK][first_true-1+BLOCK];
				second_sum+=csum[0][pos_lo+BLOCK][first_true-1+BLOCK];
			}

			// for(int pos_lo = -1; pos_lo <= max_pos_lo; pos_lo++){
			// 	for(int neg_lo = -1; neg_lo <= max_neg_lo; neg_lo++){ // best thing lower in absolute value than both pos_ind, neg_ind
			// 		if(pos_lo == -1 && neg_lo == -1) continue; // no replacement

			// 		bool pos_ind_to_neg_lo = get_pos_ind_to_neg_lo(pos_ind, neg_ind, pos_lo, neg_lo);
					
			// 		int how_many_smaller = ((pos_lo <= 0) ? 0 : pos_lo) + ((neg_lo <= 0) ? 0 : neg_lo);
			// 		if(pos_ind_to_neg_lo){
			// 			assert(neg_lo >= 0);
			// 			first_sum+=mi(negs[neg_lo])*tpow[how_many_smaller];
			// 		}
			// 		else{
			// 			assert(pos_lo >= 0);
			// 			second_sum+=mi(poses[pos_lo])*tpow[how_many_smaller];
			// 		}
			// 	}
			// }
			mi prod2 = first_sum*negs[neg_ind]+second_sum*poses[pos_ind];

			mi prod1 = 0;
			for(int take_pos = 1; take_pos <= min(k-1, sz(poses)); take_pos++){
				int take_neg = k-take_pos;
				if(take_neg % 2 == 1){
					prod1+=pos_prod[pos_ind+1][take_pos-1]*neg_prod[neg_ind+1][take_neg-1];
				}
				
			}
			ans+=prod1*prod2;
		}

		
	}
	

	// dbg(k_ans, neg_ans, pos_ans, ans);
	ps((k_ans+neg_ans+pos_ans+ans).v);

	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/