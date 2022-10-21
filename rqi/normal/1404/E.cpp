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
 * Description: Fast flow. After computing flow, edges ${u,v}$ such that 
    * $lev[u] \neq -1,$ $lev[v] = -1$ are part of min cut.
    * Use \texttt{reset} and \texttt{rcap} for Gomory-Hu.
 * Time: $O(N^2M)$ flow, $O(M\sqrt N)$ bipartite matching
 * Source: GeeksForGeeks, Chilli
 * Verification: RMI 2017 Day 1 Fashion
    * https://pastebin.com/VJxTvEg1
 */

template<int SZ> struct Dinic {
    int N,s,t; // # verts, source, sink
    typedef ll F; // flow type
    struct Edge { int to, rev; F flo, cap; };
    vector<Edge> adj[SZ]; // use asserts, don't be dumb
    void reset() { F0R(i,N) trav(e,adj[i]) e.flo = 0; }
    void ae(int u, int v, F cap, F rcap = 0) { 
        //dbg(u, v, cap);
        assert(min(cap,rcap) >= 0); 
        Edge a{v,sz(adj[v]),0,cap}, b{u,sz(adj[u]),0,rcap};
        adj[u].pb(a), adj[v].pb(b); } 
    int lev[SZ]; typename vector<Edge>::iterator cur[SZ]; 
    bool bfs() { // level = shortest distance from source
        F0R(i,N) lev[i] = -1, cur[i] = begin(adj[i]);
        queue<int> q({s}); lev[s] = 0; 
        while (sz(q)) {
            int u = q.ft; q.pop();
            trav(e,adj[u]) if (lev[e.to] < 0 && e.flo < e.cap) 
                q.push(e.to), lev[e.to] = lev[u]+1;
        }
        return lev[t] >= 0;
    }
    F dfs(int v, F flo) {
        if (v == t) return flo;
        for (; cur[v] != end(adj[v]); cur[v]++) {
            Edge& e = *cur[v];
            if (lev[e.to]!=lev[v]+1||e.flo==e.cap) continue;
            F df = dfs(e.to,min(flo,e.cap-e.flo));
            if (df) { e.flo += df; adj[e.to][e.rev].flo -= df;
                return df; } // saturated >=1 one edge
        }
        return 0;
    }
    F maxFlow(int _N, int _s, int _t) {
        N = _N, s = _s, t = _t; assert(s != t);
        F tot = 0; while (bfs()) while (F df = 
            dfs(s,numeric_limits<F>::max())) tot += df;
        return tot;
    }
};

const int mx = 205;
bool filled[mx][mx];
pi horz[mx][mx];
pi vert[mx][mx];
Dinic<mx*mx*3> din;

void AE(pi a, pi b){
    if(a.f == 0 || b.f == 0) return;
    if(a.s == 1) swap(a, b);
    din.ae(a.f, b.f, 1);
}

int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        for(int j = 1; j <= m; j++){
            if(s[j-1] == '#'){
                filled[i][j] = 1;
                ans++;
            }
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(filled[i][j] && filled[i+1][j]) horz[i][j] = mp(++cnt, 0), ans--;
            if(filled[i][j] && filled[i][j+1]) vert[i][j] = mp(++cnt, 1), ans--;
            //dbg(i, j, horz[i][j], vert[i][j]);
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            AE(horz[i][j], vert[i][j]);
            AE(horz[i][j], vert[i][j-1]);
            AE(horz[i-1][j], vert[i][j]);
            AE(horz[i-1][j], vert[i][j-1]);
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(horz[i][j].f != 0){
                // dbg(i, j, horz[i][j]);
                if(horz[i][j].s == 0){
                    din.ae(0, horz[i][j].f, 1);
                }
                else{
                    din.ae(horz[i][j].f, cnt+1, 1);
                }
            }
            if(vert[i][j].f != 0){
                //dbg(i, j, vert[i][j]);
                if(vert[i][j].s == 0){
                    din.ae(0, vert[i][j].f, 1);
                }
                else{
                    din.ae(vert[i][j].f, cnt+1, 1);
                }
            }
        }
    }
    ans+=din.maxFlow(cnt+2, 0, cnt+1);

    ps(ans);
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
*/