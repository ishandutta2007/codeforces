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
const int mx = 1000005;

pi ad(pi a, pi b){
	return mp(a.f+b.f, a.s+b.s);
}
pi cmax(pi a, pi b){
	if(a.f == b.f){
		if(a.s > b.s) return b; // min xcoordinate
		return a;
	}
	if(a.f > b.f) return a;
	return b;
}
int n, k, l;
bool cas[mx];
pi dp[mx];
int nex[mx];
int onum[mx]; // number of zeroes covering
pi dodp(int cost){ // cost per interval. Output min total cost of 0s, # of intervals used
	for(int i = 0; i < mx; i++){
		dp[i] = mp(0, 0);
	}	
	for(int i = n; i >= 1; i--){
		if(cas[i] == 1) continue;
		// dp has max number of 0s we can cover
		//we need number of 0s an interval with length l covers starting at i, index of next 1 after an index 
		dp[i] = cmax(ad(dp[nex[i+l-1]], mp(onum[i]-cost, 1)), dp[nex[i]]);
	}
	if(cost == 0){
		//ps(dp[38]);
		//ps(nex[38+l-1]);
	}
	int tzeroes = 0;
	for(int i = 1; i <= n; i++){
		if(cas[i] == 0) tzeroes++;
	}
	for(int i = 1; i <= n; i++){
		if(cas[i] == 0) return mp(tzeroes-dp[i].f, dp[i].s);
	}
	return mp(0, 0);
}
int solve(){ // output minimum number of 0s
	// clear all necessary variables
	for(int i = 0; i < mx; i++){
		nex[i] = 0;
		onum[i] = 0;
	}
	vi poses;
	for(int i = 1; i <= n; i++){
		if(cas[i] == 0) poses.pb(i);
		//cout << cas[i] << " ";
	}
	//cout << "\n";
	nex[n] = n+1;
	for(int i = 0; i < sz(poses); i++){
		if(i == sz(poses)-1){
			nex[poses[i]] = n+1;
			break;
		}
		nex[poses[i]] = poses[i+1]; 
	}
	
	for(int i = n-1; i >= 1; i--){
		if(cas[i] == 1){
			if(cas[i+1] == 0) nex[i] = i+1;
			else nex[i] = nex[i+1];
		}
	}
	/*for(int i = 1; i <= n; i++){
		cout << nex[i] << " ";
	}
	cout << "\n";*/
	for(int i = 0; i < sz(poses); i++){
		int curpos = poses[i];
		int ind = upper_bound(all(poses), curpos+l-1)-poses.begin()-1;
		onum[curpos] = ind-i+1;
	}
	
	//cout << "\n";
	int lo = 0; // cost per interval
	int hi = mx;
	while(lo < hi){
		int mid = (lo+hi)/2;
		int is = dodp(mid).s; //# of intervals with cost mid
		if(is > k){
			lo = mid+1;
		}		
		else hi = mid;
	}
	/*int lastind = -1;
	for(int i = 1000; i >= 0; i--){
		assert(dodp(i).s >= lastind);
		lastind = dodp(i).s;
	}*/
	//ps(lo);
	//ps(dodp(2));
	if(dodp(lo).s == k){
		return dodp(lo).f-dodp(lo).s*lo;
	}
	if(dodp(lo-1).s == k){
		return dodp(lo-1).f-dodp(lo-1).s*(lo-1);
	}
	assert(dodp(lo).s <= k);
	assert(dodp(lo+1).s < k);
	assert(lo == 0 || dodp(lo-1).s >= k);
	/*if(lo == 0){
		ps(dodp(0));
	}*/
	return dodp(lo).f-k*(lo);
}
int main() {
	setIO();
    // you should actually read the stuff at the bottom
    cin >> n >> k >> l;
    string s;
    cin >> s;
    for(int i = 1; i <= n; i++){
    	if(s[i-1] >= 'a' && s[i-1] <= 'z'){
    		cas[i] = 1;
    	}
    	else cas[i] = 0;
    }

    
    int ans = solve();
    for(int i = 1; i <= n; i++){
    	cas[i] = 1-cas[i];
    }
    ans = min(ans, solve());
    
    cout << ans;
}
 
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), set tle
	* do smth instead of nothing and stay organized
*/