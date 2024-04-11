#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using db = long double; // or double, if TL is tight
using str = string; // yay python!

using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>; 
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>; 
using vpd = vector<pd>;

#define tcT template<class T
#define tcTU tcT, class U
// ^ lol this makes everything look weird but I'll try it
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
tcT> using PR = pair<T,T>;

// pairs
#define mp make_pair
#define f first
#define s second

// vectors
// oops size(x), rbegin(x), rend(x) need C++17
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back 
#define pf push_front
#define rtn return

#define lb lower_bound
#define ub upper_bound 
tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5;
const ll INF = 1e18; // not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
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
	return a < b ? a = b, 1 : 0; }

tcTU> T fstTrue(T lo, T hi, U f) {
	hi ++; assert(lo <= hi); // assuming f is increasing
	while (lo < hi) { // find first index such that f is true 
		T mid = lo+(hi-lo)/2;
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
	lo --; assert(lo <= hi); // assuming f is decreasing
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


bool debugging = 0;

vi orig_poses = vi{0, 1, 7};

const int mx = 105;

int n, m;
typedef bitset<mx> B;
int ans[mx];



int last_zero_pos;
int last_query_res;

void printAns(){
	dbg(last_zero_pos);
	for(int i = 1; i < n; i++){
		dbg(i, ans[i]);
		ans[i] = ans[i]-last_zero_pos;
		ans[i] = (ans[i] % (n*m)+(n*m)) % (n*m);
	}

	for(int i = 1; i < n; i++){
		orig_poses[i]-=orig_poses[0];
		orig_poses[i] = (orig_poses[i] % (n*m)+(n*m)) % (n*m);
		dbg(i, orig_poses[i]);
	}

	cout << "!" << " ";
	for(int i = 1; i < n; i++){
		cout << ans[i] << " ";
	}
	cout << "\n";
	cout.flush();
}

void genQueryRes(){
	assert(debugging);
	vb blocked(n*m, false);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int a = (orig_poses[i]+j);
			a%=(n*m);
			a = (a+(n*m)) % (n*m);
			// dbg(a);
			blocked[a] = 1;
		}
	}

	int res = 0;
	for(int i = 0; i < n*m; i++){
		if(!blocked[i]){
			res++;
		}
	}
	last_query_res = res;

	// dbg(last_query_res, orig_poses);
}

int moveLeft(int a){
	if(a == 0) last_zero_pos--;
	cout << "?" << " " << a << " " << -1 << "\n";
	cout.flush();

	if(debugging){
		orig_poses[a]--;
	}
	if(!debugging){
		cin >> last_query_res;
	}
	else{
		genQueryRes();
	}
	

	
	return last_query_res;
}

int moveRight(int a){
	if(a == 0) last_zero_pos++;
	cout << "?" << " " << a << " " << 1 << "\n";
	cout.flush();
	if(debugging){
		orig_poses[a]++;
	}
	if(!debugging){
		cin >> last_query_res;
	}
	else{
		genQueryRes();
	}
	return last_query_res;
}

B getHalf(B a){
	vi bits;
	for(int i = 1; i < n; i++){
		if(a[i] == 1){
			bits.pb(i);
		}
	}

	assert(sz(bits));
	shuffle(all(bits), rng);

	B res;
	res[bits[0]] = 1;

	return res;
	// int chosen = 0;
	// int lim = a.count()/2;
	// for(int i = 0; i < mx; i++){
	// 	if(a[i] == 1){
	// 		if(chosen < lim){
	// 			chosen++;
	// 		}			
	// 		else{
	// 			a[i] = 0;
	// 		}
	// 	}
	// }

	// return a;
}

int getSingleBit(B a){
	int sing_pos = -1;
	for(int i = 0; i < mx; i++){
		if(a[i] == 1){
			assert(sing_pos == -1);
			sing_pos = i;
		}
	}

	assert(sing_pos != -1);
	return sing_pos;
}

bool isArc(){
	int res_1 = moveLeft(0);
	int res_2 = moveRight(0);
	int diff = res_1-res_2;
	if(diff == -1){
		return false;
	}
	return true;
}

int main() {
	setIO();
	cin >> n >> m;

	B S;
	for(int i = 1; i < n; i++){
		S[i] = 1;
	}


	for(int i = 1; i < n; i++){
		int last_num = moveLeft(0);
		while(true){
			int cur_num = moveRight(0);
			if(cur_num == last_num+1){
				last_num = cur_num;
				break;
			}
			else{
				last_num = cur_num;
				continue;
			}
		}

		while(true){
			int cur_num = moveRight(0);
			if(cur_num != last_num+1){
				moveLeft(0);
				break;
			}
			else{
				last_num = cur_num;
				continue;
			}
		}

		B T = S;

		bool on_right = 1;

		while(T.count() > 1){
			B half_T = getHalf(T);


			dbg(T, half_T, on_right);
			if(on_right){
				for(int i = 1; i < n; i++){
					if(half_T[i]){
						moveLeft(i);
					}
				}

				if(isArc()){
					T = half_T;
					on_right = 0;
				}
				else{
					T^=half_T;
					on_right = 1;
				}
			}
			else{
				for(int i = 1; i < n; i++){
					if(half_T[i]){
						moveRight(i);
					}
				}

				if(isArc()){
					T^=half_T;
					on_right = 0;
				}
				else{
					T = half_T;
					on_right = 1;
				}
			}
		}

		assert(T.count() == 1);

		int here = getSingleBit(T);

		
		ans[here] = last_zero_pos-(m+1);
		for(int j = 0; j < m; j++){
			moveLeft(here);
		}
		if(on_right){
			moveLeft(here);
		}

		dbg("FOUND", here, ans[here], last_zero_pos);



		S[here] = 0;
	}

	printAns();

	

	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/