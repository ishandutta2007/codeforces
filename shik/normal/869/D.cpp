// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
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

template<int MOD>
struct ModInt {
    int x;
    ModInt() : x(0) {}
    ModInt(int _x) {
        x = _x % MOD;
        if (x < 0) x += MOD;
    }
    ModInt(long long _x) {
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
    ModInt pow(long long e) {
        ModInt r = 1, p = *this;
        while (e) {
            if (e & 1) r *= p;
            p *= p;
            e >>= 1;
        }
        return r;
    }
    bool operator==(ModInt rhs) { return x == rhs.x; }
    bool operator!=(ModInt rhs) { return x != rhs.x; }
    bool operator<(ModInt rhs) { return x < rhs.x; }
    bool operator<=(ModInt rhs) { return x <= rhs.x; }
    bool operator>(ModInt rhs) { return x > rhs.x; }
    bool operator>=(ModInt rhs) { return x >= rhs.x; }
    friend ostream& operator<<(ostream &os, ModInt i) { return os << i.x; }
};

const int MOD = 1e9 + 7;
using mint = ModInt<MOD>;

inline int get_lv( int x ) { return 31-__builtin_clz(x); }

const int L=32;
const int M=4;
const int N=1010;
int n,m,ea[M],eb[M];

set<int> st;
void add_st( int x ) {
    while ( x ) {
        st.insert(x);
        x/=2;
    }
}

int get_cnt( int x ) {
    int c=0,d=0;
    while ( x<=n ) {
        int u=min(x+(1<<d)-1,n);
        c+=u-x+1;
        x*=2;
        d++;
    }
    return c;
}

map<int,int> cnt,idx;
void dfs( int p ) {
    if ( p>n ) return;
    if ( st.count(p) ) {
        cnt[p]=1;
        dfs(p*2);
        dfs(p*2+1);
    } else {
        cnt[p]=get_cnt(p);
    }
}

VI e[N];
int id,sz[N];

bool vis[N];
mint go( int p ) {
    vis[p]=1;
    mint s=sz[p];
    for ( int i:e[p] ) if ( !vis[i] ) s+=go(i);
    vis[p]=0;
    return s;
}

void main() {
    R(n,m);
    REP(i,m) R(ea[i],eb[i]);
    st.insert(1);
    REP(i,m) {
        add_st(ea[i]);
        add_st(eb[i]);
    }
    dfs(1);
    for ( auto i:cnt ) idx[i.first]=++id;
    for ( auto i:cnt ) {
        int u=idx[i.first];
        sz[u]=i.second;
        REP(j,2) {
            int v=i.first*2+j;
            if ( !idx.count(v) ) continue;
            v=idx[v];
            e[u].PB(v);
            e[v].PB(u);
        }
    }
    REP(i,m) {
        int u=idx[ea[i]];
        int v=idx[eb[i]];
        e[u].PB(v);
        e[v].PB(u);
    }
    mint ans=0;
    REP1(i,1,id) ans+=1LL*sz[i]*sz[i];
    REP1(i,1,id) {
        vis[i]=1;
        mint s=0;
        for ( int j:e[i] ) s+=go(j);
        ans+=s*sz[i];
        vis[i]=0;
    }
    W(ans);
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}