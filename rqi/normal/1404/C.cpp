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
 * Description: A set (not multiset!) with support for finding the $n$'th
 * element, and finding the index of an element. Change \texttt{null\_type} for map.
 * Time: O(\log N)
 * Source: KACTL
   * https://codeforces.com/blog/entry/11080
 * Verification: many
 */

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, 
    rb_tree_tag, tree_order_statistics_node_update>; 
#define ook order_of_key
#define fbo find_by_order

void treeExample() {
    Tree<int> t, t2; t.insert(8);
    auto it = t.insert(10).f; assert(it == t.lb(9));
    assert(t.ook(10) == 1 && t.ook(11) == 2 && *t.fbo(0) == 8);
    t.join(t2); // assuming T < T2 or T > T2, merge t2 into t
}

/**
int atMost(Tree<pi>& T, int r) { 
    return T.ook({r,MOD}); }
int getSum(Tree<pi>& T, int l, int r) { 
    return atMost(T,r)-atMost(T,l-1); }
*/

/**
 * Description: range sum queries and point updates for $D$ dimensions
 * Source: https://codeforces.com/blog/entry/64914
 * Verification: SPOJ matsum
 * Usage: \texttt{BIT<int,10,10>} gives 2D BIT
 * Time: O((\log N)^D)
 */

template <class T, int ...Ns> struct BIT {
    T val = 0; void upd(T v) { val += v; }
    T query() { return val; }
};
template <class T, int N, int... Ns> struct BIT<T, N, Ns...> {
    BIT<T,Ns...> bit[N+1];
    template<typename... Args> void upd(int pos, Args... args) { assert(pos > 0);
        for (; pos<=N; pos+=pos&-pos) bit[pos].upd(args...); }
    template<typename... Args> T sum(int r, Args... args) {
        T res=0; for (;r;r-=r&-r) res += bit[r].query(args...); 
        return res; }
    template<typename... Args> T query(int l, int r, Args... 
        args) { return sum(r,args...)-sum(l-1,args...); }
}; 



const int mx = 300005;
int a[mx];
int num[mx]; //how many things before it need to get removed?
vi nums[mx];
BIT<int, mx> vals;
int nL[mx]; //L should be <= this, make it -1 if impossible
int anses[mx];

int x[mx];
int y[mx];


BIT<int, mx> bt;

int main() {
    setIO();
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }   

    for(int i = 1; i <= n; i++){
        if(a[i] > i) num[i] = -1;
        else num[i] = i-a[i];
    }

    for(int i = 1; i <= n; i++){
        //dbg(i, num[i]);
        if(num[i] == -1) continue;
        nums[num[i]].pb(i);
    }

    for(int i = 1; i <= n; i++){
        nL[i] = -1;
    }
    Tree<pi> poses; //nL value, index

    for(int i = 1; i <= n; i++){
        if(num[i] == -1){
            nL[i] = -1;
        }
        else if(num[i] == 0){
            nL[i] = i;
        }
        else if(i == 1){
            nL[i] = -1;
        }
        else{
            if(vals.query(1, i-1) < num[i]){
                nL[i] = -1;
            }
            else{
                int lo = 1;
                int hi = i-1;
                while(lo < hi){
                    int mid = (lo+hi)/2+1;
                    if(vals.query(mid, i-1) >= num[i]){
                        lo = mid;
                    }
                    else{
                        hi = mid-1;
                    }
                }
                nL[i] = lo;
            }
        }
        if(nL[i] >= 1){
            vals.upd(nL[i], 1);
        }
    }
    // for(int i = 0; i <= n; i++){
    //     for(auto u: nums[i]){

    //         // int a = poses.ook(u); //# of things before it
    //         // if(a < i){
    //         //     nL[u] = -1;
    //         //     continue;
    //         // }
    //         // if(i == 0){
    //         //     nL[u] = u;
    //         // }
    //         // else{
    //         //     nL[u] = *(poses.fbo(a-i));
    //         // }
    //     }

    //     for(auto u: nums[i]){
    //         poses.ins(mp(nL[u], u));
    //     }
    // }

    // for(int i = 1; i <= n; i++){
    //     dbg(i, nL[i]);
    // }

    vpi queries; //l value, index
    for(int i = 1; i <= q; i++){
        cin >> x[i] >> y[i];
        x[i] = x[i]+1;
        y[i] = n-y[i];
        queries.pb(mp(x[i], i));
    }

    vpi upds;
    for(int i = 1; i <= n; i++){
        upds.pb(mp(nL[i], i));
    }

    sort(queries.rbegin(), queries.rend());
    sort(upds.rbegin(), upds.rend());

    int upind = 0;
    for(auto u: queries){
        while(upind < sz(upds) && upds[upind].f >= u.f){
            if(upds[upind].s >= 1) bt.upd(upds[upind].s, 1);
            upind++;
        }

        anses[u.s] = bt.query(x[u.s], y[u.s]);
    }

    for(int i = 1; i <= q; i++){
        ps(anses[i]);
    }

    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
*/