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

const int mx = 1000015;

const bool DEBUG_TIME = false;
int n;
vpi adj[mx];
vpi eds;

pi par[mx];
// vpi children[mx];

pair<ll, int> dp[2*mx];
bool used[2 * mx];
// map<pi, pair<ll, int>> dp; //for edge (a, b), subtree rooted at a, store number of paths up, number of nodes in it

// int cur_count = 0;
// void genDP(int id) {
// 	int node = eds[id >> 1].first;
// 	int p = eds[id >> 1].second; 

// 	//node and p ^
// 	//node is in the subtree and is the root, p is not in the subtree
// 	if (!(id & 1)) {
// 		swap(node, p);
// 	}
// 	if(used[id]) return;
// 	used[id] = true;
// 	ll paths_up = 1;
// 	int sub_size = 1;

// 	for(auto u: adj[node]){
// 		if(u.first == p) continue;
// 		genDP(u.second);
// 		pair<ll, int> dp_val = dp[u.second];
// 		paths_up+=dp_val.f+dp_val.s;
// 		sub_size+=dp_val.s;
// 	}
// 	dp[id] = mp(paths_up, sub_size);
// }

void genUpDPs(int id){ //id is up, down
	int node = eds[id >> 1].second;
	int p = eds[id >> 1].first; 


	//node and p ^
	//node is in the subtree and is the root, p is not in the subtree
	if ((id & 1)) {
		swap(node, p);
	}

	// dbg(id, node, p);

	dp[id^1].f = 1;
	dp[id^1].s = 1;
	for(auto u: adj[node]){
		if(u.f == p) continue;
		genUpDPs(u.s);
		dp[id^1].f+=dp[u.s^1].f+dp[u.s^1].s;
		dp[id^1].s+=dp[u.s^1].s;
	}
}

void genDownDPs(int node){ //for node -> child
	int p = par[node].f;

	pair<ll, int> tot_sum = mp(1, 1);
	if(node != 1){
		tot_sum.f+=dp[par[node].s^1].f+dp[par[node].s^1].s;
		tot_sum.s+=dp[par[node].s^1].s;
	}
	for(auto u: adj[node]){
		if(u.f == p) continue;
		tot_sum.f+=dp[u.s^1].f+dp[u.s^1].s;
		tot_sum.s+=dp[u.s^1].s;
	}

	for(auto u: adj[node]){
		if(u.f == p) continue;
		tot_sum.f-=dp[u.s^1].f+dp[u.s^1].s;
		tot_sum.s-=dp[u.s^1].s;

		dp[u.s] = tot_sum;

		tot_sum.f+=dp[u.s^1].f+dp[u.s^1].s;
		tot_sum.s+=dp[u.s^1].s;
	}

	for(auto u: adj[node]){
		if(u.f == p) continue;
		genDownDPs(u.f);
	}
}

int getKnapSackClosest(vi sizes){
	// dbg("DOING");
	//if(DEBUG_TIME) return 0;
	int sum = 0;
	for(auto u: sizes){
		sum+=u;
	}
	assert(sum == n-1);

	sort(all(sizes));

	vi occ((n-1)/2+1, 0);
	for(auto u: sizes){
		occ[u]++;
	}

	for(int i = 1; i < sz(occ); i++){
		if(occ[i] >= 3){
			int extras = 0;
			if(occ[i] % 2 == 0){
				extras = occ[i]-2;
			}
			else{
				extras = occ[i]-1;
			}
			occ[i]-=extras;
			if(2*i < sz(occ)) occ[2*i]+=extras/2;
		}
	}

	bitset<500005> possibles;
	possibles[0] = 1;

	int num_times = 0;
	for(int i = 1; i < sz(occ); i++){
		for(int j = 0; j < occ[i]; j++){
			num_times++;
			possibles |= (possibles<<i);
		}
	}
	// dbg(num_times);

	int closest = 0;
	for(int i = (n-1)/2; i >= 0; i--){
		if(possibles[i] == 1){
			closest = i;
			break;
		}
	}

	// int sz = 1;
	// can[0] = 0;
	// for (int i = 0; i < sz(sizes); i++) {
	// 	for (int j = 0; j < sz; j++) {
	// 		can1[j] = can[j] + sizes[i];
	// 	}
	// 	merge(can, can + sz, can1, can1 + sz, can2);
	// 	int uk = 0;
	// 	for (int j = 0; j < sz * 2; j++) {
	// 		if (j == 0 || can2[j] != can2[j - 1]) {
	// 			can[uk] = can2[j];
	// 			uk++;
	// 		}
	// 	}
	// 	sz = uk;
	// }	
	// int closest = 0;
	// for(int i = 0; i < sz; i++){
	// 	int this_sum = can[i];
	// 	if(abs((n-1)/2-this_sum) < abs((n-1)/2-closest)){
	// 		closest = this_sum;
	// 	}
	// }
	//return the subset that sums closest to (n-1)/2


	return closest;
}

ll getAns(int node){
	ll tot_dp_sum = 0;
	
	int max_size = 0;
	for(auto u: adj[node]){
		pair<ll, int> dp_val = dp[u.s^1];
		tot_dp_sum+=dp_val.f;
		ckmax(max_size, dp_val.s);
	}

	int closest_partition = 0;
	if(max_size >= (n-1)/2){
		closest_partition = max_size;
	}
	else{
		vi sizes;
		for(auto u: adj[node]){
			pair<ll, int> dp_val = dp[u.s^1];

			sizes.pb(dp_val.s);
		}
		closest_partition = getKnapSackClosest(sizes);
	}

	ll res = tot_dp_sum+ll(closest_partition+1)*ll(n-1-closest_partition+1);
	// if(node == 2){
	// 	dbg(tot_dp_sum, res);
	// }
	return res;
}



int main() {
	setIO();

	if(DEBUG_TIME){
		n = 1000000;
	}
	else{
		cin >> n;
	}

	

	clock_t BEG = clock();
	int id = 0;
	for(int i = 2; i <= n; i++){
		int p; 
		if(DEBUG_TIME){
			// p = 1;
			p = 1 + rng() % (i-1);
		}
		else{
			cin >> p;
		}

		par[i] = mp(p, id*2);
		// children[p].pb(mp(i, id*2+1));
		
		eds.pb(mp(i, p));
		adj[i].pb(mp(p, id * 2));
		adj[p].pb(mp(i, id * 2 + 1));
		id++;
	}

	// dbg((clock()-BEG)/double(CLOCKS_PER_SEC));

	for(auto u: adj[1]){
		genUpDPs(u.s);
	}

	// dbg((clock()-BEG)/double(CLOCKS_PER_SEC));
	// for(int i = 0; i < sz(eds); i++){
	// 	dbg(i, eds[i], dp[2*i], dp[2*i+1]);
	// }

	// dbg("DONE");
	genDownDPs(1);

	// dbg((clock()-BEG)/double(CLOCKS_PER_SEC));

	// for(int i = 0; i < sz(eds); i++){
	// 	dbg(i, eds[i], dp[2*i], dp[2*i+1]);
	// }
	// for(int i = 0; i < 2*sz(eds); i++){
	// 	dbg(i, dp[i]);
	// }

	// for(int it = 0; it < sz(eds); it++){
	// 	genDP(it * 2);
	// 	genDP(it * 2 + 1);
	// }

	// dbg(dp);

	ll ans = 0;
	for(int i = 1; i <= n; i++){
		ckmax(ans, getAns(i));
	}

	ps(ans);

	// dbg((clock()-BEG)/double(CLOCKS_PER_SEC));



	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/