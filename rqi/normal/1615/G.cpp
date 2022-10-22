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

/**tcT> T kruskal(int N, vector<pair<T,pi>> ed) {
    sort(all(ed));
    T ans = 0; DSU D; D.init(N); // edges that unite are in MST
    each(a,ed) if (D.unite(a.s.f,a.s.s)) ans += a.f; 
    return ans;
}*/

/**
 * Description: Edmond's Blossom Algorithm. General unweighted 
     * matching with 1-based indexing. If \texttt{vis[v]=0}
     * when \texttt{bfs} returns 0, \texttt{v} is not part of every 
     * max matching.
 * Time: O(N^3), faster in practice
 * Source: 
    * https://github.com/koosaga/DeobureoMinkyuParty
    * https://www-m9.ma.tum.de/graph-algorithms/matchings-blossom-algorithm/index_en.html
    * https://codeforces.com/blog/entry/63630
 * Verification: 
     * https://codeforces.com/contest/1089 B
     * https://www.codechef.com/problems/HAMILG
 */

template<int SZ> struct UnweightedMatch {
    int match[SZ], N; vi adj[SZ];
    void ae(int u, int v) { adj[u].pb(v), adj[v].pb(u); }
    queue<int> q;
    int par[SZ], vis[SZ], orig[SZ], aux[SZ];
    void augment(int u, int v) { // toggle edges on u-v path
        while (1) { // one more matched pair
            int pv = par[v], nv = match[pv];
            match[v] = pv; match[pv] = v;
            v = nv; if (u == pv) return;
        }
    }
    int lca(int u, int v) { // find LCA of supernodes in O(dist)
        static int t = 0;
        for (++t;;swap(u,v)) {
            if (!u) continue;
            if (aux[u] == t) return u; // found LCA
            aux[u] = t; u = orig[par[match[u]]];
        }
    }
    void blossom(int u, int v, int a) { // go other way
        for (; orig[u] != a; u = par[v]) { // around cycle
            par[u] = v; v = match[u]; // treat u as if vis[u] = 1
            if (vis[v] == 1) vis[v] = 0, q.push(v);
            orig[u] = orig[v] = a; // merge into supernode
        }
    }
    bool bfs(int u) { // u is initially unmatched
        F0R(i,N+1) par[i] = 0, vis[i] = -1, orig[i] = i;
        q = queue<int>(); vis[u] = 0, q.push(u);
        while (sz(q)) { // each node is pushed to q at most once
            int v = q.ft; q.pop(); // 0 -> unmatched vertex
            each(x,adj[v]) {
                if (vis[x] == -1) { // neither of x, match[x] visited
                    vis[x] = 1; par[x] = v;
                    if (!match[x]) return augment(u,x),1;
                    vis[match[x]] = 0, q.push(match[x]);
                } else if (vis[x] == 0 && orig[v] != orig[x]) {
                    int a = lca(orig[v],orig[x]); // odd cycle
                    blossom(x,v,a), blossom(v,x,a); 
                } // contract O(n) times
            }
        }
        return 0;
    }
    int calc(int _N) { // rand matching -> constant improvement
        N = _N; F0R(i,N+1) match[i] = aux[i] = 0; 
        int ans = 0; vi V(N); iota(all(V),1); shuffle(all(V),rng); // find rand matching
        each(x,V) if (!match[x]) each(y,adj[x]) if (!match[y]) { 
            match[x] = y, match[y] = x; ++ans; break; }
        FOR(i,1,N+1) if (!match[i] && bfs(i)) ++ans;
        return ans;
    }
};

const int mx = 300005;

int n;
int a[mx];

vpi RANGS;
vpi tree_adj[mx];

void fillTree(int node, int p = -1){
    for(auto u: tree_adj[node]){
        if(u.f == p) continue;
        if(a[RANGS[u.s].f-1] == u.f){
            a[RANGS[u.s].f] = u.f;
        }
        else{
            assert(a[RANGS[u.s].s+1] == u.f);
            a[RANGS[u.s].s] = u.f;
        }
        fillTree(u.f, node);
    }
}

void doHardPart(){
    set<int> eq_vals;
    for(int i = 1; i+1 <= n; i++){
        if(a[i] != 0 && a[i] == a[i+1]){
            eq_vals.insert(a[i]);
        }
    }

    for(int i = 1; i <= n; i++){
        if(a[i] == 0){
            int L = i;
            int R = i;
            for(int j = i; j <= n; j++){
                if(a[j] == 0){
                    R = j;
                }
                else{
                    break;
                }
            }
            RANGS.pb(mp(L, R));
            i = R;
        }
    }

    for(int i = 0; i < sz(RANGS); i++){
        set<int> good_vals;
        if(!eq_vals.count(a[RANGS[i].f-1])){
            good_vals.insert(a[RANGS[i].f-1]);
        }
        if(!eq_vals.count(a[RANGS[i].s+1])){
            good_vals.insert(a[RANGS[i].s+1]);
        }
        assert(sz(good_vals) == 2);
    }

    int max_val = 0;
    for(auto u: RANGS){
        ckmax(max_val, a[u.f-1]);
        ckmax(max_val, a[u.s+1]);
    }
    assert(max_val <= 600);

    DSU dsu;
    dsu.init(max_val+5);

    vi cycle_edges;
    vb is_odd;
    for(int i = 0; i < sz(RANGS); i++){
        if((RANGS[i].s-RANGS[i].f+1) % 2 == 1){
            is_odd.pb(true);
        }
        else{
            is_odd.pb(false);
        }
    }

    for(int i = 0; i < sz(RANGS); i++){
        if(!is_odd[i]) continue;
        int v1 = a[RANGS[i].f-1];
        int v2 = a[RANGS[i].s+1];
        if(dsu.unite(v1, v2)){
            tree_adj[v1].pb(mp(v2, i));
            tree_adj[v2].pb(mp(v1, i));
        }
        else{
            cycle_edges.pb(i);
        }
    }

    vb comp_done(max_val+5, false);

    for(auto u: cycle_edges){
        int v1 = a[RANGS[u].f-1];
        if(comp_done[dsu.get(v1)]) continue;
        comp_done[dsu.get(v1)] = true;
        a[RANGS[u].f] = v1;
        fillTree(v1);
    }

    UnweightedMatch<605> um;
    map<pi, int> range_ind;

    for(int i = 0; i < sz(RANGS); i++){
        if(is_odd[i]) continue;
        int v1 = dsu.get(a[RANGS[i].f-1]);
        int v2 = dsu.get(a[RANGS[i].s+1]);

        if(v1 == v2 || comp_done[v1] || comp_done[v2]) continue;
        
        um.ae(v1, v2);
        range_ind[mp(v1, v2)] = i;
        range_ind[mp(v2, v1)] = i;
    }

    um.calc(max_val+1);

    for(int i = 1; i <= max_val; i++){
        if(um.match[i] > i){
            assert(um.match[um.match[i]] == i);
            int RANG_ind = range_ind[mp(i, um.match[i])];
            int v1 = a[RANGS[RANG_ind].f-1];
            int v2 = a[RANGS[RANG_ind].s+1];
            a[RANGS[RANG_ind].f] = v1;
            a[RANGS[RANG_ind].s] = v2;
            comp_done[dsu.get(v1)] = true;
            comp_done[dsu.get(v2)] = true;
            fillTree(v1);
            fillTree(v2);
        }
    }

    for(int i = 1; i <= max_val; i++){
        if(dsu.get(i) == i && !comp_done[i]){
            fillTree(i);
        }
    }
}

void ERASE(set<int>& s, int v){
    if(s.count(v)) s.erase(v);
}

set<int> remain;

void fillRest(int L = 1, int R = n){
    for(int i = L; i <= R; i++){
        if(a[i] == 0){
            assert(sz(remain));
            int v = *(remain.begin());
            if(i+1 <= R && a[i+1] == 0){
                a[i] = a[i+1] = v;
                ERASE(remain, v);
            }
            else{
                a[i] = v;
                ERASE(remain, v);
            }
        }
        
    }
}

void PRINT(){
    for(int i = 1; i <= n; i++){
        // assert(a[i] != 0);
        if(a[i] == 0){
            dbg("ZERO IN ARRAY");
        }
    }
    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}



int main() {
    setIO();
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++){
        remain.insert(i);
    }
    for(int i = 1; i <= n; i++){
        ERASE(remain, a[i]);
    }

    bool all_zero = true;
    for(int i = 1; i <= n; i++){
        if(a[i] != 0){
            all_zero = false;
        }
    }

    if(all_zero){
        fillRest();
        PRINT();
        exit(0);
    }

    if(a[1] == 0){
        int last_ind = 1;
        for(int i = 1; i <= n; i++){
            if(a[i] == 0){
                last_ind = i;
            }
            else{
                break;
            }
        }
        if(last_ind % 2 == 1){
            a[last_ind] = a[last_ind+1];
        }
        fillRest(1, last_ind);
    }

    // PRINT();
    if(a[n] == 0){
        int last_ind = n;
        for(int i = n; i >= 1; i--){
            if(a[i] == 0){
                last_ind = i;
            }
            else{
                break;
            }
        }
        if((n+1-last_ind) % 2 == 1){
            a[last_ind] = a[last_ind-1];
        }
        fillRest(last_ind, n);
    }
    // PRINT();

    vpi LR;
    for(int i = 1; i <= n; i++){
        if(a[i] == 0){
            int L = i;
            int R = i;
            for(int j = i; j <= n; j++){
                if(a[j] == 0){
                    R = j;
                }
                else{
                    break;
                }
            }
            LR.pb(mp(L, R));
            i = R;
        }
    }

    vb bad_rang(sz(LR), false);
    map<int, vi> val_check;
    for(int i = 0; i < sz(LR); i++){
        val_check[a[LR[i].f-1]].pb(i);
        val_check[a[LR[i].s+1]].pb(i);
    }

    queue<int> q_check;
    set<int> eq_vals;

    auto addValToQueue = [&](int v){
        eq_vals.insert(v);
        while(sz(val_check[v])){
            q_check.push(val_check[v].bk); val_check[v].pop_back();
        }
    };

    for(int i = 1; i+1 <= n; i++){
        if(a[i] == a[i+1] && a[i] != 0){
            addValToQueue(a[i]);
        }
    }

    for(int i = 0; i < sz(LR); i++){
        if(a[LR[i].f-1] == a[LR[i].s+1]){
            q_check.push(i);
        }
    }

    while(sz(q_check)){
        int ind = q_check.front(); q_check.pop();
        if(bad_rang[ind]) continue;

        set<int> good_vals;
        if(!eq_vals.count(a[LR[ind].f-1])){
            good_vals.insert(a[LR[ind].f-1]);
        }
        if(!eq_vals.count(a[LR[ind].s+1])){
            good_vals.insert(a[LR[ind].s+1]);
        }

        assert(sz(good_vals) <= 1);
        // if(sz(good_vals) >= 2) continue;
        bad_rang[ind] = 1;
        if((LR[ind].s-LR[ind].f+1) % 2 == 0){
            fillRest(LR[ind].f, LR[ind].s);
        }
        else{
            if(eq_vals.count(a[LR[ind].f-1])){
                a[LR[ind].s] = a[LR[ind].s+1];
            }
            else{
                assert(eq_vals.count(a[LR[ind].s+1]) || a[LR[ind].f-1] == a[LR[ind].s+1]);
                a[LR[ind].f] = a[LR[ind].f-1];
            }

            fillRest(LR[ind].f, LR[ind].s);

            addValToQueue(a[LR[ind].f-1]);
            addValToQueue(a[LR[ind].s+1]);
        }
    }

    doHardPart();

    fillRest();
    PRINT();
    

    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/