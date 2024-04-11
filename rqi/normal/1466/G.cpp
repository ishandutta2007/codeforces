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

const int MOD = 1e9+7; // 998244353;
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
 * Description: Polynomial hash for substrings with two bases.
 * Source:
	* KACTL
	* https://codeforces.com/contest/1207/submission/59309672
 * Verification: 
	* USACO Dec 17 Plat 1 (LCP :o)
	* CF Check Transcription
 */

typedef array<int,2> H; // bases not too close to ends 
uniform_int_distribution<int> BDIST(0.1*MOD,0.9*MOD);
const H base = {BDIST(rng),BDIST(rng)};
/// const T ibase = {(int)inv(mi(base[0])),(int)inv(mi(base[1]))};
H operator+(H l, H r) { 
	F0R(i,2) if ((l[i] += r[i]) >= MOD) l[i] -= MOD;
	return l; }
H operator-(H l, H r) { 
	F0R(i,2) if ((l[i] -= r[i]) < 0) l[i] += MOD;
	return l; }
H operator*(H l, H r) { 
	F0R(i,2) l[i] = (ll)l[i]*r[i]%MOD;
	return l; }
H makeH(char c) { return {c,c}; }
/// H& operator+=(H& l, H r) { return l = l+r; }
/// H& operator-=(H& l, H r) { return l = l-r; }
/// H& operator*=(H& l, H r) { return l = l*r; }

vector<H> pows = {{1,1}};
struct HashRange {
	str S; vector<H> cum = {{0,0}};
	void add(char c) { S += c; cum.pb(base*cum.bk+makeH(c)); }
	void add(str s) { trav(c,s) add(c); }
	void extend(int len) { while (sz(pows) <= len) pows.pb(base*pows.bk); }
	H hash(int l, int r) { int len = r+1-l; extend(len);
		return cum[r+1]-pows[len]*cum[l]; }
	/**int lcp(HashRange& b) { return first_true([&](int x) { 
		return cum[x] != b.cum[x]; },0,min(sz(S),sz(b.S)))-1; }*/
};
/// HashRange HR; HR.add("ababab"); F0R(i,6) FOR(j,i,6) ps(i,j,HR.hash(i,j));


/**
 * Description: Aho-Corasick for fixed alphabet. For each prefix, 
 	* stores link to max length suffix which is also a prefix.
 * Time: O(N\sum)
 * Source: https://ideone.com/0cMjZJ
	* https://codeforces.com/contest/710/problem/F
	* https://codeforces.com/contest/1207/problem/G
 */

struct ACfixed { // fixed alphabet
	static const int ASZ = 26;
	struct node { array<int,ASZ> to; int link; int depth; int occ;};
	vector<node> d = {{}};
	vector<pi> pq;
	int add(str s) { // add word
		int v = 0;
		trav(C,s) {
			int c = C-'a';
			if (!d[v].to[c]){
				d[v].to[c] = sz(d), d.eb();
				d[d[v].to[c]].depth = d[v].depth+1;
				d[d[v].to[c]].occ = 0;
			}
			v = d[v].to[c];
		}
		return v;
	}
	void init() { // generate links
		d[0].link = -1; 
		queue<int> q; q.push(0);
		while (sz(q)) {
			int v = q.ft; q.pop();
			F0R(c,ASZ) {
				int u = d[v].to[c]; if (!u) continue;
				d[u].link = d[v].link == -1 ? 0 : d[d[v].link].to[c];
				q.push(u); 
			}
			if (v) F0R(c,ASZ) if (!d[v].to[c]) 
				d[v].to[c] = d[d[v].link].to[c];
		}

		
	}

	void genpq(){
		for(int i = 0; i < sz(d); i++){
			pq.pb(mp(d[i].depth, i));
		}
		sort(pq.rbegin(), pq.rend());
	}

	void genOcc(){
		for(int i = 0; i < sz(pq); i++){
			int v = pq[i].s;
			int nv = d[v].link;
			if(nv != -1){
				d[nv].occ+=d[v].occ;
			}
		}
	}
};

ACfixed ac;
vi poses;

void init(vector<string> b){
	for(auto u: b){
		poses.pb(ac.add(u));
	}
	ac.init();
	ac.genpq();
}

vmi occs(string a){
	int cur = 0;
	ac.d[cur].occ++;
	for(auto u: a){
		cur = ac.d[cur].to[u-'a'];
		ac.d[cur].occ++;
	}
	ac.genOcc();
	vmi anses;
	for(auto u: poses){
		anses.pb(mi(ac.d[u].occ));
	}
	for(auto u: ac.pq){
		ac.d[u.s].occ = 0;
	}
	return anses;
}

const int mx = 100005;
int k[mx];
string w[mx];

vmi dp[60];
vmi topdp[26];
mi csum[26][mx];
mi tpow[mx];
mi negtpow[mx];

int main() {
	setIO();
	int n, q;
	cin >> n >> q;
	string s0, t;
	cin >> s0 >> t;

	vs dict;
	int MAXWORD = 0;
	for(int i = 0; i < q; i++){
		cin >> k[i];
		cin >> w[i];
		dict.pb(w[i]);
		ckmax(MAXWORD, sz(w[i]));
	}

	init(dict);
	string curs = s0;

	int topi = 0;
	for(int i = 0; i <= n; i++){
		topi = i;
		dp[i] = occs(curs);

		//dbg(curs, occs(curs));

		if(sz(curs) > 2*MAXWORD+1 && i >= 1){
			for(int j = 0; j < 26; j++){
				topdp[j] = vmi(q, mi(0));
			}
			HashRange CURS; CURS.add(curs);
			HashRange W;
			//dbg(curs);
			for(int l = 0; l < q; l++){
				//dbg(l);
				W.S.clear(); W.cum = {{0,0}};
				W.add(w[l]);
				for(int start = sz(curs)/2+1-sz(w[l]); start <= sz(curs)/2; start++){
					int len1 = sz(curs)/2-start;
					int len2 = sz(w[l])-len1-1;
					//dbg(start, start+len1-1);
					//dbg(sz(curs)/2+1, sz(curs)/2+len2);
					if(CURS.hash(start, start+len1-1) == W.hash(0, len1-1) && CURS.hash(sz(curs)/2+1, sz(curs)/2+len2) == W.hash(len1+1, len1+len2)){
						topdp[w[l][len1]-'a'][l]+=mi(1);
						// dbg(w[l]);

						// dbg(w[l][len1], start, start+len1-1, 0, len1-1);
					}
				}
			}
			break;
		}

		

		if(i < n) curs = curs+t[i]+curs;
	}

	//dbg(topi);

	tpow[0] = mi(1);
	negtpow[0] = mi(1);
	for(int i = 1; i <= n; i++){
		tpow[i] = tpow[i-1]*mi(2);
		negtpow[i] = negtpow[i-1]/mi(2);
	}

	for(int j = 0; j < 26; j++){
		for(int i = 0; i <= n-1; i++){
			if(t[i]-'a' == j){
				csum[j][i]+=negtpow[i];
			}
			if(i-1 >= 0) csum[j][i]+=csum[j][i-1];
		}
	}

	for(int i = 0; i < q; i++){
		if(k[i] <= topi){
			ps(dp[k[i]][i]);
		}
		else{
			mi ans = dp[topi][i]*pow(mi(2), k[i]-topi);
			for(int j = 0; j < 26; j++){
				int x = topi;
				int y = k[i]-1;
				mi sum = csum[j][y];
				if(x-1 >= 0) sum-=csum[j][x-1];
				sum*=tpow[k[i]-1];
				ans+=topdp[j][i]*sum;
			}
			//dbg("CASE 2");
			ps(ans);
		}
	}

	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/