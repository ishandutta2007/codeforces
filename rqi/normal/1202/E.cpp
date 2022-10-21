#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>
 
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
typedef long long int ll;
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
 
const ll MOD = (ll)1000000007;//989466010702279111 ; // 998244353
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

const ll expo = ll(rng() % 10000 + 7); // random number
const ll expo2 = ll(rng() % 10000 + 8);
string t;
long long n;
string rings[200005];
pair<modular<ll>, modular<ll>> csum[200005];
pair<ll, ll> trief[200005][26]; //node (beginning at 1), number of strings ending at that
unordered_set<ll> pfixes; //all hashed prefixes of given strings
unordered_set<ll> pfixes2; //all hashed prefixes of given strings
map<ll, ll> snums; //number of strings that are prefixes for each given prefix (key).
 map<ll, ll> snums2;

pair<modular<ll>, modular<ll>> powa[200005];

pair<modular<ll>, modular<ll>> invpowa[200005];

ll ans1[200005];
ll ans2[200005];


pair<ll, ll> gethash(ll a, ll b){
	return mp(ll((csum[b+1].f-csum[a].f)*(invpowa[a+1].f)), ll((csum[b+1].s-csum[a].s)*(invpowa[a+1].s))); // modll
	// looks good
}
 
bool checkright(ll a, ll b){
	if(pfixes.find(gethash(a, b).f) == pfixes.end() || pfixes2.find(gethash(a, b).s) == pfixes2.end()){
		return false;
	}
	return true;
}
 
void prop(ll a, ll b, pair<modular<ll>, modular<ll>> c, ll d){ //current node, current sum, string, length
	
	for(int i = 0; i < 26; i++){
		
		
		if(trief[a][i].f == 0) continue;
		trief[a][i].s+=b;
		//cout << a << " " << b << " " << c << " " << d << "\n";
		modular<ll> num1 = c.f+(modular<ll>)(i+1)*powa[d].f;
		
		modular<ll> num2 = c.s+(modular<ll>)(i+1)*powa[d].s;
		snums[ll(num1)] += trief[a][i].s;// keep track of the actual string
		snums2[ll(num2)] += trief[a][i].s;
		prop(trief[a][i].f, trief[a][i].s, mp(num1, num2),d+1);
		
	}
}
 
int main() {
    setIO();
    // 1 index the t string
	//require bigger mod
	
	cin >> t >> n;
	// hash the string (csum)
	powa[1] = mp(1, 1);
	for(int i = 2; i <= 200004; i++){
	
		powa[i].f = powa[i-1].f*expo;
		invpowa[i].f = 1/powa[i].f;
		
		powa[i].s = powa[i-1].s*expo2;
		invpowa[i].s = 1/powa[i].s;
	}
	/*for(int i = 1; i <= t.size(); i++){
		cout << powa[i] << "\n";
	}*/
	for(int i = 0; i < t.size(); i++){
		csum[i+1].f = csum[i].f+(modular<ll>)(t[i]-'a'+1)*powa[i+1].f;
		
		csum[i+1].s = csum[i].s+(modular<ll>)(t[i]-'a'+1)*powa[i+1].s;
	}
	ll curnewnode = 2; // starting node is 1
	
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		rings[i] = s;
		pair<modular<ll>,modular<ll>> curnum = mp(0, 0);
		// add it to the trie
		ll curnode = 1;
		for(int i = 0; i < sz(s); i++){
			curnum.f+=(modular<ll>)(s[i]-'a'+1)*powa[i+1].f;
			
			curnum.s+=(modular<ll>)(s[i]-'a'+1)*powa[i+1].s;
			
			pfixes.insert((ll)curnum.f);
			
			pfixes2.insert((ll)curnum.s);
			if(i == sz(s)-1){
				trief[curnode][s[i]-'a'].s++;
			}
			if(trief[curnode][s[i]-'a'].f == 0){
				trief[curnode][s[i]-'a'].f = curnewnode;
				curnewnode++;
				curnode = trief[curnode][s[i]-'a'].f;
			}
			else{
				curnode = trief[curnode][s[i]-'a'].f;
			}
		}
		
	}
	/*for(int i = 0; i < 100; i++){
		for(int j = 0; j < 26; j++){
			if(trief[i][j].f != 0 || trief[i][j].s != 0){
				cout << i << " " << j << " " << trief[i][j].f << " " << trief[i][j].s << "\n";
			}
		}
	}*/
	prop(1, 0, mp(0, 0), 1);
	/*cout << "\n\n";
	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 26; j++){
			if(trief[i][j].f != 0 || trief[i][j].s != 0){
				cout << i << " " << j << " " << trief[i][j].f << " " << trief[i][j].s << "\n";
			}
		}
	}*/
	// do pfixes, snums, sfixes, snums2
	/*for(auto u: snums){
		cout << u.f << " " << u.s << "\n";
	}*/
	long long ans = 0;
	for(int i = 0; i < t.size()-1; i++){ // last character included in the left side
		
		ll lo = i;
		ll hi = t.size()-1;
		while(lo < hi){
			ll mid = (lo+hi)/2+1;
			if(checkright(i+1, mid) == true) lo = mid;
			else hi = mid-1;
		}
		ll rightans;
		if(lo  < i+1) rightans = 0;
		else{
			rightans = min(snums[gethash(i+1, lo).f], snums2[gethash(i+1, lo).s]);
			//cout << i+1 << "HI" << lo << "\n";
		}
		ans1[i] = rightans;
		//cout << rightans << "\n";
	}
	//cout << ans;
	for(int i = 0; i < 200005; i++){
		csum[i] = mp(0, 0);
	}
	for(int i = 0; i < 200005; i++){
		for(int j = 0; j < 26; j++){
			trief[i][j] = mp(0, 0);
		}
	}
	pfixes.clear();
	pfixes2.clear();
	snums.clear();
	snums2.clear();
	///////////////////////
	
	reverse(t.begin(), t.end());
	
	for(int i = 0; i < t.size(); i++){
		csum[i+1].f = csum[i].f+(modular<ll>)(t[i]-'a'+1)*powa[i+1].f;
		
		csum[i+1].s = csum[i].s+(modular<ll>)(t[i]-'a'+1)*powa[i+1].s;
	}
	curnewnode = 2; // starting node is 1
	
	for(int i = 0; i < n; i++){
		string s;
		s = rings[i];
		reverse(s.begin(), s.end());
		pair<modular<ll>,modular<ll>> curnum = mp(0, 0);
		// add it to the trie
		ll curnode = 1;
		for(int i = 0; i < sz(s); i++){
			curnum.f+=(modular<ll>)(s[i]-'a'+1)*powa[i+1].f;
			
			curnum.s+=(modular<ll>)(s[i]-'a'+1)*powa[i+1].s;
			pfixes.insert((ll)curnum.f);
			pfixes2.insert((ll)curnum.s);
			if(i == sz(s)-1){
				trief[curnode][s[i]-'a'].s++;
			}
			if(trief[curnode][s[i]-'a'].f == 0){
				trief[curnode][s[i]-'a'].f = curnewnode;
				curnewnode++;
				curnode = trief[curnode][s[i]-'a'].f;
			}
			else{
				curnode = trief[curnode][s[i]-'a'].f;
			}
		}
		
	}
	prop(1, 0, mp(0, 0), 1);
	
	for(int i = 0; i < t.size()-1; i++){ // last character included in the left side
		
		ll lo = i;
		ll hi = t.size()-1;
		while(lo < hi){
			ll mid = (lo+hi)/2+1;
			if(checkright(i+1, mid) == true) lo = mid;
			else hi = mid-1;
		}
		ll rightans;
		if(lo  < i+1) rightans = 0;
		else{
			rightans = min(snums[gethash(i+1, lo).f], snums2[gethash(i+1, lo).s]);
			//cout << i+1 << "HI" << lo << "\n";
		}
		ans2[i] = rightans;
		//cout << rightans << "\n";
	}
	for(int i = 0; i < t.size(); i++){
		//cout << ans1[i] << " " << ans2[t.size()-2-i] << "\n";
		ans+=(long long)ans1[i]*(long long)ans2[t.size()-2-i];
	}
	cout << (long long)(ans);
}
 
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/