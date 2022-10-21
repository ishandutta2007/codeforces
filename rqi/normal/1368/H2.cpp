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

int n, m, q;
string horzsides[2];
string vertsides[2];
int dp[100005][2];
char typ[100005];
pi rang[100005];

/**
 * Description: 1D range update and query, $SZ=2^p$.
 * Source: USACO Counting Haybales
 * Verification: SPOJ Horrible
 * Type: Counts sume in a range. 0 = red, 1 = blue. Flip updates
 */

template<class T, int SZ> struct LazySegSum { 
    T sum[2*SZ], lazy[2*SZ]; 
    LazySegSum() { F0R(i,2*SZ) sum[i] = lazy[i] = 0; }
    void push(int ind, int L, int R) { /// modify values for current node
        if(lazy[ind] == 0) return;
        if (L != R) F0R(i,2) lazy[2*ind+i] ^= lazy[ind]; /// prop to children
        sum[ind] = (R-L+1)-sum[ind]; lazy[ind] = 0; 
    } // recalc values for current node
    void pull(int ind) { sum[ind] = sum[2*ind]+sum[2*ind+1]; }
    void build() { ROF(i,1,SZ) pull(i); }
    void upd(int lo,int hi, int inc=1,int ind=1,int L=0, int R=SZ-1) {
        push(ind,L,R); if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) { 
            lazy[ind] ^= inc; push(ind,L,R); return; }
        int M = (L+R)/2; upd(lo,hi,inc,2*ind,L,M); 
        upd(lo,hi,inc,2*ind+1,M+1,R); pull(ind);
    }
    T qsum(int lo, int hi, int ind=1, int L=0, int R = SZ-1) {
        push(ind,L,R); if (lo > R || L > hi) return 0;
        if (lo <= L && R <= hi) return sum[ind];
        int M = (L+R)/2; 
        return qsum(lo,hi,2*ind,L,M)+qsum(lo,hi,2*ind+1,M+1,R);
    }
};


/**
 * Description: 1D range update and query, $SZ=2^p$.
 * Source: USACO Counting Haybales
 * Verification: SPOJ Horrible
 */
typedef array<int, 4> A;

A ID = {-1, -1, -1, -1};
vpi rb = {{0, 0}, {0, 1}, {1, 0}, {1, 1}}; 

template<int SZ> struct LazySeg { 
    pair<A, A> sum[2*SZ]; //regular, if U was flipped
    int lazy[2*SZ]; //1 --> flip U, 2--> flip D
    LazySeg() { 
        F0R(i,2*SZ){
            sum[i] = mp(ID, ID);
            lazy[i] = 0;
        }
    }
    void push(int ind, int L, int R) { /// modify values for current node
        if (L != R) F0R(i,2) lazy[2*ind+i] ^= lazy[ind]; /// prop to children
        if((lazy[ind]&2) == 2){
            swap(sum[ind].f[0], sum[ind].f[3]);
            swap(sum[ind].f[1], sum[ind].f[2]);

            swap(sum[ind].s[0], sum[ind].s[3]);
            swap(sum[ind].s[1], sum[ind].s[2]);

            lazy[ind]^=3;
        }

        if((lazy[ind]&1) == 1){
            swap(sum[ind].f, sum[ind].s);
            lazy[ind]^=1;
        }

    } // recalc values for current node

    A comb(A a, A b){
        #warning recoloring doesn't matter here?
        if(a[0] == -1) return b;
        if(b[0] == -1) return a;

        A c;
        for(int i = 0; i < 4; i++) c[i] = MOD;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                int mayben = 0;
                if(rb[i].s != rb[j].f) mayben = n;
                ckmin(c[2*rb[i].f+rb[j].s], a[i]+b[j]+mayben);
            }
        }
        return c;
    }

    void pull(int ind) { 
        sum[ind].f = comb(sum[2*ind].f, sum[2*ind+1].f); 
        sum[ind].s = comb(sum[2*ind].s, sum[2*ind+1].s); 
    }
    void build() { ROF(i,1,SZ) pull(i); }
    #warning remember to build first
    void upd(int lo,int hi,int inc,int ind=1,int L=0, int R=SZ-1) {
        push(ind,L,R); if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) { 
            lazy[ind] ^= inc; push(ind,L,R); return; }
        int M = (L+R)/2; upd(lo,hi,inc,2*ind,L,M); 
        upd(lo,hi,inc,2*ind+1,M+1,R); pull(ind);
    }
    A qsum(int lo, int hi, int ind=1, int L=0, int R = SZ-1) {
        push(ind,L,R); if (lo > R || L > hi) return ID;
        if (lo <= L && R <= hi) return sum[ind].f;
        int M = (L+R)/2; 
        return comb(qsum(lo,hi,2*ind,L,M), qsum(lo,hi,2*ind+1,M+1,R));
    }
};

LazySegSum<int, 131072> leftside;
LazySegSum<int, 131072> rightside;
LazySeg<131072> middle;

int getans(){
    int ans = MOD;

    vi leftsums = {n-leftside.qsum(1, n), leftside.qsum(1, n)};
    vi rightsums = {n-rightside.qsum(1, n), rightside.qsum(1, n)};
    A val = middle.qsum(1, m);

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            ckmin(ans, leftsums[1-i]+rightsums[1-j]+val[2*i+j]);
        }
    }

    return ans;
}

vi solve(){
    leftside = LazySegSum<int, 131072>();
    rightside = LazySegSum<int, 131072>();
    middle = LazySeg<131072>();

    for(int i = 1; i <= n; i++){
        if(horzsides[0][i] == 'B'){
            leftside.upd(i, i);
        }
        if(horzsides[1][i] == 'B'){
            rightside.upd(i, i);
        }
    }

    A ar = {0, MOD, MOD, 2};
    A ab = {2, MOD, MOD, 0};
    A ad = {1, MOD, MOD, 1};
    for(int i = 1; i <= m; i++){
        pair<A, A> val = mp(ID, ID);
        if(vertsides[0][i] == 'R' && vertsides[1][i] == 'R'){
            val = mp(ar, ad);
        }
        else if(vertsides[0][i] == 'R' && vertsides[1][i] == 'B'){
            val = mp(ad, ab);
        }
        else if(vertsides[0][i] == 'B' && vertsides[1][i] == 'R'){
            val = mp(ad, ar);
        }
        else if(vertsides[0][i] == 'B' && vertsides[1][i] == 'B'){
            val = mp(ab, ad);
        }
        middle.sum[i+131072] = val;
    }
    middle.build();

    vi anses;
    anses.pb(getans());
    for(int i = 1; i <= q; i++){
        if(typ[i] == 'L'){
            leftside.upd(rang[i].f, rang[i].s);
        }
        else if(typ[i] == 'R'){
            rightside.upd(rang[i].f, rang[i].s);
        }
        else if(typ[i] == 'U'){
            middle.upd(rang[i].f, rang[i].s, 1);
        }
        else if(typ[i] == 'D'){
            middle.upd(rang[i].f, rang[i].s, 2);
        } 
        anses.pb(getans());
    }

    return anses;
}

int main() {
    setIO();
    cin >> n >> m >> q;
    cin >> horzsides[0] >> horzsides[1] >> vertsides[0] >> vertsides[1];
    horzsides[0] = "#"+horzsides[0];
    horzsides[1] = "#"+horzsides[1];
    vertsides[0] = "#"+vertsides[0];
    vertsides[1] = "#"+vertsides[1];
    for(int i = 1; i <= q; i++){
        cin >> typ[i];
        cin >> rang[i].f >> rang[i].s;
    }
    vi ans0 = solve();
    swap(n, m);
    swap(horzsides[0], vertsides[0]);
    swap(horzsides[1], vertsides[1]);
    for(int i = 1; i <= q; i++){
        if(typ[i] == 'L') typ[i] = 'U';
        else if(typ[i] == 'R') typ[i] = 'D';
        else if(typ[i] == 'U') typ[i] = 'L';
        else if(typ[i] == 'D') typ[i] = 'R';
    }
    vi ans1 = solve();

    for(int i = 0; i <= q; i++){
        ps(min(ans0[i], ans1[i]));
    }

    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
*/