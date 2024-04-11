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
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

template<class T> bool ckmin(T& a, const T& b) { 
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
    return a < b ? a = b, 1 : 0; } 
int pct(int x) { return __builtin_popcount(x); } 
int bits(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
int cdiv(int a, int b) { return a/b+!(a<0||a%b == 0); } // division of a by b rounded up, assumes b > 0 
int fstTrue(function<bool(int)> f, int lo, int hi) {
    hi ++; assert(lo <= hi); // assuming f is increasing
    while (lo < hi) { // find first index such that f is true 
        int mid = (lo+hi)/2; 
        f(mid) ? hi = mid : lo = mid+1; 
    } 
    return lo;
}

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
str ts(bool b) { return b ? "true" : "false"; }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
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
    cerr << ts(h); if (sizeof...(t)) cerr << ", ";
    DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
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

/**
 * Description: Calculates min and # of mins
 * Source: Own
 * Verification: FHC19 Final D
 */

typedef pi T;
T operator+(const T& l, const T& r) {
    if (l.f != r.f) return min(l,r);
    return {l.f,l.s+r.s};
}

template<int SZ> struct LazySeg { 
    T sum[2*SZ];
    int lazy[2*SZ];
    LazySeg() {
        memset(sum,0,sizeof sum);
        memset(lazy,0,sizeof lazy);
    }
    void push(int ind, int L, int R) { // modify values for current node
        sum[ind].f += lazy[ind]; 
        if (L != R) lazy[2*ind] += lazy[ind], lazy[2*ind+1] += lazy[ind]; 
        lazy[ind] = 0; // pushed lazy to children
    }
    void pull(int ind) { // recalc values for current node
        sum[ind] = sum[2*ind]+sum[2*ind+1]; }
    void build() { 
        FOR(i,SZ,2*SZ) sum[i] = {0,1};
        ROF(i,1,SZ) pull(i); 
    }
    void upd(int lo, int hi, int inc, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind] = inc; 
            push(ind,L,R); return;
        }
        int M = (L+R)/2;
        upd(lo,hi,inc,2*ind,L,M); upd(lo,hi,inc,2*ind+1,M+1,R);
        pull(ind);
    }
    T qsum(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return {MOD,0};
        if (lo <= L && R <= hi) return sum[ind];
        int M = (L+R)/2;
        return qsum(lo,hi,2*ind,L,M)+qsum(lo,hi,2*ind+1,M+1,R);
    }
};


const int mx = 200005;
int n, m;
string grid[mx];
int par[mx];
vi children[mx];

bool inRect(int x, int y){
    if(x >= 0 && x <= n-1 && y >= 0 && y <= m-1) return true;
    return false;
}

int toint(pi p){
    return p.f*m+p.s;
}

void addEdge(int a, int b){
    par[a] = b;
}

bool visited[mx];
int curtim[2];
int etnum[mx];
int rang[2][mx];

void genET(int node, bool typ){
    if(visited[node] == 1) return;
    visited[node] = 1;
    etnum[node] = ++curtim[typ];
    for(auto u: children[node]){
        genET(u, typ);
    }
    rang[typ][etnum[node]] = curtim[typ];
}

vector<pair<int, pi>> upds[mx]; //for each y coor, delta, L, R
LazySeg<262144> lseg;


int main() {
    setIO();
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }

    for(int i = 0; i < n*m; i++){
        par[i] = -1;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'U'){
                if(inRect(i+2, j)){
                    addEdge(toint(mp(i, j)), toint(mp(i+2, j)));
                }
                if(inRect(i-1, j)){
                    addEdge(toint(mp(i+1, j)), toint(mp(i-1, j)));
                }
            }
            else if(grid[i][j] == 'R'){
                if(inRect(i, j-2)){
                    addEdge(toint(mp(i, j)), toint(mp(i, j-2)));
                }
                if(inRect(i, j+1)){
                    addEdge(toint(mp(i, j-1)), toint(mp(i, j+1)));
                }
            }
        }
    }

    for(int i = 0; i < n*m; i++){
        if(par[i] != -1) children[par[i]].pb(i);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int node = toint(mp(i, j));
            if((i+j) % 2 == 0){
                if(par[node] == -1){
                    genET(node, 0);
                }
            }
            else{
                if(par[node] == -1){
                    genET(node, 1);
                }
            }
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         dbg(i, j, toint(mp(i, j)), etnum[toint(mp(i, j))]);
    //         dbg(par[toint(mp(i, j))]);
    //     }
    // }

    // for(int i = 1; i <= 4; i++){
    //     dbg(rang[0][i]);
    // }
    // for(int i = 1; i <= 4; i++){
    //     dbg(rang[1][i]);
    // }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int node0 = 0, node1 = 0;
            if(grid[i][j] == 'U'){
                node0 = toint(mp(i, j));
                node1 = toint(mp(i+1, j));
                if((i+j) % 2 == 1) swap(node0, node1);
            }
            else if(grid[i][j] == 'R'){
                node0 = toint(mp(i, j));
                node1 = toint(mp(i, j-1));
                if((i+j) % 2 == 1) swap(node0, node1);
            }
            else continue;
            node0 = etnum[node0];
            node1 = etnum[node1];
            //dbg(i, j, node0, node1);
            upds[node1].pb(mp(1, mp(node0, rang[0][node0])));
            upds[rang[1][node1]+1].pb(mp(-1, mp(node0, rang[0][node0])));
        }
    }

    lseg.build();
    ll ans = 0;
    //dbg(curtim[0]);
    //dbg(lseg.qsum(0, curtim[0]));

    for(int y = 0; y <= curtim[1]; y++){
        //dbg(upds[y]);
        for(auto u: upds[y]){
            lseg.upd(u.s.f, u.s.s, u.f);
        }
        //dbg(y, lseg.qsum(0, curtim[0]));
        ans+=curtim[0]+1-lseg.qsum(0, curtim[0]).s;
    }

    ps(ans);

    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
*/