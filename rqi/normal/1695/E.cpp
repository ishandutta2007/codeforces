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
 * Description: Disjoint Set Union with path compression
 	* and union by size. Add edges and test connectivity. 
 	* Use for Kruskal's or Boruvka's minimum spanning tree.
 * Time: O(\alpha(N))
 * Source: CSAcademy, KACTL
 * Verification: *
 */

struct DSU {
	vi e; void init(int N) { e = vi(N,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { // union by size
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
};

/**tcT> T kruskal(int N, vector<pair<T,pi>> ed) {
	sort(all(ed));
	T ans = 0; DSU D; D.init(N); // edges that unite are in MST
	each(a,ed) if (D.unite(a.s.f,a.s.s)) ans += a.f; 
	return ans;
}*/


const int mx = 600005;

int n;
int x[mx];
int y[mx];
vi adj[mx];

vector<vpi> RES;
vi t_adj[mx];

vpi extra[mx];
pi single_extra[mx];

void dfs(int node, int p = -1){
	dbg(node, p);
	for(auto u: t_adj[node]){
		if(u == p) continue;
		dfs(u, node);
	}

	while(sz(extra[node]) >= 2){
		pi ed1 = extra[node].bk; extra[node].pop_back();
		pi ed2 = extra[node].bk; extra[node].pop_back();

		RES.pb(vpi{mp(ed2.s, ed2.f), ed1});
	}

	if(sz(extra[node]) == 0){
		if(p != -1){
			extra[p].pb(mp(p, node));
		}	
	}
	else{
		pi extra_ed = extra[node][0];
		if(p == -1){
			RES.pb(vpi{mp(extra_ed.s, extra_ed.f)});
		}
		else{
			dbg(extra_ed, mp(node, p));
			RES.pb(vpi{mp(extra_ed.s, extra_ed.f), mp(node, p)});
		}
	}
}

vector<vpi> getPaths(vpi adj_list){
	DSU dsu;
	dsu.init(mx);

	vpi tree_edges;
	vpi non_tree_edges;
	for(auto u: adj_list){
		if(dsu.unite(u.f, u.s)){
			tree_edges.pb(u);
		}
		else{
			non_tree_edges.pb(u);
		}
	}

	
	vector<vpi> comp_extras(mx);
	vector<vpi> comp_tree_edges(mx);
	vi tot_num(mx, 0);
	vi deg(mx, 0);

	for(auto u: adj_list){
		tot_num[dsu.get(u.f)]++;
	}
	for(auto u: tree_edges){
		comp_tree_edges[dsu.get(u.f)].pb(u);
	}
	for(auto u: non_tree_edges){
		comp_extras[dsu.get(u.f)].pb(u);
	}
	for(auto u: adj_list){
		deg[u.f]++;
		deg[u.s]++;
	}

	vi actual_root(mx, 0);
	//construct t_adj, single_extra, extras, actual_root
	for(int i = 1; i <= 2*n; i++){
		if(dsu.get(i) == i){
			if(tot_num[i] % 2 == 0){
				actual_root[i] = i;
				for(auto u: comp_tree_edges[i]){
					t_adj[u.f].pb(u.s);
					t_adj[u.s].pb(u.f);
				}
				for(auto u: comp_extras[i]){
					extra[u.f].pb(u);
				}
				continue;
			}

			//address this component
			if(sz(comp_extras[i])){
				for(auto u: comp_tree_edges[i]){
					t_adj[u.f].pb(u.s);
					t_adj[u.s].pb(u.f);
				}
				int ROOT = comp_extras[i][0].f;

				single_extra[ROOT] = comp_extras[i][0];
				actual_root[i] = ROOT;

				for(int j = 1; j < sz(comp_extras[i]); j++){
					pi ED = comp_extras[i][j];
					extra[ED.f].pb(ED);
				}
			}
			else{
				//use a leaf

				int leaf_ind = -1;
				for(int j = 0; j < sz(comp_tree_edges[i]); j++){
					int nodef = comp_tree_edges[i][j].f;
					int nodes = comp_tree_edges[i][j].s;
					if(deg[nodef] == 1){
						leaf_ind = j;
						break;
					}
					else if(deg[nodes] == 1){
						swap(comp_tree_edges[i][j].f, comp_tree_edges[i][j].s);
						leaf_ind = j;
						break;
					}
				}
				assert(leaf_ind != -1);
				pi leaf_edge = comp_tree_edges[i][leaf_ind];
				for(int j = 0; j < sz(comp_tree_edges[i]); j++){
					if(j == leaf_ind) continue;
					pi ED = comp_tree_edges[i][j];

					t_adj[ED.f].pb(ED.s);
					t_adj[ED.s].pb(ED.f);
				}
				single_extra[leaf_edge.s] = mp(leaf_edge.s, leaf_edge.f);
				actual_root[i] = leaf_edge.s;

				//no extras
			}
		}
	}

	dbg(t_adj[13]);
	dbg(t_adj[14]);
	dbg(t_adj[15]);
	dbg(t_adj[16]);
	dbg(single_extra[9]);

	for(int i = 1; i <= 2*n; i++){
		if(dsu.get(i) == i){
			int ROOT = actual_root[i];
			dbg(ROOT);
			dfs(ROOT);
			if(single_extra[ROOT] != mp(0, 0)){
				if(sz(RES) == 0){
					ps(-1);
					exit(0);
				}
				if(sz(RES.bk) == 2){
					if(single_extra[ROOT].f == RES.bk[1].s){
						RES.bk.pb(single_extra[ROOT]);
					}
					else if(single_extra[ROOT].f == RES.bk[0].s && single_extra[ROOT].f == RES.bk[1].f){
						swap(RES.bk[0].f, RES.bk[0].s);
						RES.bk.pb(single_extra[ROOT]);
					}
					else if(single_extra[ROOT].f == RES.bk[0].f && single_extra[ROOT].f == RES.bk[1].f){
						RES.bk.pb(single_extra[ROOT]);
					}
					else{
						ps(-1);
						exit(0);
					}
				}
				else{
					RES.bk.pb(single_extra[ROOT]);
				}
				
			}
		}
	}
	return RES;
}


bool isStar(vpi path){
	return sz(path) == 3 && path[0].f == path[1].f && path[0].f == path[2].f;
}

bool isPath(vpi path){
	if(sz(path) <= 1 || sz(path) >= 4) return false;
	for(int i = 0; i+1 < sz(path); i++){
		if(path[i].s != path[i+1].f){
			return false;
		}
	}
	return true;
}



int main() {
	setIO();
	
	cin >> n;
	dbg(n);
	for(int i = 1; i <= n; i++){
		cin >> x[i] >> y[i];
	}
	vpi adj_list;
	for(int i = 1; i <= n; i++){
		adj_list.pb(mp(x[i], y[i]));
	}

	vector<vpi> paths = getPaths(adj_list);


	dbg(paths);
	string P_sol_top;
	string P_sol_bot;

	string M_sol_top;
	string M_sol_bot;

	vi ans_top;
	vi ans_bot;

	for(auto path: paths){
		if(!isStar(path) && !isPath(path)){
			dbg(path);
			ps(-1);
			exit(0);
		}
		if(isStar(path)){
			vi nums;
			for(auto u: path){ //assert it's of the form (root, other node), (root, other node), (root, other node)
				nums.pb(u.s);
			}
			int root = path[0].f;

			assert(sz(nums) == 3);

			P_sol_top+="LRU";
			P_sol_bot+="LRD";

			M_sol_top+="ULR";
			M_sol_bot+="DLR";

			ans_top.pb(root);
			ans_top.pb(nums[2]);
			ans_top.pb(root);

			ans_bot.pb(nums[0]);
			ans_bot.pb(root);
			ans_bot.pb(nums[1]);
		}
		else{
			assert(isPath(path));
			assert(sz(path) == 2 || sz(path) == 3);

			//assert of the form (a, b), (b, c), (c, d)
			vi nums;
			for(int i = 0; i < sz(path); i++){
				nums.pb(path[i].f);
				if(i == sz(path)-1){
					nums.pb(path[i].s);
				}
			}

			
			

			if(sz(path) == 2){
				assert(sz(nums) == 3);
				P_sol_top+="UU";
				P_sol_bot+="DD";

				M_sol_top+="LR";
				M_sol_bot+="LR";

				ans_top.pb(nums[1]);
				ans_top.pb(nums[2]);
				ans_bot.pb(nums[0]);
				ans_bot.pb(nums[1]);
			}
			else if(sz(path) == 3){
				assert(sz(nums) == 4);
				P_sol_top+="LRU";
				P_sol_bot+="LRD";

				M_sol_top+="ULR";
				M_sol_bot+="DLR";

				ans_top.pb(nums[0]);
				ans_top.pb(nums[1]);
				ans_top.pb(nums[2]);
				ans_bot.pb(nums[1]);
				ans_bot.pb(nums[2]);
				ans_bot.pb(nums[3]);
			}
		}
	}

	ps(2, n);
	for(int i = 0; i < sz(ans_top); i++){
		cout << ans_top[i];
		if(i+1 < sz(ans_top)){
			cout << " ";
		}
	}
	cout << "\n";

	for(int i = 0; i < sz(ans_bot); i++){
		cout << ans_bot[i];
		if(i+1 < sz(ans_bot)){
			cout << " ";
		}
	}

	cout << "\n";

	cout << "\n";
	ps(P_sol_top);
	ps(P_sol_bot);

	cout << "\n";
	ps(M_sol_top);
	ps(M_sol_bot);

	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/