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

const int mid = sqrt(200000); // should be sqrt(200000)
int n;

bool chars[200005];
int bigs[200005];
int cumbig[200005];
int curcums[mid*220005];
ll ans = 0;
int zsums[200005];
void findmaj(int rat){ //0s/1s = rat
	for(ll i = 1; i <= n; i++){
		if(chars[i] == 1) bigs[i] = rat;
		else bigs[i] = -1;
	}
	cumbig[0] = 0;
	int curmin = 0;
	for(int i = 1; i <= n; i++){
		cumbig[i] = cumbig[i-1]+bigs[i];
		curmin = min(cumbig[i], curmin);
	}
	for(int i = 0; i <= n; i++){
		ans+=ll(curcums[cumbig[i]-curmin]);
		curcums[cumbig[i]-curmin]++;
	}
	for(int i = 0; i <= n; i++){
		curcums[cumbig[i]-curmin] = 0;
	}
}
int getzeroes(int l, int r){
	if(l <= 0) return zsums[r];
	return zsums[r]-zsums[l-1];
}
int dp1[200005];
int dp2[200005];
vector<int> oposes;
int getdp1(int l, int r){
	if(l <= 0) return dp1[r];
	return dp1[r]-dp1[l-1];
}
void zeroestoans(int lzeroes, int mzeroes, int rzeroes, int ones, int minrat){ // 
	//fo(lzeroes, mzeroes, rzeroes, ones, minrat);
	for(int i = 0; i <= lzeroes+rzeroes; i++){
		dp1[i] = 0;
		dp2[i] = 0;
	}
	for(int i = 0; i <= lzeroes; i++){
		dp1[i] = 1;
	}
	for(int i = 1; i <= lzeroes+rzeroes; i++) dp1[i]+=dp1[i-1];
	for(int j = 0; j <= lzeroes+rzeroes; j++){
		dp2[j] = getdp1(j-rzeroes, j);
	}
	
	for(int i = max(mzeroes/ones*ones, ones*minrat); i <= lzeroes+rzeroes+mzeroes; i+=ones){
		if(i-mzeroes < 0) continue;
		ans+=ll(dp2[i-mzeroes]);
	}
	//ps(curcount);
}

void findbrute(int ones, int minrat){ //1s, 0s >= minrat * 1s
	

	//ps(ones, minrat, ": ");
	for(int i = 1; i+ones-1 <= sz(oposes)-2; i++){
		int pos1 = oposes[i];
		int pos2 = oposes[i+ones-1];
		int lzeroes = getzeroes(oposes[i-1], oposes[i]);
		int mzeroes = getzeroes(oposes[i], oposes[i+ones-1]);
		int rzeroes = getzeroes(oposes[i+ones-1], oposes[i+ones]);
		zeroestoans(lzeroes, mzeroes, rzeroes, ones, minrat);
	}
}
int main() {
	setIO();
    // REMEMBER LL REMEMBER LL REMEMBER LL REMEMBER LL AND CHANGE mid
    string s = "";
    cin >> s;
    /*for(int i = 1; i <= 199999; i++){
    	s+='1';
    }*/
    n = sz(s);
    for(int i = 1; i <= n; i++){
    	chars[i] = s[i-1]-'0';
    }
    oposes.pb(0);
	for(int i = 1; i <= n; i++){
		if(chars[i] == 1) oposes.pb(i);
	}
	oposes.pb(n+1);
    for(int i = 1; i <= n; i++){
    	zsums[i] = zsums[i-1];
    	if(chars[i] == 0) zsums[i]++;
    }
    
    zsums[n+1] = zsums[n];
    //first find just 1s (11111)
    int currun = 0;
    for(int i = 1; i <= n+1; i++){
    	if(chars[i] == 0){
    		ans+=(ll(currun)*ll(currun+1))/2;
    		currun = 0;
    	}
    	else currun++;
    }
    //then find 0s/1s = 1, 2, 3, .... mid
    for(int i = 1; i <= mid; i++){
    	findmaj(i);
    }
	
    //then find 0s/1s = mid+1, mid+2, mid+3..., 
    for(int i = 1; i*(mid+1) <= 200002; i++){ // i is # of 1s
    	findbrute(i, mid+1);
    }
    cout << ans;
    
}
 
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), set tle
	* do smth instead of nothing and stay organized
*/