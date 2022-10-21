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

int n;
char chars[3] = {'C', 'H', 'O'};
int ans[55]; // -1 = unfilled 0, 1, 2 = chars
vi query(vi a){
	string qstring;
	for(auto u: a){
		qstring.pb(chars[u]);
	}
	cout << "? " << qstring << "\n";
	cout.flush();
	int k;
	cin >> k;
	vi rval;
	for(int i = 1; i <= k; i++){
		int c;
		cin >> c;
		rval.pb(c);
	}
	return rval;
}
int end(){
	for(int i = 1; i <= n; i++){
		assert(ans[i] != -1);
	}
	string finans;
	for(int i = 1; i <= n; i++) finans.pb(chars[ans[i]]);
	cout << "! " << finans << "\n";
	cout.flush();
	int bol;
	cin >> bol;
	return bol;
}


void fillin(vi a){
	vi b = query(a);
	//ps("FILLIN", b);
	for(auto u: b){
		for(int i = u; i <= u+sz(a)-1; i++){
			ans[i] = a[i-u];
		}
	}
	
}

bool hasval(){
	for(int i = 1; i <= n; i++){
		if(ans[i] != -1) return 1;
	}
	return 0;
}
bool isfull(){
	for(int i = 1; i <= n; i++){
		if(ans[i] == -1) return 0;
	}
	return 1;
}
bool isin(vi &a, int b){
	for(auto &u: a){
		if(u == b) return 1;
	}
	return 0;
}
void laststep(){
	vi qstring;
	for(int i = 1; i <= n; i++){
		if(ans[i] != -1){
			qstring.pb(ans[i]);
		}
		else qstring.pb(1);
	}
	fillin(qstring);
	if(isfull() == 1){
		return;
	}
	for(int i = 1; i <= n; i++){
		if(ans[i] == -1) ans[i] = 2;
	}
	return;
}

int main() {
	setIO();
    // you should actually read the stuff at the bottom
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
    	
    	cin >> n;
		for(int i = 1; i <= n; i++){
			ans[i] = -1;
		}
		fillin({1, 0});
		fillin({1, 2});
		fillin({2, 0});
		fillin({2, 1});

		if(hasval() == 0){ // we know nothing case
			
			//test 3 0s
			fillin({0, 0, 0});
			fillin({1, 1, 1});
			fillin({2, 2, 2});
			
			//if nothing filled, must be 0011 or 0022
			
			if(hasval() == 0){
				assert(n == 4);
				fillin({0, 0, 1, 1});
				//for(int i = 1; i <= n; i++) cout << ans[i];
				if(isfull() == 1){
					end();
					continue;
				}
				else{
					ans[1] = 0;
					ans[2] = 0;
					ans[3] = 2;
					ans[4] = 2;
					end();
					continue;
				}
			}
			//if partially filled in at the end but not beginning, fill in beginning with 0s
			if(ans[n] != -1){
				for(int i = 1; i <= n; i++){
					if(ans[i] == -1) ans[i] = 0;
				}
			}
			//if everything is filled in, we good
			if(isfull() == 1){
				end();
				continue;
			}
			// if partially filled in, test entire thing for 0000011 case
			vi qstring;
			for(int i = 1; i <= n; i++){
				if(ans[i] != -1){
					qstring.pb(ans[i]);
					assert(ans[i] == 0);
				}
				else qstring.pb(1);
			}
			fillin(qstring);
			if(isfull() == 1){
				end();
				continue;
			}
			for(int i = 1; i <= n; i++){
				if(ans[i] == -1) ans[i] = 2;
			}
			end();
			continue;
		}
		else{
			
			//find the 2 possibilities for everything and 2 known things, then do everything based off of that
			int ind = n;
			for(int i = n; i >= 1; i--){
				if(ans[i] != -1){
					ind = i;
					break;
				}
			}
			vi qs;
			int curval = -2;
			for(int i = ind; i >= 1; i--){
				if(ans[i] != -1){
					
				}
				else{
					// change ans[ind]
					vi tval = qs;
					tval.insert(tval.begin(), curval);
					vi ou = query(tval);
					if(isin(ou, i) == 1){
						ans[i] = curval;
					}
					else{
						ans[i] = 0;
					}
				}
				qs.insert(qs.begin(), ans[i]);
				curval = ans[i];
			}
			for(int i = ind+1; i <= n; i++){
				vi tval = qs;
				tval.pb(0);
				vi ou = query(tval);
				if(isin(ou, 1) == 1){
					ans[i] = 0;
					qs.pb(0);
				}
				else{
					laststep();
					break;
				}
			}
			end();
		}
    }
}
 
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), set tle
	* do smth instead of nothing and stay organized
*/