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
 * Description: 1D range minimum query
 * Source: KACTL
 * Verification: 
	* https://cses.fi/problemset/stats/1647/
	* http://wcipeg.com/problem/ioi1223
	* https://pastebin.com/ChpniVZL
 * Memory: O(N\log N)
 * Time: O(1)
 */

template<class T> struct RMQ {
	// floor(log_2(x))
	int level(int x) { return 31-__builtin_clz(x); } 
	vector<T> v; vector<vi> jmp;
	int comb(int a, int b) { 
		return v[a] == v[b] ? min(a,b) : (v[a] < v[b] ? a : b); 
	} // index of minimum
	void init(const vector<T>& _v) {
		v = _v; jmp = {vi(sz(v))}; iota(all(jmp[0]),0);
		for (int j = 1; 1<<j <= sz(v); ++j) {
			jmp.pb(vi(sz(v)-(1<<j)+1));
			F0R(i,sz(jmp[j])) jmp[j][i] = comb(jmp[j-1][i],
									jmp[j-1][i+(1<<(j-1))]);
		}
	}
	int index(int l, int r) { // get index of min element
		int d = level(r-l+1);
		return comb(jmp[d][l],jmp[d][r-(1<<d)+1]);
	}
	T query(int l, int r) { return v[index(l,r)]; }
};

template<int SZ> struct LCA {
	int N, R = 1, depth[SZ], pos[SZ];
	vi adj[SZ];
	vpi tmp;
	RMQ<pi> r;
	void ae(int u, int v) { adj[u].pb(v), adj[v].pb(u); }
	void dfs(int u, int prev){
		pos[u] = sz(tmp); depth[u] = depth[prev]+1;
		tmp.pb({depth[u],u});
		trav(v,adj[u]) if (v != prev) {
			dfs(v, u);
			tmp.pb({depth[u],u});
		}
	}
	void init(int _N) {
		N = _N; dfs(R, 0);
		r.init(tmp);
	}
	int lca(int u, int v){
		u = pos[u], v = pos[v]; if (u > v) swap(u,v);
		return r.query(u,v).s;
	}
	int dist(int u, int v) {
		return depth[u]+depth[v]-2*depth[lca(u,v)];
	}
};

int n;
LCA<3005> lca;
ll paths[3005][3005];
int par[3005];
int subsizes[3005];
ll ans;

void gensubs(int node, int prv = -1){
	ll cursub = 1;
	for(auto u: lca.adj[node]){
		if(u == prv) continue;
		par[u] = node;
		gensubs(u, node);
		cursub+=subsizes[u];
	}
	subsizes[node] = cursub;
}
ll anses[3005][3005];
vector<pi> alldists[3005];
ll getANS(int a, int b){
	ll e1, e2;
	for(auto u: lca.adj[a]){
		if(lca.dist(u, b) == lca.dist(a, b)-1){
			if(u == par[a]){
				e1 = subsizes[a];
			}
			else e1 = subsizes[1]-subsizes[u];
			break;
		}
	}
	for(auto u: lca.adj[b]){
		if(lca.dist(u, a) == lca.dist(a, b)-1){
			if(u == par[b]){
				e2 = subsizes[b];
			}
			else e2 = subsizes[1]-subsizes[u];
			break;
		}
	}
	return e1*e2;
}
ll getans(int a, int b){
	return anses[a][b];
}

int main() {
	setIO();
    // you should actually read the stuff at the bottom
    cin >> n;
    for(int i = 0; i < n-1; i++){
    	int u, v;
    	cin >> u >> v;
    	lca.ae(u, v);
    }
    lca.init(n);
    gensubs(1);
    
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		paths[i][j] = -1;
    	}
    }
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		anses[i][j] = getANS(i, j);
    	}
    }
    for(int i = 1; i <= n; i++){
    	for(int j = i+1; j <= n; j++){
    		alldists[lca.dist(i, j)].pb(mp(i, j));
    	}
    }
    
    for(int i = 1; i <= n; i++){
    	if(i == 1) continue;
    	int a, b;
    	a = i;
    	b = par[i];
    	if(a > b) swap(a, b);
    	paths[a][b] = subsizes[i]*(subsizes[1]-subsizes[i]);
    }
    
    for(int i = 1; i <= n; i++){
    	for(auto p: alldists[i]){
    		int b1 = p.f;
    		int b2 = p.s;
    		
    		if(b1 > b2) swap(b1, b2);
    		ll tot = paths[b1][b2];
    		ans = max(ans, tot);
    		for(auto u: lca.adj[b1]){
    			if(lca.dist(u, b2) == lca.dist(b1, b2)+1){
    				int n1 = min(u, b2);
    				int n2 = max(u, b2);
    				paths[n1][n2] = max(paths[n1][n2], tot+getans(u, b2));
    			}
    		}
    		for(auto u: lca.adj[b2]){
    			if(lca.dist(b1, u) == lca.dist(b1, b2)+1){
    				int n1 = min(u, b1);
    				int n2 = max(u, b1);
    				paths[n1][n2] = max(paths[n1][n2], tot+getans(b1, u));
    			}
    		}
    	}
    }
    
    ps(ans);
}
 
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), set tle
	* do smth instead of nothing and stay organized
*/