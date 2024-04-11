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
    mint(ll _v) { v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
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
        v = (ll)v*m.v%MOD; return *this; }
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
 * Description: Multiply two polynomials of modular ints. For xor convolution 
     * ignore \texttt{m}. If product of sizes is at most a certain 
     * threshold (ex. 10000) then it's faster to multiply directly.
 * Time: O(N\log N)
 * Source: 
     * KACTL
     * https://cp-algorithms.com/algebra/fft.html
     * https://csacademy.com/blog/fast-fourier-transform-and-variations-of-it
     * maroonrk
 * Verification: 
    * https://judge.yosupo.jp/problem/convolution_mod
    * SPOJ polymul, CSA manhattan, CF Perfect Encoding
    * http://codeforces.com/contest/632/problem/E
 */

// const int MOD = 998244353;

template<class T> void fft(vector<T>& A, bool inv = 0) {
    int n = sz(A); vector<T> B(n);
    assert((T::mod-1)%n == 0);
    T r = pow(T::rt(),(T::mod-1)/n);
    for(int b = n/2; b; b /= 2, swap(A,B)) {
        T w = pow(r,b), m = 1;
        for(int i = 0; i < n; i += b*2, m *= w) F0R(j,b) {
            T u = A[i+j], v = A[i+j+b]*m;
            B[i/2+j] = u+v; B[i/2+j+n/2] = u-v;
        }
    }
    if (inv) { reverse(1+all(A)); 
        T z = T(1)/T(n); trav(t,A) t *= z; }
}
template<class T> vector<T> mul(vector<T> A, vector<T> B) { 
    if (!min(sz(A),sz(B))) return {};
    int s = sz(A)+sz(B)-1, n = 1; while (n < s) n *= 2;
    bool eq = A == B; A.rsz(n), fft(A);
    if (eq) B = A; // squaring A, so remove one FFT
    else B.rsz(n), fft(B);
    F0R(i,n) A[i] *= B[i];
    fft(A,1); A.rsz(s); return A;
}


/**
 * Description: Multiply two polynomials with arbitrary modulus.
 * Source: maroonrk
 * Verification: see FFT
 */

template<class M, class T> vector<M> go(vector<T> x, vector<T> y) {
    auto con = [](const vector<T>& v) {
        vector<M> w(sz(v)); F0R(i,sz(v)) w[i] = (int)v[i];
        return w; };
    return mul(con(x),con(y));
}
template<class T> vector<T> MUL(const vector<T>& A, const vector<T>& B) {
    using m0 = mint<(997<<20)+1,3>;  auto c0 = go<m0>(A,B); // 2^20 * 997  + 1
    using m1 = mint<(1003<<20)+1,6>; auto c1 = go<m1>(A,B); // 2^20 * 1003 + 1
    // using m2 = mint<(1005<<20)+1,7>; auto c2 = go<m2>(A,B); // 2^20 * 1005 + 1
    int n = sz(c0); vector<T> res(n);
    m1 r01 = 1/m1(m0::mod); //m2 r02 = 1/m2(m0::mod), r12 = 1/m2(m1::mod);
    F0R(i,n) { // a is remainder mod m0::mod, b fixes it mod m1::mod
        int a = c0[i].v, b = ((c1[i]-a)*r01).v; //c = (((c2[i]-a)*r02-b)*r12).v;
        res[i] = T(b)*m0::mod+a; // c fixes it mod m2::mod
        if(res[i] >= ll(m0::mod)*m1::mod-res[i]) res[i] -= ll(m0::mod)*m1::mod;
    }
    return res;
}

const int mx = 100005;
int a[mx];
int b[mx];

int main() {
    setIO();
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> b[i];
    }

    vl a1, a2;
    vl b1, b2;
    a1.rsz(100005);
    a2.rsz(100005);
    b1.rsz(100005);
    b2.rsz(100005);
    for(int i = 1; i <= n; i++){
        a1[a[i]]++;
        b1[a[i]]++;
        if(i+1 <= n){
            a1[max(a[i], a[i+1])]--;
            b1[min(a[i], a[i+1])]--;
        }
    }

    for(int i = 1; i <= m; i++){
        a2[b[i]]++;
        b2[b[i]]++;
        if(i+1 <= m){
            a2[max(b[i], b[i+1])]--;
            b2[min(b[i], b[i+1])]--;
        }
    }

    vl a3 = MUL(a1, a2);
    vl b3 = MUL(b1, b2);
    a3.rsz(200005);
    b3.rsz(200005);
    for(int i = 1; i < sz(a3); i++){
        a3[i]+=a3[i-1];
    }
    for(int i = sz(b3)-2; i >= 0; i--){
        b3[i]+=b3[i+1];
    }

    for(int i = 1; i <= q; i++){
        int x;
        cin >> x;
        ll ans = b3[x]-a3[x-1];
        ps(ans);
    }

    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
*/