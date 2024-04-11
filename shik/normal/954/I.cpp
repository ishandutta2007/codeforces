// {{{ by shik
#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-function"
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define REP(i, n) for (int i = 0; i < int(n); i++)
#define REP1(i, a, b) for (int i = (a); i <= int(b); i++)
#define MP make_pair
#define PB push_back
using namespace std;
typedef int64_t LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

namespace { namespace shik {

template<class T> void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%" SCNd64, &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }

template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%" PRId64, x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }

#ifdef SHIK
#include "dump.hpp"
#else
#define dump(...)
#endif

template<class T, class F = less<T>> void sort_uniq(vector<T> &v, F f = F()) { sort(begin(v), end(v), f); v.resize(unique(begin(v), end(v)) - begin(v)); }
template<class T> inline T bit(T x, int i) { return (x >> i) & 1; }
template<class T> inline bool chkmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<class T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

// }}}

// {{{ DJS
struct DJS {
    vector<int> fa, sz;
    DJS() {}
    DJS(int n) { init(n); }
    void init(int n) {
        n++; // be nice for 1-index usage
        fa.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; i++) {
            fa[i] = i;
            sz[i] = 1;
        }
    }
    int f(int x) {
        return x == fa[x] ? x : fa[x] = f(fa[x]);
    }
    void u(int a, int b) {
        a = f(a);
        b = f(b);
        if (a == b) return;
        if (sz[a] > sz[b]) swap(a, b);
        fa[a] = b;
        sz[b] += sz[a];
    }
    bool is_root(int x) {
        return x == fa[x];
    }
    bool same(int a, int b) {
        return f(a) == f(b);
    }
};
// }}}

// {{{ FFT
namespace FFT {
using Double = double;
const Double pi = acos((Double)-1);

struct Complex {
    Double re, im;
    Complex operator+(const Complex &x) const { return {re + x.re, im + x.im}; }
    Complex operator-(const Complex &x) const { return {re - x.re, im - x.im}; }
    Complex operator*(const Complex &x) const { return {re * x.re - im * x.im, re * x.im + im * x.re}; }
    Complex operator/(Double x) const { return {re / x, im / x}; }
    Complex operator~() const { return {re, -im}; }
};

vector<vector<Complex>> omega{ {{1, 0}, {1, 0}}, {{1, 0}, {0, 1}, {1, 0}, {0, -1}} };
void build_omega(int n) {
    while (n >> omega.size()) {
        auto &u = omega.back();
        int m = u.size();
        vector<Complex> v(2 * m);
        for (int i = 0; i < 2 * m; i += 2) v[i] = u[i / 2];
        for (int i = 1; i < m / 2; i += 2) v[i] = {cos(i * pi / m), sin(i * pi / m)};
        for (int i = m / 2 + 1; i < m; i += 2) v[i] = {-v[m - i].re, v[m - i].im};
        for (int i = 1; i < m; i += 2) v[m + i] = ~v[i];
        omega.emplace_back(v);
    }
}

void fft(vector<Complex> &a, bool inv) {
    int n = a.size();
    build_omega(n);
    for (int i = 0, j = 1; j < n - 1; j++) {
        for (int k = n >> 1; k > (i ^= k); k >>= 1);
        if (i < j) swap(a[i], a[j]);
    }
    for (int l = 0, m = 1; m + m <= n; l++, m <<= 1) {
        for (int i = 0; i < n; i += m + m) {
            auto p = a.data() + i, q = a.data() + i + m, w = omega[l].data() + (inv ? m : 0);
            for (int j = 0; j < m; j++) {
                Complex t = q[j] * w[j];
                q[j] = p[j] - t;
                p[j] = p[j] + t;
            }
        }
    }
    if (inv) for (int i = 0; i < n; i++) a[i] = a[i] / n;
}
void dft(vector<Complex> &a) { fft(a, false); }
void idft(vector<Complex> &a) { fft(a, true); }

template<class T> void mul(int na, const int *a, int nb, const int *b, T *c) {
    static vector<Complex> x;
    assert(na > 0 && nb > 0);
    int n = 1;
    while (n < 2 * max(na, nb)) n *= 2;
    x.resize(n);
    for (int i = 0; i < n; i++) x[i].re = (i < na ? a[i] : 0);
    for (int i = 0; i < n; i++) x[i].im = (i < nb ? b[i] : 0);
    dft(x);
    const Complex t{0, 0.25};
    for (int i = 0; i <= n / 2; i++) {
        int j = (n - i) & (n - 1);
        auto p1 = x[i], p2 = x[j], q1 = ~x[j], q2 = ~x[i];
        x[i] = t * (p1 + q1) * (q1 - p1);
        x[j] = t * (p2 + q2) * (q2 - p2);
    }
    idft(x);
    for (int i = 0; i < na + nb - 1; i++) {
#ifdef SHIK
        assert(fabs(round(x[i].re) - x[i].re) < 0.1);
#endif
        c[i] = x[i].re + 0.5;
    }
}

template<class T> vector<T> mul(const vector<int> &a, const vector<int> &b) {
    int na = a.size(), nb = b.size();
    assert(na > 0 && nb > 0);
    vector<T> c(na + nb - 1);
    mul(na, a.data(), nb, b.data(), c.data());
    return c;
}
};
// }}}

const int N=125010;

void build( int n, char s[N], int v[26][N] ) {
    REP(i,n) v[s[i]-'a'][i]=1;
}

int ns,nt;
char s[N],t[N];
int vs[6][N],vt[6][N],c[2*N];
int msk[N][6],ans[N];

void main() {
    R(s,t);
    ns=strlen(s);
    nt=strlen(t);
    reverse(t,t+nt);
    build(ns,s,vs);
    build(nt,t,vt);
    REP(i,6) REP(j,6) {
        FFT::mul(ns,vs[i],nt,vt[j],c);
        REP1(k,0,ns-nt) if ( c[nt-1+k] ) {
            dump(i,j,k);
            msk[k][i]|=1<<j;
        }
    }
    DJS djs;
    REP1(i,0,ns-nt) {
        djs.init(6);
        REP(j,6) REP(k,6) if ( (msk[i][j]>>k)&1 ) djs.u(j,k);
        int cnt=0;
        REP(j,6) if ( djs.is_root(j) ) cnt++;
        ans[i]=6-cnt;
    }
    W(VI(ans,ans+ns-nt+1));
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}