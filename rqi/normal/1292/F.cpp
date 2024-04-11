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

int inside[65]; //0 - not inside. 1-divides stuff 2 - divided by stuff
vi adj[65];
pair<vi, vi> comp[65];
bool visited[65];
int compnum;


/**
 * Description: pre-compute factorial mod inverses for $MOD$, 
 	* assumes $MOD$ is prime and $SZ < MOD$
 * Time: O(SZ)
 * Source: KACTL
 * Verification: https://dmoj.ca/problem/tle17c4p5
 */

vector<mi> invs, fac, ifac;
void genFac(int SZ) {
	invs.rsz(SZ), fac.rsz(SZ), ifac.rsz(SZ); 
	invs[1] = fac[0] = ifac[0] = 1; 
	FOR(i,2,SZ) invs[i] = mi(-(mi)(MOD/i)*(invs[MOD%i]));
	FOR(i,1,SZ) {
		fac[i] = fac[i-1]*mi(i);
		ifac[i] = ifac[i-1]*invs[i];
	}
}

int toint(bitset<17> a){
	int tpow = 1;
	int b = 0;
	for(int i = 0; i < 17; i++){
		b+=tpow*a[i];
		tpow*=2;
	}
	return b;
}
void makeCOMP(int node){
	if(visited[node] == 1) return;
	visited[node] = 1;
	if(inside[node] == 1){
		comp[compnum].f.pb(node);
	}
	else if(inside[node] == 2){
		comp[compnum].s.pb(node);
	}
	for(auto u: adj[node]){
		makeCOMP(u);
	}
}

mi anses[131075][60];
vi bits[60];
int ind[65];
int within[131075]; //how many bottom nodes within a certain subset of the top
vi transitions[131075]; // what bottom nodes could transition the set
mi getans(vi a, vi b){
	for(int i = 0; i < 1<<sz(a); i++){
		for(int j = 0; j < 60; j++){
			anses[i][j] = 0;
		}
		transitions[i].clear();
		within[i] = 0;
	}
	for(int i = 0; i < 60; i++) bits[i].clear();
	for(int i = 0; i < sz(a); i++){
		ind[a[i]] = i;
	}
	for(int i = 0; i < sz(b); i++){
		ind[b[i]] = i;
	}
	for(int i = 0; i < 1<<sz(a); i++){
		bitset<17> c = i;
		for(int j = 0; j < sz(b); j++){
			bool ins = true;
			bool out = false;
			for(auto u: adj[b[j]]){
				if(c[ind[u]] == 0){
					ins = false;
				}
				else if(c[ind[u]] == 1){
					out = true;
				}
			}
			if(i == 0){
				bitset<17> d = i;
				for(auto u: adj[b[j]]){
					d[ind[u]] = 1;
				}
				transitions[i].pb(toint(d));
				continue;
			}
			if(ins == true){
				within[i]++;
			}
			else if(out == true){
				bitset<17> d = i;
				for(auto u: adj[b[j]]){
					d[ind[u]] = 1;
				}
				transitions[i].pb(toint(d));
			}

		}
		//ps(i, transitions[i]);
	}
	for(int i = 0; i < 1<<sz(a); i++){
		int num = i;
		int bitnum = 0;
		for(int i = 0; i < sz(a); i++){
			if(num>>i & 1 == 1) bitnum++;
		}
		bits[bitnum].pb(i);
	}
	
	anses[0][0] = 1;
	for(int i = 0; i <= sz(a); i++){
		for(auto u: bits[i]){
			bitset<17> c = u;
			
			for(int j = 0; j <= within[u]; j++){
				//ps(u, j, anses[u][j]);
				anses[u][j+1]+=anses[u][j]*mi(within[u]-j);
				for(auto k: transitions[u]){
					anses[k][j+1]+=anses[u][j];
				}
			}
		}
	}
	return anses[(1<<sz(a))-1][sz(b)];
}
int main() {
	setIO();
    // you should actually read the stuff at the bottom
    genFac(200);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
    	int a;
    	cin >> a;
    	inside[a] = 1;
    }
	for(int i = 1; i <= 60; i++){
		if(inside[i] != 1) continue;
		for(int j = i*2; j <= 60; j+=i){
			if(inside[j] == 1 || inside[j] == 2){
				adj[i].pb(j);
				adj[j].pb(i);
				inside[j] = 2;
			}
		}
	}
	
	for(int i = 1; i <= 60; i++){
		if(inside[i] == 0) visited[i] = 1;
	}
	for(int i = 1; i <= 60; i++){
		if(visited[i] == 0){
			compnum++;
			makeCOMP(i);
		}
	}
	int sumsizes = 0;
	mi ans = 1;
	for(int i = 1; i <= compnum; i++){
		if(sz(comp[i].s) == 0) continue;
		//ps(comp[i]);
		
		ans*=getans(comp[i].f, comp[i].s);
		//ps(getans(comp[i].f, comp[i].s));
		sumsizes+=sz(comp[i].s)-1;
		//ps(sz(comp[i].f), sz(comp[i].s));
		//ps(sz(comp[i].s)-1);
		ans*=ifac[sz(comp[i].s)-1];
	}
	//ps(ifac[sumsizes]*fac[sumsizes]);
	//ps(sumsizes);
	ans*=fac[sumsizes];
	ps(int(ans));
}
 
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), set tle
	* do smth instead of nothing and stay organized
*/