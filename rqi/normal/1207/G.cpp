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
 
const int MOD = 1000000007; // 998244353
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

template<int SZ> struct AhoCorasick { // fixed alphabet
	int sz = 1, link[SZ]; 
	int elinks[SZ];
	array<int,26> to[SZ];
	bool isquery[SZ]; //1 if query string does end here
	vector<int> children[SZ];
	AhoCorasick() {
		F0R(i,SZ) to[i] = array<int,26>();
		F0R(i, SZ){
			elinks[i] = 0;
			isquery[i] = 0;
		}
	}
    
	int add(string s) { // add word
		int v = 0;
		trav(C,s) {
			int c = C-'a';
			if (!to[v][c]) to[v][c] = sz++;
			v = to[v][c];
		}
		isquery[v] = 1;
		return v;
	}
	
	void init() { // generate links
		link[0] = -1;
		queue<int> q; q.push(0);
		while (sz(q)) {
			int v = q.front(); q.pop();
			F0R(c,26) if (to[v][c]) {
				int u = to[v][c];
				link[u] = link[v] == -1 ? 0 : to[link[v]][c];
				q.push(u); 
			}
			if (v) F0R(c,26) if (!to[v][c]) to[v][c] = to[link[v]][c];
			// to[v][c] is equivalent to nex(v,c) in above
		}
	}
	void init2(){ // generate escape links
		for(int i = 1; i < sz; i++){
			children[link[i]].pb(i);
		}
	}
};
template<int SZ> struct RegTrie { // fixed alphabet
	int sz = 1;
	array<int,26> to[SZ];
	vector<pair<int, int>> querynodes[SZ]; // corresponding node in query trie, query number
	RegTrie() {
		F0R(i,SZ) to[i] = array<int,26>();
	}
    
};

template <class T, int ...Ns> struct BIT {
    T val = 0;
    void upd(T v) { val += v; }
    T query() { return val; }
};

template <class T, int N, int... Ns> struct BIT<T, N, Ns...> {
    BIT<T,Ns...> bit[N + 1];
    template<typename... Args> void upd(int pos, Args... args) {
        for (; pos <= N; pos += (pos&-pos)) bit[pos].upd(args...);
    }
    template<typename... Args> T sum(int r, Args... args) {
        T res = 0; for (; r; r -= (r&-r)) res += bit[r].query(args...); 
        return res;
    }
    template<typename... Args> T query(int l, int r, Args... args) {
        return sum(r,args...)-sum(l-1,args...);
    }
}; // BIT<int,10,10> gives a 2D BIT

int n;
RegTrie<800010> songs;
AhoCorasick<800010> querystrings;

int songnode[800010];
int treetravers[800010]; // node id
pair<int, int> firstlastposes[800010];
int curtreeind = 1;
BIT<ll, 800010> travbit;
ll anses[800010];

void maketrav(int node){
	treetravers[curtreeind] = node;
	firstlastposes[node].f = curtreeind;
	firstlastposes[node].s = curtreeind;
	curtreeind++;
	for(auto u: querystrings.children[node]){
		maketrav(u);
		treetravers[curtreeind] = node;
		firstlastposes[node].s = curtreeind;
		curtreeind++;
	}
}

int curqnode = 0;
void dfs(int node){
	//cout << node << " " << curqnode << "\n";
	for(auto u: songs.querynodes[node]){
		anses[u.s] = travbit.query(firstlastposes[u.f].f, firstlastposes[u.f].s);
		/*for(int i = 1; i <= 2*13; i++){
			cout << travbit.query(i, i) << " ";
		}
		cout<< "\n";*/
	}
	int origqnode = curqnode;
	for(int i = 0; i < 26; i++){
		if(songs.to[node][i] == 0){
			continue;
		}
		
		curqnode = querystrings.to[curqnode][i];
		int c = firstlastposes[curqnode].f;
		travbit.upd(firstlastposes[curqnode].f, 1);
		dfs(songs.to[node][i]);
		
		travbit.upd(firstlastposes[curqnode].f, -1);
		curqnode = origqnode;
	}
}

int main() {
    setIO();
    cin >> n;
    for(int i = 1; i <= n; i++){
    	int typ;
    	cin >> typ;
    	int c, j;
    	char cd;
    	if(typ == 2) cin >> j;
    	else j = 0;
    	cin >> cd;
    	c = cd-'a';
    	if(songs.to[songnode[j]][c] == 0){
    		songs.to[songnode[j]][c] = songs.sz;
    		songnode[i] = songs.sz;
    		songs.sz++;
    	}
    	else{
    		songnode[i] = songs.to[songnode[j]][c];
    	}
    }
    int m;
    cin >> m;
    for(int k = 1; k <= m; k++){
    	int i;
    	string t;
    	cin >> i >> t;
    	(songs.querynodes[songnode[i]]).pb(mp(querystrings.add(t), k));
    }
    querystrings.init();
    querystrings.init2();
    /* check if init2 is working:
    for(int i = 0; i < querystrings.sz; i++){
    	for(auto u: querystrings.children[i]){
    		cout << i << " " << u << "\n";
    	}
    }*/
    // now make suffix link tree & BIT
    maketrav(0);
    /*for(int i = 1; i <= 2*13; i++){
    	cout << treetravers[i] << " ";
    }*/
    //cout << firstlastposes[5].f << " " << firstlastposes[5].s;
    // now use dfs and backtracking to find the answers to each node query
    dfs(0);
    for(int i = 1; i <= m; i++){
    	cout << anses[i] << "\n";
    }
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/