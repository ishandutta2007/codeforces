#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef double db; 
typedef string str; 
 
typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef pair<db,db> pd; 
 
typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef vector<db> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 
typedef vector<pd> vpd; 
 
#define mp make_pair 
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define rsz resize
#define ins insert 
#define ft front() 
#define bk back()
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound 
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
const int MOD = 998244353; // 998244353;
const int MX = 2e5+5; 
const ll INF = 1e18; 
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; 
 
template<class T> bool ckmin(T& a, const T& b) { 
	return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; } 
int pct(int x) { return __builtin_popcount(x); } 
int bit(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
int cdiv(int a, int b) { return a/b+!(a<0||a%b == 0); } // division of a by b rounded up, assumes b > 0 
 
// INPUT
template<class A> void re(complex<A>& c);
template<class A, class B> void re(pair<A,B>& p);
template<class A> void re(vector<A>& v);
template<class A, size_t SZ> void re(array<A,SZ>& a);
 
template<class T> void re(T& x) { cin >> x; }
void re(db& d) { str t; re(t); d = stod(t); }
void re(ld& d) { str t; re(t); d = stold(t); }
template<class H, class... T> void re(H& h, T&... t) { re(h); re(t...); }
 
template<class A> void re(complex<A>& c) { A a,b; re(a,b); c = {a,b}; }
template<class A, class B> void re(pair<A,B>& p) { re(p.f,p.s); }
template<class A> void re(vector<A>& x) { trav(a,x) re(a); }
template<class A, size_t SZ> void re(array<A,SZ>& x) { trav(a,x) re(a); }
 
// TO_STRING
#define ts to_string
template<class A, class B> str ts(pair<A,B> p);
template<class A> str ts(complex<A> c) { return ts(mp(c.real(),c.imag())); }
str ts(bool b) { return b ? "true" : "false"; }
str ts(char c) { str s = ""; s += c; return s; }
str ts(str s) { return s; }
str ts(const char* s) { return (str)s; }
str ts(vector<bool> v) { 
	bool fst = 1; str res = "{";
	F0R(i,sz(v)) {
		if (!fst) res += ", ";
		fst = 0; res += ts(v[i]);
	}
	res += "}"; return res;
}
template<size_t SZ> str ts(bitset<SZ> b) {
	str res = ""; F0R(i,SZ) res += char('0'+b[i]);
	return res; }
template<class T> str ts(T v) {
	bool fst = 1; str res = "{";
	for (const auto& x: v) {
		if (!fst) res += ", ";
		fst = 0; res += ts(x);
	}
	res += "}"; return res;
}
template<class A, class B> str ts(pair<A,B> p) {
	return "("+ts(p.f)+", "+ts(p.s)+")"; }
 
// OUTPUT
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { 
	pr(h); pr(t...); }
void ps() { pr("\n"); } // print w/ spaces
template<class H, class... T> void ps(const H& h, const T&... t) { 
	pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 
// DEBUG
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
	cerr << to_string(h); if (sizeof...(t)) cerr << ", ";
	DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 42
#endif
 
// FILE I/O
void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void unsyncIO() { ios_base::sync_with_stdio(0); cin.tie(0); }
void setIO(string s = "") {
	unsyncIO();
	// cin.exceptions(cin.failbit); 
	// throws exception when do smth illegal
	// ex. try to read letter into int
	if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
}
 
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
 
 
/**
 * Description: modular arithmetic operations 
 * Source: 
	* KACTL
	* https://codeforces.com/blog/entry/63903
	* https://codeforces.com/contest/1261/submission/65632855 (tourist)
	* https://codeforces.com/contest/1264/submission/66344993 (ksun)
 * Verification: 
	* https://open.kattis.com/problems/modulararithmetic
 */
 
struct mi {
	typedef decay<decltype(MOD)>::type T; 
 	/// don't silently convert to T
	T v; explicit operator T() const { return v; }
	mi() { v = 0; }
	mi(ll _v) { 
		v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0) v += MOD;
	}
	friend bool operator==(const mi& a, const mi& b) { 
		return a.v == b.v; }
	friend bool operator!=(const mi& a, const mi& b) { 
		return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) { 
		return a.v < b.v; }
	friend void re(mi& a) { ll x; re(x); a = mi(x); }
	friend str ts(mi a) { return ts(a.v); }
   
	mi& operator+=(const mi& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	mi& operator-=(const mi& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	mi& operator*=(const mi& m) { 
		v = (ll)v*m.v%MOD; return *this; }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	mi operator-() const { return mi(-v); }
	mi& operator++() { return *this += 1; }
	mi& operator--() { return *this -= 1; }
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
};
typedef vector<mi> vmi;
typedef pair<mi,mi> pmi;
typedef vector<pmi> vpmi;
 
vector<vmi> comb;
void genComb(int SZ) {
	comb.assign(SZ,vmi(SZ)); comb[0][0] = 1;
	FOR(i,1,SZ) F0R(j,i+1) 
		comb[i][j] = comb[i-1][j]+(j?comb[i-1][j-1]:0);
}
 
/**
 * Description: 1D point update, range query where \texttt{comb} is
 	* any associative operation. If $N$ is not power of 2 then 
 	* operations work but \texttt{seg[1] != query(0,N-1)}.
 * Time: O(\log N)
 * Source: 
	* http://codeforces.com/blog/entry/18051
	* KACTL
 * Verification: SPOJ Fenwick
 */
 
template<class T> struct Seg { // comb(ID,b) = b
	const T ID = 0; T comb(T a, T b) { return a+b; } 
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n,ID); }
	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) { // set val at position p
		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {	// sum on interval [l, r]
		T ra = ID, rb = ID; 
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		return comb(ra,rb);
	}
};
 
 /**
  * Description: range sum queries and point updates for $D$ dimensions
  * Source: https://codeforces.com/blog/entry/64914
  * Verification: SPOJ matsum
  * Usage: \texttt{BIT<int,10,10>} gives 2D BIT
  * Time: O((\log N)^D)
  */
 
 template <class T, int N> struct BIT {
	T bit[N+1];
	int curr = 0;
 	void upd(int pos, T v){
 		for(int i = curr+1; i <= pos; i++){
 			bit[i] += bit[i-1];
 		}
 		bit[pos]+=v;
 		curr = pos;
 	}
 	T query(int l, int r) {
 		for(int i = curr+1; i <= r; i++){
 			bit[i]+=bit[i-1];
 		}
 		curr = r;
 		return bit[r]-bit[l-1];
 	}
 };
 
 
vector<pair<pi, bool>> cond[35];
vector<pair<pi, int>> naiv;
int nums[500005];
int under[500005];
int qs[500005];
mi tpow[500005];
int n, m, k;
BIT<mi, 500005> seg;
 
mi solve(vector<pair<pi, bool>> req, int ind){
	sort(all(req));
	mi ans = 1;
	for(int i = 1; i < 500005; i++){
		nums[i] = under[i] = qs[i] = 0;
		seg.upd(i, -seg.query(i, i));
	}
 
 
	vector<pi> req2;
 
	for(auto u: req){ //get rid of duplicates
		if(u.s == 1) continue;
		while(sz(req2) && req2.back().s >= u.f.s) req2.pop_back();
		req2.pb(u.f);
	}
 
	dbg(req2);
 
	for(auto u: req2){
		under[u.s+1]--;
		under[u.f]++;
	}
 
	for(auto u: req){
		if(u.s == 1){
			nums[u.f.s+1]--;
			nums[u.f.f]++;
		}
	}
 
	for(int i = 1; i < 500005; i++){
		nums[i] += nums[i-1]; //becomes 1
		under[i]+=under[i-1];
	}
 
	for(int i = 1; i < 500005; i++){
		qs[i] = qs[i-1];
		if(nums[i] > 0){ //it's a 1
			continue;
		}
		else{ //it's a ?
			qs[i]++;
		}
	}
 
	for(int i = 1; i <= n; i++){
		if(under[i] == 0 && nums[i] == 0){
			ans*=mi(2); // can be anything
		}
	}
 
 
	
	pi lastint = mp(-1, -1);
	for(auto u: req2){
		if(lastint.s >= u.f){
			mi q = seg.query(lastint.f, lastint.s);
			for(int i = lastint.s+1; i <= u.s; i++){
				if(nums[i] != 0) continue;
				int qnum = qs[i-1]-qs[lastint.s];
				dbg(i, qnum, q);
				seg.upd(i, q*tpow[qnum]); // how many ?s between lastint.s+1 and i-1
			}
		}
		else{
			//ez updates
			if(lastint != mp(-1, -1)) ans*=seg.query(lastint.f, lastint.s);
			for(int i = u.f; i <= u.s; i++){
				if(nums[i] != 0) continue;
				int qnum = qs[i-1]-qs[u.f-1];
				dbg(i, tpow[qnum]);
				seg.upd(i, tpow[qnum]); //how many ?s between u.f and i-1
			}
		}
		lastint = u;
	}
 
 
	if(lastint == mp(-1, -1)){
		return ans;
	}
	return ans*seg.query(lastint.f, lastint.s);
 
}
 
 
 
mi nans = 0;
int bu[500005];
int test(){
	for(auto u: naiv){
		int a = bu[u.f.f];
		for(int i = u.f.f; i <= u.f.s; i++){
			a = (a&bu[i]);
			dbg(a, bu[i]);
		}
		dbg(a, u.f.f, u.f.s);
		if(a != u.s) return 0;
	}
	return 1;
}
 
void search(int pos){
	if(pos == n+1){
		if(test() == 1){
			nans+=1;
			for(int i = 1; i <= n; i++){
				dbg(i, bu[i]);
			}
		}
		return;
	}
	for(int i = 0; i < (1<<k); i++){
		bu[pos] = i;
		search(pos+1);
	}
	bu[pos] = 0;
}
 
mi naive(){
	search(1);
	return nans;
}
 
 
int main() {
	setIO();
	tpow[0] = 1;
	for(int i = 1; i < 500005; i++){
		tpow[i] = tpow[i-1]*mi(2);
	}
	
	cin >> n >> k >> m;
	for(int i = 1; i <= m; i++){
		int l, r, x;
		cin >> l >> r >> x;
		//naiv.pb(mp(mp(l, r), x));
		for(int j = 0; j < k; j++){
			cond[j].pb(mp(mp(l, r), (x>>j) & 1));
 
			//dbg(j, mp(mp(l, r), (x>>j) & 1));
		}
	}
	//dbg(naiv);
	//ps(naive());
 
 
	mi ans = 1;
	for(int i = 0; i < k; i++){
		mi c = solve(cond[i], i);
		ans*=c;
		dbg(i, c);
	}
	ps(ans);
	// you should actually read the stuff at the bottom
}
 
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/