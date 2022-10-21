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

const int MOD = 998244353;
const int MX = 2e5+5; 
const ll INF = 1e18; 
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; 

template<class T> bool ckmin(T& a, const T& b) { 
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
    return a < b ? a = b, 1 : 0; } 
int pct(int x) { return __builtin_popcount(x); } 
int bit(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
int cdiv(int a, int b) { return a/b+!(a<0||a%b == 0); } // division of a by b rounded up, assumes b > 0 

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
template<class A, class B> str ts(pair<A,B> p);
template<class A> str ts(complex<A> c) { return ts(mp(c.real(),c.imag())); }
str ts(bool b) { return b ? "true" : "false"; }
str ts(char c) { str s = ""; s += c; return s; }
str ts(str s) { return s; }
str ts(const char* s) { return (str)s; }
str ts(vector<bool> v) { 
    bool fst = 1; str res = "{";
    F0R(i,sz(v)) {
        if (!fst) res += ", ";
        fst = 0; res += ts(v[i]);
    }
    res += "}"; return res;
}
template<size_t SZ> str ts(bitset<SZ> b) {
    str res = ""; F0R(i,SZ) res += char('0'+b[i]);
    return res; }
template<class T> str ts(T v) {
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
    cerr << to_string(h); if (sizeof...(t)) cerr << ", ";
    DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 42
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

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

/**
 * Description: modular arithmetic operations 
 * Source: 
    * KACTL
    * https://codeforces.com/blog/entry/63903
    * https://codeforces.com/contest/1261/submission/65632855 (tourist)
    * https://codeforces.com/contest/1264/submission/66344993 (ksun)
 * Verification: 
    * https://open.kattis.com/problems/modulararithmetic
 */

struct mi {
    typedef decay<decltype(MOD)>::type T; 
     /// don't silently convert to T
    T v; explicit operator T() const { return v; }
    mi() { v = 0; }
    mi(ll _v) { 
        v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
        if (v < 0) v += MOD;
    }
    friend bool operator==(const mi& a, const mi& b) { 
        return a.v == b.v; }
    friend bool operator!=(const mi& a, const mi& b) { 
        return !(a == b); }
    friend bool operator<(const mi& a, const mi& b) { 
        return a.v < b.v; }
    friend void re(mi& a) { ll x; re(x); a = mi(x); }
    friend str ts(mi a) { return ts(a.v); }
   
    mi& operator+=(const mi& m) { 
        if ((v += m.v) >= MOD) v -= MOD; 
        return *this; }
    mi& operator-=(const mi& m) { 
        if ((v -= m.v) < 0) v += MOD; 
        return *this; }
    mi& operator*=(const mi& m) { 
        v = (ll)v*m.v%MOD; return *this; }
    mi& operator/=(const mi& m) { return (*this) *= inv(m); }
    friend mi pow(mi a, ll p) {
        mi ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend mi inv(const mi& a) { assert(a.v != 0); 
        return pow(a,MOD-2); }
        
    mi operator-() const { return mi(-v); }
    mi& operator++() { return *this += 1; }
    mi& operator--() { return *this -= 1; }
    friend mi operator+(mi a, const mi& b) { return a += b; }
    friend mi operator-(mi a, const mi& b) { return a -= b; }
    friend mi operator*(mi a, const mi& b) { return a *= b; }
    friend mi operator/(mi a, const mi& b) { return a /= b; }
};
typedef vector<mi> vmi;
typedef pair<mi,mi> pmi;
typedef vector<pmi> vpmi;

vector<vmi> comb;
void genComb(int SZ) {
    comb.assign(SZ,vmi(SZ)); comb[0][0] = 1;
    FOR(i,1,SZ) F0R(j,i+1) 
        comb[i][j] = comb[i-1][j]+(j?comb[i-1][j-1]:0);
}

const int mx = 300005;
int a[mx];
mi fterm[mx];
mi cterm[mx];
mi val[mx];
int s = 0; //sum
int main() {
    setIO();
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s+=a[i];
    }
    fterm[0] = 1;
    cterm[0] = 0;
    fterm[1] = 1;
    cterm[1] = -mi(n)+mi(1);
    for(int i = 1; i <= s-1; i++){
        fterm[i+1] = (fterm[i]*(mi(1)-mi(s-i)/mi(s)*mi(n-2)/mi(n-1))-mi(i)/mi(s)*fterm[i-1])*mi(n-1)*mi(s)/mi(s-i);
        cterm[i+1] = (cterm[i]*(mi(1)-mi(s-i)/mi(s)*mi(n-2)/mi(n-1))-mi(i)/mi(s)*cterm[i-1]-1)*mi(n-1)*mi(s)/mi(s-i);
    }
    val[s] = 0;
    val[0] = -cterm[s]/(fterm[s]);
    for(int i = 1; i <= s-1; i++){
        val[i] = val[0]*fterm[i]+cterm[i];
    }

    //dbg(fterm[1]);
    //dbg(cterm[1]);
    //dbg(val[3]);

    mi ans = 0;
    for(int i = 1; i <= n; i++){
        ans+=val[a[i]];
    }
    ans-=val[0]*mi(n-1);
    ans/=mi(n);
    ps(ans);

    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
*/