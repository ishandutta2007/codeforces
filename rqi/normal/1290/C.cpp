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
 
const int MOD = 1e9+7; // 998244353 = (119<<23)+1
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
 * Description: Disjoint Set Union with path compression. 
 	* Add edges and test connectivity. Use for Kruskal's 
 	* minimum spanning tree.
 * Time: O(\alpha(N))
 * Source: CSAcademy, KACTL
 * Verification: USACO superbull
 */

struct DSU {
	pi par[300005]; //node, 0/1
	int parinfo[300005][3]; //0, 1, or 2. # of equal nodes in comp, # of diff nodes in comp
	int curans = 0;
	void init() {
		for(int i = 0; i < 300005; i++){
			par[i] = mp(-1, 0);
			parinfo[i][0] = 2;
			parinfo[i][1] = 1;
			parinfo[i][2] = 0;
		}
	}
	
	pi get(int x, int sam) { // return parent, whether it is same or different
		if(par[x].f == -1) return mp(x, sam);
		return get(par[x].f, (sam+par[x].s) % 2);
	} 
	bool sameSet(int a, int b) { return get(a, 0).f == get(b, 0).f; }
	int size(int x) { return parinfo[x][1]+parinfo[x][2]; }
	
	int getans(int x){
		if(parinfo[x][0] == 0){
			return parinfo[x][2];
		}
		else if(parinfo[x][0] == 1){
			return parinfo[x][1];
		}
		else{
			return min(parinfo[x][1], parinfo[x][2]);
		}
	}
	
	void unitSame();
	void uniteDiff();
	
	void uniteSame(int x, int y) { // union-by-rank
		pi a = get(x, 0);
		pi b = get(y, 0);
		if(a.s != b.s){
			uniteDiff(a.f, b.f);
			return;
		}
		x = a.f;
		y = b.f;
		if(size(x) < size(y)) swap(x, y);
		if(x == y) return;
		par[y] = mp(x, 0);
		curans-=getans(x);
		curans-=getans(y);
		parinfo[x][1]+=parinfo[y][1];
		parinfo[x][2]+=parinfo[y][2];
		//ps(x, parinfo[x][1], parinfo[x][2], getans(x));
		
		if(parinfo[x][0] != 2){
			curans+=getans(x);
			return;
		}
		if(parinfo[y][0] != 2){
			parinfo[x][0] = parinfo[y][0];
			curans+=getans(x);
			return;
		}
		curans+=getans(x);
	}
	void uniteDiff(int x, int y){
		pi a = get(x, 0);
		pi b = get(y, 0);
		if(a.s != b.s){
			uniteSame(a.f, b.f);
			return;
		}
		x = a.f;
		y = b.f;
		if(size(x) < size(y)) swap(x, y);
		par[y] = mp(x, 1);
		curans-=getans(x);
		curans-=getans(y);
		parinfo[x][1]+=parinfo[y][2];
		parinfo[x][2]+=parinfo[y][1];
		//ps(parinfo[x][1], parinfo[x][2], getans(x));
		
		if(parinfo[x][0] != 2){
			curans+=getans(x);
			return;
		}
		if(parinfo[y][0] != 2){
			parinfo[x][0] = 1-parinfo[y][0];
			curans+=getans(x);
			return;
		}
		curans+=getans(x);
	}
	
	void setTo(int x, int val){
		if(par[x].f == -1){
			curans-=getans(x);
			parinfo[x][0] = val;
			curans+=getans(x);
			return;
		}
		//ps(x, val);
		setTo(par[x].f, (val+par[x].s) % 2);
		
	}
};

/**template<class T> T kruskal(int n, vector<pair<T,pi>> ed) {
	sort(all(ed));
	T ans = 0; DSU D; D.init(n+1); // edges that unite are in MST
	trav(a,ed) if (D.unite(a.s.f,a.s.s)) ans += a.f; 
	return ans;
}*/

DSU dsu;
vi adj[300005];
int main() {
	setIO();
    // you should actually read the stuff at the bottom
    dsu.init();
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = "0"+s;
    for(int i = 1; i <= k; i++){
    	int c;
    	cin >> c;
    	for(int j = 1; j <= c; j++){
    		int x;
    		cin >> x;
    		adj[x].pb(i);
    	}
    }
    for(int i = 1; i <= n; i++){
    	if(sz(adj[i]) == 0){
    		ps(dsu.curans);
    		continue;
    	}
    	if(sz(adj[i]) == 1){
    		dsu.setTo(adj[i][0], 1-(s[i]-'0'));
    		//ps("setTo", adj[i][0], 1-(s[i]-'0'));
    		ps(dsu.curans);
    		continue;
    	}
    	assert(sz(adj[i]) == 2);
    	if(s[i]-'0' == 0){
    		dsu.uniteDiff(adj[i][0], adj[i][1]);
    		//ps("uniteDiff", adj[i][0], adj[i][1]);
    	}
    	else{
    		dsu.uniteSame(adj[i][0], adj[i][1]);
    		//ps("uniteSame", adj[i][0], adj[i][1]);
    	}
    	ps(dsu.curans);
    	continue;
    }
    /*for(int i = 1; i <= k; i++){
    	ps(i, dsu.par[i]);
    }*/
}
 
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), set tle
	* do smth instead of nothing and stay organized
*/