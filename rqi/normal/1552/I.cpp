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

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

const int MOD = 998244353;
const int MX = 2e5+5;
const ll INF = 1e18; // not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
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

const int mx = 105;
/**
 * Description: Disjoint Set Union with path compression
     * and union by size. Add edges and test connectivity. 
     * Use for Kruskal's or Boruvka's minimum spanning tree.
 * Time: O(\alpha(N))
 * Source: CSAcademy, KACTL
 * Verification: *
 */

struct DSU {
    vi e; void init(int N) { e = vi(N,-1); }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) { // union by size
        x = get(x), y = get(y); if (x == y) return 0;
        if (e[x] > e[y]) swap(x,y);
        e[x] += e[y]; e[y] = x; return 1;
    }
};

/**template<class T> T kruskal(int N, vector<pair<T,pi>> ed) {
    sort(all(ed));
    T ans = 0; DSU D; D.init(N); // edges that unite are in MST
    each(a,ed) if (D.unite(a.s.f,a.s.s)) ans += a.f; 
    return ans;
}*/

/**
 * Description: modular arithmetic operations 
 * Source: 
    * KACTL
    * https://codeforces.com/blog/entry/63903
    * https://codeforces.com/contest/1261/submission/65632855 (tourist)
    * https://codeforces.com/contest/1264/submission/66344993 (ksun)
    * also see https://github.com/ecnerwala/cp-book/blob/master/src/modnum.hpp (ecnerwal)
 * Verification: 
    * https://open.kattis.com/problems/modulararithmetic
 */

template<int MOD, int RT> struct mint {
    static const int mod = MOD;
    static constexpr mint rt() { return RT; } // primitive root for FFT
    int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
    mint() { v = 0; }
    mint(ll _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
        if (v < 0) v += MOD; }
    friend bool operator==(const mint& a, const mint& b) { 
        return a.v == b.v; }
    friend bool operator!=(const mint& a, const mint& b) { 
        return !(a == b); }
    friend bool operator<(const mint& a, const mint& b) { 
        return a.v < b.v; }
    friend void re(mint& a) { ll x; re(x); a = mint(x); }
    friend str ts(mint a) { return ts(a.v); }
   
    mint& operator+=(const mint& m) { 
        if ((v += m.v) >= MOD) v -= MOD; 
        return *this; }
    mint& operator-=(const mint& m) { 
        if ((v -= m.v) < 0) v += MOD; 
        return *this; }
    mint& operator*=(const mint& m) { 
        v = int((ll)v*m.v%MOD); return *this; }
    mint& operator/=(const mint& m) { return (*this) *= inv(m); }
    friend mint pow(mint a, ll p) {
        mint ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans; }
    friend mint inv(const mint& a) { assert(a.v != 0); 
        return pow(a,MOD-2); }
        
    mint operator-() const { return mint(-v); }
    mint& operator++() { return *this += 1; }
    mint& operator--() { return *this -= 1; }
    friend mint operator+(mint a, const mint& b) { return a += b; }
    friend mint operator-(mint a, const mint& b) { return a -= b; }
    friend mint operator*(mint a, const mint& b) { return a *= b; }
    friend mint operator/(mint a, const mint& b) { return a /= b; }
};

typedef mint<MOD,5> mi; // 5 is primitive root for both common mods
typedef vector<mi> vmi;
typedef pair<mi,mi> pmi;
typedef vector<pmi> vpmi;

vector<vmi> scmb; // small combinations
void genComb(int SZ) {
    scmb.assign(SZ,vmi(SZ)); scmb[0][0] = 1;
    FOR(i,1,SZ) F0R(j,i+1) 
        scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}

/**
 * Description: pre-compute factorial mod inverses,
     * assumes $MOD$ is prime and $SZ < MOD$.
 * Time: O(SZ)
 * Source: KACTL
 * Verification: https://dmoj.ca/problem/tle17c4p5
 */

vmi invs, fac, ifac; // make sure to convert to LL before doing any multiplications ...
void genFac(int SZ) {
    invs.rsz(SZ), fac.rsz(SZ), ifac.rsz(SZ); 
    invs[1] = fac[0] = ifac[0] = 1; 
    FOR(i,2,SZ) invs[i] = mi(-(ll)MOD/i*(int)invs[MOD%i]);
    FOR(i,1,SZ) {
        fac[i] = fac[i-1]*i;
        ifac[i] = ifac[i-1]*invs[i];
    }
}
mi comb(int a, int b) {
    if (a < b || b < 0) return 0;
    return fac[a]*ifac[b]*ifac[a-b];
}

typedef bitset<mx> B;

const B B_ZERO;
B B_FULL;

void bitsetRemDup(vector<B>& v){
    vector<B> new_v;
    for(auto b: v){
        bool already_in = 0;
        for(auto in: new_v){
            if(b == in) already_in = 1;
        }

        if(!already_in) new_v.pb(b);
    }

    v = new_v;
}

int n, m;
vector<B> friends;

DSU dsu;
vi comp_adj[mx];
vi comp_nodes[mx];
// vpi comp_edges[mx];
// vpi comp_tree_edges[mx];
B comp_P[mx];
int par[mx]; //tree parent
vi children[mx]; //tree children

bool isAncestor(int C, int D){ // is C ancestor of D
    assert(C != D);
    if((comp_P[D]&comp_P[C]) == comp_P[D]){
        if(comp_P[D] == comp_P[C]){
            if(sz(comp_nodes[C]) == 1) return true;
            return false;
        }
        else{
            return true;
        }
    }
    return false;
}

bool visited[mx];
vi order;
void buildOrder(int node){
    visited[node] = 1;
    order.pb(node);
    for(auto u: comp_adj[node]){
        if(visited[u]) continue;
        buildOrder(u);
    }
}

bool isContiguous(vi a){
    assert(sz(a));
    for(int i = 0; i+1 < sz(a); i++){
        if(a[i]+1 != a[i+1]) return false;
    }
    return true;
}

int main() {
    setIO();
    #warning change mx back to 105
    genFac(100005);
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        B_FULL[i] = 1;
    }

    for(int i = 1; i <= m; i++){
        B b;
        int qi;
        cin >> qi;
        for(int j = 1; j <= qi; j++){
            int s;
            cin >> s;
            b[s] = 1;
        }
        friends.pb(b);
    }
    B full; for(int i = 1; i <= n; i++) full[i] = 1;
    friends.pb(full);
    bitsetRemDup(friends);
    m = sz(friends);

    dbg(m, friends);

    dsu.init(m);
    vpi edges;
    vpi tree_edges;
    for(int i = 0; i < m; i++){
        for(int j = i+1; j < m; j++){
            B isect = friends[i]&friends[j];
            if(isect != B_ZERO && isect != friends[i] && isect != friends[j]){
                //add edge i-j
                edges.pb(mp(i, j));
                if(dsu.unite(i, j)){
                    tree_edges.pb(mp(i, j));
                }
            }
        }
    }

    for(auto u: edges){
        comp_adj[u.f].pb(u.s);
        comp_adj[u.s].pb(u.f);
    }
    // for(auto u: edges){
    //     comp_edges[dsu.get(u.f)].pb(u);
    // }
    // for(auto u: tree_edges){
    //     comp_tree_edges[dsu.get(u.f)].pb(u);
    // }

    for(int i = 0; i < m; i++){
        comp_nodes[dsu.get(i)].pb(i);
        comp_P[dsu.get(i)]|=friends[i];
    }

    for(int i = 0; i < m; i++){
        dbg(i, comp_nodes[i], comp_P[i]);
    }

    int R = -1;
    for(int i = 0; i < m; i++){
        if(dsu.get(i) != i) continue;
        //get parent of this component
        par[i] = -1;
        for(int j = 0; j < m; j++){
            if(dsu.get(j) != j) continue;
            if(j == i) continue;
            if(!isAncestor(j, i)) continue;
            if(par[i] != -1 && isAncestor(j, par[i])) continue;

            par[i] = j;
        }

        if(par[i] == -1){
            assert(R == -1);
            R = i;
        }
    }

    assert(R != -1);

    for(int i = 0; i < m; i++){
        if(dsu.get(i) != i) continue;
        if(i == R) continue;
        children[par[i]].pb(i);
    }

    mi ans = mi(1);

    for(int i = 0; i < m; i++){
        if(dsu.get(i) != i) continue;
        dbg("COMPONENT", i);
        order.clear();
        buildOrder(i);

        assert(sz(order));

        vector<B> Z(2); //0 index is meaningless
        Z[1] = friends[order[0]];

        dbg(order);
        for(int j = 1; j < sz(order); j++){
            int k = sz(Z)-1;
            B S = friends[order[j]];
            vi I;
            vi nonempty_isect;

            B Z0 = S;
            for(int w = 1; w <= k; w++){
                Z0 = (Z0&(B_FULL^Z[w]));
            }

            dbg(Z, S);
            dbg(Z0);


            for(int w = 1; w <= k; w++){
                B Z_isect_S = Z[w]&S;
                B Z_minus_S = Z[w]^Z_isect_S;
                if(Z_isect_S != B_ZERO){
                    nonempty_isect.pb(w);
                    if(Z_minus_S != B_ZERO){
                        I.pb(w);
                    }
                }
            }
            assert(sz(nonempty_isect));

            // dbg(I);
            // dbg(nonempty_isect);

            if(!isContiguous(nonempty_isect)){
                ps(0);
                dbg("CASE1");
                exit(0);
            }

            if(sz(I) == 0){
                //prefix or suffix
                if(Z0 != B_ZERO){
                    if(nonempty_isect[0] == 1){ //prefix
                        assert(nonempty_isect.bk != k);
                        vector<B> new_Z(1);
                        new_Z.pb(Z0);
                        for(int i = 1; i <= k; i++){
                            new_Z.pb(Z[i]);
                        }
                        Z = new_Z;
                    }
                    else if(nonempty_isect.bk == k){ //suffix
                        Z.pb(Z0);
                    }
                    else{
                        ps(0);
                        dbg("CASE2");
                        exit(0);
                    }
                }
                else{
                    //everything is fine
                }
            }
            else if(sz(I) >= 3){
                ps(0);
                dbg("CASE3");
                exit(0);
            }
            else if(sz(I) == 2){
                if(Z0 != B_ZERO){
                    ps(0);
                    dbg("CASE4");
                    exit(0);
                }
                if(nonempty_isect[0] == I[0] && nonempty_isect.bk == I[1]){
                    int l = I[0];
                    int r = I[1];
                    B Zlp = Z[l]&S;
                    B Zlpp = Z[l]^Zlp;
                    B Zrp = Z[r]&S;
                    B Zrpp = Z[r]^Zrp;

                    vector<B> new_Z(1);
                    for(int i = 1; i <= l-1; i++){
                        new_Z.pb(Z[i]);
                    }
                    new_Z.pb(Zlpp); new_Z.pb(Zlp);
                    for(int i = l+1; i <= r-1; i++){
                        new_Z.pb(Z[i]);
                    }
                    new_Z.pb(Zrp); new_Z.pb(Zrpp);
                    for(int i = r+1; i <= k; i++){
                        new_Z.pb(Z[i]);
                    }
                    Z = new_Z;
                }
                else{
                    ps(0);
                    dbg("CASE5");
                    exit(0);
                }
            }
            else if(sz(I) == 1){
                if(Z0 != B_ZERO){
                    // dbg("I11");
                    int t = I[0];
                    if(nonempty_isect.bk == t && nonempty_isect[0] == 1){
                        vector<B> new_Z(1);
                        B Ztp = Z[t]&S;
                        B Ztpp = Z[t]^Ztp;

                        new_Z.pb(Z0);
                        for(int i = 1; i < t; i++){
                            new_Z.pb(Z[i]);
                        }
                        new_Z.pb(Ztp); new_Z.pb(Ztpp);
                        for(int i = t+1; i <= k; i++){
                            new_Z.pb(Z[i]);
                        }
                        Z = new_Z;
                    }
                    else if(nonempty_isect[0] == t && nonempty_isect.bk == k){
                        vector<B> new_Z(1);
                        B Ztp = Z[t]&S;
                        B Ztpp = Z[t]^Ztp;

                        for(int i = 1; i < t; i++){
                            new_Z.pb(Z[i]);
                        }
                        new_Z.pb(Ztpp); new_Z.pb(Ztp);
                        for(int i = t+1; i <= k; i++){
                            new_Z.pb(Z[i]);
                        }
                        new_Z.pb(Z0);
                        Z = new_Z;
                    }
                    else{
                        ps(0);
                        dbg("CASE6");
                        exit(0);
                    }
                }
                else{
                    // dbg("I12");
                    int t = I[0];
                    B Ztp = Z[t]&S;
                    B Ztpp = Z[t]^Ztp;
                    assert(nonempty_isect[0] < t || nonempty_isect.bk > t);

                    if(nonempty_isect[0] < t && nonempty_isect.bk == t){
                        vector<B> new_Z(1);

                        for(int i = 1; i < t; i++){
                            new_Z.pb(Z[i]);
                        }
                        new_Z.pb(Ztp); new_Z.pb(Ztpp);
                        for(int i = t+1; i <= k; i++){
                            new_Z.pb(Z[i]);
                        }
                        Z = new_Z;
                    }
                    else if(nonempty_isect.bk > t && nonempty_isect[0] == t){
                        vector<B> new_Z(1);

                        for(int i = 1; i < t; i++){
                            new_Z.pb(Z[i]);
                        }
                        new_Z.pb(Ztpp); new_Z.pb(Ztp);
                        for(int i = t+1; i <= k; i++){
                            new_Z.pb(Z[i]);
                        }
                        Z = new_Z;
                    }
                    else{
                        ps(0);
                        exit(0);
                    }
                }
            }
        }

        // dbg(Z);

        //multiply by 1 or 2
        if(sz(order) == 1){
            ans*=mi(1);
        }
        else{
            ans*=mi(2);
        }

        //mult by factorials
        for(int w = 1; w < sz(Z); w++){
            B E = Z[w];
            int fact_num = E.count();
            for(auto D: children[i]){
                if((comp_P[D]&E) == comp_P[D]){
                    fact_num-=(comp_P[D].count()-1);
                }
            }
            assert(fact_num >= 0);
            // dbg(fact_num);
            ans*=fac[fact_num];
        }
    }

    ps(ans);

    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/