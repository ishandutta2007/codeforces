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

const int MOD = 998244353; // 998244353;
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

vector<vmi> scmb; // small combinations
void genComb(int SZ) {
    scmb.assign(SZ,vmi(SZ)); scmb[0][0] = 1;
    FOR(i,1,SZ) F0R(j,i+1) 
        scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}

/**
 * Description: pre-compute factorial mod inverses,
     * assumes $MOD$ is prime and $SZ < MOD$.
 * Time: O(SZ)
 * Source: KACTL
 * Verification: https://dmoj.ca/problem/tle17c4p5
 */

vi invs, fac, ifac;
void genFac(int SZ) {
    invs.rsz(SZ), fac.rsz(SZ), ifac.rsz(SZ); 
    invs[1] = fac[0] = ifac[0] = 1; 
    FOR(i,2,SZ) invs[i] = MOD-(ll)MOD/i*invs[MOD%i]%MOD;
    FOR(i,1,SZ) {
        fac[i] = (ll)fac[i-1]*i%MOD;
        ifac[i] = (ll)ifac[i-1]*invs[i]%MOD;
    }
}

ll comb(int a, int b) {
    if (a < b || b < 0) return 0;
    return (ll)fac[a]*ifac[b]%MOD*ifac[a-b]%MOD;
}



/**
 * Description: Basic poly ops including division. Can replace \texttt{T} with double, complex.
 * Source: Own. Also see
     * https://github.com/kth-competitive-programming/kactl/blob/master/content/numerical/PolyInterpolate.h
     * https://github.com/ecnerwala/icpc-book/blob/master/content/numerical/fft.cpp
 * Verification: see FFT
 */

typedef mi T; using poly = vector<T>;
void remz(poly& p) { while (sz(p)&&p.bk==T(0)) p.pop_back(); }
poly rev(poly p) { reverse(all(p)); return p; }
poly shift(poly p, int x) { p.insert(begin(p),x,0); return p; }
poly RSZ(poly p, int x) { p.rsz(x); return p; }
T eval(const poly& p, T x) { // evaluate at point x
    T res = 0; R0F(i,sz(p)) res = x*res+p[i]; 
    return res; }
poly dif(const poly& p) { // differentiate
    poly res; FOR(i,1,sz(p)) res.pb(T(i)*p[i]); 
    return res; }
poly integ(const poly& p) { // integrate
    poly res(sz(p)+1); F0R(i,sz(p)) res[i+1] = p[i]/T(i+1);
    return res; }

poly& operator+=(poly& l, const poly& r) {
    l.rsz(max(sz(l),sz(r))); F0R(i,sz(r)) l[i] += r[i]; 
    return l; }
poly& operator-=(poly& l, const poly& r) {
    l.rsz(max(sz(l),sz(r))); F0R(i,sz(r)) l[i] -= r[i]; 
    return l; }
poly& operator*=(poly& l, const T& r) { trav(t,l) t *= r; 
    return l;     }
poly& operator/=(poly& l, const T& r) { trav(t,l) t /= r; 
    return l; }
poly operator+(poly l, const poly& r) { return l += r; }
poly operator-(poly l, const poly& r) { return l -= r; }
poly operator-(poly l) { trav(t,l) t *= -1; return l; }
poly operator*(poly l, const T& r) { return l *= r; }
poly operator*(const T& r, const poly& l) { return l*r; }
poly operator/(poly l, const T& r) { return l /= r;     }
poly operator*(const poly& l, const poly& r) {
    if (!min(sz(l),sz(r))) return {};
    poly x(sz(l)+sz(r)-1); 
    F0R(i,sz(l)) F0R(j,sz(r)) x[i+j] += l[i]*r[j];
    return x;
}
poly& operator*=(poly& l, const poly& r) { return l = l*r; }

pair<poly,poly> quoRem(poly a, poly b) { 
    remz(a); remz(b); assert(sz(b));
    T lst = b.bk, B = T(1)/lst; trav(t,a) t *= B; 
    trav(t,b) t *= B;
    poly q(max(sz(a)-sz(b)+1,0));
    for (int dif; (dif=sz(a)-sz(b)) >= 0; remz(a)) {
        q[dif] = a.bk; F0R(i,sz(b)) a[i+dif] -= q[dif]*b[i]; }
    trav(t,a) t *= lst;
    return {q,a}; // quotient, remainder
}
/**
poly quo(poly a, poly b) { return quoRem(a,b).f; }
poly rem(poly a, poly b) { return quoRem(a,b).s; }

poly a = {1,3,5,8,6,0,0,0,0}, b = {1,5,1};
ps(quoRem(a,b)); a = 2*a, b = 2*b; ps(quoRem(a,b));
*/
T resultant(poly a, poly b) { // R(A,B)
    // =b_m^n*prod_{j=1}^mA(mu_j)
    // =b_m^na_m^n*prod_{i=1}^nprod_{j=1}^m(mu_j-lambda_i)
    // =(-1)^{mn}a_n^m*prod_{i=1}^nB(lambda_i)
    // =(-1)^{nm}R(B,A)
    // Also, R(A,B)=b_m^{deg(A)-deg(A-CB)}R(A-CB,B)
    int ad = sz(a)-1, bd = sz(b)-1; 
    if (bd <= 0) return bd < 0 ? 0 : pow(b.bk,ad);
    int pw = ad; a = quoRem(a,b).s; pw -= (ad = sz(a)-1);
    return resultant(b,a)*pow(b.bk,pw)*T((bd&ad&1)?-1:1);
}




/**
 * Description: Multiply two polynomials. For xor convolution 
     * don't multiply \texttt{v} by \texttt{roots[ind]}. If
     * product of sizes is at most a certain threshold (ex. 10000)
     * then it's faster to multiply directly.
 * Time: O(N\log N)
 * Source: 
     * KACTL
     * https://cp-algorithms.com/algebra/fft.html
     * https://csacademy.com/blog/fast-fourier-transform-and-variations-of-it
 * Verification: 
    * SPOJ polymul, CSA manhattan, CF Perfect Encoding
    * http://codeforces.com/contest/632/problem/E
 */


const int root = 3; // 998244353
// For p < 2^30 there is also e.g. (5<<25, 3), (7<<26, 3) 
/// (479<<21, 3) and (483<<21, 5). Last two are > 10^9.
void genRoots(vmi& roots) { // REPLACE DEF OF MOD
    int n = sz(roots); mi r = pow(mi(root),(MOD-1)/n);
    roots[0] = 1; FOR(i,1,n) roots[i] = roots[i-1]*r; }
typedef complex<db> cd; typedef vector<cd> vcd;
void genRoots(vcd& roots) { // primitive n-th roots of unity
    int n = sz(roots); db ang = 2*PI/n;
    /// good way to compute these trig functions more quickly?
    F0R(i,n) roots[i] = cd(cos(ang*i),sin(ang*i)); }

int size(int s) { return s > 1 ? 32-__builtin_clz(s-1) : 0; }
template<class T> void fft(vector<T>& a, 
  const vector<T>& rts, bool inv = 0) {
    int n = sz(a);
    for (int i = 1, j = 0; i < n; i++) { 
        int bit = n>>1; for (; j&bit; bit /= 2) j ^= bit;
        j ^= bit; if (i < j) swap(a[i],a[j]);
    } // sort #s from 0 to n-1 by reverse binary
    for (int len = 1; len < n; len *= 2)
        for (int i = 0; i < n; i += 2*len) F0R(j,len) {
            T u = a[i+j], v = a[i+j+len]*rts[n/2/len*j];
            a[i+j] = u+v, a[i+j+len] = u-v;
        }
    if (inv) {
        reverse(1+all(a));
        T i = T(1)/T(n); trav(x,a) x *= i; 
    }
}
template<class T> vector<T> mul(vector<T> a, vector<T> b) {
    if (!min(sz(a),sz(b))) return {};
    int s = sz(a)+sz(b)-1, n = 1<<size(s);
    vector<T> roots(n); genRoots(roots);
    a.rsz(n), fft(a,roots); b.rsz(n), fft(b,roots);
    F0R(i,n) a[i] *= b[i];
    fft(a,roots,1); a.rsz(s); return a;
}

/**
 * Description: multiply two polynomials directly if small, otherwise use FFT
 * Source: KACTL, https://cp-algorithms.com/algebra/fft.html
 */


bool small(const poly& a, const poly& b) { // multiply directly
    return (ll)sz(a)*sz(b) <= 10000; } 
vmi smart(const vmi& a, const vmi& b) { return mul(a,b); }
vl smart(const vl& a, const vl& b) {
    auto X = mul(vcd(all(a)),vcd(all(b)));
    vl x(sz(X)); F0R(i,sz(X)) x[i] = round(X[i].real());
    return x; }
poly conv(const poly& a, const poly& b) {
    return small(a,b) ? a*b : smart(a,b); } 


/**
 * Description: computes $A^{-1}$ such that $AA^{-1}\equiv 1\pmod{x^n}$.
     * Newton's method: If you want $F(x)=0$ and $F(Q_k)\equiv 0\pmod{x^a}$
     * then $Q_{k+1}=Q_k-\frac{F(Q_k)}{F'(Q_k)}\pmod{x^{2a}}$ satisfies
     * $F(Q_{k+1})\equiv 0 \pmod{x^{2a}}$. Application: if $f(n),g(n)$ are the
     * \#s of forests and trees on $n$ nodes then 
     * $\sum_{n=0}^{\infty}f(n)x^n=\exp\left(\sum_{n=1}^{\infty}\frac{g(n)}{n!}\right)$.
 * Time: O(N\log N)
 * Source: CF, http://people.csail.mit.edu/madhu/ST12/scribe/lect06.pdf
     * https://cp-algorithms.com/algebra/polynomial.html
 * Usage: vmi v={1,5,2,3,4}; ps(exp(2*log(v,9),9)); // squares v
 * Verification: https://codeforces.com/contest/438/problem/E
     * https://codeforces.com/gym/102028/submission/77687049
     * https://loj.ac/problem/6703 (MultipointEval)
 */


poly inv(poly A, int n) { // Q-(1/Q-A)/(-Q^{-2})
    poly B{1/A[0]};
    while (sz(B) < n) { int x = 2*sz(B);
        B = RSZ(2*B-conv(RSZ(A,x),conv(B,B)),x); }
    return RSZ(B,n);
}
poly sqrt(const poly& A, int n) {  // Q-(Q^2-A)/(2Q)
    assert(A[0] == 1); poly B{1};
    while (sz(B) < n) { int x = 2*sz(B);
        B = T(1)/T(2)*RSZ(B+mul(RSZ(A,x),inv(B,x)),x); }
    return RSZ(B,n);
}
pair<poly,poly> divi(const poly& f, const poly& g) { 
    if (sz(f) < sz(g)) return {{},f};
    auto q = mul(inv(rev(g),sz(f)-sz(g)+1),rev(f));
    q = rev(RSZ(q,sz(f)-sz(g)+1));
    auto r = RSZ(f-mul(q,g),sz(g)-1); return {q,r};
}
poly log(poly A, int n) { assert(A[0] == 1); // (ln A)' = A'/A
    return RSZ(integ(conv(dif(A),inv(A,n))),n); }
poly exp(poly A, int n) { // Q-(lnQ-A)/(1/Q)
    assert(A[0] == 0); poly B = {1};
    while (sz(B) < n) { int x = 2*sz(B);
        B = RSZ(B+conv(B,RSZ(A,x)-log(B,x)),x); }
    return RSZ(B,n);
}

void segProd(vector<poly>& stor, poly& v, int ind, int l, int r) { // v -> places to evaluate at
    if (l == r) { stor[ind] = {-v[l],1}; return; }
    int m = (l+r)/2; segProd(stor,v,2*ind,l,m); segProd(stor,v,2*ind+1,m+1,r);
    stor[ind] = conv(stor[2*ind],stor[2*ind+1]);
}
void evalAll(vector<poly>& stor, vmi& res, poly v, int ind = 1) {
    v = divi(v,stor[ind]).s;
    if (sz(stor[ind]) == 2) { res.pb(sz(v)?v[0]:0); return; }
    evalAll(stor,res,v,2*ind); evalAll(stor,res,v,2*ind+1);
}
poly multiEval(poly v, poly p) {
    vector<poly> stor(4*sz(p)); segProd(stor,p,1,0,sz(p)-1);
    poly res; evalAll(stor,res,v); return res; }

poly combAll(vector<poly>& stor, poly& dems, int ind, int l, int r) {
    if (l == r) return {dems[l]};
    int m = (l+r)/2;
    poly a = combAll(stor,dems,2*ind,l,m), b = combAll(stor,dems,2*ind+1,m+1,r);
    return conv(a,stor[2*ind+1])+conv(b,stor[2*ind]);
}
poly interpolate(vector<pair<T,T>> v) {
    poly x; trav(t,v) x.pb(t.f);
    int n = sz(v);
    vector<poly> stor(4*n); segProd(stor,x,1,0,n-1);
    poly dems; evalAll(stor,dems,dif(stor[1]));
    F0R(i,n) dems[i] = v[i].s/dems[i];
    return combAll(stor,dems,1,0,n-1);
}

clock_t beg;

int n;
int m;

poly divxPow(poly a, int p){
    a.rsz(m);
    assert(a[0] == mi(0));
    for(int i = 0; i+1 < sz(a); i++){
        a[i] = a[i+1]; //divide by x
    }
    a = log(a, m);
    a*=mi(p);
    a = exp(a, m);
    return a;
}

poly ConstructE(poly P){
    P.rsz(m);
    poly E(m, 0);
    for(int i = 0; i <= n; i++){
        E[i] += P[n-i]*ifac[i];
    }
    return E;
}

poly CDsolve(poly C, poly D, poly Cneg){
    //cout << "C1" << " " << (ld(clock())-beg)/CLOCKS_PER_SEC << "\n";
    C.rsz(m);
    D.rsz(m);
    poly difCneg(4, 0);
    for(int i = 1; i <= 2; i++){
        difCneg[i+1] = mi(-i)*Cneg[i];
    }
    poly P1 = conv(dif(C), D);
    poly P1neg(4, 0);
    //cout << "C1.1" << " " << (ld(clock())-beg)/CLOCKS_PER_SEC << "\n";
    for(int i = 1; i <= 3; i++){
        for(int j = 0; j < m; j++){
            mi val = difCneg[i]*D[j];
            int ind = j-i;
            if(ind < 0){
                P1neg[-ind]+=val;
            }
            else{
                P1[ind]+=val;
            }
        }
    }
    //cout << "C1.2" << " " << (ld(clock())-beg)/CLOCKS_PER_SEC << "\n";
    //multiply by x
    for(int i = m-1; i >= 1; i--){
        P1[i] = P1[i-1];
    }
    P1[0] = P1neg[1];
    for(int i = 1; i <= 2; i++){
        P1neg[i] = P1neg[i+1];
    }
    //cout << "C1.3" << " " << (ld(clock())-beg)/CLOCKS_PER_SEC << "\n";
    poly P2 = conv(C, D);
    poly P2neg(3, 0);
    //cout << "C1.4" << " " << (ld(clock())-beg)/CLOCKS_PER_SEC << "\n";
    for(int i = 1; i <= 2; i++){
        for(int j = 0; j < m; j++){
            mi val = Cneg[i]*D[j];
            int ind = j-i;
            if(ind < 0){
                P2neg[-ind]+=val;
            }
            else{
                P2[ind]+=val;
            }
        }
    }
    //cout << "C1.5" << " " << (ld(clock())-beg)/CLOCKS_PER_SEC << "\n";
    //multiply by x
    for(int i = m-1; i >= 1; i--){
        P2[i] = P2[i-1];
    }
    P2[0] = P2neg[1];
    for(int i = 1; i <= 2; i++){
        P2neg[i] = P2neg[i+1];
    }
    //cout << "C2" << " " << (ld(clock())-beg)/CLOCKS_PER_SEC << "\n";
    poly E1 = ConstructE(P1);
    poly E2 = ConstructE(P2);
    for(int i = sz(E2)-1; i > 0; i--){
        E2[i] = E2[i-1];
    }
    E2[0] = 0;
    //cout << "C3" << " " << (ld(clock())-beg)/CLOCKS_PER_SEC << "\n";
    poly F(m, 0);
    for(int i = 0; i < m; i++){
        F[i] = mi(ifac[i]);
    }

    //cout << "C4" << " " << (ld(clock())-beg)/CLOCKS_PER_SEC << "\n";

    poly EF = conv(E1+E2, F);
    for(int i = 0; i <= n; i++){
        EF[i]*=mi(fac[i]);
    }
    poly sum(n+1, 0);
    for(int i = 0; i <= n; i++){
        sum[i]+=EF[i];
    }
    
    for(int i = 0; i <= n; i++){
        sum[i]*=mi(invs[n]);
    }
    //cout << "C5" << " " << (ld(clock())-beg)/CLOCKS_PER_SEC << "\n";
    return sum;
}

poly Zsolve(){
    poly C1, D1, C2, D2, invA1, invA2;
    poly zplus1 = {mi(1), mi(1)};

    invA1 = poly(m, 0);
    invA2 = poly(m, 0);
    for(int i = 1; i < m; i++){
        invA1[i] = mi(invs[i]);
        if(i % 2 == 0){
            invA1[i]*=mi(-1);
        }
    }
    for(int i = 1; i < m; i++){
        invA2[i] = 1;
        if(i % 2 == 0){
            invA2[i]*=mi(-1);
        }
    }
    //cout << "B2.1" << " " << (ld(clock())-beg)/CLOCKS_PER_SEC << " exp slow\n";

    poly C1denom = poly{mi(1)}-(poly{1, 1})*(poly{mi(1)}-invA1);
    poly C2denom = conv(poly{mi(1)}-invA2, poly{mi(1)}-conv(exp(invA2, m), poly{mi(1)}-invA2)); //EXP

    C1denom.rsz(m);
    C2denom.rsz(m);
    //cout << "B2.5" << " " << (ld(clock())-beg)/CLOCKS_PER_SEC << "\n";
    assert(C1denom[0] == 0);
    assert(C1denom[1] == 0);
    assert(C1denom[2] != 0);
    assert(C2denom[0] == 0);
    assert(C2denom[1] == 0);
    assert(C2denom[2] != 0);

    for(int i = 0; i+2 < m; i++){
        C1denom[i] = C1denom[i+2];
        C2denom[i] = C2denom[i+2];
    }
    poly C1neg(3, 0), C2neg(3, 0);
    //cout << "B2.6" << " " << (ld(clock())-beg)/CLOCKS_PER_SEC << " inv\n";
    C1 = -poly{1, 1}*inv(C1denom, m); //INV
    //cout << "B2.61" << " " << (ld(clock())-beg)/CLOCKS_PER_SEC << " exp log slow\n";
    D1 = divxPow(invA1, -n);
    //cout << "B2.62" << " " << (ld(clock())-beg)/CLOCKS_PER_SEC << " inv\n";
    C2 = inv(C2denom, m); //INV
    D2 = poly(m, 0);

    for(int i = 0; i <= n; i++){
        D2[i] = mi(comb(n, i));
    }
    //cout << "B2.7" << " " << (ld(clock())-beg)/CLOCKS_PER_SEC << "\n";
    C1neg[2] = C1[0];
    C1neg[1] = C1[1];
    C2neg[2] = C2[0];
    C2neg[1] = C2[1];

    for(int i = 0; i+2 < m; i++){
        C1[i] = C1[i+2];
        C2[i] = C2[i+2];
    }

    //cout << "B3" << " " << (ld(clock())-beg)/CLOCKS_PER_SEC << "\n";
    poly Z1 = CDsolve(C1, D1, C1neg);
    poly Z2 = CDsolve(C2, D2, C2neg);

    //cout << "B4" << " " << (ld(clock())-beg)/CLOCKS_PER_SEC << "\n";
    poly Zcomb = Z1+Z2;
    Zcomb.rsz(m);
    return Zcomb;
}

poly solve(){

    poly ans = Zsolve();
    
    poly ybinom(m, 0);

    for(int i = 0; i <= n+2; i++){
        ybinom[i] = mi(comb(n+2, i));
        if(i % 2 == 1){
            ybinom[i]*=-1;
        }
    }
    ans = conv(ans, ybinom);
    ans.rsz(n+1);

    for(int i = 1; i <= n; i++){
        ans[i]*=mi(fac[n]);
    }
    return ans;
}

int main() {
    setIO();
    cin >> n;
    //beg = clock();
    //cout << fixed << setprecision(5);
    //cout << "B1" << " " << (ld(clock())-beg)/CLOCKS_PER_SEC << "\n";
    m = n+100; //compute extra terms
    genFac(2*m+5);

    poly FinalAnswer = solve();
    for(int i = 1; i <= n; i++){
        cout << FinalAnswer[i].v << " ";
    }
    cout << "\n";
    //cout << "END" << " " << (ld(clock())-beg)/CLOCKS_PER_SEC << "\n";
    //dbg(mi(1)/mi(1620));
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
*/