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
string ans;
vi charnums[105];
int chars[105];
vector<pair<pi, pi>> edges;
vector<pair<int, pi>> adj[105];
vi possible[105];
vi sub(vi a, vi b){
	assert(sz(a) == sz(b));
	vi out;
	for(int i = 0; i < sz(a); i++){
		out.pb(a[i]-b[i]);
	}
	return out;
}
string teststring = "abb";
void genTestData(int l, int r){
	for(int i = l; i <= r; i++){
		for(int j = 1; i+j-1 <= r; j++){
			ps(teststring.substr(i-1, j));
		}
	}
	cout << "\n";
}

void query(int l, int r){
	if(l > r) return;
	if(l < 1) return;
	if(r > n) return;
	int dist = r-l;
	for(int i = 0; i < 105; i++){
		charnums[i] = vector<int>(26, 0);
	}
	cout << "? " << l << " " << r << "\n";
	
	cout.flush();
	
	for(int i = 0; i < ((dist+1)*(dist+2))/2; i++){
		string s;
		cin >> s;
		for(char u: s){
			charnums[sz(s)][u-'a']++;
		}
	}
	
	for(int i = l; i <= l+(dist)/2; i++){
		vi a = charnums[i-l+1];
		for(int j = i-l+2; j < 105; j++){
			charnums[j] = sub(charnums[j], a);
		}
	}
	
	for(int i = l; i <= l+(dist)/2; i++){
		charnums[i-l+1] = sub(charnums[i-l+1], charnums[i-l+2]);
	}
	
	for(int i = l; i <= l+(dist)/2; i++){
		vi nums;
		for(int j = 0; j < 26; j++){
			if(charnums[i][j] == 1){
				nums.pb(j);
			}
			else if(charnums[i][j] == 2){
				nums.pb(j);
				nums.pb(j);
			}
		}
		//ps(nums, i, (r+l)-i);
		edges.pb(mp(mp(i, (r+l)-i), mp(nums[0], nums[1])));
	}
}
bool found = 0;
bool visited[105];
int search(int pos, int num){
	//ps(pos, possible[pos]);
		//ps(pos, adj[pos]);
		if(visited[pos] == 1){
			if(chars[pos] == num) return 0;
			return -1;
		}
		visited[pos] = 1;
		chars[pos] = num;
		bool works = 1;
		for(auto u: adj[pos]){
			bool firstsat = 0;
			bool secondsat = 0;
			if(chars[pos] == u.s.f){
				int out = search(u.f, u.s.s);
				if(out == -1) return -1;
			}
			else if(chars[pos] == u.s.s){
				int out = search(u.f, u.s.f);
				if(out == -1) return -1;
			}
			else return -1;
		}
	return 0;
}
void generatechars(){
	for(int i = 1; i <= n; i++){
		chars[i] = -1;
	}

	for(auto u: edges){
		adj[u.f.f].pb(mp(u.f.s, mp(u.s.f, u.s.s)));
		adj[u.f.s].pb(mp(u.f.f, mp(u.s.f, u.s.s)));
	}
	
	for(int i = 1; i <= n; i++){
		vector<bool> possibles = vector<bool>(26, 1);
		for(auto u: adj[i]){
			int a = u.s.f;
			int b = u.s.s;
			for(int j = 0; j < 26; j++){
				if(j != a && j != b){
					possibles[j] = 0;
				}
			}
			
		}
		for(int j = 0; j < 26; j++){
			if(possibles[j] == 1){
				possible[i].pb(j);
			}
		}
		if(sz(possible[i]) == 1) possible[i].pb(possible[i][0]);
	}
	
	for(int i = 1; i <= n; i++){
		//ps(i, adj[i]);
	}
	for(int i = 1; i <= n; i++){
		if(chars[i] == -1){
			for(int j = 1; j <= n; j++){
				visited[j] = 0;
			}
			
			int a = search(i, possible[i][0]);
			/*ps(i, ":");
			for(int i = 1; i <= n; i++){
				cout << visited[i];
			}*/
			if(a == -1){
				for(int j = 1; j <= n; j++){
					visited[j] = 0;
				}
				search(i, possible[i][1]);
			}
		}
	}
	
}
void endproblem(string ans){
	cout << "! " << ans << "\n";
	cout.flush();
}

int main() {
	setIO();
    // you should actually read the stuff at the bottom
    cin >> n;
    /*genTestData(1, sz(teststring));
    genTestData(1, sz(teststring)-1);*/
    query(1, n);
	query(1, n-1);
	
    generatechars();
    
    for(int i = 1; i <= n; i++){
    	ans.pb(char(chars[i]+'a'));
    }
    endproblem(ans);
}
 
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), set tle
	* do smth instead of nothing and stay organized
*/