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
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define resz resize

const int MOD = 1000000007; // 998244353
const ll INF = 1e18;
const int MX = 100001;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

template<class A, class B> A operator+=(A& l, const B& r) { return l = l+r; }
template<class A, class B> A operator-=(A& l, const B& r) { return l = l-r; }
template<class A, class B> A operator*=(A& l, const B& r) { return l = l*r; }
template<class A, class B> A operator/=(A& l, const B& r) { return l = l/r; }

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
        bool fst = 1; trav(a,x) pr(!fst?", ":"",a), fst = 0; 
        pr("}");
    }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
    
    void ps() { pr("\n"); } 
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

template<class T> struct modInt {
    T val;
    T mod = 0;
    // static const T mod = MOD;

    void normalize() {
        if (mod == 0) return;
        val %= mod; if (val < 0) val += mod;
    }
    modInt(T v = 0, T m = 0) : val(v), mod(m) { normalize(); }
    // modInt(T v = 0, T m = 0) : val(v) { normalize(); }

    explicit operator T() const { return val; }
    friend ostream& operator<<(ostream& os, const modInt& a) { return os << a.val; }
    friend bool operator==(const modInt& a, const modInt& b) { return a.val == b.val; }
    friend bool operator!=(const modInt& a, const modInt& b) { return !(a == b); }

    friend void check(modInt& a, modInt& b) { // make sure all operations are valid
        // comment out if mod is static const
        if (a.mod > 0 && b.mod > 0) { assert(a.mod == b.mod); return; }
        T mod = max(a.mod,b.mod); if (mod == 0) mod = MOD;
        if (a.mod != mod) { a.mod = mod; a.normalize(); }
        if (b.mod != mod) { b.mod = mod; b.normalize(); }
    }
    friend modInt operator+(modInt a, modInt b) {
        check(a,b); a.val += (T)b;
        if (a.val >= a.mod) a.val -= a.mod;
        return a;
    }
    friend modInt operator-(modInt a, modInt b) {
        check(a,b); a.val -= (T)b; 
        if (a.val < 0) a.val += a.mod; 
        return a;
    }
    friend modInt operator-(const modInt& a) { return modInt(0)-a; }

    friend modInt operator*(modInt a, modInt b) {
        check(a,b); a.val = (ll)a.val*(T)b%a.mod; return a;
    }
    friend modInt exp(modInt a, ll p) {
        modInt ans(1,a.mod);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend modInt inv(const modInt& a) {
        return {invGeneral(a.val,a.mod),a.mod};
        // return exp(b,b.mod-2) if prime
    }
    friend modInt operator/(modInt a, modInt b) { 
        check(a,b); return a*inv(b); 
    }
};

typedef modInt<int> mi;
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

set<pi> a[1000006]; //pos of first char, last char, index of first a, index of last a inside, index of first b, index of last b in bs, ...
vector<int> as;
vector<int> bs;
vector<int> cs;
int main() {
    setIO();
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
    	if(s[i] == 'a'){
    		as.pb(i);
    	}
    	else if(s[i] == 'b'){
    		bs.pb(i);
    	}
    	else cs.pb(i);
    }
    
    a[0] = {mp(-1, s.size())}; // 
    int count = 0;
    set<int> begs;
    begs.insert(-1);
    while(a[count].size() != 0){
    	auto it = a[count].begin();
    	while(it != a[count].end()){
    		pi u = *it;
    		// find first and last a within bounds
    		// same for b and c
    		/*for(auto u: as){
    			cout << u << "\n";
    		}*/
    		auto a1 = lower_bound(as.begin(), as.end(), u.f+1)-as.begin();
    		
    		auto a2 = lower_bound(as.begin(), as.end(), u.s)-as.begin();
    		//cout << a2;
    		if (a1 < as.size() && a2-1 >= 0 && a1 <= a2-1) {
    			if(next(it) == a[count].end() && begs.find(as[a1]) == begs.end()){
    				a[count+1].insert(mp(as[a1], as[a2-1]));
    				
    			}
    			else if(as[a1] <= next(it)->f && begs.find(as[a1]) == begs.end()){
    				a[count+1].insert(mp(as[a1], as[a2-1]));
    				
    			}
			}
			auto b1 = lower_bound(bs.begin(), bs.end(), u.f+1)-bs.begin();
    		auto b2 = lower_bound(bs.begin(), bs.end(), u.s)-bs.begin();
    		if (b1 < bs.size() && b2-1 >= 0 && b1 <= b2-1) {
    			if(next(it) == a[count].end() && begs.find(bs[b1]) == begs.end()){
    				a[count+1].insert(mp(bs[b1], bs[b2-1]));
    				
    			}
    			else if(bs[b1] <= next(it)->f && begs.find(bs[b1]) == begs.end()){
    				a[count+1].insert(mp(bs[b1], bs[b2-1]));
    				
    			}
			}
			auto c1 = lower_bound(cs.begin(), cs.end(), u.f+1)-cs.begin();
    		auto c2 = lower_bound(cs.begin(), cs.end(), u.s)-cs.begin();
    		if (c1 < cs.size() && c2-1 >= 0 && c1 <= c2-1) {
    			if(next(it) == a[count].end() && begs.find(cs[c1]) == begs.end()){
    				a[count+1].insert(mp(cs[c1], cs[c2-1]));
    				
    			}
    			else if(cs[c1] <= next(it)->f && begs.find(cs[c1]) == begs.end()){
    				a[count+1].insert(mp(cs[c1], cs[c2-1]));
    				
    			}
			}
			it++;
    	}
    	count++;
    	int curr = -1;
    	//cout << a[count].size();
    	vector<pi> eraselist;
    	for(auto u: a[count]){
    		
    		if(u.s <= curr){
    			eraselist.pb(u);
    		}
    		else{
    			curr = u.s;
    			begs.insert(u.f);
    		}
    	}
    	for(auto u: eraselist){
    		a[count].erase(u);
    	}
    	/*if(count == 4){
    		for(auto u: a[count]){
    			cout << u.f <<" " << u.s << "\n";
    		}
    	}*/
    }
    int length = 0;
    pi range;
    string ans;
    bool single = true;
    for(auto u: a[count-1]){
    	range = u;
    	if(u.f != u.s){
    		single = false;
    		break;
    	}
    }
    char spe = s[range.f];
    if(single == false) length+=2;
    else length++;
    
    length+=(count-2)*2;
    if(length < s.size()/2){
    	cout << "IMPOSSIBLE";
    	return 0;
    }
    
    for(int i = count-2; i >= 1; i--){
    	for(auto u: a[i]){
    		if(u.f < range.f && u.s > range.s){
    			range = u;
    			ans.append(1u, s[range.f]);
    		}
    	}
    }
    string ans1;
    for(int i = ans.size()-1; i >= 0; i--){
    	ans1.append(1u, ans[i]);
    }
    if(single == false){
    	ans1.append(1u, spe);
    	
    	ans1.append(1u, spe);
    }
    else ans1.append(1u, spe);
    for(int i = 0; i < ans.size(); i++){
    	ans1.append(1u, ans[i]);
    }
    cout << ans1;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/