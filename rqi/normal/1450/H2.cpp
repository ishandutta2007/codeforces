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
typedef vector<bool> vb; 
typedef vector<ll> vl; 
typedef vector<db> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 
typedef vector<pd> vpd; 

#define mp make_pair
#define f first
#define s second
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define sor(x) sort(all(x)) 
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

const int MOD = 998244353;
const int MX = 2e5+5; 
const ll INF = 1e18; 
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; 
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

template<class T> bool ckmin(T& a, const T& b) { 
	return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; } 
constexpr int pct(int x) { return __builtin_popcount(x); } 
constexpr int bits(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down
ll half(ll x) { return fdiv(x,2); }

template<class T, class U> T fstTrue(T lo, T hi, U f) { 
	// note: if (lo+hi)/2 is used instead of half(lo+hi) then this will loop infinitely when lo=hi
	hi ++; assert(lo <= hi); // assuming f is increasing
	while (lo < hi) { // find first index such that f is true 
		T mid = half(lo+hi);
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}
template<class T, class U> T lstTrue(T lo, T hi, U f) {
	lo --; assert(lo <= hi); // assuming f is decreasing
	while (lo < hi) { // find first index such that f is true 
		T mid = half(lo+hi+1);
		f(mid) ? lo = mid : hi = mid-1;
	} 
	return lo;
}
template<class T> void remDup(vector<T>& v) { 
	sort(all(v)); v.erase(unique(all(v)),end(v)); }

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
str ts(char c) { return str(1,c); }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) { 
	#ifdef LOCAL
		return b ? "true" : "false"; 
	#else 
		return ts((int)b);
	#endif
}
template<class A> str ts(complex<A> c) { 
	stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) {
	str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);
	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) {
	str res = ""; F0R(i,SZ) res += char('0'+b[i]);
	return res; }
template<class A, class B> str ts(pair<A,B> p);
template<class T> str ts(T v) { // containers with begin(), end()
	#ifdef LOCAL
		bool fst = 1; str res = "{";
		for (const auto& x: v) {
			if (!fst) res += ", ";
			fst = 0; res += ts(x);
		}
		res += "}"; return res;
	#else
		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += " ";
			fst = 0; res += ts(x);
		}
		return res;

	#endif
}
template<class A, class B> str ts(pair<A,B> p) {
	#ifdef LOCAL
		return "("+ts(p.f)+", "+ts(p.s)+")"; 
	#else
		return ts(p.f)+" "+ts(p.s);
	#endif
}

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
	cerr << ts(h); if (sizeof...(t)) cerr << ", ";
	DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL, chk -> fake assert
	#define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
	#define chk(...) if (!(__VA_ARGS__)) cerr << "Line(" << __LINE__ << ") -> function(" \
		 << __FUNCTION__  << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << "\n", exit(0);
#else
	#define dbg(...) 0
	#define chk(...) 0
#endif

// FILE I/O
void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }
void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }
void setIO(str s = "") {
	unsyncIO();
	// cin.exceptions(cin.failbit); 
	// throws exception when do smth illegal
	// ex. try to read letter into int
	if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
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
	mint() { v = 0; }
	mint(ll _v) { v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0) v += MOD; }
	friend bool operator==(const mint& a, const mint& b) { 
		return a.v == b.v; }
	friend bool operator!=(const mint& a, const mint& b) { 
		return !(a == b); }
	friend bool operator<(const mint& a, const mint& b) { 
		return a.v < b.v; }
	friend void re(mint& a) { ll x; re(x); a = mint(x); }
	friend str ts(mint a) { return ts(a.v); }
   
	mint& operator+=(const mint& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	mint& operator-=(const mint& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	mint& operator*=(const mint& m) { 
		v = (ll)v*m.v%MOD; return *this; }
	mint& operator/=(const mint& m) { return (*this) *= inv(m); }
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

typedef mint<MOD,5> mi; // 5 is primitive root for both common mods
typedef vector<mi> vmi;
typedef pair<mi,mi> pmi;
typedef vector<pmi> vpmi;

vector<vmi> scmb; // small combinations
void genComb(int SZ) {
	scmb.assign(SZ,vmi(SZ)); scmb[0][0] = 1;
	FOR(i,1,SZ) F0R(j,i+1) 
		scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}


/**
 * Description: pre-compute factorial mod inverses,
 	* assumes $MOD$ is prime and $SZ < MOD$.
 * Time: O(SZ)
 * Source: KACTL
 * Verification: https://dmoj.ca/problem/tle17c4p5
 */

vi invs, fac, ifac; // make sure to convert to LL before doing any multiplications ...
void genFac(int SZ) {
	invs.rsz(SZ), fac.rsz(SZ), ifac.rsz(SZ); 
	invs[1] = fac[0] = ifac[0] = 1; 
	FOR(i,2,SZ) invs[i] = MOD-(ll)MOD/i*invs[MOD%i]%MOD;
	FOR(i,1,SZ) {
		fac[i] = (ll)fac[i-1]*i%MOD;
		ifac[i] = (ll)ifac[i-1]*invs[i]%MOD;
	}
}

mi comb(int a, int b) {
	if (a < b || b < 0) return 0;
	return mi((ll)fac[a]*ifac[b]%MOD*ifac[a-b]%MOD);
}

int n, m;
int counter;  //even b minus odd b
int evens, odds; //even/odd ?

mi solveNaive(){
	mi ans = 0;

	if((abs(counter) % 2) == 0){
		int hi = (evens+odds)+((evens+odds)&1);
		for(int i = -hi; i <= hi; i+=2){
			ans+=mi(abs(counter+i))*mi(comb(evens+odds, odds+i));
		}
	}
	else{
		int hi = (evens+odds)+((evens+odds)&1);
		for(int i = -hi-2; i <= hi+2; i+=2){
			ans+=mi(abs(counter+1+i))*mi(comb(evens+odds, odds+1+i));
		}
	}
	ans/=2;
	ans/=pow(mi(2), evens+odds-1);
	return ans;
}

vector<pair<pi, mi>> lastpsums;
vector<pair<pi, mi>> curpsums;

mi naivePrefSumComb(int c, int x){
	mi ans = 0;
	for(int i = 0; i <= x; i++){
		ans+=comb(c, i);
	}
	return ans;
}

mi prefSumComb(int c, int x){ //c choose 0 + c choose 1 + ... c choose x
	 assert(c >= 0);
	 if(x < 0) return mi(0);
	 ckmin(x, c);

	 mi ans = 0;

	 pi buildans = mp(x, -1); //operations needed, index
	 for(int i = 0; i < sz(lastpsums); i++){
	 	pi coor = lastpsums[i].f;
	 	ckmin(buildans, mp(abs(coor.f-c)+abs(coor.s-x), i));
	 }

	 if(buildans.s == -1){
	 	ans = naivePrefSumComb(c, x);
	 }
	 else{
	 	ans = lastpsums[buildans.s].s;
	 	pi curcoor = lastpsums[buildans.s].f;
	 	while(curcoor.f < c){
	 		ans = 2*ans-comb(curcoor.f, curcoor.s);
	 		curcoor.f++;
	 	}
	 	while(curcoor.f > c){
	 		ans = invs[2]*ans+invs[2]*comb(curcoor.f-1, curcoor.s);
	 		curcoor.f--;
	 	}
	 	while(curcoor.s < x){
	 		ans+=comb(curcoor.f, curcoor.s+1);
	 		curcoor.s++;
	 	}
	 	while(curcoor.s > x){
	 		ans-=comb(curcoor.f, curcoor.s);
	 		curcoor.s--;
	 	}
	 }

	 // mi naiveans = naivePrefSumComb(c, x);

	 // if(ans != naiveans){
	 // 	dbg(lastpsums[buildans.s]);
	 // }
	 
	 // dbg(c, x, ans, naiveans);

	curpsums.pb(mp(mp(c, x), ans));

	return ans;
}

mi halfComb(int c, int x){ //sum of c choose x+i for even i >= 0
	assert(c >= 0);
	if(c == 0){
		if(x > c) return mi(0);
		if((c-x) % 2 == 0) return mi(1);
		return mi(0);
	}
	mi ans = prefSumComb(c-1, c-x);
	return ans;
}

mi linComb(int c, int x){ //sum of i * (c choose (x+i)) for even i >= 0
	mi ans = 0;
 	ans+=mi(c)*halfComb(c-1, x-1);
 	ans-=mi(x)*halfComb(c, x);
 	return ans;
}

mi solveReg(){
	mi ans = 0;
	ans+=linComb(evens+odds, odds-counter);
	ans+=linComb(evens+odds, evens+counter);
	ans/=mi(2);

	swap(lastpsums, curpsums);
	curpsums.clear();
	ans/=pow(mi(2), evens+odds-1);
	return ans;
}

int main() {
	setIO();
	genFac(600005);
	cin >> n >> m;
	string s;
	cin >> s;

	for(int i = 0; i < n; i++){
		if(s[i] == 'b'){
			if(i % 2 == 0){
				counter++;
			}
			else{
				counter--;
			}
		}
		else if(s[i] == '?'){
			if(i % 2 == 0){
				evens++;
			}
			else{
				odds++;
			}
		}
	}

	mi ans = solveReg();
	ps(ans);

	for(int i = 0; i < m; i++){
		int pos;
		char c;
		cin >> pos >> c;
		pos--;
		if(s[pos] == 'b'){
			if(pos % 2 == 0){
				counter--;
			}
			else{
				counter++;
			}
		}
		else if(s[pos] == '?'){
			if(pos % 2 == 0){
				evens--;
			}
			else{
				odds--;
			}
		}

		s[pos] = c;
		if(s[pos] == 'b'){
			if(pos % 2 == 0){
				counter++;
			}
			else{
				counter--;
			}
		}
		else if(s[pos] == '?'){
			if(pos % 2 == 0){
				evens++;
			}
			else{
				odds++;
			}
		}
		ans = solveReg();
		ps(ans);
	}

	

	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/