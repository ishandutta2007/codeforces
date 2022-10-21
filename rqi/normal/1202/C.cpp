#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>
 
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize
 
const int MOD = 998244353; // 998244353
const ll INF = 1e18;
const int MX = 200005;
const ld PI = 4*atan((ld)1);
 
template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }
 
namespace input {
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);
 
    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { 
        re(first); re(rest...); 
    }
 
    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}
 
using namespace input;
 
namespace output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);
 
    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        pr(first); pr(rest...); 
    }
 
    template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
        pr("{",x.f,", ",x.s,"}"); 
    }
    template<class T> void prContain(const T& x) {
        pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; // const needed for vector<bool>
        pr("}");
    }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
    
    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) { 
        pr(first); ps(); // no space at end of line
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) { 
        pr(first," "); ps(rest...); // print w/ spaces
    }
}
 
using namespace output;
 
namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0); // fast I/O
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
    
    friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
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
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll xs[4] = {0, 1, 0, -1};
ll ys[4] = {1, 0, -1, 0};
int main() {
    setIO();
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
    	string s;
    	cin >> s;
    	ll beg[sz(s)+5][4]; //left, right, down, up
    	ll end[sz(s)+5][4];
    	vector<pair<ll, ll>> poses;
    	for(int i = 0; i < sz(s)+5; i++){
    		for(int j = 0; j < 4; j++){
    			beg[i][j] = 0;
    			end[i][j] = 0;
    		}
    	}
    	pair<ll, ll> curpos = mp(0, 0);
    	poses.pb(curpos);
    	for(int i = 0; i < s.size(); i++){
    		char a = s[i];
    		if(a == 'W'){
    			curpos.s++;
    		}
    		else if(a == 'A'){
    			curpos.f--;
    		}
    		else if(a == 'S'){
    			curpos.s--;
    		}
    		else{
    			curpos.f++;
    		}
    		beg[i+1][0] = min(beg[i][0], curpos.f);
    		beg[i+1][1] = max(beg[i][1], curpos.f);
    		beg[i+1][2] = min(beg[i][2], curpos.s);
    		beg[i+1][3] = max(beg[i][3], curpos.s);
    		poses.pb(curpos);
    	}
    	end[s.size()][0] = curpos.f;
    	end[s.size()][1] = curpos.f;
    	end[s.size()][2] = curpos.s;
    	end[s.size()][3] = curpos.s;
    	
    	for(int i = s.size()-1; i >= 0; i--){
    		char a = s[i];
    		if(a == 'W'){
    			curpos.s--;
    		}
    		else if(a == 'A'){
    			curpos.f++;
    		}
    		else if(a == 'S'){
    			curpos.s++;
    		}
    		else{
    			curpos.f--;
    		}
    		end[i][0] = min(end[i+1][0], curpos.f);
    		end[i][1] = max(end[i+1][1], curpos.f);
    		end[i][2] = min(end[i+1][2], curpos.s);
    		end[i][3] = max(end[i+1][3], curpos.s);
    	}
    	ll ans = (beg[s.size()][1]-beg[s.size()][0]+1)*(beg[s.size()][3]-beg[s.size()][2]+1);
    	
    	for(int i = 0; i < s.size(); i++){
    		for(int j = 0; j < 4; j++){
    			ll lef = beg[i][0];
    			ll rig = beg[i][1];
    			ll bot = beg[i][2];
    			ll top = beg[i][3];
    			lef = min(lef, end[i+1][0]+xs[j]);
    			lef = min(lef, poses[i].f+xs[j]);
    			rig = max(rig, end[i+1][1]+xs[j]);
    			rig = max(rig, poses[i].f+xs[j]);
    			bot = min(bot, end[i+1][2]+ys[j]);
    			bot = min(bot, poses[i].s+ys[j]);
    			top = max(top, end[i+1][3]+ys[j]);
    			top = max(top, poses[i].s+ys[j]);
    			ans = min(ans, (rig-lef+1)*(top-bot+1));
    		}
    	}
    	cout << ans << "\n";
    }
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/