  
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
#define sz(x) (int)(x).size()
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
#ifdef LOCAL // compile with -DLOCAL
    #define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
    #define dbg(...) 0
#endif

// FILE I/O
void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }
void unsyncIO() { ios_base::sync_with_stdio(0); cin.tie(0); }
void setIO(str s = "") {
    unsyncIO();
    // cin.exceptions(cin.failbit); 
    // throws exception when do smth illegal
    // ex. try to read letter into int
    if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
}

/**
 * Description: 1D range minimum query. Can also do queries 
    * for any associative operation in $O(1)$ with D\&C
 * Source: KACTL
 * Verification: 
    * https://cses.fi/problemset/stats/1647/
    * http://wcipeg.com/problem/ioi1223
    * https://pastebin.com/ChpniVZL
 * Memory: O(N\log N)
 * Time: O(1)
 */

template<class T> struct RMQ { // floor(log_2(x))
    int level(int x) { return 31-__builtin_clz(x); } 
    vector<T> v; vector<vi> jmp;
    int comb(int a, int b) { // index of min
        return v[a]==v[b]?min(a,b):(v[a]<v[b]?a:b); } 
    void init(const vector<T>& _v) {
        v = _v; jmp = {vi(sz(v))}; iota(all(jmp[0]),0);
        for (int j = 1; 1<<j <= sz(v); ++j) {
            jmp.pb(vi(sz(v)-(1<<j)+1));
            F0R(i,sz(jmp[j])) jmp[j][i] = comb(jmp[j-1][i],
                                    jmp[j-1][i+(1<<(j-1))]);
        }
    }
    int index(int l, int r) { // get index of min element
        int d = level(r-l+1);
        return comb(jmp[d][l],jmp[d][r-(1<<d)+1]); }
    T query(int l, int r) { return v[index(l,r)]; }
};


struct LCA {
    int N; vector<vi> adj;
    vi depth, pos;
    vpi tmp; RMQ<pi> r;
    void init(int _N) { N = _N; adj.rsz(N); depth = pos = vi(N); }
    void ae(int x, int y) { adj[x].pb(y), adj[y].pb(x); }
    void dfs(int x, int p) {
        pos[x] = sz(tmp); tmp.eb(depth[x],x); 
        trav(y,adj[x]) if (y != p) {
            depth[y] = depth[x]+1;
            dfs(y,x), tmp.eb(depth[x],x);
        }
    }
    void gen(int R) { dfs(R,-1); r.init(tmp); }
    int lca(int u, int v){
        u = pos[u], v = pos[v]; if (u > v) swap(u,v);
        return r.query(u,v).s; }
    int dist(int u, int v) {
        return depth[u]+depth[v]-2*depth[lca(u,v)]; }
    vpi compress(vi S) {
        static vi rev; rev.rsz(N);
        auto cmp = [&](int a, int b) { return pos[a] < pos[b]; };
        sort(all(S),cmp); R0F(i,sz(S)-1) S.pb(lca(S[i],S[i+1]));
        sort(all(S),cmp); remDup(S);
        vpi ret{{0,S[0]}}; F0R(i,sz(S)) rev[S[i]] = i;
        F0R(i,sz(S)-1) ret.eb(rev[lca(S[i],S[i+1])],S[i+1]);
        return ret;
    }
};

const int mx = 100005;
int N;
LCA tr;
vi adj[mx];
int sub[mx];
int to[mx];

void genSub(int node, int prv = -1){
    sub[node]++;
    for(auto u: adj[node]){
        if(u == prv) continue;
        genSub(u, node);
        sub[node]+=sub[u];
    }
}

int cent(int node, int prv = -1){
    for(auto u: adj[node]){
        if(u == prv) continue;
        if(N-sub[u] > N/2) continue;
        return cent(u, node);
    }
    return node;
}

int cen;
vi groups[mx];

void genGroups(int node, int prv = -1, int group = -1){
    if(node == cen){
        for(auto u: adj[node]){
            genGroups(u, node, u);
        }
        return;
    }
    groups[group].pb(node);
    for(auto u: adj[node]){
        if(u == prv) continue;
        genGroups(u, node, group);
    }
}

int main() {
    setIO();
    cin >> N;
    tr.init(N+1);
    for(int i = 0; i < N-1; i++){
        int a, b;
        cin >> a >> b;
        cout.flush();
        adj[a].pb(b);
        adj[b].pb(a);
        tr.ae(a, b);
    }
    tr.gen(1);
    genSub(1);
    cen = cent(1);
    genGroups(cen);

    priority_queue<pi> pq;
    for(int i = 1; i <= N; i++){
        pq.push(mp(sz(groups[i]), i));
    }

    vi vlist;
    vlist.pb(cen);
    int last = cen;

    while(sz(pq)){
        pi a = pq.top();
        if(a.f == 0) break;
        if(a.s == last){
            pq.pop();
            pi b = pq.top();
            pq.pop();
            assert(b.f != 0);
            vlist.pb(groups[b.s].bk);
            groups[b.s].pop_back();
            last = b.s;
            pq.push(mp(sz(groups[b.s]), b.s));
            pq.push(a);
            continue;
        }

        pq.pop();
        assert(a.f != 0);
        vlist.pb(groups[a.s].bk);
        groups[a.s].pop_back();
        last = a.s;
        pq.push(mp(sz(groups[a.s]), a.s));

    }

    vlist.pb(cen);
    ll sum = 0;
    for(int i = 0; i+1 < sz(vlist); i++){
        sum+=tr.dist(vlist[i], vlist[i+1]);
        to[vlist[i]] = vlist[i+1];
    }
    //ps(vlist);

    ps(sum);
    for(int i = 1; i <= N; i++){
        cout << to[i] << " ";
    }


    // you should actually read the stuff at the bottom
}
 
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
*/