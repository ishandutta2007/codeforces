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
const ll INF = 1e18;
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
 * Description: Minimum-cost maximum flow, assumes no negative cycles. 
     * It is possible to choose negative edge costs such that the first 
     * run of Dijkstra is slow, but this hasn't been an issue in the past. 
     * Edge weights $\ge 0$ for every subsequent run. To get flow through 
     * original edges, assign ID's during \texttt{ae}.
 * Time: Ignoring first run of Dijkstra, $O(FM\log M)$ 
     * if caps are integers and $F$ is max flow.
 * Source: GeeksForGeeks
     * https://courses.csail.mit.edu/6.854/06/scribe/s12-minCostFlowAlg.pdf
     * running time is only pseudo-polynomial; see https://codeforces.com/blog/entry/70740
     * https://en.wikipedia.org/wiki/Johnson%27s_algorithm (to get non-negative weights)
     * https://codeforces.com/contest/1316/submission/72472865 
         * mango_lassi, min cost circulation w/ capacity scaling
 * Verification: https://codeforces.com/contest/164/problem/C
     * https://codeforces.com/contest/316/problem/C2
         * TLEs, don't use priority queue
 */

struct MCMF { 
    using F = ll; using C = ll; // flow type, cost type
    struct Edge { int to, rev; F flo, cap; C cost; };
    int N; V<C> p, dist; vpi pre; V<V<Edge>> adj;
    void init(int _N) { N = _N;
        p.rsz(N), adj.rsz(N), dist.rsz(N), pre.rsz(N); }
    void ae(int u, int v, F cap, C cost) { assert(cap >= 0); 
        adj[u].pb({v,sz(adj[v]),0,cap,cost}); 
        adj[v].pb({u,sz(adj[u])-1,0,0,-cost});
    } // use asserts, don't try smth dumb
    bool path(int s, int t) { // send flow through lowest cost path
        const C inf = numeric_limits<C>::max(); dist.assign(N,inf);
        using T = pair<C,int>;
        priority_queue<T,V<T>,greater<T>> todo; 
        todo.push({dist[s] = 0,s}); 
        while (sz(todo)) { // Dijkstra
            T x = todo.top(); todo.pop(); 
            if (x.f > dist[x.s]) continue;
            each(e,adj[x.s]) { // all weights should be non-negative
                if (e.flo < e.cap && ckmin(dist[e.to],
                        x.f+e.cost+p[x.s]-p[e.to]))
                    pre[e.to]={x.s,e.rev}, todo.push({dist[e.to],e.to});
            }
        } // if costs are doubles, add some EPS so you 
        // don't traverse ~0-weight cycle repeatedly
        return dist[t] != inf; // true if augmenting path
    }
    pair<F,C> calc(int s, int t) { assert(s != t);
        F0R(_,N) F0R(i,N) each(e,adj[i]) // Bellman-Ford
            if (e.cap) ckmin(p[e.to],p[i]+e.cost);
        F totFlow = 0; C totCost = 0;
        while (path(s,t)) { // p -> potentials for Dijkstra
            F0R(i,N) p[i] += dist[i]; // don't matter for unreachable
            F df = numeric_limits<F>::max();
            for (int x = t; x != s; x = pre[x].f) {
                Edge& e = adj[pre[x].f][adj[x][pre[x].s].rev]; 
                ckmin(df,e.cap-e.flo); }
            if(p[t]-p[s] >= 0) break;
            totFlow += df; totCost += (p[t]-p[s])*df;
            for (int x = t; x != s; x = pre[x].f) {
                Edge& e = adj[x][pre[x].s]; e.flo -= df;
                adj[pre[x].f][e.rev].flo += df;
            }
        } // get max flow you can send along path
        return {totFlow,totCost};
    }
};

/**
 * Description: Shortest Path w/ negative edge weights
    * Can be useful with linear programming
    * Constraints of the form x_i-x_j<k
 * Source: Own
 * Verification: 
    * https://open.kattis.com/problems/shortestpath3
    * https://probgate.org/viewproblem.php?pid=378
 */

template<int SZ> struct BellmanFord {
    int n;
    vi adj[SZ];
    V<pair<pi,int>> ed;
    void ae(int u, int v, int w) { 
        adj[u].pb(v), ed.pb({{u,v},w}); }
    ll dist[SZ];
    void genBad(int x) { 
        // if x is reachable from negative cycle
        // -> update dists of all vertices which x can go to
        if (dist[x] == -INF) return;
        dist[x] = -INF; 
        each(t,adj[x]) genBad(t);
    }
    void init(int _n, int s) {
        n = _n; F0R(i,n) dist[i] = INF; 
        dist[s] = 0;
        F0R(i,n) each(a,ed) if (dist[a.f.f] < INF)
            ckmin(dist[a.f.s],dist[a.f.f]+a.s);
        each(a,ed) if (dist[a.f.f] < INF 
                    && dist[a.f.s] > dist[a.f.f]+a.s) 
            genBad(a.f.s);
    }
};

const int mx = 100005;
int a[mx];
int u[mx];
int v[mx];

int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= m; i++){
        cin >> u[i] >> v[i];
    }

    MCMF mcmf;
    mcmf.init(n+5);
    for(int i = 1; i <= m; i++){
        mcmf.ae(u[i], v[i], MOD, 0);
    }
    for(int i = 1; i <= n; i++){
        mcmf.ae(n+1, i, 1, -a[i]);
        mcmf.ae(i, n+2, 1, +a[i]);
    }

    ll cost = mcmf.calc(n+1, n+2).s;

    BellmanFord<mx> bf;

    for(int i = 1; i <= n+2; i++){
        for(auto x: mcmf.adj[i]){
            // dbg(i, x.to, x.flo, x.cap, x.cost);
            if(x.flo < x.cap){
                bf.ae(i, x.to, int(x.cost));
            }
        }
    }

    bf.init(n+3, n+1);

    // ps(-cost);
    for(int i = 1; i <= n; i++){
        cout << -bf.dist[i] << " ";
    }
    cout << "\n";

    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/