#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using db = long double; // or double, if TL is tight
using str = string; // yay python! 

// pairs
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;
#define mp make_pair
#define f first
#define s second

#define tcT template<class T
#define tcTU tcT, class U
// ^ lol this makes everything look weird but I'll try it
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;

// vectors
// oops size(x), rbegin(x), rend(x) need C++17
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()

#define lb lower_bound
#define ub upper_bound
tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }
tcT> int upb(V<T>& a, const T& b) { return int(ub(all(a),b)-bg(a)); }

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5;
const ll BIG = 1e18; // not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4]{1,0,-1,0}, dy[4]{0,1,0,-1}; // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

// bitwise ops
// also see https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
constexpr int pct(int x) { return __builtin_popcount(x); } // # of bits set
constexpr int bits(int x) { // assert(x >= 0); // make C++11 compatible until USACO updates ...
	return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x)) 
constexpr int p2(int x) { return 1<<x; }
constexpr int msk2(int x) { return p2(x)-1; }

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down

tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; } // set a = max(a,b)

tcTU> T fstTrue(T lo, T hi, U f) {
	++hi; assert(lo <= hi); // assuming f is increasing
	while (lo < hi) { // find first index such that f is true 
		T mid = lo+(hi-lo)/2;
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
	--lo; assert(lo <= hi); // assuming f is decreasing
	while (lo < hi) { // find first index such that f is true 
		T mid = lo+(hi-lo+1)/2;
		f(mid) ? lo = mid : hi = mid-1;
	} 
	return lo;
}
tcT> void remDup(vector<T>& v) { // sort and remove duplicates
	sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcTU> void erase(T& t, const U& u) { // don't erase
	auto it = t.find(u); assert(it != end(t));
	t.erase(it); } // element that doesn't exist from (multi)set

#define tcTUU tcT, class ...U

inline namespace Helpers {
	//////////// is_iterable
	// https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable
	// this gets used only when we can call begin() and end() on that type
	tcT, class = void> struct is_iterable : false_type {};
	tcT> struct is_iterable<T, void_t<decltype(begin(declval<T>())),
	                                  decltype(end(declval<T>()))
	                                 >
	                       > : true_type {};
	tcT> constexpr bool is_iterable_v = is_iterable<T>::value;

	//////////// is_readable
	tcT, class = void> struct is_readable : false_type {};
	tcT> struct is_readable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cin >> declval<T&>()), istream&>
	        >
	    > : true_type {};
	tcT> constexpr bool is_readable_v = is_readable<T>::value;

	//////////// is_printable
	// // https://nafe.es/posts/2020-02-29-is-printable/
	tcT, class = void> struct is_printable : false_type {};
	tcT> struct is_printable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cout << declval<T>()), ostream&>
	        >
	    > : true_type {};
	tcT> constexpr bool is_printable_v = is_printable<T>::value;
}

inline namespace Input {
	tcT> constexpr bool needs_input_v = !is_readable_v<T> && is_iterable_v<T>;
	tcTUU> void re(T& t, U&... u);
	tcTU> void re(pair<T,U>& p); // pairs

	// re: read
	tcT> typename enable_if<is_readable_v<T>,void>::type re(T& x) { cin >> x; } // default
	tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } // complex
	tcT> typename enable_if<needs_input_v<T>,void>::type re(T& i); // ex. vectors, arrays
	tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
	tcT> typename enable_if<needs_input_v<T>,void>::type re(T& i) {
		each(x,i) re(x); }
	tcTUU> void re(T& t, U&... u) { re(t); re(u...); } // read multiple

	// rv: resize and read vectors
	void rv(size_t) {}
	tcTUU> void rv(size_t N, V<T>& t, U&... u);
	template<class...U> void rv(size_t, size_t N2, U&... u);
	tcTUU> void rv(size_t N, V<T>& t, U&... u) {
		t.rsz(N); re(t);
		rv(N,u...); }
	template<class...U> void rv(size_t, size_t N2, U&... u) {
		rv(N2,u...); }

	// dumb shortcuts to read in ints
	void decrement() {} // subtract one from each
	tcTUU> void decrement(T& t, U&... u) { --t; decrement(u...); }
	#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);
	#define int1(...) ints(__VA_ARGS__); decrement(__VA_ARGS__);
}

inline namespace ToString {
	tcT> constexpr bool needs_output_v = !is_printable_v<T> && is_iterable_v<T>;

	// ts: string representation to print
	tcT> typename enable_if<is_printable_v<T>,str>::type ts(T v) {
		stringstream ss; ss << fixed << setprecision(15) << v;
		return ss.str(); } // default
	tcT> str bit_vec(T t) { // bit vector to string
		str res = "{"; F0R(i,sz(t)) res += ts(t[i]);
		res += "}"; return res; }
	str ts(V<bool> v) { return bit_vec(v); }
	template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } // bit vector
	tcTU> str ts(pair<T,U> p); // pairs
	tcT> typename enable_if<needs_output_v<T>,str>::type ts(T v); // vectors, arrays
	tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
	tcT> typename enable_if<is_iterable_v<T>,str>::type ts_sep(T v, str sep) {
		// convert container to string w/ separator sep
		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += sep;
			fst = 0; res += ts(x);
		}
		return res;
	}
	tcT> typename enable_if<needs_output_v<T>,str>::type ts(T v) {
		return "{"+ts_sep(v,", ")+"}"; }

	// for nested DS
	template<int, class T> typename enable_if<!needs_output_v<T>,vs>::type 
	  ts_lev(const T& v) { return {ts(v)}; }
	template<int lev, class T> typename enable_if<needs_output_v<T>,vs>::type 
	  ts_lev(const T& v) {
		if (lev == 0 || !sz(v)) return {ts(v)};
		vs res;
		for (const auto& t: v) {
			if (sz(res)) res.bk += ",";
			vs tmp = ts_lev<lev-1>(t);
			res.ins(end(res),all(tmp));
		}
		F0R(i,sz(res)) {
			str bef = " "; if (i == 0) bef = "{";
			res[i] = bef+res[i];
		}
		res.bk += "}";
		return res;
	}
}

inline namespace Output {
	template<class T> void pr_sep(ostream& os, str, const T& t) { os << ts(t); }
	template<class T, class... U> void pr_sep(ostream& os, str sep, const T& t, const U&... u) {
		pr_sep(os,sep,t); os << sep; pr_sep(os,sep,u...); }
	// print w/ no spaces
	template<class ...T> void pr(const T&... t) { pr_sep(cout,"",t...); } 
	// print w/ spaces, end with newline
	void ps() { cout << "\n"; }
	template<class ...T> void ps(const T&... t) { pr_sep(cout," ",t...); ps(); } 
	// debug to cerr
	template<class ...T> void dbg_out(const T&... t) {
		pr_sep(cerr," | ",t...); cerr << endl; }
	void loc_info(int line, str names) {
		cerr << "Line(" << line << ") -> [" << names << "]: "; }
	template<int lev, class T> void dbgl_out(const T& t) {
		cerr << "\n\n" << ts_sep(ts_lev<lev>(t),"\n") << "\n" << endl; }
	#ifdef LOCAL
		#define dbg(...) loc_info(__LINE__,#__VA_ARGS__), dbg_out(__VA_ARGS__)
		#define dbgl(lev,x) loc_info(__LINE__,#x), dbgl_out<lev>(x)
	#else // don't actually submit with this
		#define dbg(...) 0
		#define dbgl(lev,x) 0
	#endif

	const clock_t beg = clock();
	#define dbg_time() dbg((db)(clock()-beg)/CLOCKS_PER_SEC)
}

inline namespace FileIO {
	void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
	void setOut(str s) { freopen(s.c_str(),"w",stdout); }
	void setIO(str s = "") {
		cin.tie(0)->sync_with_stdio(0); // unsync C / C++ I/O streams
		// cin.exceptions(cin.failbit);
		// throws exception when do smth illegal
		// ex. try to read letter into int
		if (sz(s)) setIn(s+".in"), setOut(s+".out"); // for old USACO
	}
}

namespace DecrementalHull{

	struct Point{
	    Point& operator+=(Point const&o) {
	        x+=o.x;
	        y+=o.y;
	        return *this;
	    }
	    Point& operator-=(Point const&o) {
	        x-=o.x;
	        y-=o.y;
	        return *this;
	    }
	    Point operator-() const {
	        return Point{-x, -y};
	    }
	    friend Point operator+(Point a, Point const&b){
	        a+=b;
	        return a;
	    }
	    friend Point operator-(Point a, Point const&b){
	        a-=b;
	        return a;
	    }
	    friend ll dot(Point const&a, Point const&b){
	        return a.x*b.x + a.y*b.y;
	    }
	    friend ll cross(Point const&a, Point const&b){
	        return a.x*b.y - a.y*b.x;
	    }
	    friend bool operator<(Point const&a, Point const&b){
	        return tie(a.x, a.y) < tie(b.x, b.y);
	    }

	    ll x=0, y=0;
	};

	int ccw(Point const&a, Point const&b){
	    ll x = cross(a, b);
	    return (x>0)-(x<0);
	}
	int ccw(Point const&a, Point const&b, Point const&c){
	    return ccw(b-a, c-a);
	}
	// Decremental convex hull in O(n log n)
	// From "Applications of a semi-dynamic convex hull algorithm" by J. Hershberger and S. Suri
	struct Upper_Hull{
	    struct Link{
	        Point p;
	        Link *prev = nullptr, *next = nullptr;
	        int id;
	    };
	    struct Node{
	        Link *chain, *chain_back;
	        Link *tangent;
	    };
	    template<typename S, typename T>
	    pair<Link*, Link*> find_bridge(Link*l, Link*r, S next, T convex){
	        while(next(l) || next(r)){
	            if(!next(r) || (next(l) && convex(Point{0, 0}, next(l)->p - l->p, next(r)->p - r->p))){
	                if(convex(l->p, next(l)->p, r->p)){
	                    l = next(l);
	                } else {
	                    break;
	                }
	            } else {
	                if(!convex(l->p, r->p, next(r)->p)){
	                    r = next(r);
	                } else {
	                    break;
	                }
	            }
	        }
	        return {l, r};
	    }
	    template<bool rev = false>
	    void fix_chain(int u, Link*l, Link*r){
	        if(rev){ // l and r to the right of actual bridge
	            tie(r, l) = find_bridge(r, l,
	                [](Link*x){ return x->prev; },
	                [](Point const&a, Point const&b, Point const&c){
	                    return ccw(a, b, c) > 0; //CHANGED
	                });
	        } else { // l and r to the left of actual bridge
	            tie(l, r) = find_bridge(l, r,
	                [](Link*x){ return x->next; },
	                [](Point const&a, Point const&b, Point const&c){
	                    return ccw(a, b, c) < 0; //CHANGED
	                });
	        }
	        tree[u].tangent = l;
	        tree[u].chain = tree[2*u].chain;
	        tree[u].chain_back = tree[2*u+1].chain_back;
	        tree[2*u].chain = l->next;
	        tree[2*u+1].chain_back = r->prev;
	        if(l->next){
	            l->next->prev = nullptr;
	        } else {
	            tree[2*u].chain_back = nullptr;
	        }
	        if(r->prev){
	            r->prev->next = nullptr;
	        } else {
	            tree[2*u+1].chain = nullptr;
	        }
	        l->next = r;
	        r->prev = l;
	    }
	    void build(int u, int a, int b){
	        if(b-a == 1){
	            tree[u].chain = tree[u].chain_back = &lists[a];
	            tree[u].tangent = nullptr;
	            return;
	        }
	        const int m = a + (b-a)/2;
	        build(2*u, a, m);
	        build(2*u+1, m, b);
	        auto l = tree[2*u].chain, r = tree[2*u+1].chain;
	        fix_chain(u, l, r);
	    }

	    void rob(int u, int v){
	            tree[u].chain = tree[v].chain;
	            tree[v].chain = nullptr;
	            tree[u].chain_back = tree[v].chain_back;
	            tree[v].chain_back = nullptr;
	    }

	    void remove(int u, int a, int b, int const&i){
	        if(i < a || i >= b) return;
	        // we should never hit a leaf
	        assert(b-a > 1);
	        const int m = a + (b-a)/2;
	        // one child -> that child contains i
	        if(!tree[u].tangent){
	            int v = i<m ? 2*u : 2*u+1;
	            tree[v].chain = tree[u].chain;
	            tree[v].chain_back = tree[u].chain_back;
	            if(i < m){
	                remove(2*u, a, m, i);
	            } else {
	                remove(2*u+1, m, b, i);
	            }
	            rob(u, v);
	            return;
	        }
	        // restore hull of children
	        auto l = tree[u].tangent, r = l->next;
	        l->next = tree[2*u].chain;
	        if(tree[2*u].chain){
	            tree[2*u].chain->prev = l;
	        } else {
	            tree[2*u].chain_back = l;
	        }
	        tree[2*u].chain = tree[u].chain;
	        r->prev = tree[2*u+1].chain_back;
	        if(tree[2*u+1].chain_back){
	            tree[2*u+1].chain_back->next = r;
	        } else {
	            tree[2*u+1].chain = r;
	        }
	        tree[2*u+1].chain_back = tree[u].chain_back;
	        // delete i
	        const int v = i<m ? 2*u : 2*u+1;
	        // only i
	        if(tree[v].chain == tree[v].chain_back && tree[v].chain->id == i){
	            tree[v].chain = tree[v].chain_back = nullptr;
	            rob(u, v^1);
	            tree[u].tangent = nullptr;
	            return;
	        }
	        if(i < m){
	            if(l->id == i){
	                l = l->next;
	            }
	            remove(2*u, a, m, i);
	            if(!l){
	                l = tree[2*u].chain_back;
	            }
	            fix_chain<true>(u, l, r);
	        } else {
	            if(r->id == i){
	                r = r->prev;
	            }
	            remove(2*u+1, m, b, i);
	            if(!r){
	                r = tree[2*u+1].chain;
	            }
	            fix_chain<false>(u, l, r);
	        }
	    }
	    void remove(int i){
	        // i is the only point
	        if(tree[1].chain == tree[1].chain_back){
	            tree[1].chain = tree[1].chain_back = nullptr;
	            return;
	        }
	        remove(1, 0, n, i);
	    }
	    void remove(Point p){
	    	if(ind_map.count(p)){
	    		remove(ind_map[p]);
	    	}
	    }
	    Upper_Hull(vector<Point> v) : n(v.size()), tree(4*n), lists(n){
	    	sort(all(v));
	        // assert(is_sorted(v.begin(), v.end()));
	        for(int i=0; i<n; ++i){
	            lists[i].p = v[i];
	            lists[i].id = i;
	            ind_map[v[i]] = i;
	        }
	        build(1, 0, n);
	    }

	    Upper_Hull(){

	    }

	    vector<int> get_hull(){
	        vector<int> ret;
	        for(Link* u = tree[1].chain; u; u=u->next){
	            ret.push_back(u->id);
	        }
	        return ret;
	    }
	    vector<Point> get_hull_points(){
	        vector<Point> ret;
	        for(Link* u = tree[1].chain; u; u=u->next){
	            ret.push_back(u->p);
	        }
	        return ret;
	    }

	    int n;
	    vector<Node> tree;
	    vector<Link> lists;
	    map<Point, int> ind_map;
	};



	Upper_Hull up_hull, bo_hull;
	void INIT(vpl v_pair){
		vector<Point> v;
		for(auto u: v_pair){
			v.pb(Point({u.f, u.s}));
		}
		up_hull = Upper_Hull(v);


		for(auto& u: v){
			u = Point{-u.x, -u.y};
		}
		bo_hull = Upper_Hull(v);
	}



	vpl QUERY(){
		vector<Point> up_res = up_hull.get_hull_points();
		vector<Point> bo_res = bo_hull.get_hull_points();
		for(auto u: bo_res){
			up_res.pb(Point{-u.x, -u.y});
		}

		set<Point> seen_points;
		vector<Point> res;
		for(auto u: up_res){

			if(seen_points.count(u)) continue;
			seen_points.ins(u);
			res.pb(u);
		}

		vpl res_pair;
		for(auto u: res){
			res_pair.pb(mp(u.x, u.y));
		}

		reverse(all(res_pair)); //ccw order
		return res_pair;
	}

	void REMOVE(pl p_pair){
		up_hull.remove(Point{p_pair.f, p_pair.s});
		bo_hull.remove(Point{-p_pair.f, -p_pair.s});
	}


	void hullTest(){
		vpl pol = vpl({mp(0, 0), mp(0, 2), mp(2, 0), mp(2, 2), mp(1, 1)});
		INIT(pol);
		dbg(QUERY());
		REMOVE(pol[0]);
		dbg(QUERY());

		REMOVE(pol[2]);
		dbg(QUERY());
	}

}


/**
 * Description: Use in place of \texttt{complex<T>}.
 * Source: http://codeforces.com/blog/entry/22175, KACTL
 * Verification: various
 */

using T = ll; // or ll
const T EPS = 0; // adjust as needed
using P = pair<T,T>; using vP = V<P>; using Line = pair<P,P>;
int sgn(T a) { return (a>EPS)-(a<-EPS); }
T sq(T a) { return a*a; }

bool close(const P& a, const P& b) { 
	return sgn(a.f-b.f) == 0 && sgn(a.s-b.s) == 0; } 
T norm(const P& p) { return sq(p.f)+sq(p.s); }
// T abs(const P& p) { return sqrt(norm(p)); }
// T arg(const P& p) { return atan2(p.s,p.f); }
P conj(const P& p) { return P(p.f,-p.s); }
P perp(const P& p) { return P(-p.s,p.f); }
P dir(T ang) { return P(cos(ang),sin(ang)); }

P operator-(const P& l) { return P(-l.f,-l.s); }
P operator+(const P& l, const P& r) { 
	return P(l.f+r.f,l.s+r.s); }
P operator-(const P& l, const P& r) { 
	return P(l.f-r.f,l.s-r.s); }
P operator*(const P& l, const T& r) { 
	return P(l.f*r,l.s*r); }
P operator*(const T& l, const P& r) { return r*l; }
P operator/(const P& l, const T& r) { 
	return P(l.f/r,l.s/r); }
P operator*(const P& l, const P& r) { 
	return P(l.f*r.f-l.s*r.s,l.s*r.f+l.f*r.s); }
P operator/(const P& l, const P& r) { 
	return l*conj(r)/norm(r); }
P& operator+=(P& l, const P& r) { return l = l+r; }
P& operator-=(P& l, const P& r) { return l = l-r; }
P& operator*=(P& l, const T& r) { return l = l*r; }
P& operator/=(P& l, const T& r) { return l = l/r; }
P& operator*=(P& l, const P& r) { return l = l*r; }
P& operator/=(P& l, const P& r) { return l = l/r; }

// P unit(const P& p) { return p/abs(p); }
T dot(const P& a, const P& b) { return a.f*b.f+a.s*b.s; }
T dot(const P& p, const P& a, const P& b) { return dot(a-p,b-p); }
T cross(const P& a, const P& b) { return a.f*b.s-a.s*b.f; }
T cross(const P& p, const P& a, const P& b) {
	return cross(a-p,b-p); }
P reflect(const P& p, const Line& l) {
	P a = l.f, d = l.s-l.f;
	return a+conj((p-a)/d)*d; }
P foot(const P& p, const Line& l) {
	return (p+reflect(p,l))/(T)2; }
bool onSeg(const P& p, const Line& l) {
	return sgn(cross(l.f,l.s,p)) == 0 && sgn(dot(p,l.f,l.s)) <= 0; }


/** 
 * Description: Given convex polygon with no three points collinear and a point 
 	* strictly outside of it, computes the lower and upper tangents.
 * Source: Own
 * Time: O(\log N)
 * Verification: tested
 */

bool lower;
bool better(P a, P b, P c) { 
	T z = cross(a,b,c); 
	return lower ? z < 0 : z > 0; }
int tangent(const vP& a, P b) {
	if (sz(a) == 1) return 0;
	int lo, hi;
	if (better(b,a[0],a[1])) {
		lo = 0, hi = sz(a)-1;
		while (lo < hi) {
			int mid = (lo+hi+1)/2;
			if (better(b,a[0],a[mid])) lo = mid;
			else hi = mid-1;
		}
		lo = 0;
	} else {
		lo = 1, hi = sz(a);
		while (lo < hi) {
			int mid = (lo+hi)/2;
			if (!better(b,a[0],a[mid])) lo = mid+1;
			else hi = mid;
		}
		hi = sz(a);
	}
	while (lo < hi) {
		int mid = (lo+hi)/2;
		if (better(b,a[mid],a[(mid+1)%sz(a)])) lo = mid+1;
		else hi = mid;
	}
	return lo%sz(a);
}
pi tangents(const vP& a, P b) {
	lower = 1; int x = tangent(a,b); 
	lower = 0; int y = tangent(a,b); 
	return {x,y};
}

/**
 * Description: Sorts points in ccw order about origin in the same way as
 	* \texttt{atan2}, which returns real in $(-\pi,\pi]$ so points on 
 	* negative $x$-axis come last.
 * Verification: https://codeforces.com/contest/1284/submission/68175790
 	* https://codeforces.com/contest/1284/submission/68207607 
 	* (don't use atan2, weird stuff happens!)
 */

// WARNING: you will get unexpected results if you mistype this as bool instead of int
// -1 if lower half, 0 if origin, 1 if upper half
int half(P x) { return x.s != 0 ? sgn(x.s) : -sgn(x.f); }
bool angleCmp(P a, P b) { int A = half(a), B = half(b);
	return A == B ? cross(a,b) > 0 : A < B; }

/* Usage: 
 	* vP v;
 	* sort(all(v),[](P a, P b) { return 
 		atan2(a.s,a.f) < atan2(b.s,b.f); });
 	* sort(all(v),angleCmp); // should give same result
*/


const int mx = 100005;

struct Eff{

pl XY[mx];
pl dxy[mx];
int K[mx];

void solve(){
	
	int N;
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> XY[i].f >> XY[i].s;
	}
	int Q;
	cin >> Q;
	for(int i = 1; i <= Q; i++){
		cin >> dxy[i].f >> dxy[i].s >> K[i];
	}

	
	vpl init_poly;
	map<pl, int> to_ind;
	for(int i = 1; i <= N; i++){
		init_poly.pb(XY[i]);
		to_ind[XY[i]] = i;
	}
	// dbg("INIT");
	DecrementalHull::INIT(init_poly);

	int points_left = N;

	vector<vP> hulls;

	while(points_left > 0){
		vpl hull = DecrementalHull::QUERY();
		hulls.pb(hull);
		// dbg(hull);
		for(auto u: hull){
			DecrementalHull::REMOVE(u);
			points_left--;
		}
	}

	// dbg(hulls);

	//order hulls[0]
	pair<pl, int> min_point = mp(mp(BIG, BIG), -1);
	for(int i = 0; i < sz(hulls[0]); i++){
		ckmin(min_point, mp(mp(-hulls[0][i].s, hulls[0][i].f), i));
	}

	vpl new_hull0;
	for(int i = 0; i < sz(hulls[0]); i++){
		new_hull0.pb(hulls[0][(min_point.s+i) % sz(hulls[0])]);
	}
	hulls[0] = new_hull0;



	vector<vector<vector<pair<pi, int>>>> jmp; //number includes end but not beginning
	for(int i = 0; i < sz(hulls); i++){
		vector<vector<pair<pi, int>>> add_jmp;
		for(int j = 0; j < sz(hulls[i]); j++){
			vector<pair<pi, int>> add_add_jmp(20, mp(mp(i, j), MOD));
			if(i+1 < sz(hulls)){
				add_add_jmp[0] = mp(mp(i+1, tangents(hulls[i+1], hulls[i][(j-1+sz(hulls[i])) % (sz(hulls[i]))]).f), sz(hulls[i]));
			}
			add_jmp.pb(add_add_jmp);
		}
		jmp.pb(add_jmp);
	}

	for(int k = 0; k+1 < 20; k++){
		for(int i = 0; i < sz(hulls); i++){
			for(int j = 0; j < sz(hulls[i]); j++){
				pair<pi, int> trans1 = jmp[i][j][k];
				pair<pi, int> trans2 = jmp[trans1.f.f][trans1.f.s][k];
				jmp[i][j][k+1] = mp(trans2.f, min(MOD, trans1.s+trans2.s));
				
			}
		}
	}
	

	// dbg(hulls);

	//last i such that hulls[0][i] -> hulls[0][(i+1) % sz(hulls[0])] is less than dx, dy
	for(int i = 1; i <= Q; i++){
		

		int start_ind = 0;

		auto getLine = [&](int ind){
			return hulls[0][(ind+1) % sz(hulls[0])]-hulls[0][ind];
		};

		if(angleCmp(dxy[i], getLine(0))){
			// dbg("CASE1");
			start_ind = 0;
		}
		else{
			int lo = 0;
			int hi = sz(hulls[0])-1;
			while(lo < hi){
				int mid = (lo+hi)/2+1;
				// dbg(mid);
				// dbg(getLine(mid));
				// dbg(dxy[i]);
				if(angleCmp(getLine(mid), dxy[i])){
					// dbg("LESS");
					lo = mid;
				}
				else{
					// dbg("GREAT");
					hi = mid-1;
				}
			}
			// dbg(lo);
			start_ind = (lo+1) % sz(hulls[0]);
		}

		// dbg(angleCmp(getLine(0), dxy[i]));
		pi cur_state = mp(0, start_ind);
		int to_pop = K[i]-1;

		for(int k = 19; k >= 0; k--){
			if(to_pop >= jmp[cur_state.f][cur_state.s][k].s){
				to_pop-=jmp[cur_state.f][cur_state.s][k].s;
				cur_state = jmp[cur_state.f][cur_state.s][k].f;
				// if(k > 0) dbg("JUMPING");
			}
		}
		// while(to_pop > 0){
		// 	dbg(to_pop);
		// 	if(to_pop >= jmp[cur_state.f][cur_state.s][0].s){
		// 		to_pop-=jmp[cur_state.f][cur_state.s][0].s;
		// 		cur_state = jmp[cur_state.f][cur_state.s][0].f;
		// 	}
		// 	else{
		// 		break;
		// 	}
		// }
		// dbg(to_pop);
		cur_state.s = (cur_state.s+to_pop) % sz(hulls[cur_state.f]);
		// dbg(cur_state);
		int ans = to_ind[hulls[cur_state.f][cur_state.s]];
		ps(ans);
	}

}

};

int main() {
	// setIO();
	// DecrementalHull::hullTest();
	// vP poly; poly.pb(mp(0, 0)); poly.pb(mp(1, 0)); poly.pb(mp(0, 1));
	// dbg(tangents(poly, mp(-1, -1)));
	Eff e; e.solve();
	
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/