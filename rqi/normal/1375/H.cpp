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

int n, q;
vi ranges[10005]; //ranges for each segment tree node
map<pi, int> seg[10005]; //> 2*2^12
int a[5005]; // > 2^12
int cnt;
vpi opos;

void genRanges(int ind = 1, int L = 1, int R = n){
    if(ind == 1){
        for(int i = 1; i <= n; i++){
            ranges[ind].pb(i);
        }
    }
    else{
        for(auto u: ranges[ind/2]){
            if(L <= a[u] && a[u] <= R){
                ranges[ind].pb(u);
            }
        }
    }
    //dbg(L, R, ranges[ind]);
    if(L == R){
        for(int i = 1; i <= n; i++){
            if(a[i] == L){
                seg[ind][mp(0, 0)] = i;
                break;
            }
        }
        return;
    }
    int M = (L+R)/2;
    genRanges(2*ind, L, M);
    genRanges(2*ind+1, M+1, R);
}

int query(int lo, int hi, int ind = 1, int L = 1, int R = n){

    int l = -1;
    int r = sz(ranges[ind]);
    for(int i = 0; i < sz(ranges[ind]); i++){
        if(ranges[ind][i] >= lo){
            l = i;
            break;
        }
    }
    for(int i = sz(ranges[ind])-1; i >= 0; i--){
        if(ranges[ind][i] <= hi){
            r = i;
            break;
        }
    }
    //dbg(lo, hi, L, R, l, r);
    if(l > r) return 0;
    if(l < 0) return 0;
    if(r > sz(ranges[ind])-1) return 0;

    if(seg[ind].count(mp(l, r))){
        return seg[ind][mp(l, r)];
    }

    assert(L != R);
    int M = (L+R)/2;
    int res1 = query(lo, hi, 2*ind, L, M);
    int res2 = query(lo, hi, 2*ind+1, M+1, R);
    if(res1 == 0) return seg[ind][mp(l, r)] = res2;
    if(res2 == 0) return seg[ind][mp(l, r)] = res1;
    opos.pb(mp(res1, res2));
    return seg[ind][mp(l, r)] = ++cnt;
}

int main() {
    setIO();
    cin >> n >> q;
    cnt = n;
    //#warning prove bounds
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    genRanges();
    vi anses;
    for(int i = 1; i <= q; i++){
        int l, r;
        cin >> l >> r;
        anses.pb(query(l, r));
    }
    cout << cnt << "\n";
    for(auto u: opos){
        cout << u.f << " " << u.s << "\n";
    }
    for(auto u: anses){
        cout << u << " ";
    }
    cout << "\n";

    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
*/