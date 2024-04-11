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

int MOD;
// {{{ ModInt
struct ModInt {
    template<class T> using integral_only = typename enable_if<is_integral<T>::value>::type;

    int x;
    constexpr ModInt() : x() {}
    template<class T, integral_only<T>* = nullptr>
    ModInt(T _x) {
        x = _x % MOD;
        if (x < 0) x += MOD;
    }
    ModInt operator-() const { return {x == 0 ? 0 : MOD-x}; }
    ModInt& operator+=(ModInt rhs) {
        x += rhs.x;
        if (x >= MOD) x -= MOD;
        return *this;
    }
    ModInt& operator-=(ModInt rhs) {
        x -= rhs.x;
        if (x < 0) x += MOD;
        return *this;
    }
    ModInt& operator*=(ModInt rhs) {
        x = (long long)x * rhs.x % MOD;
        return *this;
    }
    ModInt& operator/=(ModInt rhs) {
        return *this *= rhs.inv();
    }
    ModInt operator+(ModInt rhs) const { return ModInt(*this) += rhs; }
    ModInt operator-(ModInt rhs) const { return ModInt(*this) -= rhs; }
    ModInt operator*(ModInt rhs) const { return ModInt(*this) *= rhs; }
    ModInt operator/(ModInt rhs) const { return ModInt(*this) /= rhs; }
    ModInt inv() const {
        // should work for non-prime MOD if gcd(x, MOD) = 1
        int a = x, b = MOD, u = 1, v = 0;
        while (b != 0) {
            int t = a / b;
            a -= t * b;
            u -= t * v;
            swap(a, b);
            swap(u, v);
        }
        return u;
    }
    template<class T, integral_only<T>* = nullptr>
    ModInt pow(T e) {
        ModInt r = 1, p = *this;
        while (e) {
            if (e & 1) r *= p;
            p *= p;
            e >>= 1;
        }
        return r;
    }
    bool operator==(ModInt rhs) const { return x == rhs.x; }
    bool operator!=(ModInt rhs) const { return x != rhs.x; }
    bool operator<(ModInt rhs) const { return x < rhs.x; }
    bool operator<=(ModInt rhs) const { return x <= rhs.x; }
    bool operator>(ModInt rhs) const { return x > rhs.x; }
    bool operator>=(ModInt rhs) const { return x >= rhs.x; }
    friend string to_string(ModInt i) { return to_string(i.x); }
    friend ostream& operator<<(ostream &os, ModInt i) { return os << i.x; }
};
// }}}

// Seg {{{
template<typename T, typename U>
struct Seg {
    int n;
    vector<T> val;
    vector<U> upd;
    template<typename F>
    void _init(int id, int l, int r, F f) {
        if (l == r) {
            val[id] = f(l);
            return;
        }
        int m = (l + r) / 2;
        _init(id * 2, l, m, f);
        _init(id * 2 + 1, m + 1, r, f);
        pull(id);
    }
    template<class F>
    void init(int _n, F f) {
        n = _n;
        val.clear();
        val.resize(4 * (n + 1));
        upd.clear();
        upd.resize(4 * (n + 1));
        _init(1, 1, n, f);
    }
    T get(int id) {
        return upd[id](val[id]);
    }
    void pull(int id) {
        val[id] = get(id * 2) + get(id * 2 + 1);
    }
    void push(int id) {
        upd[id * 2] += upd[id];
        upd[id * 2 + 1] += upd[id];
        upd[id] = U();
    }
    T _ask(int id, int l, int r, int ql, int qr) {
        // dump(id,l,r,ql,qr);
        if (ql <= l && r <= qr) return get(id);
        push(id);
        int m = (l + r) / 2;
        if (qr <= m) {
            T t = _ask(id * 2, l, m, ql, qr);
            pull(id);
            return t;
        } else if (ql > m) {
            T t = _ask(id * 2 + 1, m + 1, r, ql, qr);
            pull(id);
            return t;
        } else {
            T tl = _ask(id * 2, l, m, ql, qr);
            T tr = _ask(id * 2 + 1, m + 1, r, ql, qr);
            pull(id);
            return tl + tr;
        }
    }
    T ask(int l, int r) {
        assert(l <= r);
        return _ask(1, 1, n, l, r);
    }
    void _update(int id, int l, int r, int ql, int qr, U qv) {
        if (ql <= l && r <= qr) {
            upd[id] += qv;
            return;
        }
        push(id);
        int m = (l + r) / 2;
        if (ql <= m) _update(id * 2, l, m, ql, qr, qv);
        if (qr > m) _update(id * 2 + 1, m + 1, r, ql, qr, qv);
        pull(id);
    }
    void update(int ql, int qr, U qv) {
        assert(ql <= qr);
        _update(1, 1, n, ql, qr, qv);
    }
    void _zet(int id, int l, int r, int qx, T qv) {
        if (l == r) {
            upd[id] = U();
            val[id] = qv;
            return;
        }
        push(id);
        int m = (l + r) / 2;
        if (qx <= m) _zet(id * 2, l, m, qx, qv);
        else _zet(id * 2 + 1, m + 1, r, qx, qv);
        pull(id);
    }
    void zet(int qx, T qv) {
        assert(1 <= qx && qx <= n);
        _zet(1, 1, n, qx, qv);
    }
};
// }}}

using mint=ModInt;

const int L=10;

int np,p[L];
void factor( int m ) {
    for ( int i=2; i*i<=m; i++ ) if ( m%i==0 ) {
        p[np++]=i;
        while ( m%i==0 ) m/=i;
    }
    if ( m!=1 ) p[np++]=m;
    assert(np<=L);
}

struct Z {
    int e[L];
    mint x;
    Z() {}
    Z( int t ) {
        REP(i,np) {
            int c=0;
            while ( t%p[i]==0 ) {
                c++;
                t/=p[i];
            }
            e[i]=c;
        }
        x=t;
    }

    void operator*=( const Z& t ) {
        // dump(e[0],t.e[0]);
        REP(i,np) e[i]+=t.e[i];
        x*=t.x;
    }

    void operator/=( int rhs ) {
        Z t=rhs;
        REP(i,np) {
            assert(e[i]>=t.e[i]);
            e[i]-=t.e[i];
        }
        x/=t.x;
    }

    mint val() {
        mint ans=x;
        REP(i,np) ans*=mint(p[i]).pow(e[i]);
        return ans;
    }
};


struct Val {
    mint x;
    Z *z;
    Val(mint _x = 0, Z *_z = nullptr) : x(_x),z(_z) {}
};
Val operator +(Val a, Val b) {
    return {a.x + b.x};
}

Z* gz;
struct Upd {
    mint d;
    Z z;
    Upd(int x) : d(x), z(x) {}
    Upd(mint _d = 1, Z _z = 1) : d(_d), z(_z) {}
    Val operator()(Val v) {
        if ( gz && v.z==gz ) {
            *gz *= z;
            gz=nullptr;
        }
        return {v.x * d, v.z};
    }
    Upd& operator +=(Upd rhs) {
        d *= rhs.d;
        z *= rhs.z;
        return *this;
    }
};
Seg<Val,Upd> seg;

const int N=1e5+10;
int n,m,a[N];
Z z[N];
void main() {
    R(n,m);
    MOD=m;
    factor(m);
    REP1(i,1,n) R(a[i]);
    REP1(i,1,n) z[i]=a[i];
    // REP1(i,1,n) dump(i,VI(z[i].e,z[i].e+np),z[i].x);
    seg.init(n,[&]( int i ) { return Val(mint(a[i]),&z[i]); });
    int q;
    R(q);
    while ( q-- ) {
        int op;
        R(op);
        // dump(q,op);
        if ( op==1 ) {
            int l,r,x;
            R(l,r,x);
            seg.update(l,r,Upd(x));
        } else if ( op==2 ) {
            int i,x;
            R(i,x);
            gz=&z[i];
            auto v=seg.ask(i,i);
            assert(!gz);
            assert(v.z==&z[i]);
            // dump(v.x,VI(v.z->e,v.z->e+np),v.z->x);
            // z[i]=*v.z;
            z[i]/=x;
            seg.zet(i,Val(z[i].val(),&z[i]));
        } else if ( op==3 ) {
            int l,r;
            R(l,r);
            auto ans=seg.ask(l,r);
            W(ans.x.x);
        } else assert(0);
    }
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}