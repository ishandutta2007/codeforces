#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef double db; 
typedef string str; 

typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef pair<db,db> pd; 

typedef vector<int> vi; 
typedef vector<bool> vb; 
typedef vector<ll> vl; 
typedef vector<db> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 
typedef vector<pd> vpd; 

#define mp make_pair
#define f first
#define s second
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define ft front() 
#define bk back()
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound 

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5; 
const ll INF = 1e18; 
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; 
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

template<class T> bool ckmin(T& a, const T& b) { 
	return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; } 
constexpr int pct(int x) { return __builtin_popcount(x); } 
constexpr int bits(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down
ll half(ll x) { return fdiv(x,2); }

template<class T, class U> T fstTrue(T lo, T hi, U f) { 
	// note: if (lo+hi)/2 is used instead of half(lo+hi) then this will loop infinitely when lo=hi
	hi ++; assert(lo <= hi); // assuming f is increasing
	while (lo < hi) { // find first index such that f is true 
		T mid = half(lo+hi);
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}
template<class T, class U> T lstTrue(T lo, T hi, U f) {
	lo --; assert(lo <= hi); // assuming f is decreasing
	while (lo < hi) { // find first index such that f is true 
		T mid = half(lo+hi+1);
		f(mid) ? lo = mid : hi = mid-1;
	} 
	return lo;
}
template<class T> void remDup(vector<T>& v) { 
	sort(all(v)); v.erase(unique(all(v)),end(v)); }

// INPUT
template<class A> void re(complex<A>& c);
template<class A, class B> void re(pair<A,B>& p);
template<class A> void re(vector<A>& v);
template<class A, size_t SZ> void re(array<A,SZ>& a);

template<class T> void re(T& x) { cin >> x; }
void re(db& d) { str t; re(t); d = stod(t); }
void re(ld& d) { str t; re(t); d = stold(t); }
template<class H, class... T> void re(H& h, T&... t) { re(h); re(t...); }

template<class A> void re(complex<A>& c) { A a,b; re(a,b); c = {a,b}; }
template<class A, class B> void re(pair<A,B>& p) { re(p.f,p.s); }
template<class A> void re(vector<A>& x) { trav(a,x) re(a); }
template<class A, size_t SZ> void re(array<A,SZ>& x) { trav(a,x) re(a); }

// TO_STRING
#define ts to_string
str ts(char c) { return str(1,c); }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) { 
	#ifdef LOCAL
		return b ? "true" : "false"; 
	#else 
		return ts((int)b);
	#endif
}
template<class A> str ts(complex<A> c) { 
	stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) {
	str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);
	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) {
	str res = ""; F0R(i,SZ) res += char('0'+b[i]);
	return res; }
template<class A, class B> str ts(pair<A,B> p);
template<class T> str ts(T v) { // containers with begin(), end()
	#ifdef LOCAL
		bool fst = 1; str res = "{";
		for (const auto& x: v) {
			if (!fst) res += ", ";
			fst = 0; res += ts(x);
		}
		res += "}"; return res;
	#else
		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += " ";
			fst = 0; res += ts(x);
		}
		return res;

	#endif
}
template<class A, class B> str ts(pair<A,B> p) {
	#ifdef LOCAL
		return "("+ts(p.f)+", "+ts(p.s)+")"; 
	#else
		return ts(p.f)+" "+ts(p.s);
	#endif
}

// OUTPUT
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { 
	pr(h); pr(t...); }
void ps() { pr("\n"); } // print w/ spaces
template<class H, class... T> void ps(const H& h, const T&... t) { 
	pr(h); if (sizeof...(t)) pr(" "); ps(t...); }

// DEBUG
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
	cerr << ts(h); if (sizeof...(t)) cerr << ", ";
	DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL, chk -> fake assert
	#define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
	#define chk(...) if (!(__VA_ARGS__)) cerr << "Line(" << __LINE__ << ") -> function(" \
		 << __FUNCTION__  << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << "\n", exit(0);
#else
	#define dbg(...) 0
	#define chk(...) 0
#endif

// FILE I/O
void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }
void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }
void setIO(str s = "") {
	unsyncIO();
	// cin.exceptions(cin.failbit); 
	// throws exception when do smth illegal
	// ex. try to read letter into int
	if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
}

/**
 * Description: Disjoint Set Union with Rollback
 * Source: see DSU
 * Verification: *
 */

struct DSUrb {
	vi e; void init(int n) { e = vi(n,-1); }
	int get(int x) { return e[x] < 0 ? x : get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	vector<array<int,4>> mod;
	bool unite(int x, int y) { // union-by-rank
		x = get(x), y = get(y); 
		if (x == y) { mod.pb({-1,-1,-1,-1}); return 0; }
		if (e[x] > e[y]) swap(x,y);
		mod.pb({x,y,e[x],e[y]});
		e[x] += e[y]; e[y] = x; return 1;
	}
	void rollback() {
		auto a = mod.bk; mod.pop_back();
		if (a[0] != -1) e[a[0]] = a[2], e[a[1]] = a[3];
	}
};




const int mx = 500005;
int p[mx];
int a[mx];
int b[mx];
int typ[mx];
int qval[mx];

bool edgein[mx]; //which edges currently in the tree

set<int> adj[mx];
set<pi> vals[mx];

bool visited[mx];

int main() {
	setIO();
	int n, m, q;
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++){
		cin >> p[i];
	}

	for(int i = 1; i <= m; i++){
		cin >> a[i] >> b[i];
	}

	for(int i = 1; i <= q; i++){
		cin >> typ[i] >> qval[i];
	}

	for(int i = 1; i <= m; i++){
		edgein[i] = 1;
	}

	for(int i = 1; i <= q; i++){
		if(typ[i] == 2){
			edgein[qval[i]] = 0;
		}
	}

	DSUrb dsu;
	dsu.init(n+5);

	for(int i = 1; i <= m; i++){
		if(edgein[i] == 0) continue;
		if(dsu.unite(a[i], b[i])){
			adj[a[i]].ins(b[i]);
			adj[b[i]].ins(a[i]);
		}
		else{
			edgein[i] = 0;
		}
	}

	for(int i = q; i >= 1; i--){
		if(typ[i] == 2){
			if(dsu.unite(a[qval[i]], b[qval[i]])){
				adj[a[qval[i]]].ins(b[qval[i]]);
				adj[b[qval[i]]].ins(a[qval[i]]);
				edgein[qval[i]] = 1;
			}
		}
	}

	for(int i = 1; i <= n; i++){
		if(dsu.get(i) != i) continue;
		queue<int> q1;
		visited[i] = 1;
		vals[i].ins(mp(p[i], i));
		q1.push(i);

		while(sz(q1)){
			int node = q1.front();
			q1.pop();
			for(auto u: adj[node]){
				if(visited[u] == 1) continue;
				visited[u] = 1;
				vals[i].ins(mp(p[u], u));
				q1.push(u);
			}
		}
	}

	for(int i = 1; i <= n; i++){
		visited[i] = 0;
	}

	for(int i = 1; i <= q; i++){
		if(typ[i] == 1){
			int v = qval[i];
			v = dsu.get(v);
			int ans;
			if(sz(vals[v]) == 0){
				ans = 0;
			}
			else{
				pi a = *(prev(vals[v].end()));
				vals[v].erase(a);
				p[a.s] = 0;
				ans = a.f;
			}
			ps(ans);
		}
		else{
			if(edgein[qval[i]] == 0){
				dsu.rollback();
				continue;
			}
			queue<int> q1, q2;
			vi nodes1, nodes2;
			int A = a[qval[i]];
			int B = b[qval[i]];
			int V = dsu.get(A); //representative

			visited[A] = visited[B] = 1;
			nodes1.pb(A);
			nodes2.pb(B);
			q1.push(A);
			q2.push(B);

			adj[A].erase(B);
			adj[B].erase(A);

			while(sz(q1) > 0 && sz(q2) > 0){
				if(sz(nodes1)+sz(adj[q1.front()]) > sz(nodes2)+sz(adj[q2.front()])){
					//search q2
					int node = q2.front();
					q2.pop();
					for(auto u: adj[node]){
						if(visited[u] == 1) continue;
						visited[u] = 1;
						nodes2.pb(u);
						q2.push(u);
					}
				}
				else{
					//search q1
					int node = q1.front();
					q1.pop();
					for(auto u: adj[node]){
						if(visited[u] == 1) continue;
						visited[u] = 1;
						nodes1.pb(u);
						q1.push(u);
					}
				}
			}

			dsu.rollback();
			A = dsu.get(A);
			B = dsu.get(B);

			if(sz(q2) == 0){
				set<pi> BVAL;
				for(auto u: nodes2){
					if(vals[V].count(mp(p[u], u))){
						vals[V].erase(mp(p[u], u));
						BVAL.ins(mp(p[u], u));
					}
				}
				swap(vals[V], vals[A]);
				swap(vals[B], BVAL);
			}
			else{
				set<pi> AVAL;
				for(auto u: nodes1){
					if(vals[V].count(mp(p[u], u))){
						vals[V].erase(mp(p[u], u));
						AVAL.ins(mp(p[u], u));
					}
				}
				swap(vals[V], vals[B]);
				swap(vals[A], AVAL);
			}

			for(auto u: nodes1) visited[u] = 0;
			for(auto u: nodes2) visited[u] = 0;
	
		}
	}



	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/