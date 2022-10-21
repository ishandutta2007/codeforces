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
const int MX = 5000;
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

int n;
int highest[5005]; // highest prime factor
vector<pair<int, pair<int, ll>>> child[15005]; //next node, prime fac, dist
int node[5005];
int subsize[15005];
int k[5005];

ll pnums[5005][5005];
ll rdist[5005]; // distance from root 
ll cans[5005]; // distance of common ancestor of i! and (i-1)! from root

vector<pair<int, ll>> adj[15005];
void getsubsizes(int node){
	int sub = 0;
	for(auto u: child[node]){
		getsubsizes(u.f);
		
		sub+=subsize[u.f];
		if(node == 1 && u.f == 2) ps(sub);
	}
	subsize[node] += sub;
}
int getBEST(int node){
	for(auto u: child[node]){
		if(subsize[u.f] >= subsize[1]-subsize[u.f]){
			return getBEST(u.f); 
		}
	}
	return node;
}
ll dists[15005];
void getdists(int node, int prv = -1, ll dist = 0){
	dists[node] = dist;
	for(auto u: adj[node]){
		if(u.f == prv) continue;
		getdists(u.f, node, dist+u.s);
	}
}
int main() {
	setIO();
	// you should actually read the stuff at the bottom
    for(int i = 2; i <= MX; i++){
    	if(highest[i] == 0){
    		for(int j = i; j <= MX; j+=i){
    			highest[j] = i;
    		}
    	}
    }
    for(int i = 2; i <= MX; i++){
    	for(int j = 2; j <= MX; j++){
    		pnums[i][j] = pnums[i-1][j];
    	}
    	int curnum = i;
    	while(curnum > 1){
    		pnums[i][highest[curnum]]++;
    		curnum/=highest[curnum];
    	}
    }
    for(int i = 2; i <= MX; i++){
	    ll rd = 0;
    	for(int j = 1; j <= MX; j++){
    		rd+=pnums[i][j];
    	}
    	rdist[i] = rd;
    	rd = 0;
    	for(int j = MX; j >= 1; j--){
    		if(pnums[i][j] > pnums[i-1][j]){
    			rd+=pnums[i-1][j];
    			break;
    		}
    		rd+=pnums[i][j];
    	}
    	cans[i] = rd;
    }
    // you should actually read the stuff at the bottom
    int c = 1;
    node[1] = 1;
    for(int i = 2; i <= MX; i++){
    	int curnode = 1;
    	ll curdist = cans[i];
    	while(true){
    		if(sz(child[curnode]) == 0){
    			child[curnode].pb(mp(++c, mp(2, rdist[i]-cans[i])));
    	
    			break;
    		}
    		if(child[curnode].back().s.f >= highest[i]){
    			curdist-=child[curnode].back().s.s;
    			curnode = child[curnode].back().f;
    			
    			continue;
    		}
    		pair<int, pair<int, ll>> ochild = child[curnode].back();
    		child[curnode].pop_back();
    		child[curnode].pb(mp(c+1, mp(highest[i], curdist)));
    		ochild.s.s-=curdist;
    		child[c+1].pb(ochild);
    		child[c+1].pb(mp(c+2, mp(2, rdist[i]-cans[i])));
    		c+=2;
    		break;
    	}
    	node[i] = c;
    }
    /*for(int i = 1; i <= MX+5; i++){
    	ps(i, child[i]);
    }
    for(int i = 1; i <= MX; i++) ps(i, node[i]);*/
    
    cin >> n;
    for(int i = 1; i <= n; i++){
    	int K;
    	cin >> K;
    	if(K == 0) K = 1;
    	k[K]++;
    }
    for(int i = 1; i <= MX; i++){
    	//ps(i, node[i], k[i]);
    	subsize[node[i]]+=k[i];
    }
    getsubsizes(1);
    int mid = getBEST(1);
    
    
    for(int i = 0; i < 15005; i++){
    	for(auto u: child[i]){
    		int a = i;
    		int b = u.f;
    		ll d = u.s.s;
    		adj[a].pb(mp(b, d));
    		adj[b].pb(mp(a, d));
    	}
    }
    getdists(mid);
    ll ans = 0;
    for(int i = 1; i <= MX; i++){
    	ans+=dists[node[i]]*ll(k[i]);
    }
    ps(ans);
}
 
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), set tle
	* do smth instead of nothing and stay organized
*/