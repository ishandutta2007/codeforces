#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef double db;
typedef long long ll;
typedef long double ld;
typedef string str;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;
 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a : x)
 
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define rsz resize
#define ins insert
 
const int MOD = 998244353; // 998244353 = (119<<23)+1
const ll INF = 1e18;
const int MX = 2e5+5;
const ld PI = 4*atan((ld)1);
 
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>
 
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define ook order_of_key
#define fbo find_by_order
 
namespace input {
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);
 
    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    template<class T, class... Ts> void re(T& t, Ts&... ts) { 
        re(t); re(ts...); 
    }
 
    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}
 
using namespace input;
 
namespace output {
    void pr(int x) { cout << x; }
    void pr(long x) { cout << x; }
    void pr(ll x) { cout << x; }
    void pr(unsigned x) { cout << x; }
    void pr(unsigned long x) { cout << x; }
    void pr(unsigned long long x) { cout << x; }
    void pr(float x) { cout << x; }
    void pr(double x) { cout << x; }
    void pr(ld x) { cout << x; }
    void pr(char x) { cout << x; }
    void pr(const char* x) { cout << x; }
    void pr(const string& x) { cout << x; }
    void pr(bool x) { pr(x ? "true" : "false"); }
    template<class T> void pr(const complex<T>& x) { cout << x; }
    
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T> void pr(const T& x);
    
    template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { 
        pr(t); pr(ts...); 
    }
    template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
        pr("{",x.f,", ",x.s,"}"); 
    }
    template<class T> void pr(const T& x) { 
        pr("{"); // const iterator needed for vector<bool>
        bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; 
        pr("}");
    }
    
    void ps() { pr("\n"); } // print w/ spaces
    template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
        pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
    }
    
    void pc() { pr("]\n"); } // debug w/ commas
    template<class T, class... Ts> void pc(const T& t, const Ts&... ts) { 
        pr(t); if (sizeof...(ts)) pr(", "); pc(ts...); 
    }
    #define dbg(x...) pr("[",#x,"] = ["), pc(x);
}
 
using namespace output;
 
namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        cin.sync_with_stdio(0); cin.tie(0); // fast I/O
        cin.exceptions(cin.failbit); // ex. throws exception when you try to read letter into int
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
    }
}
 
using namespace io;
 
template<class T> T invGeneral(T a, T b) {
	a %= b; if (a == 0) return b == 1 ? 0 : -1;
	T x = invGeneral(b,a); 
	return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
}
 
template<class T> struct modular {
	T val; 
	explicit operator T() const { return val; }
	modular() { val = 0; }
	modular(const ll& v) { 
		val = (-MOD <= v && v <= MOD) ? v : v % MOD;
		if (val < 0) val += MOD;
	}
	
	// friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
	friend void pr(const modular& a) { pr(a.val); }
	friend void re(modular& a) { ll x; re(x); a = modular(x); }
   
	friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
	friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }
	friend bool operator<(const modular& a, const modular& b) { return a.val < b.val; }
 
	modular operator-() const { return modular(-val); }
	modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
	modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
	modular& operator*=(const modular& m) { val = (ll)val*m.val%MOD; return *this; }
	friend modular pow(modular a, ll p) {
		modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend modular inv(const modular& a) { 
		auto i = invGeneral(a.val,MOD); assert(i != -1);
		return i;
	} // equivalent to return exp(b,MOD-2) if MOD is prime
	modular& operator/=(const modular& m) { return (*this) *= inv(m); }
	
	friend modular operator+(modular a, const modular& b) { return a += b; }
	friend modular operator-(modular a, const modular& b) { return a -= b; }
	friend modular operator*(modular a, const modular& b) { return a *= b; }
	
	friend modular operator/(modular a, const modular& b) { return a /= b; }
};
 
typedef modular<int> mi;
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

/**
 * Description: pre-compute factorial mod inverses for $MOD$, 
 	* assumes $MOD$ is prime and $SZ < MOD$
 * Time: O(SZ)
 * Source: KACTL
 * Verification: https://dmoj.ca/problem/tle17c4p5
 */

vi invs, fac, ifac;
void genFac(int SZ) {
	invs.rsz(SZ), fac.rsz(SZ), ifac.rsz(SZ); 
	invs[1] = fac[0] = ifac[0] = 1; 
	FOR(i,2,SZ) invs[i] = MOD-(ll)MOD/i*invs[MOD%i]%MOD;
	FOR(i,1,SZ) {
		fac[i] = (ll)fac[i-1]*i%MOD;
		ifac[i] = (ll)ifac[i-1]*invs[i]%MOD;
	}
}
ll comb(int a, int b) {
	if (a < b || b < 0) return 0;
	return (ll)fac[a]*ifac[b]%MOD*ifac[a-b]%MOD;
}

/**
 * Description: 1D point update, range query. \texttt{comb} 
 	* can be any associative operation.
 * Time: O(\log N)
 * Source: 
	* http://codeforces.com/blog/entry/18051
	* KACTL
 * Verification: SPOJ Fenwick
 */
const mi inv10000 = mi(1)/mi(10000);
const mi inv100 = mi(1)/mi(100);
typedef array<array<mi, 2>, 2> T;
array<array<mi, 2>, 2> ID;

struct Seg { 
	
	T comb(T a, T b) { 
		T c;
		c[0][0] = a[0][0]*b[0][0]+a[0][1]*b[1][0];
		c[0][1] = a[0][0]*b[0][1]+a[0][1]*b[1][1];
		c[1][0] = a[1][0]*b[0][0]+a[1][1]*b[1][0];
		c[1][1] = a[1][0]*b[0][1]+a[1][1]*b[1][1];
		return c;
	} 
	int n; vector<T> seg;
	void init(int _n) { n = _n; ID[0][0] = 1; ID[0][1] = 0; ID[1][0] = 0; ID[1][1] = 1; seg.assign(2*n,ID); }
	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T value) {	// set value at position p
		seg[p += n] = value;
		for (p /= 2; p; p /= 2) pull(p);
	}
	T query(int l, int r) {	 // sum on interval [l, r]
		T ra = ID, rb = ID; 
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		return comb(ra,rb);
	}
};

int x[200005];
int v[200005];
mi p[200005];
Seg probs;
mi expected[200005];
mi ans;

bool comparefracs(pair<pi, pair<int, pi>> a, pair<pi, pair<int, pi>> b){
	return ll(a.f.f)*ll(b.f.s) < ll(b.f.f)*ll(a.f.s);
}
int main() {
	setIO();
    // you should actually read the stuff at the bottom
    genFac(2000005);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
    	cin >> x[i] >> v[i];
    	int P;
    	cin >> P;
    	p[i] = mi(P);
    }
	probs.init(2*n+5);
	
	vector<pair<pi, pair<int, pi>>> events;
	for(int i = 1; i <= n-1; i++){
		int x1 = x[i];
		int x2 = x[i+1];
		int v1 = v[i];
		int v2 = v[i+1];
		mi p1 = p[i];
		mi p2 = p[i+1];
		if(v1 > v2){
			events.pb(mp(mp(x2-x1, v1-v2), mp(i, mp(1, 1))));
		}
		else if(v2 > v1){
			events.pb(mp(mp(x2-x1, v2-v1), mp(i, mp(0, 0))));
		}
		events.pb(mp(mp(x2-x1, v1+v2), mp(i, mp(1, 0))));
	}
	sort(all(events), comparefracs);
	//for(auto u: events) ps(u);
	expected[0] = 1; // probability one there is at least 0 things prohibited
	//now initialize values of segment tree
	for(int i = 1; i <= n-1; i++){
		array<array<mi, 2>, 2> a;
		a[0][0] = p[i]*inv100;
		a[0][1] = p[i]*inv100;
		a[1][0] = (100-p[i])*inv100;
		a[1][1] = (100-p[i])*inv100;
		probs.upd(i, a);
	}
	array<array<mi, 2>, 2> r;
	r[0][0] = p[n]*inv100;
	r[0][1] = 0;
	r[1][0] = (100-p[n])*inv100;
	r[1][1] = 0;
	probs.upd(n, r);
	
	
	for(int i = 1; i <= sz(events); i++){
		pair<pi, pair<int, pi>> a = events[i-1];
		//update segment tree, query value and put it in expected
		array<array<mi, 2>, 2> b = probs.query(a.s.f, a.s.f);
		b[1-a.s.s.f][1-a.s.s.s] = 0;
		probs.upd(a.s.f, b);
		array<array<mi, 2>, 2> c = probs.query(1, n);
		assert(c[0][1] == 0);
		assert(c[1][1] == 0);
		expected[i] = c[0][0]+c[1][0];
		
	}
	for(int i = 0; i <= sz(events); i++){
		//ps(i, expected[i]);
	}
	for(int i = 0; i <= sz(events); i++){
		expected[i] = expected[i]-expected[i+1];
		//ps(i, expected[i]);
	}
	for(int i = 0; i < sz(events); i++){
		mi xdiff = mi(events[i].f.f); //events-1?
		mi vdiff = mi(events[i].f.s);
		//ans+=expected[i]*xdiff*mi(1)/mi((vdiff));
		ans+=expected[i]*xdiff*mi(1)*mi(invs[int(vdiff)]);
		//ps(xdiff*mi(1)/(vdiff));
		// otherwise contributes 0 to expected value
	}
	//subtract expected[i] - expected[i+1]
	cout << int(ans);
}
 
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), set tle
	* do smth instead of nothing and stay organized
*/