#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using db = long double; // or double, if TL is tight
using str = string; // yay python! 

using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;

#define tcT template<class T
#define tcTU tcT, class U
// ^ lol this makes everything look weird but I'll try it
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
tcT> using PR = pair<T,T>;

// pairs
#define mp make_pair
#define f first
#define s second

// vectors
// oops size(x), rbegin(x), rend(x) need C++17
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back 
#define pf push_front
#define rtn return

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
    return a < b ? a = b, 1 : 0; }

tcTU> T fstTrue(T lo, T hi, U f) {
    hi ++; assert(lo <= hi); // assuming f is increasing
    while (lo < hi) { // find first index such that f is true 
        T mid = lo+(hi-lo)/2;
        f(mid) ? hi = mid : lo = mid+1; 
    } 
    return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
    lo --; assert(lo <= hi); // assuming f is decreasing
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
        if (sz(s)) setIn(s+".in"), setOut(s+".out"); // for odb USACO
    }
}

/**
 * Description: Use in place of \texttt{complex<T>}.
 * Source: http://codeforces.com/blog/entry/22175, KACTL
 * Verification: various
 */

using T = db; // or ll
const T EPS = 1e-7; // adjust as needed
using P = pair<T,T>; using vP = V<P>; using Line = pair<P,P>;
int sgn(T a) { return (a>EPS)-(a<-EPS); }
T sq(T a) { return a*a; }

bool close(const P& a, const P& b) { 
    return sgn(a.f-b.f) == 0 && sgn(a.s-b.s) == 0; } 
T norm(const P& p) { return sq(p.f)+sq(p.s); }
T abs(const P& p) { return sqrt(norm(p)); }
T arg(const P& p) { return atan2(p.s,p.f); }
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

P unit(const P& p) { return p/abs(p); }
T dot(const P& a, const P& b) { return a.f*b.f+a.s*b.s; }
T cross(const P& a, const P& b) { return a.f*b.s-a.s*b.f; }
T cross(const P& p, const P& a, const P& b) {
    return cross(a-p,b-p); }
P reflect(const P& p, const Line& l) { 
    P a = l.f, d = l.s-l.f;
    return a+conj((p-a)/d)*d; }
P foot(const P& p, const Line& l) { 
    return (p+reflect(p,l))/(T)2; }
bool onSeg(const P& p, const Line& l) {
    return sgn(cross(l.f,l.s,p)) == 0 && sgn(dot(p-l.f,p-l.s)) <= 0; }

const int mx = 55;
const int MAX_REP = 35;

int n;
P P_inp[mx];
db t_end[mx];
db t_csum[mx];
P unit_vec[mx];

P getPos(int i, db t1){
    // assert(1 <= i && i <= n);
    assert(t1 <= t_end[i]+EPS);
    return P_inp[i]+t1*unit_vec[i];
}

db G(int i, int j, db t1, db t2){ //O(1)

    // assert(i != j);
    if(i > j){
        swap(i, j);
        swap(t1, t2);
    }
    return (abs(getPos(i, t1)-getPos(j, t2)))/abs(t_csum[j-1]-t_csum[i-1]+t2-t1);
}

db Gt(int i, int j, db t2){ //t2 value respect to j, log
    db t1_lo = 0;
    db t1_hi = t_end[i];
    // dbg(t1_hi);
    for(int rep = 0; rep < 1.5*MAX_REP; rep++){
        db t1_third1 = t1_lo+(t1_hi-t1_lo)*db(1)/db(3);
        db t1_third2 = t1_lo+(t1_hi-t1_lo)*db(2)/db(3);

        if(G(i, j, t1_third1, t2) < G(i, j, t1_third2, t2)){
            t1_hi = t1_third2;
        }
        else{
            t1_lo = t1_third1;
        }
    }

    // dbg(t1_lo, t1_hi);

    return G(i, j, t1_lo, t2);
}

P Gt_min[mx][mx];

set<pd> left_rangs[mx];

bool addLeftRange(int i, pd rang, bool actually_add = 1){
    bool removed = 0;
    while(true){
        auto it = left_rangs[i].lb(mp(rang.f, -MOD));
        if(it != left_rangs[i].end() && it->f <= rang.s){
            ckmax(rang.s, it->s);
            left_rangs[i].erase(it);
            removed = 1;
            continue;
        }

        if(it != left_rangs[i].begin()){
            it = prev(it);
            if(it->s >= rang.f){
                ckmin(rang.f, it->f);
                left_rangs[i].erase(it);
                removed = 1;
                continue;
            }
        }
        break;
    }

    if(actually_add){
        left_rangs[i].ins(rang);
        // dbg(left_rangs[i]);
    }
    else{
        if(removed){
            return true;
        }
        return false;
    }

    return false;
}

int main() {
    setIO();
    clock_t BEG = clock();
    cout << fixed << setprecision(9);
    cin >> n;
    for(int i = 1; i <= n+1; i++){
        cin >> P_inp[i].f >> P_inp[i].s;
    }

    for(int i = 1; i <= n; i++){
        t_end[i] = abs(P_inp[i+1]-P_inp[i]);
    }
    for(int i = 1; i <= n; i++){
        t_csum[i] = t_csum[i-1]+t_end[i];
    }

    for(int i = 1; i <= n; i++){
        unit_vec[i] = unit(P_inp[i+1]-P_inp[i]);
    }

    //compute Gt_min, n^2*log^2
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            db t2_lo = 0;
            db t2_hi = t_end[j];

            for(int rep = 0; rep < 1.5*MAX_REP; rep++){
                db t2_third1 = t2_lo+(t2_hi-t2_lo)*db(1)/db(3);
                db t2_third2 = t2_lo+(t2_hi-t2_lo)*db(2)/db(3);

                if(Gt(i, j, t2_third1) < Gt(i, j, t2_third2)){
                    t2_hi = t2_third2;
                }
                else{
                    t2_lo = t2_third1;
                }
            }

            Gt_min[i][j] = mp(t2_lo, Gt(i, j, t2_lo));
        }
    }

    // dbg(db(clock()-BEG)/CLOCKS_PER_SEC);
    db v_lo = 1;
    db v_hi = MOD;

    while(abs(v_lo-v_hi) > 0.0000001){ 
        db v_mid = (v_lo+v_hi)/2;
        db cutoff = 1.0/v_mid;

        for(int i = 1; i <= n; i++){
            left_rangs[i].clear();
        }

        //test if v_mid works
        bool can_escape = 0;

        for(int j = 1; j <= n; j++){
            for(int i = 1; i <= n; i++){
                if(i == j) continue;

                if(Gt_min[i][j].s > cutoff){
                    continue;
                }

                db l_lo = 0;
                db l_hi = Gt_min[i][j].f;

                // dbg(Gt_min[i][j].s, cutoff);

                for(int rep = 0; rep < 0.5*MAX_REP; rep++){ //n^2*log^3
                    db l_mid = (l_lo+l_hi)/2;
                    if(Gt(i, j, l_mid) < cutoff){
                        l_hi = l_mid;
                    }
                    else{
                        l_lo = l_mid;
                    }
                }

                db r_lo = Gt_min[i][j].f;
                db r_hi = t_end[j];

                // dbg(Gt(i, j, r_lo), Gt(i, j, r_hi));
                // assert(Gt(i, j, r_lo) < Gt(i, j, r_hi)+EPS);

                for(int rep = 0; rep < 0.5*MAX_REP; rep++){
                    db r_mid = (r_lo+r_hi)/2;
                    // assert(Gt(i, j, r_mid) < Gt(i, j, r_hi)+EPS);
                    if(Gt(i, j, r_mid) < cutoff){
                        r_lo = r_mid;
                    }
                    else{
                        r_hi = r_mid;
                    }
                }



                // if(abs(l_lo-l_hi) > EPS || abs(r_lo-r_hi) > EPS){
                //     dbg("DIFF", l_lo, l_hi, r_lo, r_hi);
                // }
                
                
                if(i < j){
                    addLeftRange(j, mp(l_lo, r_lo), 1);
                }
                else if(i > j){
                    if(addLeftRange(j, mp(l_lo, r_lo), 0)){
                        can_escape = 1;
                        break;
                    }
                }
            }
            if(can_escape) break;
        }

        if(can_escape){
            v_lo = v_mid;
        }
        else{
            v_hi = v_mid;
        }
    }

    cout << v_lo << "\n";

    dbg(db(clock()-BEG)/CLOCKS_PER_SEC);
    // you shoudb actually read the stuff at the bottom
}

/* stuff you shoudb look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/