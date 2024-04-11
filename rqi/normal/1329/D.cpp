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
typedef vector<ll> vl; 
typedef vector<db> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 
typedef vector<pd> vpd; 

#define mp make_pair 
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
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

template<class T> bool ckmin(T& a, const T& b) { 
	return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; } 
int pct(int x) { return __builtin_popcount(x); } 
int bit(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
int cdiv(int a, int b) { return a/b+!(a<0||a%b == 0); } // division of a by b rounded up, assumes b > 0 

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
template<class A, class B> str ts(pair<A,B> p);
template<class A> str ts(complex<A> c) { return ts(mp(c.real(),c.imag())); }
str ts(bool b) { return b ? "true" : "false"; }
str ts(char c) { str s = ""; s += c; return s; }
str ts(str s) { return s; }
str ts(const char* s) { return (str)s; }
str ts(vector<bool> v) { 
	bool fst = 1; str res = "{";
	F0R(i,sz(v)) {
		if (!fst) res += ", ";
		fst = 0; res += ts(v[i]);
	}
	res += "}"; return res;
}
template<size_t SZ> str ts(bitset<SZ> b) {
	str res = ""; F0R(i,SZ) res += char('0'+b[i]);
	return res; }
template<class T> str ts(T v) {
	bool fst = 1; str res = "{";
	for (const auto& x: v) {
		if (!fst) res += ", ";
		fst = 0; res += ts(x);
	}
	res += "}"; return res;
}
template<class A, class B> str ts(pair<A,B> p) {
	return "("+ts(p.f)+", "+ts(p.s)+")"; }

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
	cerr << to_string(h); if (sizeof...(t)) cerr << ", ";
	DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

// FILE I/O
void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void unsyncIO() { ios_base::sync_with_stdio(0); cin.tie(0); }
void setIO(string s = "") {
	unsyncIO();
	// cin.exceptions(cin.failbit); 
	// throws exception when do smth illegal
	// ex. try to read letter into int
	if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
}

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 



template<class T, int SZ> struct LazySeg1 { //cur indices of original indices
	T sum[2*SZ], lazy[2*SZ]; 
	LazySeg1() { F0R(i,2*SZ) sum[i] = lazy[i] = 0; }
	void push(int ind, int L, int R) { /// modify values for current node
		if (L != R) F0R(i,2) lazy[2*ind+i] += lazy[ind]; /// prop to children
		sum[ind] += (R-L+1)*lazy[ind]; lazy[ind] = 0; 
	} // recalc values for current node
	void pull(int ind) { sum[ind] = sum[2*ind]+sum[2*ind+1]; }
	void build() { ROF(i,1,SZ) pull(i); }
	void upd(int lo,int hi,T inc,int ind=1,int L=0, int R=SZ-1) {
		push(ind,L,R); if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) { 
			lazy[ind] = inc; push(ind,L,R); return; }
		int M = (L+R)/2;
		upd(lo,hi, inc, 2*ind,L,M); upd(lo,hi, inc, 2*ind+1,M+1,R); 
		pull(ind);
	}
	T qsum(int lo, int hi, int ind=1, int L=0, int R = SZ-1) {
		push(ind,L,R); if (lo > R || L > hi) return 0;
		if (lo <= L && R <= hi) return sum[ind];
		int M = (L+R)/2; 
		return qsum(lo,hi,2*ind,L,M)+qsum(lo,hi,2*ind+1,M+1,R);
	}
};



template<class T, int SZ> struct LazySeg2 { //1 = active, 0 = inactive, range set to 0, find sum
	T sum[2*SZ], lazy[2*SZ]; 
	LazySeg2() { F0R(i,2*SZ) sum[i] = lazy[i] = -1; }
	void push(int ind, int L, int R) { /// modify values for current node
		 if(lazy[ind] == -1) return;
		if (L != R) F0R(i,2) lazy[2*ind+i] = lazy[ind]; /// prop to children
		sum[ind] = lazy[ind]*(R-L+1); lazy[ind] = -1; 
	} // recalc values for current node
	void pull(int ind) { sum[ind] = sum[2*ind]+sum[2*ind+1]; }
	void build() { ROF(i,1,SZ) pull(i); }
	void upd(int lo,int hi, int inc, int ind=1,int L=0, int R=SZ-1) {
		push(ind,L,R); if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) { 
			lazy[ind] = inc; push(ind,L,R); return; }
		int M = (L+R)/2;
		upd(lo,hi, inc, 2*ind,L,M); upd(lo,hi, inc, 2*ind+1,M+1,R); 
		pull(ind);
	}
	T qsum(int lo, int hi, int ind=1, int L=0, int R = SZ-1) {
		push(ind,L,R); if (lo > R || L > hi) return 0;
		if (lo <= L && R <= hi) return sum[ind];
		int M = (L+R)/2; 
		return qsum(lo,hi,2*ind,L,M)+qsum(lo,hi,2*ind+1,M+1,R);
	}
};


int n;
string s;
set<pair<int, char>> letnum; //# of occurrences of each character block
set<pair<int, char>> bigchars; // Original location of current character blocks
set<pair<int, pair<int, char>>> par1[26]; // <A>B. Location of A, location of [character] 
set<pair<int, pair<int, char>>> par2[26]; // B<A>.
LazySeg1<ll, 262144> lseg1; //cur indices of original indices
LazySeg2<ll, 262144> lseg2; //1 = active, 0 = inactive, range set to 0, find sum
vpi ans;

void SegRemov(int l, int r){ //original left, right indices
	int curl = lseg1.qsum(l, l);
	int curr = lseg1.qsum(r, r);
	ans.pb(mp(curl, curr));
	int dec = lseg2.qsum(l, r);
	lseg2.upd(l, r, 0); // set to 0
	lseg1.upd(r+1, n, -dec);
}

map<char, int> letnummap; 


void updletnum(char a, int inc){
	letnum.erase(mp(letnummap[a], a));
	letnummap[a]+=inc;
	letnum.insert(mp(letnummap[a], a));
}

void insertpair(pair<int, char> p1, pair<int, char> p2){
	if(p1.s != p2.s){
		par1[p1.s-'a'].insert(mp(p1.f, mp(p2.f, p2.s)));
		par2[p2.s-'a'].insert(mp(p2.f, mp(p1.f, p1.s)));
	}
}

void removpair(pair<int, char> p1, pair<int, char> p2){
	if(p1.s != p2.s){
		par1[p1.s-'a'].erase(mp(p1.f, mp(p2.f, p2.s)));
		par2[p2.s-'a'].erase(mp(p2.f, mp(p1.f, p1.s)));
	}
}


void BigRemov(pair<int, char> p){ //update all the data structures given that we remove this from bigchars
	updletnum(p.s, -1);
	//update par1, par2
	//remove, then maybe insert
	pair<int, char> l = mp(-1, '0'); // left of p
	pair<int, char> r = mp(-1, '0'); // right of p
	auto it = bigchars.find(p);
	assert(it != bigchars.end());
	if(it != bigchars.begin()){
		l = *(prev(it));
	}
	if(it != prev(bigchars.end())){
		r = *(next(it));
	}

	if(l.f != -1){
		//remove pairs between l, p
		removpair(l, p);
	}
	if(r.f != -1){
		//remove pairs between p, r
		removpair(p, r);
	}
	if(l.f != -1 && r.f != -1){
		//insert pairs between l, r
		insertpair(l, r);
	}


	//update bigchars
	bigchars.erase(p);
}


int main() {
	setIO();
	int t;
	cin >> t;

	for(int i = 0; i < t; i++){
		cin >> s;
		n = sz(s);
		s = "0"+s;
		
		letnum.clear();
		bigchars.clear();
		ans.clear();
		letnummap.clear();
		for(int i = 0; i < 26; i++){
			par1[i].clear();
			par2[i].clear();
		}
		for(int i = 1; i <= n; i++){
			lseg1.upd(i, i, -lseg1.qsum(i, i));
			lseg1.upd(i, i, i);
		}
		lseg2.upd(1, n, 1);


		bool isEZ = true;

		for(int i = 1; i <= n-1; i++){
			if(s[i] == s[i+1]){
				isEZ = false;
				updletnum(s[i], 1);
				bigchars.insert(mp(i, s[i]));
			}
		}


		if(isEZ == true){
			cout << 1 << "\n" << 1 << " " << n << "\n";
			continue;
		}



		auto it = bigchars.begin();
		while(true){
			if(next(it) == bigchars.end()) break;
			insertpair(*it, *(next(it)));
			it = next(it);
		}
		//int onum = 0;
		while(true){ //do SegRemov operations
			//onum++;
			bool charleft0 = 0;
			if(sz(letnum) == 0) charleft0 = 1;
			else if(prev(letnum.end())->f == 0) charleft0 = 1;

			if(charleft0 == 1){
				SegRemov(1, n);
				break;
			}

			bool charleft1 = 0;
			if(sz(letnum) == 1) charleft1 = 1;
			else if(prev(prev(letnum.end()))->f == 0) charleft1 = 1;
			if(charleft1 == 1){
				//SegRemov Everything!
				int L = 0;
				int R = 0;
				for(auto u: bigchars){
					swap(L, R);
					L++;
					R = u.f;
					SegRemov(L, R);
				}
				SegRemov(R+1, n);
				break;
			}

			pair<int, char> p1, p2;
			p1.s = prev(letnum.end())->s;
			assert(sz(par1[p1.s-'a']) >= 1 || sz(par2[p1.s-'a']) >= 1);
			if(sz(par1[p1.s-'a']) >= 1){
				p1.f = (par1[p1.s-'a'].begin())->f;
				p2 = (*(par1[p1.s-'a'].begin())).s;
			}
			else{
				p1.f = (par2[p1.s-'a'].begin())->f;
				p2 = (*(par2[p1.s-'a'].begin())).s;
			}
			
			int L = p1.f;
			int R = p2.f;
			if(L > R) swap(L, R);
			L++;
			SegRemov(L, R);
			BigRemov(p1);
			BigRemov(p2);
		}

		cout << sz(ans) << "\n";
		for(auto u: ans){
			cout << u.f << " " << u.s << "\n";
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