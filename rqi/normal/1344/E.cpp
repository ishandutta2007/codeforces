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

const int MOD = 1e9+7; // 998244353;
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

vector<pair<ll, int>> access_path;

/**
 * Description: Link-Cut Tree. Given a function $f(1\ldots N)\to 1\ldots N,$ 
     * evaluates $f^b(a)$ for any $a,b.$ \texttt{sz} is for path queries; 
     * \texttt{sub}, \texttt{vsub} are for subtree queries. \texttt{x->access()} 
     * brings \texttt{x} to the top and propagates it; its left subtree will be 
     * the path from \texttt{x} to the root and its right subtree will be empty. 
     * Then \texttt{sub} will be the number of nodes in the connected component
     * of \texttt{x} and \texttt{vsub} will be the number of nodes under \texttt{x}.
     * Use \texttt{makeRoot} for arbitrary path queries.
 * Time: O(\log N)
 * Usage: FOR(i,1,N+1)LCT[i]=new snode(i); link(LCT[1],LCT[2],1);
 * Source: Dhruv Rohatgi, Eric Zhang
    * https://sites.google.com/site/kc97ble/container/splay-tree/splaytree-cpp-3
    * https://codeforces.com/blog/entry/67637
 * Verification: (see README for links)
    * ekzhang Balanced Tokens
    * Dynamic Tree Test (Easy)
    * https://probgate.org/viewproblem.php?pid=578 (The Applicant)
 */

typedef struct snode* sn;
struct snode { //////// VARIABLES
    sn p, c[2]; // parent, children
    sn extra; // extra cycle node for "The Applicant"
    bool flip = 0; // subtree flipped or not
    int sz; // value in node, # nodes in current splay tree
    int sub, vsub = 0; // vsub stores sum of virtual children
    int id;
    ll val;
    ll lazy;

    snode(int _id){
        id = _id;
        val = lazy = 0;
        p = c[0] = c[1] = extra = NULL; calc(); }

    friend int getSz(sn x) { return x?x->sz:0; }
    friend int getSub(sn x) { return x?x->sub:0; }
    void prop() { // lazy prop
        ckmax(val, lazy);
        for(int i = 0; i < 2; i++){
            if(c[i]){
                ckmax(c[i]->lazy, lazy);
            }
        }
        lazy = 0;

        if (!flip) return;
        swap(c[0],c[1]); flip = 0;
        F0R(i,2) if (c[i]) c[i]->flip ^= 1;
    }
    void calc() { // recalc vals
        F0R(i,2) if (c[i]) c[i]->prop();
        sz = 1+getSz(c[0])+getSz(c[1]);
        sub = 1+getSub(c[0])+getSub(c[1])+vsub;
    }
    //////// SPLAY TREE OPERATIONS
    int dir() {
        if (!p) return -2;
        F0R(i,2) if (p->c[i] == this) return i;
        return -1; // p is path-parent pointer
    } // -> not in current splay tree
    // test if root of current splay tree
    bool isRoot() { return dir() < 0; } 
    friend void setLink(sn x, sn y, int d) {
        if (y) y->p = x;
        if (d >= 0) x->c[d] = y; }
    void rot() { // assume p and p->p propagated
        assert(!isRoot()); int x = dir(); sn pa = p;
        setLink(pa->p, this, pa->dir());
        setLink(pa, c[x^1], x); setLink(this, pa, x^1);
        pa->calc();
    }
    void splay() {
        while (!isRoot() && !p->isRoot()) {
            p->p->prop(), p->prop(), prop();
            dir() == p->dir() ? p->rot() : rot();
            rot();
        }
        if (!isRoot()) p->prop(), prop(), rot();
        prop(); calc();
    }
    sn fbo(int b) { // find by order
        prop(); int z = getSz(c[0]); // of splay tree
        if (b == z) { splay(); return this; }
        return b < z ? c[0]->fbo(b) : c[1] -> fbo(b-z-1);
    }
    //////// BASE OPERATIONS
    void access() { // bring this to top of tree, propagate
        for (sn v = this, pre = NULL; v; v = v->p) {
            v->splay(); // now switch virtual children
            if (pre) v->vsub -= pre->sub;
            if (v->c[1]) v->vsub += v->c[1]->sub;
            v->c[1] = pre; v->calc(); pre = v;
        }
        splay(); assert(!c[1]); // right subtree is empty
    }

    void specialAccess(ll t){
        access_path.clear();
        for (sn v = this, pre = NULL; v; v = v->p) {
            v->splay(); // now switch virtual children

            if(!pre){
                pre = v;
                continue;
            }

            access_path.pb(mp(v->val, v->id));

            if (pre) v->vsub -= pre->sub;
            if (v->c[1]) v->vsub += v->c[1]->sub;
            v->c[1] = pre; v->calc(); pre = v;
        }
        splay(); //assert(!c[1]); // right subtree is empty
        if(c[0]){
            c[0]->lazy = t;
            c[0]->prop();
        }
    }

    void makeRoot() { 
        access(); flip ^= 1; access(); assert(!c[0] && !c[1]); }
    //////// QUERIES
    friend sn lca(sn x, sn y) {
        if (x == y) return x;
        x->access(), y->access(); if (!x->p) return NULL;
        x->splay(); return x->p?:x; // y was below x in latter case
    } // access at y did not affect x -> not connected
    friend bool connected(sn x, sn y) { return lca(x,y); } 
    // # nodes above
    int distRoot() { access(); return getSz(c[0]); } 
    sn getRoot() { // get root of LCT component
        access(); sn a = this; 
        while (a->c[0]) a = a->c[0], a->prop();
        a->access(); return a;
    }
    sn getPar(int b) { // get b-th parent on path to root
        access(); b = getSz(c[0])-b; assert(b >= 0);
        return fbo(b);
    } // can also get min, max on path to root, etc
    //////// MODIFICATIONS
    void set(int v) { access(); val = v; calc(); } 
    friend void link(sn x, sn y, bool force = 0) { 
        assert(!connected(x,y)); 
        if (force) y->makeRoot(); // make x par of y
        else { y->access(); assert(!y->c[0]); }
        x->access(); setLink(y,x,0); y->calc();
    }
    friend void cut(sn y) { // cut y from its parent
        y->access(); assert(y->c[0]);
        y->c[0]->p = NULL; y->c[0] = NULL; y->calc(); }
    friend void cut(sn x, sn y) { // if x, y adj in tree
        x->makeRoot(); y->access(); 
        assert(y->c[0] == x && !x->c[0] && !x->c[1]); cut(y); }
};


//////// THE APPLICANT SOLUTION
void setNex(sn a, sn b) { // set f[a] = b
    if (connected(a,b)) a->extra = b;
    else link(b,a); }
void delNex(sn a) { // set f[a] = NULL
    auto t = a->getRoot();
    if (t == a) { t->extra = NULL; return; }
    cut(a); assert(t->extra);
    if (!connected(t,t->extra)) 
        link(t->extra,t), t->extra = NULL; 
}
sn getPar(sn a, int b) { // get f^b[a]
    int d = a->distRoot(); if (b <= d) return a->getPar(b);
    b -= d+1; auto r = a->getRoot()->extra; assert(r);
    d = r->distRoot()+1; return r->getPar(b%d);
}

const int mx = 100005;
int n, m;
sn LCT[mx];

vector<pair<int, ll>> adj[mx];
ll depth[mx];
int par[mx];

void genDepth(int node){
    for(auto u: adj[node]){
        depth[u.f] = depth[node]+u.s;
        par[u.f] = node;
        genDepth(u.f);
    }
}

void initAccess(int node){
    // dbg("ACCESS", node);
    LCT[node]->access();
    for(auto u: adj[node]){
        initAccess(u.f);
    }   
}

int main() {
    setIO();
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        LCT[i] = new snode(i);
    }

    for(int i = 1; i <= n-1; i++){
        int u, v;
        ll d;
        cin >> u >> v >> d;
        link(LCT[u], LCT[v]);
        adj[u].pb(mp(v, d));
    }

    genDepth(1);
    initAccess(1);

    vl times;
    vpl deadlines;
    for(int i = 1; i <= m; i++){
        dbg(i);
        int s;
        ll t;
        cin >> s >> t;
        LCT[s]->specialAccess(t);
        // dbg(s);
        for(auto u: access_path){
            times.pb(depth[u.s]+t);
            assert(u.f+depth[u.s]+1 <= depth[u.s]+t);
            pl add_val;
            if(u.f == 0){
                add_val = mp(1, depth[u.s]+t);
            }
            else{
                add_val = mp(u.f+depth[u.s]+1, depth[u.s]+t);
            }
            deadlines.pb(add_val);
            // ps(add_val);
        }
    }


    ll crash_time = INF;
    ll cur_time = 1;
    sort(all(deadlines));
    int deadline_ind = 0; //deadline to add
    priority_queue<ll, vector<ll>, greater<ll>> to_complete; // end times

    // dbg(deadlines);
    while(sz(to_complete) || deadline_ind < sz(deadlines)){
        //add deadlines
        while(deadline_ind < sz(deadlines)){
            if(deadlines[deadline_ind].f <= cur_time){
                to_complete.push(deadlines[deadline_ind].s);
                deadline_ind++;
                continue;
            }
            else{
                break;
            }
        }

        if(sz(to_complete)){
            ll task_tim = to_complete.top(); to_complete.pop();
            if(task_tim < cur_time){
                crash_time = task_tim;
                assert(task_tim == cur_time-1);
                break;
            }
            cur_time++;
        }
        else{
            assert(deadline_ind < sz(deadlines));
            assert(deadlines[deadline_ind].f > cur_time); //time skip
            cur_time = deadlines[deadline_ind].f;
            to_complete.push(deadlines[deadline_ind].s);
            deadline_ind++;
        }
    }


    sort(all(times));
    int switches = 0;
    for(auto u: times){
        if(u < crash_time){
            switches++;
        }
    }

    if(crash_time == INF) crash_time = -1;

    ps(crash_time, switches);
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/